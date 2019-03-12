//
// Created by 杨光 on 2019/3/4.
//

#include "simple_stack.h"
#include <stdio.h>
#include <stdlib.h>

_p_stack init_stack(int capacity) {

    _p_stack ptrStack = malloc(sizeof(_stack));

    ptrStack->capacity = capacity;
    ptrStack->size = 0;
    ptrStack->p_ad = malloc(sizeof(_adt) * capacity);

    return ptrStack;
}

void destroy_stack(_p_stack p_stack) {

    if (p_stack != NULL) {

        if (p_stack->p_ad != NULL) {

            free(p_stack->p_ad);
        }

        free(p_stack);
    }
}

_p_adt pop_stack(_p_stack p_stack) {

    if (p_stack != NULL && p_stack->p_ad != NULL && p_stack->size > 0) {

        p_stack->size--;
        return p_stack->p_ad + p_stack->size;
    }

    return NULL;
}

_p_adt top_stack(_p_stack p_stack) {

    if (p_stack != NULL && p_stack->p_ad != NULL && p_stack->size > 0) {

        return p_stack->p_ad + p_stack->size - 1;
    }
    return NULL;

}

void push_stack(_p_stack p_stack, _p_adt p_ad) {

    if (p_stack != NULL && p_stack->p_ad != NULL && p_ad != NULL) {

        if (p_stack->capacity == p_stack->size) {

            int capacity = p_stack->capacity * 2;

            p_stack->capacity = capacity;
            _p_adt new_stack = malloc(sizeof(_adt) * capacity);

            for (int i = 0; i < p_stack->size; ++i) {

                new_stack[i] = p_stack->p_ad[i];
            }

            free(p_stack->p_ad);
            p_stack->p_ad = new_stack;
        }

        p_stack->p_ad[p_stack->size] = *p_ad;
        p_stack->size++;
    }
}

_p_linked_stack init_linked_stack() {

    _p_linked_stack p_linked_stack = malloc(sizeof(_linked_stack));

    p_linked_stack->size = 0;
    p_linked_stack->head = p_linked_stack->tail = NULL;

    return p_linked_stack;
}

void destroy_linked_stack(_p_linked_stack p_linked_stack) {

    if (p_linked_stack != NULL) {

        _p_linked_adt top = p_linked_stack->tail;

        while (top != NULL) {

            top = top->p_prev_ad;
            p_linked_stack->tail = top;
            free(top->p_next_ad);
            top->p_next_ad = NULL;
        }

        p_linked_stack->head = NULL;
        p_linked_stack->tail = NULL;

        free(p_linked_stack);
    }
}

_p_linked_adt pop_linked_stack(_p_linked_stack p_linked_stack) {

    if (p_linked_stack != NULL) {

        _p_linked_adt top = p_linked_stack->tail;

        if (p_linked_stack->tail != NULL) {
            p_linked_stack->tail = top->p_prev_ad;

            if (p_linked_stack->tail != NULL) {

                p_linked_stack->tail->p_next_ad = NULL;
            } else {

                p_linked_stack->head = NULL;
            }

            p_linked_stack->size--;
        }

        return top;
    }

    return NULL;

}

_p_linked_adt top_linked_stack(_p_linked_stack p_linked_stack) {

    if (p_linked_stack != NULL) {

        return p_linked_stack->tail;
    }
    return NULL;

}

void push_linked_stack(_p_linked_stack p_linked_stack, _p_linked_adt p_linked_adt) {

    if (p_linked_stack != NULL && p_linked_adt != NULL) {

        _p_linked_adt new_linked_adt = malloc(sizeof(_linked_adt));

        new_linked_adt->p_ad = p_linked_adt->p_ad;
        new_linked_adt->p_next_ad = NULL;

        if (p_linked_stack->head == NULL) {

            new_linked_adt->p_prev_ad = NULL;
            p_linked_stack->head = p_linked_stack->tail = new_linked_adt;

        } else {

            new_linked_adt->p_prev_ad = p_linked_stack->tail;
            p_linked_stack->tail->p_next_ad = new_linked_adt;
            p_linked_stack->tail = new_linked_adt;
        }

        p_linked_stack->size++;
    }
}