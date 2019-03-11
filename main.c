#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "global.h"
#include "simple_queue.h"
#include "simple_list.h"
#include "bucket_sample.h"
#include "eight_queens/stack_eight_queens_worse.h"
#include "eight_queens/stack_eight_queens_iterator.h"
#include "eight_queens/stack_eight_queens_non_iterator.h"
#include "eight_queens/stack_eight_quees_simple.h"
#include "tree/tree.h"

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

void eight_queens_iterator_test() {

    char *eight_queen_array = init_eight_queens_array(8);
    eight_queens(eight_queen_array, 8, 0);

    destroy_eight_queens_array(eight_queen_array);
}

void eight_queens_simple_test() {

    char *column_index_array = init_eight_queens_simple_array(8);

    eight_queens_simple(column_index_array, 8, 0);

    destroy_eight_queens_simple_array(column_index_array);
}

void queue_test() {

//    _p_queue p_queue = queue_init(NULL, NULL);
//
//    _linked_adt linked_adt1;
//    _linked_adt linked_adt2;
//    _linked_adt linked_adt3;
//    _linked_adt linked_adt4;
//
//    linked_adt1.adt = (void *) 1;
//    linked_adt2.adt = (void *) 2;
//    linked_adt3.adt = (void *) 3;
//    linked_adt4.adt = (void *) 4;
//
//    queue_add(p_queue, &linked_adt1);
//    queue_add(p_queue, &linked_adt2);
//    queue_add(p_queue, &linked_adt3);
//    queue_add(p_queue, &linked_adt4);
//
//    queue_peek(p_queue);
//
//    queue_remove(p_queue);
//
//    queue_destroy(p_queue);
}

void print_adt(_p_adt p_adt) {

    printf("%2d ", (unsigned) p_adt->p_data);
}

void list_test() {

    _p_list p_list = list_init(16, NULL, NULL);

    _adt adt1;
    _adt adt2;
    _adt adt3;
    _adt adt4;
    _adt adt5;

    adt1.p_data = (void *) 0;
    adt2.p_data = (void *) 1;
    adt3.p_data = (void *) 2;
    adt4.p_data = (void *) 3;
    adt5.p_data = (void *) 4;

    adt1.size = adt2.size = adt3.size = adt4.size = adt5.size = sizeof(unsigned);

    list_append_ad(p_list, &adt1);
    list_append_ad(p_list, &adt2);
    list_insert_ad(p_list, 0, &adt3);
    list_insert_ad(p_list, 1, &adt4);
    list_insert_ad(p_list, 0, &adt5);

    list_print(p_list, print_adt);

    list_destroy(p_list);
}

void eight_queens_non_iterator_test(unsigned size) {

    char *column_index_array = init_eight_queens_non_iterator_array(size);

    eight_queens_non_iterator(column_index_array, size);
    destroy_eight_queens_non_iterator_array(column_index_array);
}

_p_t_node make_a_tree() {

    return NULL;
}

void tree_first_traverse_test() {

}

void tree_last_traverse_test() {

}

void tree_level_traverse_test() {

//    _adt adt;
//    adt.p_data = 'a';
//
//    _adt b_adt;
//    b_adt.p_data = 'b';
//
//    _adt c_adt;
//    c_adt.p_data = 'c';
//
//    _adt d_adt;
//    d_adt.p_data = 'd';
//
//    _adt e_adt;
//    e_adt.p_data = 'e';
//
//    _adt f_adt;
//    f_adt.p_data = 'f';
//
//    _adt g_adt;
//    g_adt.p_data = 'g';
//
//    _adt h_adt;
//    h_adt.p_data = 'h';
//
//    _adt i_adt;
//    i_adt.p_data = 'i';
//
//
//    _t_node root, b_node, c_node, d_node, e_node, f_node, g_node, h_node, i_node,
//            *p_root, *p_b_node, *p_c_node, *p_d_node, *p_e_node, *p_f_node, *p_g_node, *p_h_node, *p_i_node;
//
//    p_root = tree_init_node(&root, &adt);
//    p_b_node = tree_init_node(&b_node, &b_adt);
//    p_c_node = tree_init_node(&c_node, &c_adt);
//    p_d_node = tree_init_node(&d_node, &d_adt);
//    p_e_node = tree_init_node(&e_node, &e_adt);
//    p_f_node = tree_init_node(&f_node, &f_adt);
//    p_g_node = tree_init_node(&g_node, &g_adt);
//    p_h_node = tree_init_node(&h_node, &h_adt);
//    p_i_node = tree_init_node(&i_node, &i_adt);
//
//    tree_append_a_child(p_d_node, p_h_node);
//    tree_append_a_child(p_d_node, p_i_node);
//    tree_append_a_child(p_b_node, p_d_node);
//    tree_append_a_child(p_b_node, p_e_node);
//    tree_append_a_child(p_b_node, p_f_node);
//    tree_append_a_child(p_c_node, p_g_node);
//    tree_append_a_child(p_root, p_b_node);
//    tree_append_a_child(p_root, p_c_node);
//
//
//    _p_queue p_queue = queue_init();
//
//    tree_level_traverse(p_root, p_queue);
//
//    queue_destroy(p_queue);
}

int main() {

    init_global_var();

//    bucket_test();
//    list_test();
//    queue_test();

//    tree_level_traverse_test();
//    eight_queens_worse_test();
//    eight_queen_iterator_test();

//    eight_queens_simple_test();
//    eight_queens_non_iterator_test(5);
    return 0;
}