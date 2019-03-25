//
// Created by 杨光 on 2019/3/5.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../global.h"
#include "stack_eight_queens_worse.h"

extern int count;
void init_chessboard(void *cb) {

    memset(cb, EQ_INIT_MARK, QUEEN_COUNT * QUEEN_COUNT);
}

void *copy_chessboard(void *cb, unsigned size) {

    char *new_cb = malloc(sizeof(char) * size * size);

    size *= size;
    for (unsigned i = 0; i < size; ++i) {

        new_cb[i] = ((char *) cb)[i];
    }

    return new_cb;
}

void print_an_answer(void *cb, unsigned size) {

    for (unsigned i = 0; i < size * size; ++i) {

        printf("%2c%c", ((char *) cb)[i], (i + 1) % size != 0 ? ' ' : '\n');
    }
}

void mark_chessboard(void *cb, unsigned size, unsigned row_index, unsigned col_index) {

    char *tcb = cb;

    tcb[size * row_index + col_index] = EQ_QUEEN_MARK;

    for (unsigned i = 0; i < size; ++i) {

        if (row_index != i) {

            tcb[size * i + col_index] = EQ_INVALID_MARK;

            unsigned col = col_index - (row_index - i);

            if (col >= 0 && col < size) {
                tcb[size * i + col] = EQ_INVALID_MARK;
            }

            col = col_index + row_index - i;

            if (col < size && col >= 0) {
                tcb[size * i + col] = EQ_INVALID_MARK;
            }
        }

        if (col_index != i) {

            tcb[size * row_index + i] = EQ_INVALID_MARK;
        }
    }
}

void try_a_location(void *cb, unsigned row_index, unsigned size) {

    char *tcb = cb;

    for (unsigned i = 0; i < size; ++i) {

        void *new_cb = copy_chessboard(cb, size);

        if (tcb[size * row_index + i] == EQ_INIT_MARK) {

            mark_chessboard(new_cb, size, row_index, i);

            if (row_index < size - 1) {

                try_a_location(new_cb, row_index + 1, size);
            } else {

                printf("%2d\n", ++count);
                print_an_answer(new_cb, size);
            }
        }

        free(new_cb);
    }
}
