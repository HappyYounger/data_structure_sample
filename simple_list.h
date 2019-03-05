//
// Created by 杨光 on 2019/3/4.
//

#ifndef DATA_STRUCTURE_SAMPLE_SIMPLE_LIST_H
#define DATA_STRUCTURE_SAMPLE_SIMPLE_LIST_H

#include "adt.h"

typedef struct _List {

    unsigned size;
    unsigned capacity;
    _padt header;

} _list, *_p_list;


_p_list list_init(unsigned capacity);

void list_destroy(_p_list p_list);

_p_list list_expand(_p_list p_list);

void list_add(_p_list p_list, _padt padt);

void list_remove_at(_p_list p_list, unsigned index);

void list_remove(_p_list p_list, _padt padt);

void list_insert(_p_list p_list, unsigned index, _padt padt);

void list_clear(_p_list p_list);

#endif //DATA_STRUCTURE_SAMPLE_SIMPLE_LIST_H
