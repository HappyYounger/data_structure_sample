//
// Created by 杨光 on 2019/3/4.
//

#ifndef DATA_STRUCTURE_SAMPLE_SIMPLE_LIST_H
#define DATA_STRUCTURE_SAMPLE_SIMPLE_LIST_H

#include "adt.h"

typedef struct List {

    unsigned element_count;
    unsigned list_capacity;
    _p_adt* header;

    _p_func_ad_assign p_func_ad_assign;
    _p_func_ad_equal p_func_ad_equal;
    _p_ad_pool p_ad_pool;
} _list, *_p_list;

_p_list list_init(unsigned element_size, unsigned list_capacity,
                  _p_func_ad_assign p_func_adt_assign,
                  _p_func_ad_equal p_func_adt_equal);

void list_append(_p_list p_list, _p_adt p_ad);

void list_destroy(_p_list p_list);

_p_list list_extend(_p_list p_list);

void list_remove_ad_at(_p_list p_list, unsigned index);

void list_remove_ad_if(_p_list p_list, _p_adt p_ad, _p_func_ad_if p_func_ad_if);

void list_insert(_p_list p_list, unsigned index, _p_adt p_ad);

void list_clear(_p_list p_list);

void list_print(_p_list p_list, _p_func_ad_print print_ad);

void list_move(_p_list p_list, unsigned from, unsigned to);

void list_copy(_p_list p_list, void *des, void *src, unsigned size);


#endif //DATA_STRUCTURE_SAMPLE_SIMPLE_LIST_H
