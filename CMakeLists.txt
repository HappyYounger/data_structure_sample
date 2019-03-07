cmake_minimum_required(VERSION 3.12)
project(data_structure_sample C)

set(CMAKE_C_STANDARD 99)

add_executable(data_structure_sample main.c simple_stack.h simple_stack.c simple_queue.c simple_queue.h bucket_sample.c bucket_sample.h adt.h simple_list.c simple_list.h eight_queens/stack_eight_queens_worse.c eight_queens/stack_eight_queens_worse.h eight_queens/stack_eight_queens_iterator.c eight_queens/stack_eight_queens_iterator.h global.h eight_queens/stack_eight_queens_non_iterator.c eight_queens/stack_eight_queens_non_iterator.h eight_queens/stack_eight_quees_simple.c eight_queens/stack_eight_quees_simple.h global.c tree/tree.c tree/tree.h)