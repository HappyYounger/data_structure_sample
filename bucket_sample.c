//
// Created by 杨光 on 2019/3/4.
//

#include <stdio.h>
#include <stdlib.h>
#include "bucket_sample.h"
#include "simple_list.h"

int BASE = 1;
int count = 0;
int remain = 0, result = 0;

unsigned *bucket(unsigned *unsigned_array, unsigned size) {


    _p_list p_list_array[10];

    for (int i = 0; i < 10; ++i) {

        p_list_array[i] = list_init(16);
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
            adt.n = unsigned_array[i];
            list_add(p_list_array[remain], &adt);
        }

        BASE *= 10;
        //回收

        int index = 0;

        for (int j = 0; j < 10; ++j) {

            int i = 0;
            while (i < p_list_array[j]->size) {

                unsigned_array[index] = p_list_array[j]->header[i].n;
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

        printf("%d%2c", unsigned_array[i], i == size - 1 ? '\n' : ',');
    }

}
