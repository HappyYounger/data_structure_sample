//
// Created by 杨光 on 2019/3/10.
//
#include "adt.h"
#include <stdlib.h>
#include <string.h>

_p_adt ad_assign(void *p_ad1, void *p_ad2, unsigned size, _p_func_ad_assign p_func_ad_assigns) {

    if (p_ad1 != NULL && p_ad2 != NULL && size > 0) {

        if (p_func_ad_assigns == NULL) {

            memcpy(p_ad1, p_ad2, size);
            return p_ad1;
        }

        return p_func_ad_assigns(p_ad1, p_ad2);
    }

    return NULL;
}

//pool
unsigned get_mapping_length(unsigned pool_capacity, unsigned size) {

    unsigned length = 0, mod = 0;
    if (size > 0 && pool_capacity > 0) {

        mod = pool_capacity % size;
        length = pool_capacity / size;

        return mod ? ++length : length;
    }

    return length;
}

_p_ad_pool ad_pool_init(unsigned element_size, unsigned pool_capacity) {

    if (element_size > 0 && pool_capacity > 0) {

        _p_ad_pool p_ad_pool = malloc(sizeof(_ad_pool));

        p_ad_pool->element_size = element_size;
        p_ad_pool->pool_capacity = pool_capacity;

        p_ad_pool->ad_array = malloc(element_size * pool_capacity);

        unsigned length = get_mapping_length(p_ad_pool->pool_capacity, sizeof(char) * 8);

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

        unsigned length = get_mapping_length(p_ad_pool->pool_capacity, sizeof(char) * 8);
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

    unsigned i, j;
    char mask;

    if (p_ad_pool != NULL) {

        for (i = 0; i < p_ad_pool->pool_capacity; ++i) {

            unsigned mapping_index = i / 8;
            char mapping = p_ad_pool->p_ad_element_mapping[mapping_index];

            for (j = 0; j < sizeof(char) * 8; ++j) {

                mask = 1 << (7 - j);
                if ((mapping & mask) == 0) {

                    p_ad_pool->p_ad_element_mapping[mapping_index] |= mask;
                    return p_ad_pool->ad_array + i * sizeof(char) + j;
                }
            }
        }
    }
    return NULL;
}

_p_adt ad_pool_return_an_unavailable(_p_ad_pool p_ad_pool, _p_adt p_ad) {

    if (p_ad_pool != NULL && p_ad != NULL) {

        unsigned index = p_ad - p_ad_pool->ad_array;

        unsigned mapping_index = index / (sizeof(char) * 8);
        unsigned mapping_bit_index = index % (sizeof(char) * 8);

        char mask = 1 << (7 - mapping_bit_index);

        p_ad_pool->p_ad_element_mapping[mapping_index] &= ~mask;
    }

    return NULL;
}

_p_adt ad_build(_p_adt p_ad, void *p_data, unsigned data_size) {

    if (p_ad != NULL) {

        p_ad->p_data = p_data;
        p_ad->data_size = data_size;

        return p_ad;
    }

    return NULL;
}

void ad_pool_clear(_p_ad_pool p_ad_pool) {

    if (p_ad_pool != NULL) {

        memset(p_ad_pool->p_ad_element_mapping, 0, p_ad_pool->mapping_length);
    }
}
