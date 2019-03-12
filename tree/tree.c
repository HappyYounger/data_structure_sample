//
// Created by 杨光 on 2019/3/6.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

static const unsigned _Pool_Capacity = 64;

_p_t_node tree_init(_p_adt p_ad, _p_func_ad_assign p_func_ad_assign) {

    if (p_ad != NULL) {
        _p_t_node p_t_node = malloc(sizeof(_t_node));

        p_t_node->p_ad_pool = ad_pool_init(sizeof(_adt), _Pool_Capacity);

        p_t_node->p_parent = NULL;
        p_t_node->p_left_sibling = NULL;
        p_t_node->p_right_sibling = NULL;

        p_t_node->children_count = 0;
        p_t_node->p_first_child = NULL;

        _p_adt p_ad_clone = ad_pool_take_an_available(p_t_node->p_ad_pool);

        ad_assign(p_ad_clone, p_ad, sizeof(_adt), p_func_ad_assign);

        return p_t_node;
    }

    return NULL;
}

void tree_destroy(_p_t_node p_t_node) {

    if (p_t_node != NULL) {


    }
}
//
//
////_p_t_node tree_init_node(_p_t_node p_t_node, _padt padt) {
////
////    if (p_t_node != NULL) {
////
////        p_t_node->p_parent = NULL;
////        p_t_node->p_left_sibling = NULL;
////        p_t_node->p_right_sibling = NULL;
////        p_t_node->children_count = 0;
////        p_t_node->p_first_child = NULL;
////        p_t_node->padt = padt;
////
////        return p_t_node;
////    }
////
////    return NULL;
////}
//
//_p_t_node tree_append_a_child(_p_t_node p_parent_node, _p_t_node p_child_node) {
//
//    if (p_parent_node != NULL && p_child_node != NULL) {
//
//        p_child_node->p_parent = p_parent_node;
//        ++p_parent_node->children_count;
//
//        _p_t_node p_t_node = p_parent_node->p_first_child;
//
//        if (p_t_node == NULL) {
//
//            p_parent_node->p_first_child = p_child_node;
//        } else {
//
//            while (p_t_node->p_right_sibling != NULL) {
//
//                p_t_node = p_t_node->p_right_sibling;
//            }
//
//            p_t_node->p_right_sibling = p_child_node;
//        }
//
//        p_child_node->p_left_sibling = p_t_node;
//        p_child_node->p_right_sibling = NULL;
//
//        return p_child_node;
//    }
//
//    return NULL;
//}
//
//_p_t_node tree_insert_a_child(_p_t_node p_parent_node, _p_t_node p_child_node, _p_t_node p_new_child_node) {
//
//    if (p_parent_node != NULL && p_child_node != NULL && p_new_child_node != NULL) {
//
//        _p_t_node p_t_node = p_parent_node->p_first_child;
//
//        while (p_t_node != p_child_node) {
//
//            p_t_node = p_child_node->p_right_sibling;
//        }
//
//        if (p_t_node != NULL) {
//
//            p_new_child_node->p_left_sibling = p_t_node->p_left_sibling;
//            p_new_child_node->p_right_sibling = p_t_node;
//            p_t_node->p_left_sibling = p_new_child_node;
//
//            return p_new_child_node;
//        }
//    }
//
//    return NULL;
//}
//
//
//_p_t_node tree_move_a_child_forward(_p_t_node p_parent_node, _p_t_node p_child_node) {
//
//    if (p_parent_node != NULL && p_child_node != NULL) {
//
//        _p_t_node p_t_node = p_parent_node->p_first_child;
//        while (p_t_node != p_child_node) {
//
//            p_t_node = p_child_node->p_right_sibling;
//        }
//
//        if (p_t_node != NULL) {
//
//            p_t_node = p_child_node->p_left_sibling;
//
//            p_t_node->p_left_sibling->p_right_sibling = p_child_node;
//            p_t_node->p_right_sibling = p_child_node->p_right_sibling;
//
//            p_child_node->p_left_sibling = p_t_node->p_left_sibling;
//            p_t_node->p_left_sibling = p_child_node;
//
//            return p_child_node;
//        }
//    }
//
//    return NULL;
//}
//
//_p_t_node tree_move_a_child_afterward(_p_t_node p_parent_node, _p_t_node p_child_node) {
//
//    if (p_parent_node != NULL && p_child_node != NULL) {
//
//        _p_t_node p_t_node = p_parent_node->p_first_child;
//        while (p_t_node != p_child_node) {
//
//            p_t_node = p_child_node->p_left_sibling;
//        }
//
//        if (p_t_node != NULL) {
//
//            p_t_node = p_child_node->p_right_sibling;
//
//            p_t_node->p_right_sibling->p_left_sibling = p_child_node;
//            p_t_node->p_left_sibling = p_child_node->p_left_sibling;
//
//            p_child_node->p_right_sibling = p_t_node->p_right_sibling;
//            p_t_node->p_right_sibling = p_child_node;
//
//            return p_child_node;
//        }
//    }
//
//    return NULL;
//}
//
//
////_p_t_node tree_insert_a_right_sibling(_p_t_node p_node, _p_t_node p_sibling_node) {
////
////    if (p_node != NULL && p_node->p_parent != NULL) {
////
////        if (p_node->p_right_sibling != NULL) {
////
////            p_sibling_node->p_right_sibling = p_node->p_right_sibling;
////            p_node->p_right_sibling->p_left_sibling = p_sibling_node;
////
////        } else {
////
////            p_sibling_node->p_right_sibling = NULL;
////        }
////
////        p_node->p_right_sibling = p_sibling_node;
////        p_sibling_node->p_left_sibling = p_node;
////        return p_node;
////    }
////
////    return NULL;
////}
////
////_p_t_node tree_append_a_right_sibling(_p_t_node p_node, _p_t_node p_sibling_node) {
////
////    if (p_node != NULL && p_node->p_parent != NULL) {
////
////        _p_t_node p_t_node;
////        while (p_node->p_right_sibling != NULL) {
////
////            p_t_node = p_node->p_right_sibling;
////        }
////
////        p_t_node->p_right_sibling = p_sibling_node;
////        p_sibling_node->p_left_sibling = p_t_node;
////        p_sibling_node->p_right_sibling = NULL;
////
////        return p_node;
////    }
////
////    return NULL;
////}
////
////_p_t_node tree_append_a_left_sibling(_p_t_node p_node, _p_t_node p_sibling_node) {
////
////    if (p_node != NULL && p_node->p_parent != NULL) {
////
////        _p_t_node p_t_node;
////        while (p_node->p_left_sibling != NULL) {
////
////            p_t_node = p_node->p_left_sibling;
////        }
////
////        p_t_node->p_left_sibling = p_sibling_node;
////        p_sibling_node->p_right_sibling = p_t_node;
////        p_sibling_node->p_left_sibling = NULL;
////
////        return p_node;
////    }
////
////    return NULL;
////}
////
////_p_t_node tree_insert_a_left_sibling(_p_t_node p_node, _p_t_node p_sibling_node) {
////
////    if (p_node != NULL && p_node->p_parent != NULL) {
////
////        if (p_node->p_left_sibling != NULL) {
////
////            p_sibling_node->p_left_sibling = p_node->p_left_sibling;
////            p_node->p_left_sibling->p_right_sibling = p_sibling_node;
////
////        } else {
////
////            p_sibling_node->p_left_sibling = NULL;
////        }
////
////        p_node->p_left_sibling = p_sibling_node;
////        p_sibling_node->p_right_sibling = p_node;
////        return p_node;
////    }
////
////    return NULL;
////
////}
//
//_p_t_node tree_remove_a_child_node(_p_t_node p_parent_node, _p_t_node p_child_node) {
//
//    if (p_parent_node != NULL && p_child_node != NULL) {
//
//        _p_t_node p_t_node = p_parent_node->p_first_child;
//
//        if (p_t_node != NULL) {
//
//            if (p_t_node == p_child_node) {
//
//                p_parent_node->p_first_child = p_t_node->p_right_sibling;
//
//                return p_child_node;
//            } else {
//
//                while ((p_t_node = p_t_node->p_right_sibling) == NULL) {
//
//                    if (p_t_node == p_child_node) {
//
//                        p_child_node->p_right_sibling->p_left_sibling = p_child_node->p_left_sibling;
//                        p_child_node->p_left_sibling->p_right_sibling = p_child_node->p_right_sibling;
//                        return p_child_node;
//                    }
//                }
//            }
//        }
//    }
//
//    return NULL;
//}
//
//_p_queue tree_root_first_traverse(_p_t_node p_root_node, _p_queue p_queue) {
//
//    if (p_root_node != NULL) {
//
//        printf("%c", *((char *) p_root_node->p_ad->p_data));
//        _p_t_node p_t_node = p_root_node->p_first_child;
//
//        while (p_t_node != NULL) {
//
//            tree_root_first_traverse(p_t_node);
//            p_t_node = p_t_node->p_right_sibling;
//        }
//    }
//
//    return p_root_node;
//
//
//}
//
//_p_queue tree_root_last_traverse(_p_t_node p_root_node, _p_queue p_queue) {
//
//    if (p_root_node != NULL) {
//
//        _p_t_node p_t_node = p_root_node->p_first_child;
//
//        while (p_t_node != NULL) {
//
//            tree_root_last_traverse(p_t_node);
//            p_t_node = p_t_node->p_right_sibling;
//        }
//        printf("%c", *((char *) p_root_node->p_ad->p_data));
//    }
//
//    return NULL;
//}
//
//_p_list tree_level_traverse(_p_t_node p_root_node) {
//
//    if (p_root_node != NULL) {
//
//        _p_t_node p_child = p_root_node->p_first_child;
//        _p_linked_adt p_linked_adt;
//
//        _p_queue p_queue = queue_init();
//
//        while (p_child != NULL) {
//
//            p_linked_adt = malloc(sizeof(_linked_adt));
//            p_linked_adt->p_ad->p_data = p_child;
//            queue_add(p_queue, p_linked_adt);
//            p_child = p_child->p_right_sibling;
//        }
//
//        while ((p_linked_adt = queue_peek(p_queue)) != NULL) {
//
//            tree_level_traverse(p_linked_adt->p_ad->p_data);
//        }
//
//        return p_queue;
//    }
//
//    return NULL;
//}