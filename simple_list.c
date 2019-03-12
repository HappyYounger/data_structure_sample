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
                  _p_func_ad_assign p_func_adt_assign,
                  _p_func_ad_equal p_func_adt_equal) {

    if (element_size > 0) {

        _p_list p_list = malloc(sizeof(_list));

        p_list->element_count = 0;
        p_list->list_capacity = list_capacity < _ListCapacity ? _ListCapacity : list_capacity;

        p_list->header = malloc(sizeof(_p_adt) * p_list->list_capacity);

        p_list->p_func_ad_assign = p_func_adt_assign;
        p_list->p_func_ad_equal = p_func_adt_equal;

        p_list->p_ad_pool = ad_pool_init(element_size, list_capacity);

        return p_list;
    }

    return NULL;
}

void list_copy(_p_list p_list, void *des, void *src, unsigned size) {

    if (p_list != NULL) {

        for (int i = 0; i < size; ++i) {

            if (p_list->p_func_ad_assign == NULL) {

//                *(_p_adt) des = *(_p_adt) src;
                des = src;
            } else {

                p_list->p_func_ad_assign(des, src);
            }
        }
    }
}

_p_list list_extend(_p_list p_list) {

    if (p_list != NULL) {

        _p_adt *p_adt_old = p_list->header;

        p_list->list_capacity *= 2;
        p_list->header = malloc(sizeof(_adt) * p_list->list_capacity);

        list_copy(p_list, p_list->header, p_adt_old, p_list->element_count);
        free(p_adt_old);
        ad_pool_extend(p_list->p_ad_pool);

        return p_list;
    }
    return NULL;
}


void list_append(_p_list p_list, _p_adt p_ad) {

    if (p_list != NULL) {

        if (p_list->element_count == p_list->list_capacity) {

            list_extend(p_list);
        }

        _p_adt p_ad_clone = ad_pool_take_an_available(p_list->p_ad_pool);

        ad_assign(p_ad_clone, p_ad, sizeof(_p_adt), p_list->p_func_ad_assign);

        p_list->header[p_list->element_count++] = p_ad_clone;
    }
}

void list_destroy(_p_list p_list) {

    if (p_list != NULL) {

        p_list->list_capacity = 0;
        p_list->element_count = 0;
        free(p_list->header);
        ad_pool_destroy(p_list->p_ad_pool);
        free(p_list);
    }
}


void list_move(_p_list p_list, unsigned from, unsigned to) {


    if (p_list != NULL && from < p_list->element_count) {

        unsigned size = p_list->element_count - from;

        while (to + size >= p_list->list_capacity) {

            list_extend(p_list);
        }

        memmove(p_list->header + to, p_list->header + from, size * sizeof(_p_adt));
        p_list->element_count += to - from;
    }
}

unsigned list_find(_p_list p_list, _p_adt p_ad) {

    if (p_list != NULL && p_ad != NULL) {

        for (int i = 0; i < p_list->element_count; ++i) {

            if ((p_list->p_func_ad_equal != NULL && p_list->p_func_ad_equal(p_list->header[i], p_ad))
                || (p_list->p_func_ad_equal == NULL && p_list->header[i]->p_data == p_ad->p_data)) {

                return i;
            }
        }
    }

    return -1;
}

unsigned list_remove(_p_list p_list, _p_adt p_ad) {

    unsigned index = list_find(p_list, p_ad);

    if (index >= 0) {

        list_remove_ad_at(p_list, index);
    }
    return index;
}

void list_remove_ad_at(_p_list p_list, unsigned index) {

    list_move(p_list, index, index - 1);
}

void list_remove_ad_if(_p_list p_list, _p_func_ad_if p_func_ad_if) {

    if (p_list != NULL && p_func_ad_if != NULL) {

        for (int i = p_list->element_count; i >= 0; --i) {

            if (p_func_ad_if(p_list->header[i])) {

                list_remove_ad_at(p_list, i);
            }
        }
    }

}

void list_insert(_p_list p_list, unsigned index, _p_adt p_ad) {

    if (p_list != NULL && index < p_list->element_count) {

        list_move(p_list, index, 1);

        if (p_list->p_func_ad_assign == NULL) {

            p_list->header[index] = p_ad;
        } else {

            p_list->p_func_ad_assign(p_list->header + index, p_ad);
        }
    }
}

void list_clear(_p_list p_list) {

    if (p_list != NULL) {

        p_list->element_count = 0;
        ad_pool_clear(p_list->p_ad_pool);
    }
}

void list_print(_p_list p_list, _p_func_ad_print print_ad) {

    if (p_list != NULL) {

        for (int i = 0; i < p_list->element_count; ++i) {

            print_ad(p_list->header[i]);
        }
    }
}
