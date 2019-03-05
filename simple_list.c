//
// Created by 杨光 on 2019/3/4.
//
#include <stdio.h>
#include <stdlib.h>

#include "simple_list.h"

_p_list list_init(unsigned capacity) {

    _p_list p_list = malloc(sizeof(_list));

    if (capacity < 16) {

        capacity = 16;
    }

    p_list->capacity = capacity;
    p_list->size = 0;
    p_list->header = malloc(sizeof(_adt) * capacity);


    return p_list;
}

void list_destroy(_p_list p_list) {

    if (p_list != NULL) {

        p_list->capacity = 0;
        p_list->size = 0;
        free(p_list->header);

        free(p_list);
    }
}

void list_copy(_padt des, _padt src, unsigned size) {

    for (int i = 0; i < size; ++i) {

        des[i] = src[i];
    }
}

_p_list list_expand(_p_list p_list) {

    if (p_list != NULL) {

        _padt src = p_list->header;

        p_list->capacity *= 2;
        p_list->header = malloc(sizeof(_adt) * p_list->capacity);

        list_copy(p_list->header, src, p_list->size);

        free(src);
        return p_list;

    }
    return NULL;
}

void list_add(_p_list p_list, _padt padt) {

    if (p_list != NULL) {

        if (p_list->size == p_list->capacity) {

            list_expand(p_list);
        }

        p_list->header[p_list->size++].n = padt->n;
    }
}

void list_move(_p_list p_list, unsigned index, int offset) {

    if (p_list != NULL && index < p_list->size && offset != 0) {

        if (offset > 0) {

            if (offset + p_list->size == p_list->capacity) {

                list_expand(p_list);
            }

            for (int i = p_list->size - 1; i >= (int) index; --i) {

                p_list->header[i + offset] = p_list->header[i];
            }


        } else {

            for (int i = index; i < p_list->size; ++i) {

                p_list->header[index] = p_list->header[index + offset];
            }
        }

        p_list->size += offset;
    }
}

void list_remove_at(_p_list p_list, unsigned index) {

    list_move(p_list, index, -1);
}

void list_remove(_p_list p_list, _padt padt) {

    if (p_list != NULL && p_list->header != NULL && p_list->size > 0) {

        for (int i = p_list->size - 1; i >= 0; --i) {

            if (p_list->header[i].n == padt->n) {

                list_move(p_list, i, -1);
            }
        }

    }
}

void list_insert(_p_list p_list, unsigned index, _padt padt) {

    if (p_list != NULL && index < p_list->size) {

        list_move(p_list, index, 1);
        p_list->header[index].n = padt->n;
    }
}

void list_clear(_p_list p_list) {

    if (p_list != NULL) {

        p_list->size = 0;
    }
}
