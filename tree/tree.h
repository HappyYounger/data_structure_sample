//
// Created by 杨光 on 2019/3/6.
//

#ifndef DATA_STRUCTURE_SAMPLE_TREE_H
#define DATA_STRUCTURE_SAMPLE_TREE_H

#include "../adt.h"
#include "../simple_queue.h"
#include "../simple_list.h"

typedef struct TreeNode {

    _p_adt p_ad;
    struct TreeNode *p_parent;
    struct TreeNode *p_right_sibling;
    struct TreeNode *p_left_sibling;
    struct TreeNode *p_first_child;
    unsigned children_count;

} _t_node, *_p_t_node;

typedef struct Tree {

    _p_t_node root;
    _p_ad_pool p_ad_pool;


} _tree, *_p_tree;

_p_tree tree_init(_p_adt p_ad_root, _p_func_ad_assign p_func_ad_assign);

void tree_destroy(_p_tree p_tree);

//_p_t_node tree_init_node(_p_t_node p_t_node, _padt p_ad);

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
