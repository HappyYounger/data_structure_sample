//
// Created by 杨光 on 2019/3/10.
//
#include "adt.h"
#include <stdlib.h>
#include <string.h>


_p_adt ad_pool_peek(_p_ad_pool p_ad_pool) {

    if (p_ad_pool != NULL) {

        if (p_ad_pool->current_available == p_ad_pool->pool_capacity - 1) {

            ad_pool_extend(p_ad_pool);
        }

        return p_ad_pool->ad_array + p_ad_pool->current_available++;
    }
    return NULL;
}

//_p_adt ad_inits(void *p_ad, unsigned data_size) {
//
//
//    if (p_ad != NULL && data_size > 0) {
//
//        _p_adt p_ad_clone = ad_pool_peek(p_global_ad_pool);
//        p_ad_clone->p_data = malloc(data_size);
//        p_ad_clone->data_size = data_size;
//
//        ad_assign(p_ad_clone->p_data, p_ad, p_ad_clone->data_size);
//        return p_ad_clone;
//    }
//
//    return NULL;
//}


_p_adt ad_assign(void *p_ad1, void *p_ad2, unsigned size) {

    if (p_ad1 != NULL && p_ad2 != NULL && size > 0) {

        memcpy(p_ad1, p_ad2, size);

        return p_ad1;
    }

    return NULL;
}

void ad_destroy(void *p_ad) {

    if (p_ad != NULL) {

        free(((_p_adt) p_ad)->p_data);
        free(p_ad);
    }
}

//pool
unsigned get_neccessary_length(unsigned pool_capacity, unsigned size) {

    unsigned length = 0;
    if (size > 0 && pool_capacity > 0) {

        length = pool_capacity % size;
        return length ? ++length : pool_capacity / size;
    }

    return length;
}

_p_ad_pool ad_pool_init(unsigned element_size, unsigned pool_capacity) {

    if (element_size > 0 && pool_capacity > 0) {

        _p_ad_pool p_ad_pool = malloc(sizeof(_ad_pool));

        p_ad_pool->element_size = element_size;
        p_ad_pool->pool_capacity = pool_capacity;
        p_ad_pool->ad_array = malloc(element_size * pool_capacity);

        unsigned length = get_neccessary_length(p_ad_pool->pool_capacity, sizeof(char));
        p_ad_pool->p_ad_element_mapping = malloc(sizeof(char) * length);
        memset(p_ad_pool->p_ad_element_mapping, 0, length);

        p_ad_pool->mapping_length = length;
        return p_ad_pool;
    }

    return NULL;
}


_p_ad_pool ad_pool_extend(_p_ad_pool p_ad_pool) {

    if (p_ad_pool != NULL) {

        _p_adt old_ad_array = p_ad_pool->ad_array;

        p_ad_pool->pool_capacity *= 2;

        p_ad_pool->ad_array = malloc(p_ad_pool->element_size * p_ad_pool->pool_capacity);
        memcpy(p_ad_pool->ad_array, old_ad_array, p_ad_pool->element_size * p_ad_pool->pool_capacity / 2);

        unsigned length = get_neccessary_length(p_ad_pool->pool_capacity, sizeof(char));
        char *old_p_ad_element_mapping = p_ad_pool->p_ad_element_mapping;

        p_ad_pool->p_ad_element_mapping = malloc(sizeof(char) * length);
        memcpy(p_ad_pool->p_ad_element_mapping, old_p_ad_element_mapping, sizeof(char) * length);

        p_ad_pool->mapping_length = length;
        free(old_ad_array);
        free(old_p_ad_element_mapping);
        return p_ad_pool;
    }

    return NULL;
}

void ad_pool_destroy(_p_ad_pool p_ad_pool) {

    if (p_ad_pool != NULL) {

        free(p_ad_pool->ad_array);
        free(p_ad_pool->p_ad_element_mapping);
        free(p_ad_pool);
    }
}

_p_adt ad_pool_take_an_available(_p_ad_pool p_ad_pool) {


    unsigned index = 0;
    if (p_ad_pool != NULL) {


    }
    return NULL;
}
