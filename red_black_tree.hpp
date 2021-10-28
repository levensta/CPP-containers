//
// Created by Lorent Evenstar on 10/20/21.
//

#pragma once

#include <iostream>
#include "nodes.hpp"
#include "vector.hpp"

namespace ft
{
	template<class Node, class EndNode, class Alloc = std::allocator<Node> >
	class red_black_tree {

	public:
		typedef typename Node::key key;
		typedef typename Node::type type;
		typedef Alloc allocator_type;

		red_black_tree() {}
		~red_black_tree() {}

		static pair<Node *, bool>	insert(Node **root, type type_node, allocator_type &alloc) {
			Node *new_node = NULL;
			if (dynamic_cast<EndNode*>(*root) != 0) {
				new_node = create_node(type_node, *root, alloc);
				(*root)->parent = new_node;
				*root = new_node;
				(*root)->isRed = false;
				return (ft::make_pair(*root, true));
			}
			else {
				Node *tmp = *root;
				while (tmp) {
					if (type_node == *tmp) {
						break;
					}
					else if (type_node < *tmp) {
						if (tmp->left == NULL) {
							tmp->left = create_node(type_node, (*root)->end, alloc);
							new_node = tmp->left;
							change_links(tmp->left, tmp, NULL, NULL);
							tmp->left->end = (*root)->end;
							insertion_balance(tmp->left, root);
							return (ft::make_pair(new_node, true));
						}
						tmp = tmp->left;
					}
					else if (type_node > *tmp) {
						if (tmp->right == NULL) {
							tmp->right = create_node(type_node, (*root)->end, alloc);
							new_node = tmp->right;
							change_links(tmp->right, tmp, NULL, NULL);
							tmp->right->end = (*root)->end;
							insertion_balance(tmp->right, root);
							return (ft::make_pair(new_node, true));
						}
						tmp = tmp->right;
					}
				}
				return (ft::make_pair(tmp, false));
			}
		}

		static void erase(Node **root, key key_element, allocator_type &alloc) {
			Node *foundNode = find_key(*root, key_element);
			Node *replacement = NULL;

			while (foundNode) {
				Node	*max = max_node(foundNode->left);
				Node	*min = min_node(foundNode->right);
				replacement = foundNode;

				if (max && max->isRed) {
					replacement = max;
				}
				else if (min && min->isRed) {
					replacement = min;
				}
				else if (max) {
					replacement = max;
				}
				else if (min) {
					replacement = min;
				}
				swap_nodes(foundNode, replacement);
				if (*root == foundNode) {
					*root = replacement;
					replacement->end->parent = replacement;
					if (foundNode == replacement) {
						*root = (*root)->end;
						(*root)->parent = NULL;
					}
				}
				if (!foundNode->left && !foundNode->right) {
					break ;
				}
			}
			if (foundNode) {
				removal_balance(foundNode, root);
				if (foundNode->parent) {
					if (is_left_child(foundNode)) {
						foundNode->parent->left = NULL;
					} else {
						foundNode->parent->right = NULL;
					}
				}
				delete_node(foundNode, alloc);
			}
		}

		static Node *find_key(Node *root, key key_element) {
			while (root && key_element != *root) {
				if (key_element < *root) {
					root = root->left;
				}
				else if (key_element > *root) {
					root = root->right;
				}
			}
			return root;
		}

		static Node *next(Node *node_element) {
			if (dynamic_cast<EndNode *>(node_element) != 0) {
				node_element = min_node(node_element->parent, true);
			}
			else if (node_element == max_node(node_element, true)) {
				node_element = node_element->end;
			}
			else if (node_element->right) {
				node_element = min_node(node_element->right);
			}
			else {
				while (node_element->parent && node_element->parent->right == node_element) {
					node_element = node_element->parent;
				}
				if (node_element->parent) {
					node_element = node_element->parent;
				}
			}
			return node_element;
		}

		static Node *prev(Node *node_element) {
			if (dynamic_cast<EndNode *>(node_element) != 0) {
				node_element = max_node(node_element->parent, true);
			}
			else if (node_element == min_node(node_element, true)) {
				node_element = node_element->end;
			}
			else if (node_element->left) {
				node_element = max_node(node_element->left);
			}
			else {
				while (node_element->parent && node_element->parent->left == node_element) {
					node_element = node_element->parent;
				}
				if (node_element->parent) {
					node_element = node_element->parent;
				}
			}
			return node_element;
		}

		static void	clear(Node **root, allocator_type &alloc) {
			while (*root && (*root)->end) {
//				visualisation(*root);
				erase(root, (*root)->get_key(), alloc);
			}
		}

		static Node *min_node(Node *src, bool fromRoot = false) {
			if (fromRoot && src && src->end) {
				src = src->end->parent;
			}
			while (src && src->left) {
				src = src->left;
			}
			return src;
		}

		static Node *max_node(Node *src, bool fromRoot = false) {
			if (fromRoot && src && src->end) {
				src = src->end->parent;
			}
			while (src && src->right) {
				src = src->right;
			}
			return src;
		}



		/*0: left = 1; right = 2; parent = NULL; 1: left = 3; right = NULL; parent = 0;*/
		/*0: left = 0; right = 2; parent = NULL; 1: left = 3; right = NULL; parent = 1;*/
		/*0: left = 3; right = NULL; parent = 1; 1: left = 0; right = 2; parent = NULL;*/
	private:
		static void balance(Node *root) {}

		static void swap_nodes(Node *lhs, Node *rhs) {
			if (lhs->left == rhs) {
				rhs->parent = rhs;
				lhs->left = lhs;
			}
			else if (lhs->right == rhs) {
				rhs->parent = rhs;
				lhs->right = lhs;
			}
			Node	tmp(*lhs);
			*lhs = *rhs;
			*rhs = tmp;
			if (rhs->parent) {
				if (rhs->parent->left == lhs) {
					rhs->parent->left = rhs;
				}
				else if (rhs->parent->right == lhs) {
					rhs->parent->right = rhs;
				}
			}
			if (rhs->left) {
				rhs->left->parent = rhs;
			}
			if (rhs->right) {
				rhs->right->parent = rhs;
			}
			if (lhs->parent) {
				if (lhs->parent->left == rhs) {
					lhs->parent->left = lhs;
				}
				else if (lhs->parent->right == lhs) {
					lhs->parent->right = lhs;
				}
			}
			if (lhs->left) {
				lhs->left->parent = lhs;
			}
			if (lhs->right) {
				lhs->right->parent = lhs;
			}
		}

		static Node *create_node(type type_node, Node *end, allocator_type &alloc) {
			Node *new_node = alloc.allocate(1);
			Node tmp(type_node, end);
			alloc.construct(new_node, tmp);
			return new_node;
		}

		static void delete_node(Node *removement, allocator_type &alloc) {
			alloc.destroy(removement);
			alloc.deallocate(removement, 1);
		}

		static void change_links(Node *src, Node *new_parent, Node *new_left, Node *new_right) {
			src->left = new_left;
			src->right = new_right;
			src->parent = new_parent;
		}

		static bool is_left_child(Node *src) {
			if (src == src->parent->left) {
				return true;
			}
			return false;
		}

		static ft::pair<Node *, bool> get_bro(Node *src) {
			if (src->parent == NULL) {
				return (ft::make_pair<Node *, bool>(NULL, false));
			}
			if (src == src->parent->left) {
				return (ft::make_pair<Node *, bool>(src->parent->right, true));
			}
			return (ft::make_pair<Node *, bool>(src->parent->left, true));
		}

		static ft::pair<Node *, bool> get_grand(Node *src) {
			if (src->parent == NULL || src->parent->parent == NULL) {
				return (ft::make_pair<Node *, bool>(NULL, false));
			}
			return (ft::make_pair<Node *, bool>(src->parent->parent, true));
		}

		static ft::pair<Node *, bool> get_uncle(Node *src) {
			if (src->parent == NULL) {
				return (ft::make_pair<Node *, bool>(NULL, false));
			}
			return (get_bro(src->parent));
		}

		// обмен цветами происходит только в том случае, когда у черного родителя – два красных потомка
		static void swap_colors(Node *src, Node *bro, Node *parent) {
			src->isRed = false;
			bro->isRed = false;
			parent->isRed = true;
		}

		static void left_rotate(Node *src, Node **root) {
			if (!src || !src->right)
				return;
			Node	*right = src->right;

			if (src->parent) {
				if (is_left_child(src)) {
					src->parent->left = right;
				}
				else {
					src->parent->right = right;
				}
			}
			right->parent = src->parent;
			src->right = right->left;
			if (src->right) {
				src->right->parent = src;
			}
			right->left = src;
			src->parent = right;
			if (*root == src) {
				(*root)->end->parent = right;
				*root = right;
			}
			bool color = src->isRed;
			src->isRed = right->isRed;
			right->isRed = color;
		}

		static void right_rotate(Node *src, Node **root) {
			if (!src || !src->left)
				return;
			Node	*left = src->left;

			if (src->parent) {
				if (is_left_child(src)) {
					src->parent->left = left;
				}
				else {
					src->parent->right = left;
				}
			}
			left->parent = src->parent;
			src->left = left->right;
			if (src->left) {
				src->left->parent = src;
			}
			left->right = src;
			src->parent = left;
			if (*root == src) {
				(*root)->end->parent = left;
				*root = left;
			}
			bool color = src->isRed;
			src->isRed = left->isRed;
			left->isRed = color;
		}

		static void insertion_balance(Node *src, Node **root) {
			if (src->isRed && src->parent && src->parent->isRed) {
				// когда мы получаем дядю для красного родителя, мы всегда знаем, что его родитель (дед) существует
				ft::pair<Node *, bool> uncle = get_uncle(src);
				if (uncle.second) {
					if (uncle.first && uncle.first->isRed) {
						swap_colors(src->parent, uncle.first, get_grand(src).first);
					}
					else {
						if (is_left_child(src->parent)) {
							if (!is_left_child(src)) {
								left_rotate(src->parent, root);
								src = src->left;
							}
							right_rotate(get_grand(src).first, root);
						}
						else {
							if (is_left_child(src)) {
								right_rotate(src->parent, root);
								src = src->right;
							}
							left_rotate(get_grand(src).first, root);
						}
					}
					insertion_balance(src->parent, root);
				}
			}
			(*root)->isRed = false;
		}

		static void removal_balance(Node *src, Node **root) {
			while (src->parent && !src->isRed) {
				Node *bro = get_bro(src).first;
				if (!get_bro(src).second) {
					break ;
				}
				if (bro && !bro->isRed) {
					if (bro->right && bro->right->isRed) {
						bro->right->isRed = false;
						if (is_left_child(src)) {
							left_rotate(src->parent, root);
						}
						else {
							right_rotate(src->parent, root);
						}
						break;
					}
					else if (bro->left && bro->left->isRed) {
						if (is_left_child(src)) {
							right_rotate(bro, root);
						}
						else {
							left_rotate(bro, root);
						}
					}
					else {
						bro->isRed = true;
						if (bro->parent->isRed) {
							bro->parent->isRed = false;
							break;
						}
						else {
							src = bro->parent;
						}
					}
				}
				else {
					if (is_left_child(src)) {
						left_rotate(src->parent, root);
					}
					else {
						right_rotate(src->parent, root);
					}
				}
			}
		}
	};
}