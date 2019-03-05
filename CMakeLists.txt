cmake_minimum_required(VERSION 3.12)
project(data_structure_sample C)

set(CMAKE_C_STANDARD 99)

add_executable(data_structure_sample main.c simple_stack.h simple_stack.c simple_queue.c simple_queue.h bucket_sample.c bucket_sample.h adt.h simple_list.c simple_list.h)