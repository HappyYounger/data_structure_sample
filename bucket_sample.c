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

        p_list_array[i] = list_init(sizeof(_adt), RANDOM_COUNT, NULL, NULL);
    }

    while (count < size) {

        count = 0;

        for (int i = 0; i < size; ++i) {

            result = unsigned_array[i] / BASE;
            remain = result % 10;

            if (result == 0) {
                ++count;
            }

            _adt ad;

            ad_build(&ad, unsigned_array[i], sizeof(unsigned_array[i]));

            list_append(p_list_array[remain], &ad);
        }

        BASE *= 10;
        //回收

        int index = 0;

        for (int j = 0; j < 10; ++j) {

            if (p_list_array[j]->element_count > 0) {

                int i = 0;
                while (i < p_list_array[j]->element_count) {

                    unsigned_array[index] = (unsigned) p_list_array[j]->header[i]->p_data;
                    ++i;
                    ++index;
                }
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
