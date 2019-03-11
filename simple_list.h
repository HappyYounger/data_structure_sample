//
// Created by 杨光 on 2019/3/4.
//

#ifndef DATA_STRUCTURE_SAMPLE_SIMPLE_LIST_H
#define DATA_STRUCTURE_SAMPLE_SIMPLE_LIST_H

#include "adt.h"

typedef struct List {

    unsigned element_count;
    unsigned list_capacity;
    _p_adt header;

    _p_func_ad_assigns p_func_ad_assigns;
    _p_func_ad_equals p_func_ad_equals;
    _p_ad_pool p_ad_pool;
} _list, *_p_list;


_p_list list_init(unsigned element_size, unsigned list_capacity,
                  _p_func_ad_assigns p_func_ad_assigns,
                  _p_func_ad_equals p_func_ad_equals);

void list_append_ad(_p_list p_list, _p_adt p_ad);

void list_destroy(_p_list p_list);

_p_list list_extends(_p_list p_list);

void list_remove_ad_at(_p_list p_list, unsigned index);

void list_remove_ad_if(_p_list p_list, _p_adt p_ad, _p_func_ad_meets_condition p_func_adt_meets_condition);

void list_insert_ad(_p_list p_list, unsigned index, _p_adt p_ad);

void list_clear(_p_list p_list);

void list_print(_p_list p_list, _p_func_ad_prints print_ad);

#endif //DATA_STRUCTURE_SAMPLE_SIMPLE_LIST_H
