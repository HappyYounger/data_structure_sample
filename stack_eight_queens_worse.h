//
// Created by 杨光 on 2019/3/5.
//

#ifndef DATA_STRUCTURE_SAMPLE_STACK_EIGHT_QUEENS_WORSE_H
#define DATA_STRUCTURE_SAMPLE_STACK_EIGHT_QUEENS_WORSE_H

#define QUEEN_COUNT 8

void init_chessboard(void *cb);

void *copy_chessboard(void *cb, unsigned size);

void print_an_answer(void *cb, unsigned size);

void mark_chessboard(void *cb, unsigned size, unsigned row_index, unsigned col_index);

void try_a_location(void *cb, unsigned row_index, unsigned size);

#endif //DATA_STRUCTURE_SAMPLE_STACK_EIGHT_QUEENS_WORSE_H
