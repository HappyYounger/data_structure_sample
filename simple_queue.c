//
// Created by 杨光 on 2019/3/4.
//
#include <stdio.h>
#include <stdlib.h>
#include "simple_queue.h"

_p_queue queue_init(_p_func_ad_assigns p_func_adt_assign, _p_func_ad_equals p_func_adt_equal) {

    _p_queue p_queue = malloc(sizeof(_queue));
    p_queue->size = 0;
    p_queue->header = p_queue->tail = NULL;

    p_queue->p_func_ad_assigns = p_func_adt_assign;
    p_queue->p_func_ad_equals = p_func_adt_equal;

    return p_queue;
}

void queue_destroy(_p_queue p_queue) {

    p_queue = NULL;
    free(p_queue);
}


_p_linked_adt queue_add(_p_queue p_queue, _p_linked_adt p_linked_ad) {


    if (p_queue != NULL && p_linked_ad != NULL) {

        ++p_queue->size;

        if (p_queue->size == 1) {

            if (p_queue->p_func_ad_assigns == NULL) {

                p_queue->header = p_queue->tail = p_linked_ad;

                _p_adt p_ad = ad_inits(p_linked_ad->p_ad, p_linked_ad->p_ad->data_size);

                _p_linked_adt p_linked_ad_clone =

            } else {


                p_queue->p_func_ad_assigns(p_queue->header, p_linked_ad);
                p_queue->p_func_ad_assigns(p_queue->tail, p_linked_ad);
            }
            p_linked_ad->p_next_ad = NULL;
            p_linked_ad->p_prev_ad = NULL;

        } else {

            p_queue->tail->p_next_ad = p_linked_ad;
            p_linked_ad->p_next_ad = NULL;
            p_linked_ad->p_prev_ad = p_queue->tail;

            p_queue->tail = p_linked_ad;
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

                p_queue->header = p_linked_adt->p_next_ad;
                p_queue->header->p_prev_ad = NULL;
            }

            p_linked_adt->p_prev_ad = p_linked_adt->p_next_ad = NULL;

            return p_linked_adt;
        }
    }

    return NULL;

}

void queue_clear(_p_queue p_queue) {

    if (p_queue != NULL) {

        p_queue->size = 0;

        p_queue->header = p_queue->tail = NULL;
    }
}
