//
// Created by 杨光 on 2019/3/4.
//

#ifndef DATA_STRUCTURE_SAMPLE_SIMPLE_QUEUE_H
#define DATA_STRUCTURE_SAMPLE_SIMPLE_QUEUE_H

#include "simple_stack.h"

typedef struct Queue {

    unsigned size;
    _p_linked_adt header;
    _p_linked_adt tail;
    _p_func_ad_assigns p_func_ad_assigns;
    _p_func_ad_equals p_func_ad_equals;
} _queue, *_p_queue;

_p_queue queue_init(_p_func_ad_assigns p_func_ad_assigns, _p_func_ad_equals p_func_ad_equals);

void queue_destroy(_p_queue p_queue);

_p_linked_adt queue_add(_p_queue p_queue, _p_linked_adt p_linked_ad);

_p_linked_adt queue_peek(_p_queue p_queue);

_p_linked_adt queue_remove(_p_queue p_queue);

void queue_clear(_p_queue p_queue);

#endif //DATA_STRUCTURE_SAMPLE_SIMPLE_QUEUE_H
