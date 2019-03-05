//
// Created by 杨光 on 2019/3/5.
//

#ifndef DATA_STRUCTURE_SAMPLE_STACK_EIGHT_QUEENS_NON_ITERATOR_H
#define DATA_STRUCTURE_SAMPLE_STACK_EIGHT_QUEENS_NON_ITERATOR_H


unsigned *init_eight_queens_non_iterator_array(unsigned size);

void destroy_eight_queens_non_iterator_array(unsigned *column_index_array);

int check_eight_queens_non_iterator_array(unsigned *column_index_array, unsigned row, unsigned col);

void eight_queens_non_iterator(unsigned *column_index_array, unsigned size);

void print_queens_non_iterator(unsigned *column_index_array, unsigned size);


#endif //DATA_STRUCTURE_SAMPLE_STACK_EIGHT_QUEENS_NON_ITERATOR_H
