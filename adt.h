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

    _p_adt p_ad_element;
    _p_adt p_ad_next;
    _p_adt p_ad_previous;

} _ad_element_record, *_p_ad_element_record;

typedef struct {

    _p_adt ad_array;

    unsigned element_size;
    unsigned pool_capacity;

    char *p_ad_element_mapping;
    unsigned mapping_length;

} _ad_pool, *_p_ad_pool;

_p_ad_pool ad_pool_init(unsigned element_size, unsigned pool_capacity);

_p_ad_pool ad_pool_extend(_p_ad_pool p_ad_pool);

_p_adt ad_pool_take_an_available(_p_ad_pool p_ad_pool);

_p_adt ad_pool_return_an_unavailable(_p_ad_pool p_ad_pool, _p_adt p_ad);

void ad_pool_destroy(_p_ad_pool p_ad_pool);

_p_adt ad_assign(void *p_ad1, void *p_ad2, unsigned size);

void ad_destroy(void *p_ad);

typedef void (*_p_func_ad_assigns)(void *p_ad1, void *p_ad2);

typedef bool (*_p_func_ad_equals)(void *p_ad1, void *p_ad2);

typedef bool (*_p_func_ad_meets_condition)(void *p_ad);

typedef void(*_p_func_ad_prints)(void *p_ad);


#endif //DATA_STRUCTURE_SAMPLE_ADT_H
