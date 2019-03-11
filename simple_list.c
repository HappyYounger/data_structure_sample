//
// Created by 杨光 on 2019/3/4.
//
#include <stdio.h>
#include <stdlib.h>

#include "simple_list.h"
#include <string.h>

static const unsigned _ListCapacity = 16;

_p_list list_init(unsigned element_size,
                  unsigned list_capacity,
                  _p_func_ad_assigns p_func_adt_assigns,
                  _p_func_ad_equals p_func_adt_equals) {

    if (element_size > 0) {

        _p_list p_list = malloc(sizeof(_list));

        p_list->element_count = 0;
        p_list->list_capacity = list_capacity < _ListCapacity ? _ListCapacity : list_capacity;
        p_list->header = malloc(element_size * p_list->list_capacity);
        p_list->p_func_ad_assigns = p_func_adt_assigns;
        p_list->p_func_ad_equals = p_func_adt_equals;

        ad_pool_init(element_size, list_capacity);

        return p_list;
    }

    return NULL;
}

void list_append_ad(_p_list p_list, _p_adt p_ad) {

    if (p_list != NULL) {

        if (p_list->element_count == p_list->list_capacity) {

            list_extends(p_list);
        }

        if (p_list->p_func_ad_assigns == NULL) {

            _p_adt p_ad = ad_pool_peek(p_list->p_ad_pool);

            p_list->header[p_list->element_count++].p_data = p_ad->p_data;
        } else {

            p_list->p_func_ad_assigns(p_list->header + p_list->element_count++, p_ad);
        }
    }
}

void list_destroy(_p_list p_list) {

    if (p_list != NULL) {

        p_list->list_capacity = 0;
        p_list->element_count = 0;
        free(p_list->header);
        free(p_list);
    }
}

static void list_copy(_p_list p_list, void *des, void *src, unsigned size) {

    if (p_list != NULL) {

        for (int i = 0; i < size; ++i) {

            if (p_list->p_func_ad_assigns == NULL) {

                *(_p_adt) des = *(_p_adt) src;
            } else {

                p_list->p_func_ad_assigns(des, src);
            }
        }
    }
}

_p_list list_extends(_p_list p_list) {

    if (p_list != NULL) {

        _p_adt p_adt_old = p_list->header;

        p_list->list_capacity *= 2;
        p_list->header = malloc(sizeof(_adt) * p_list->list_capacity);

        list_copy(p_list, p_list->header, p_adt_old, p_list->element_count);

        free(p_adt_old);
        return p_list;

    }
    return NULL;
}


void list_move_ad_array(_p_list p_list, unsigned index, int offset) {

    if (p_list != NULL && index < p_list->element_count && offset != 0) {

        if (offset > 0) {

            if (offset + p_list->element_count == p_list->list_capacity) {

                list_extends(p_list);
            }

            for (int i = p_list->element_count - 1; i >= (int) index; --i) {

                p_list->header[i + offset] = p_list->header[i];
            }
        } else {

            for (int i = index; i < p_list->element_count; ++i) {

                p_list->header[index] = p_list->header[index + offset];
            }
        }

        p_list->element_count += offset;
    }
}

void list_remove_ad_at(_p_list p_list, unsigned index) {

    list_move_ad_array(p_list, index, -1);
}

void list_remove_ad(_p_list p_list, _p_adt p_ad) {

//    if (p_list != NULL && p_list->header != NULL && p_list->element_size > 0) {
//
//        for (int i = p_list->element_size - 1; i >= 0; --i) {
//
//            if (p_list->p_func_ad_equals == NULL) {
//
//                if (p_list->header[i].ad == p_ad->ad) {
//
//                    list_move_ad_array(p_list, i, -1);
//                }
//            } else if (p_list->p_func_ad_equals(p_list->header[i].ad, p_ad->ad)) {
//
//
//            }
//
//
//        }
//
//    }
}

void list_insert_ad(_p_list p_list, unsigned index, _p_adt p_ad) {

    if (p_list != NULL && index < p_list->element_count) {

        list_move_ad_array(p_list, index, 1);

        if (p_list->p_func_ad_assigns == NULL) {

            p_list->header[index] = *p_ad;
        } else {

            p_list->p_func_ad_assigns(p_list->header + index, p_ad);
        }
    }
}

void list_clear(_p_list p_list) {

    if (p_list != NULL) {

        p_list->element_count = 0;
    }
}

void list_print(_p_list p_list, _p_func_ad_prints print_adt) {

    if (p_list != NULL) {

        for (int i = 0; i < p_list->element_count; ++i) {

            print_adt(p_list->header + i);
        }
    }
}
