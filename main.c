#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "simple_queue.h"
#include "simple_list.h"
#include "bucket_sample.h"
#include "stack_eight_queens_worse.h"

#define SIZE 10

unsigned *get_random_unsigned_array(unsigned size) {

    if (size > 0) {

        unsigned *unsigned_array = malloc(sizeof(unsigned) * size);

        srand(time(NULL));

        for (int i = 0; i < size; ++i) {

            unsigned_array[i] = rand() % 100;
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
void bucket_test(){

    unsigned *unsigned_array = get_random_unsigned_array(SIZE);

    print_unsigned_array(unsigned_array, SIZE);
    bucket(unsigned_array, SIZE);

    print_unsigned_array(unsigned_array, SIZE);
    destroy_random_unsigned_array(unsigned_array);
}


void eight_queens_test(){

    char chessboard[QUEEN_COUNT][QUEEN_COUNT];
    init_chessboard(chessboard);
    try_a_location(chessboard, 0, QUEEN_COUNT);
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





int main() {


    eight_queens_test();

//    bucket_test();

    return 0;
}