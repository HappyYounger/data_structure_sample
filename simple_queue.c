//
// Created by 杨光 on 2019/3/4.
//
#include <stdio.h>
#include <stdlib.h>
#include "simple_queue.h"
#include "string.h"

static unsigned _Capacity = 16;

_p_queue queue_init(_p_func_ad_assign p_func_adt_assign, _p_func_ad_equal p_func_adt_equal) {

    _p_queue p_queue = malloc(sizeof(_queue));
    p_queue->size = 0;
    p_queue->header = p_queue->tail = NULL;

    p_queue->p_func_ad_assigns = p_func_adt_assign;
    p_queue->p_func_ad_equals = p_func_adt_equal;

    p_queue->p_ad_pool = ad_pool_init(sizeof(_adt), _Capacity);

    return p_queue;
}

void queue_destroy(_p_queue p_queue) {

    if (p_queue != NULL) {

        ad_pool_destroy(p_queue->p_ad_pool);
        free(p_queue);
    }
}


_p_adt queue_add(_p_queue p_queue, _p_adt p_ad) {

    if (p_queue != NULL && p_ad != NULL) {

        _p_adt p_ad_clone = ad_pool_take_an_available(p_queue->p_ad_pool);

        ad_assign(p_ad_clone, p_ad, sizeof(_adt), NULL);

        _p_linked_adt p_linked_ad = malloc(sizeof(_linked_adt));

        p_linked_ad->p_ad = p_ad_clone;

        if (p_queue->size == 0) {

            p_queue->header = p_queue->tail = p_linked_ad;
            p_linked_ad->p_prev_ad = NULL;

        } else {

            p_queue->tail->p_next_ad = p_linked_ad;
            p_linked_ad->p_prev_ad = p_queue->tail;
            p_queue->tail = p_linked_ad;
        }

        p_linked_ad->p_next_ad = NULL;
        ++p_queue->size;
        return p_queue->tail->p_ad;
    }

    return NULL;
}

_p_adt queue_poll(_p_queue p_queue) {

    if (p_queue != NULL && p_queue->header != NULL) {

        _p_linked_adt older_header = p_queue->header;

        p_queue->header = p_queue->header->p_next_ad;

        if (p_queue->header == NULL) {

            p_queue->tail = NULL;
        } else {

            older_header->p_prev_ad = NULL;
        }

        --p_queue->size;

        for (int i = 0; i < p_queue->p_ad_pool->pool_capacity; ++i) {

            if (older_header == p_queue->p_ad_pool + i) {

                ad_pool_return_an_unavailable(p_queue->p_ad_pool, older_header->p_ad);
            }
        }

        return older_header->p_ad;
    }

    return NULL;
}

_p_adt queue_peek(_p_queue p_queue) {

    if (p_queue != NULL && p_queue->header != NULL) {

        return p_queue->header->p_ad;
    }

    return NULL;
}

void queue_clear(_p_queue p_queue) {

    if (p_queue != NULL) {

        p_queue->size = 0;
        memset(p_queue->p_ad_pool->p_ad_element_mapping, 0, p_queue->p_ad_pool->mapping_length);

        ad_pool_clear(p_queue->p_ad_pool);
        p_queue->header = p_queue->tail = NULL;
    }
}

void queue_print(_p_queue p_queue, _p_func_ad_print p_func_ad_print) {

    if (p_queue != NULL && p_queue->header != NULL && p_func_ad_print != NULL) {

        _p_linked_adt p_linked_ad = p_queue->header;

        do {

            p_func_ad_print(p_linked_ad->p_ad);
            p_linked_ad = p_linked_ad->p_next_ad;
        } while (p_linked_ad != NULL);
    }
}