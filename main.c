#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "global.h"
#include "simple_queue.h"
#include "simple_list.h"
#include "bucket_sample.h"
#include "stack_eight_queens_worse.h"
#include "stack_eight_queens_iterator.h"
#include "stack_eight_queens_non_iterator.h"

unsigned *get_random_unsigned_array(unsigned size) {

    if (size > 0) {

        unsigned *unsigned_array = malloc(sizeof(unsigned) * size);

        srand(time(NULL));

        for (int i = 0; i < size; ++i) {

            unsigned_array[i] = rand() % 1000;
        }

        return unsigned_array;
    }

    return NULL;
}

void destroy_random_unsigned_array(unsigned *unsigned_array) {

    if (unsigned_array != NULL) {

        free(unsigned_array);
    }
}

void bucket_test() {

    unsigned *unsigned_array = get_random_unsigned_array(RANDOM_COUNT);

    print_unsigned_array(unsigned_array, RANDOM_COUNT);
    bucket(unsigned_array, RANDOM_COUNT);

    print_unsigned_array(unsigned_array, RANDOM_COUNT);
    destroy_random_unsigned_array(unsigned_array);
}

void eight_queens_worse_test() {

    char chessboard[QUEEN_COUNT][QUEEN_COUNT];
    init_chessboard(chessboard);
    try_a_location(chessboard, 0, QUEEN_COUNT);
}

void eight_queen_iterator_test() {

    char *eight_queen_array = init_eight_queens_array(8);
    eight_queens(eight_queen_array, 8, 0);

    destroy_eight_queens_array(eight_queen_array);
}


void queue_test() {

    _p_queue p_queue = queue_init();

    _linked_adt adt1;
    _linked_adt adt2;
    _linked_adt adt3;
    _linked_adt adt4;
    adt1.n = 1;
    adt2.n = 2;
    adt3.n = 3;
    adt4.n = 4;


    queue_add(p_queue, &adt1);
    queue_add(p_queue, &adt2);
    queue_add(p_queue, &adt3);
    queue_add(p_queue, &adt4);

    queue_peek(p_queue);

    queue_remove(p_queue);

    queue_destroy(p_queue);
}

void list_test() {

    _p_list p_list = list_init(16);

    _adt adt1;
    _adt adt2;
    _adt adt3;
    _adt adt4;
    _adt adt5;

    adt1.n = 0;
    adt2.n = 1;
    adt3.n = 2;
    adt4.n = 3;
    adt5.n = 4;

    list_add(p_list, &adt1);
    list_insert(p_list, 0, &adt2);
    list_insert(p_list, 0, &adt3);
    list_insert(p_list, 0, &adt4);
    list_insert(p_list, 0, &adt5);

    list_destroy(p_list);
}

void eight_queens_non_iterator_test(unsigned size){

    unsigned * column_index_array = init_eight_queens_non_iterator_array(size);

    eight_queens_non_iterator(column_index_array, size);
    destroy_eight_queens_non_iterator_array(column_index_array);
}

int main() {

    init_global_var();

    eight_queens_non_iterator_test(5);
//    list_test();
//    queue_test();
//    bucket_test();
//    eight_queens_worse_test();
//    eight_queen_iterator_test();

    return 0;
}