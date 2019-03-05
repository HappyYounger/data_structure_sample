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

int *bucket(unsigned *data, unsigned size) {


    _p_list p_list_array[10];

    for (int i = 0; i < 10; ++i) {

        p_list_array[i] = list_init(16);
    }

    while (count < size) {

        count = 0;

        for (int i = 0; i < size; ++i) {

            result = data[i] / BASE;
            remain = result % 10;

            if (result == 0) {
                ++count;
            }

            _adt adt;
            adt.n = data[i];
            list_add(p_list_array[remain], &adt);
        }

        BASE *= 10;
        //回收

        int index = 0;

        for (int j = 0; j < 10; ++j) {

            int i = 0;
            while (i < p_list_array[j]->size) {

                data[index] = p_list_array[j]->header[i].n;
                ++i;
                ++index;
            }
            list_clear(p_list_array[j]);
        }
    }


    for (int i = 0; i < 10; ++i) {

        free(p_list_array[i]);
    }


}

void print_unsigned_array(unsigned *data, unsigned size) {


    for (unsigned i = 0; i < size; ++i) {

        printf("%d%2c", data[i] , i == size - 1 ? '\n' : ',');
    }

}
