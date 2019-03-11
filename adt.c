//
// Created by 杨光 on 2019/3/10.
//
#include "adt.h"
#include <stdlib.h>
#include <string.h>

_p_ad_pool p_global_ad_pool = NULL;

_p_adt ad_gets_from_pool(_p_ad_pool p_ad_pool) {

    if (p_ad_pool != NULL) {

        if (p_ad_pool->current == p_ad_pool->length - 1) {

            ad_pool_extends(p_ad_pool);
        }

        return p_ad_pool->ad_array + p_ad_pool->current++;
    }
    return NULL;
}

_p_adt ad_inits(void *p_ad, unsigned size) {

    if (p_global_ad_pool == NULL) {

        p_global_ad_pool = ad_pool_inits(size, 32);
    }

    if (p_ad != NULL && size > 0) {

        _p_adt p_ad_clone = ad_gets_from_pool(p_global_ad_pool);
        p_ad_clone->p_data = malloc(size);
        p_ad_clone->size = size;

        ad_assigns(p_ad_clone->p_data, p_ad, p_ad_clone->size);
        return p_ad_clone;
    }

    return NULL;
}


_p_adt ad_assigns(void *p_ad1, void *p_ad2, unsigned size) {

    if (p_ad1 != NULL && p_ad2 != NULL && size > 0) {

        memcpy(p_ad1, p_ad2, size);

        return p_ad1;
    }

    return NULL;
}

void ad_destroys(void *p_ad) {

    if (p_ad != NULL) {

        free(((_p_adt) p_ad)->p_data);
        free(p_ad);
    }
}

_p_ad_pool ad_pool_inits(unsigned size, unsigned length) {

    if (size > 0 && length > 0) {

        _p_ad_pool p_ad_pool = malloc(sizeof(_ad_pool));

        p_ad_pool->current = 0;
        p_ad_pool->size = size;
        p_ad_pool->length = length;

        p_ad_pool->ad_array = malloc(size * length);

        return p_ad_pool;
    }

    return NULL;
}

void ad_pool_destroys(_p_ad_pool p_ad_pool) {

    if (p_ad_pool != NULL) {

        free(p_ad_pool);
    }
}

_p_ad_pool ad_pool_extends(_p_ad_pool p_ad_pool) {

    if (p_ad_pool != NULL) {

        _p_adt old_array = p_ad_pool->ad_array;

        p_ad_pool->length *= 2;
        p_ad_pool->ad_array = malloc(p_ad_pool->size * p_ad_pool->length);
        memcpy(p_ad_pool->ad_array, old_array, p_ad_pool->size * p_ad_pool->length / 2);

        free(old_array);
        return p_ad_pool;
    }

    return NULL;
}