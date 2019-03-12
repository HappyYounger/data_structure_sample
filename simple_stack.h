//
// Created by 杨光 on 2019/3/4.
//

#ifndef DATA_STRUCTURE_SAMPLE_SIMPLE_STACK_H
#define DATA_STRUCTURE_SAMPLE_SIMPLE_STACK_H


#include "adt.h"

typedef struct Stack {

    _p_adt p_ad;
    int capacity;
    int size;
} _stack, *_p_stack;

typedef struct _Linked_Stack {

    _p_linked_adt head;
    _p_linked_adt tail;

    int size;
} _linked_stack, *_p_linked_stack;

_p_adt pop_stack(_p_stack p_stack);

_p_adt top_stack(_p_stack p_stack);

void push_stack(_p_stack p_stack, _p_adt p_ad);

_p_stack init_stack(int capacity);

void destroy_stack(_p_stack p_stack);

_p_linked_adt pop_linked_stack(_p_linked_stack p_linked_stack);

_p_linked_adt top_linked_stack(_p_linked_stack p_linked_stack);

void push_linked_stack(_p_linked_stack p_linked_stack, _p_linked_adt p_linked_ad);

_p_linked_stack init_linked_stack();

void destroy_linked_stack(_p_linked_stack p_linked_stack);

#endif //DATA_STRUCTURE_SAMPLE_SIMPLE_STACK_H
