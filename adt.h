//
// Created by 杨光 on 2019/3/4.
//

#ifndef DATA_STRUCTURE_SAMPLE_ADT_H
#define DATA_STRUCTURE_SAMPLE_ADT_H

typedef struct _ADT{
    int n;
}_adt, * _padt;

typedef struct _Linked_ADT{

    int n;
    struct _Linked_ADT * p_prev;
    struct _Linked_ADT * p_next;

}_linked_adt, * _p_linked_adt;

#endif //DATA_STRUCTURE_SAMPLE_ADT_H
