//
// Created by 杨光 on 2019/3/4.
//
#include <stdio.h>
#include <stdlib.h>
#include "simple_queue.h"

_p_queue queue_init() {

    _p_queue p_queue = malloc(sizeof(_queue));
    p_queue->size = 0;
    p_queue->header = p_queue->tail = NULL;

    return p_queue;
}

void queue_destroy(_p_queue p_queue) {

    p_queue = NULL;
    free(p_queue);
}


_p_linked_adt queue_add(_p_queue p_queue, _p_linked_adt p_linked_adt) {

    if (p_queue != NULL && p_linked_adt != NULL) {

        ++p_queue->size;

        if (p_queue->size == 1) {

            p_queue->header = p_queue->tail = p_linked_adt;
            p_linked_adt->p_next = NULL;
            p_linked_adt->p_prev = NULL;

        } else {

            p_queue->tail->p_next = p_linked_adt;
            p_linked_adt->p_next = NULL;
            p_linked_adt->p_prev = p_queue->tail;

            p_queue->tail = p_linked_adt;
        }

        return p_queue->tail;
    }

    return NULL;
}

_p_linked_adt queue_peek(_p_queue p_queue) {

    if (p_queue != NULL && p_queue->size > 0) {

        return p_queue->header;
    }

    return NULL;
}

_p_linked_adt queue_remove(_p_queue p_queue) {

    if (p_queue != NULL) {

        if (p_queue->size > 0) {

            --p_queue->size;

            _p_linked_adt p_linked_adt = p_queue->header;

            if (p_queue->size == 0) {

                p_queue->header = p_queue->tail = NULL;
            } else {

                p_queue->header = p_linked_adt->p_next;
                p_queue->header->p_prev = NULL;
            }

            p_linked_adt->p_prev = p_linked_adt->p_next = NULL;

            return p_linked_adt;
        }
    }

    return NULL;

}

void queue_clear(_p_queue p_queue) {

    if(p_queue != NULL){

        p_queue->size = 0;

        p_queue->header = p_queue->tail = NULL;
    }
}
