//
// Created by 杨光 on 2019/3/5.
//
#include <stdio.h>
#include <stdlib.h>

#include "stack_eight_queens_non_iterator.h"
#include "../global.h"


int check_eight_queens_non_iterator_array(char *column_index_array, unsigned row, unsigned col) {

    for (unsigned r = 0; r < row; ++r) {

        unsigned c = column_index_array[r];
        if (c == col || row - col == r - c || c + r == col + row) {

            return 0;
        }
    }

    return 1;
}


char *init_eight_queens_non_iterator_array(unsigned size) {

    char *column_index_array = malloc(sizeof(unsigned) * size);

    for (unsigned i = 0; i < size; ++i) {

        column_index_array[i] = -1;
    }

    return column_index_array;
}

void destroy_eight_queens_non_iterator_array(char *column_index_array) {

    if (column_index_array != NULL) {

        free(column_index_array);
    }
}

void eight_queens_non_iterator(char *column_index_array, unsigned size) {

    int r = 0, c = 0;

    for (; r < size;) {

        for (; c < size; ++c) {

            if (check_eight_queens_non_iterator_array(column_index_array, r, c) == 1) {

                column_index_array[r] = c;
                c = 0;
                break;
            }
        }

        if (c == size && r == 0) {

            break;
        } else if (column_index_array[r] == -1) {

            --r;
            c = column_index_array[r] + 1;
            column_index_array[r] = -1;

        } else {

            ++r;
            if (r == size) {

                printf("%d\n", ++count);
                print_queens_non_iterator(column_index_array, size);

                --r;
                c = column_index_array[r] + 1;
                column_index_array[r] = -1;
            }
        }
    }
}

void print_queens_non_iterator(char *column_index_array, unsigned size) {

    for (unsigned i = 0; i < size; ++i) {

        unsigned col = column_index_array[i];

        for (unsigned j = 0; j < size; ++j) {

            printf("%c%c", j == col ? EQ_QUEEN_MARK : EQ_INIT_MARK, j == size - 1 ? '\n' : WHITE_CHAR);
        }

    }
}