//
// Created by 杨光 on 2019/3/4.
//

#ifndef DATA_STRUCTURE_SAMPLE_ADT_H
#define DATA_STRUCTURE_SAMPLE_ADT_H

#include <stdbool.h>

typedef struct {

    void *p_data;
    unsigned size;
} _adt, *_p_adt;


typedef struct _Linked_ADT {

    _p_adt p_ad;
    struct _Linked_ADT *p_prev_ad;
    struct _Linked_ADT *p_next_ad;

} _linked_adt, *_p_linked_adt;

typedef struct {

    _p_adt ad_array;
    unsigned size;
    unsigned length;
    unsigned current;

} _ad_pool, *_p_ad_pool;

_p_adt ad_gets_from_pool(_p_ad_pool p_ad_pool);

_p_adt ad_inits(void *p_ad, unsigned size);

_p_adt ad_assigns(void *p_ad1, void *p_ad2, unsigned size);

void ad_destroys(void *p_ad);

_p_ad_pool ad_pool_inits(unsigned size, unsigned length);

void ad_pool_destroys(_p_ad_pool p_ad_pool);

_p_ad_pool ad_pool_extends(_p_ad_pool p_ad_pool);


typedef void (*_p_func_ad_assigns)(void *p_ad1, void *p_ad2);

typedef bool (*_p_func_ad_equals)(void *p_ad1, void *p_ad2);

typedef bool (*_p_func_ad_meets_condition)(void *p_ad);

typedef void(*_p_func_ad_prints)(void *p_ad);


#endif //DATA_STRUCTURE_SAMPLE_ADT_H
