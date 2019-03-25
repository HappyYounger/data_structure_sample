//
// Created by 杨光 on 2019/3/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "../global.h"
#include "stack_eight_queens_iterator.h"
extern int count;
char *init_eight_queens_array(unsigned size) {

    if (size > 0) {

        char *eight_queens_array = malloc(sizeof(char) * size);
        memset(eight_queens_array, EQ_INIT_MARK, size);

        return eight_queens_array;
    }
    return NULL;
}

void destroy_eight_queens_array(char *eight_queens_array) {

    if (eight_queens_array != NULL) {

        free(eight_queens_array);
    }
}


int check_pos_valid(char *eight_queens_array, unsigned row, unsigned col) {

    for (int r = 0; r < row; r++) {

        int c = eight_queens_array[r];
        if (col == c || (r + c) == (row + col) || (r - c) == (row - col))
            return 0;
    }
    return 1;
}

void eight_queens(char *eight_queens_array, unsigned size, unsigned row) {

    for (int col = 0; col < size; col++) {

        if (check_pos_valid(eight_queens_array, row, col)) {

            eight_queens_array[row] = col;
            if (row == size - 1) {

                printf("%d\n", ++count);
                print_queens(eight_queens_array, size);
                eight_queens_array[row] = 0;
                return;
            }
            eight_queens(eight_queens_array, size, row + 1);
            eight_queens_array[row] = 0;
        }
    }
}

void print_queens(char *eight_queens_array, unsigned size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)

            printf("%c%c", j == eight_queens_array[i] ? EQ_QUEEN_MARK : EQ_INIT_MARK,
                   j == size - 1 ? '\n' : WHITE_CHAR);
    }
}