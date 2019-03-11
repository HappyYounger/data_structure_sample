//
// Created by 杨光 on 2019/3/4.
//

#include <stdio.h>
#include <stdlib.h>
#include "bucket_sample.h"
#include "simple_list.h"
#include "global.h"

unsigned *bucket(unsigned *unsigned_array, unsigned size) {

    int BASE = 1;
    int count = 0;
    int remain = 0, result = 0;

    _p_list p_list_array[10];

    for (int i = 0; i < 10; ++i) {

        p_list_array[i] = list_init(RANDOM_COUNT, NULL, NULL);
    }

    while (count < size) {

        count = 0;

        for (int i = 0; i < size; ++i) {

            result = unsigned_array[i] / BASE;
            remain = result % 10;

            if (result == 0) {
                ++count;
            }

            _adt adt;
            adt.p_data = unsigned_array[i];
            adt.size = sizeof(unsigned_array[i]);

            _p_adt p_adt = ad_inits(&adt, adt.size);
            list_append_ad(p_list_array[remain], p_adt->p_data);
        }

        BASE *= 10;
        //回收

        int index = 0;

        for (int j = 0; j < 10; ++j) {

            int i = 0;
            while (i < p_list_array[j]->size) {

                unsigned_array[index] = (unsigned) p_list_array[j]->header[i].p_data;
                ++i;
                ++index;
            }
            list_clear(p_list_array[j]);
        }
    }


    for (int i = 0; i < 10; ++i) {

        free(p_list_array[i]);
    }


    return unsigned_array;
}

void print_unsigned_array(unsigned *unsigned_array, unsigned size) {


    for (unsigned i = 0; i < size; ++i) {

        printf("%3d%c", unsigned_array[i], i == size - 1 ? '\n' : ',');
    }

}
