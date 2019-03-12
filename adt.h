//
// Created by 杨光 on 2019/3/4.
//

#ifndef DATA_STRUCTURE_SAMPLE_ADT_H
#define DATA_STRUCTURE_SAMPLE_ADT_H

#include <stdbool.h>

typedef struct {

    void *p_data;
    unsigned data_size;
} _adt, *_p_adt;

typedef struct _Linked_ADT {

    _p_adt p_ad;
    struct _Linked_ADT *p_prev_ad;
    struct _Linked_ADT *p_next_ad;

} _linked_adt, *_p_linked_adt;

typedef struct {

    _p_adt ad_array;

    unsigned element_size;
    unsigned pool_capacity;

    char *p_ad_element_mapping;
    unsigned mapping_length;

} _ad_pool, *_p_ad_pool;

typedef void *(*_p_func_ad_assign)(void *p_ad1, void *p_ad2);

typedef bool (*_p_func_ad_equal)(void *p_ad1, void *p_ad2);

typedef bool (*_p_func_ad_if)(void *p_ad);

typedef void(*_p_func_ad_print)(void *p_ad);

_p_ad_pool ad_pool_init(unsigned element_size, unsigned pool_capacity);

_p_ad_pool ad_pool_extend(_p_ad_pool p_ad_pool);

_p_adt ad_pool_take_an_available(_p_ad_pool p_ad_pool);

_p_adt ad_pool_return_an_unavailable(_p_ad_pool p_ad_pool, _p_adt p_ad);

void ad_pool_destroy(_p_ad_pool p_ad_pool);

void ad_pool_clear(_p_ad_pool p_ad_pool);

_p_adt ad_build(_p_adt p_ad, void *p_data, unsigned data_size);

_p_adt ad_assign(void *p_ad1, void *p_ad2, unsigned size, _p_func_ad_assign p_func_ad_assigns);


#endif //DATA_STRUCTURE_SAMPLE_ADT_H
