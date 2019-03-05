//
// Created by 杨光 on 2019/3/5.
//

#ifndef DATA_STRUCTURE_SAMPLE_STACK_EIGHT_QUEES_SIMPLE_H
#define DATA_STRUCTURE_SAMPLE_STACK_EIGHT_QUEES_SIMPLE_H

char *init_eight_queens_simple_array(unsigned size);

void destroy_eight_queens_simple_array(char *eight_queens_array);

int check_pos_valid_simple(char *eight_queens_array, unsigned row, unsigned col);

void eight_queens_simple(char *eight_queens_array, unsigned size, unsigned row);

void print_queens_simple(char *eight_queens_array, unsigned size);

#endif //DATA_STRUCTURE_SAMPLE_STACK_EIGHT_QUEES_SIMPLE_H
