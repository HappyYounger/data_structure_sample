//
// Created by 杨光 on 2019/3/6.
//

#ifndef DATA_STRUCTURE_SAMPLE_TREE_H
#define DATA_STRUCTURE_SAMPLE_TREE_H

#include "../adt.h"
#include "../simple_queue.h"
#include "../simple_list.h"

typedef struct TreeNode {

    _p_adt padt;
    struct TreeNode *p_parent;
    struct TreeNode *p_right_sibling;
    struct TreeNode *p_left_sibling;
    struct TreeNode *p_first_child;
    unsigned children_count;

} _t_node, *_p_t_node;

_p_t_node tree_init(_p_adt padt, _p_func_ad_assigns p_func_copy_adt);

void tree_destroy(_p_t_node p_t_node);

//_p_t_node tree_init_node(_p_t_node p_t_node, _padt padt);

_p_t_node tree_append_a_child(_p_t_node p_parent_node, _p_t_node p_child_node);

_p_t_node tree_insert_a_child(_p_t_node p_parent_node, _p_t_node p_child_node, _p_t_node p_new_child_node);

_p_t_node tree_move_a_child_forward(_p_t_node p_parent_node, _p_t_node p_child_node);

_p_t_node tree_move_a_child_afterward(_p_t_node p_parent_node, _p_t_node p_child_node);

//_p_t_node tree_insert_a_right_sibling(_p_t_node p_node, _p_t_node p_sibling_node);
//_p_t_node tree_append_a_right_sibling(_p_t_node p_node, _p_t_node p_sibling_node);
//_p_t_node tree_append_a_left_sibling(_p_t_node p_node, _p_t_node p_sibling_node);
//_p_t_node tree_insert_a_left_sibling(_p_t_node p_node, _p_t_node p_sibling_node);

_p_t_node tree_remove_a_child_node(_p_t_node p_parent_node, _p_t_node p_child_node);

_p_list tree_root_first_traverse(_p_t_node p_root_node);

_p_list tree_root_last_traverse(_p_t_node p_root_node);

_p_list tree_level_traverse(_p_t_node p_root_node);


#endif //DATA_STRUCTURE_SAMPLE_TREE_H
