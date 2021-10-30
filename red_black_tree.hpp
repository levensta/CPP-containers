//
// Created by Lorent Evenstar on 10/20/21.
//

#pragma once

#include <iostream>
#include "nodes.hpp"
#include "vector.hpp"

namespace ft
{
	template< class Node, class Alloc = std::allocator<Node> >
	class red_black_tree {

	public:
//		typedef ft::node<int, int> Node;
//		typedef std::allocator<Node>	Alloc;
		typedef typename Node::key key;
		typedef typename Node::type type;
		typedef Alloc allocator_type;

		red_black_tree() {}
		~red_black_tree() {}

		static Node		*insert(Node **root, type type_node, bool &t, allocator_type &alloc) {
			Node *new_node = find_key(*root, type_node.first);
			if (new_node) {
				if (new_node->get_key() == type_node.first) {
					t = false;
					return new_node;
				}
				else if (new_node->get_key() < type_node.first) {
					new_node->left = create_node(type_node, *root, alloc);
					new_node->left->parent = new_node;
					new_node->left->end = (*root)->end;
					insertion_balance(new_node->left, root);
					return new_node->left;
				}
				else if (new_node->get_key() > type_node.first) {
					new_node->right = create_node(type_node, *root, alloc);
					new_node->right->parent = new_node;
					new_node->right->end = (*root)->end;
					insertion_balance(new_node->right, root);
					return new_node->right;
				}
			}
			else {
				new_node = create_node(type_node, *root, alloc);
				(*root)->parent = new_node;
				*root = new_node;
				(*root)->is_red() = false;
			}
			return new_node;
//			else {
//				Node *tmp = *root;
//				while (tmp) {
//					if (type_node == *tmp) {
//						break;
//					}
//					else if (type_node < *tmp) {
//						if (tmp->left == NULL) {
//							tmp->left = create_node(type_node, (*root)->end, alloc);
//							new_node = tmp->left;
//							change_links(tmp->left, tmp, NULL, NULL);
//							tmp->left->end = (*root)->end;
//							insertion_balance(tmp->left, root);
//							return (ft::make_pair(new_node, true));
//						}
//						tmp = tmp->left;
//					}
//					else if (type_node > *tmp) {
//						if (tmp->right == NULL) {
//							tmp->right = create_node(type_node, (*root)->end, alloc);
//							new_node = tmp->right;
//							change_links(tmp->right, tmp, NULL, NULL);
//							tmp->right->end = (*root)->end;
//							insertion_balance(tmp->right, root);
//							return (ft::make_pair(new_node, true));
//						}
//						tmp = tmp->right;
//					}
//				}
//				return new_node;
//			}
		}

//		static void erase(Node **root, key key_element, allocator_type &alloc) {
//			Node *foundNode = find_key(*root, key_element);
//
//			if (foundNode) {
//				Node *replacement = foundNode;
//				Node	*save = NULL;
//
//				if (foundNode->left) {
//					replacement = max_node(foundNode->left);
//					save = replacement->left;
//				}
//				else if (foundNode->right) {
//					replacement = min_node(foundNode->right);
//					save = replacement->right;
//				}
//				swap_nodes(foundNode, replacement);
//				if (*root == foundNode) {
//					*root = replacement;
//					replacement->end->parent = replacement;
//					if (foundNode == replacement) {
//						if (save) {
//							*root = save;
//						}
//						else {
//							*root = (*root)->end;
//							(*root)->parent = NULL;
//						}
//					}
//				}
//				if (!save || !save->is_red()) {
//					removal_balance(foundNode, root);
//				}
//				else {
//					save->is_red() = false;
//				}
//				if (save) {
//					if (foundNode->parent) {
//						if (is_left_child(save)) {
//							foundNode->parent->left = save;
//						}
//						else {
//							foundNode->parent->right = save;
//						}
//					}
//					save->parent = foundNode->parent;
//				}
//				if (foundNode->parent) {
//					if (is_left_child(foundNode)) {
//						foundNode->parent->left = NULL;
//					} else {
//						foundNode->parent->right = NULL;
//					}
//				}
//				delete_node(foundNode, alloc);
//			}
//		}

static void erase(Node **root, key key_element, allocator_type &alloc) {
			Node *foundNode = find_key(*root, key_element);
			Node *replacement = NULL;

			while (foundNode) {
				Node	*max = max_node(foundNode->left);
				Node	*min = min_node(foundNode->right);
				replacement = foundNode;

				if (max && max->is_red()) {
					replacement = max;
				}
				else if (min && min->is_red()) {
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
			if (!root->is_end()) {
				while (root && root->get_key() != key_element) {
					if (key_element < root->get_key()) {
						if (root->left) {
							root = root->left;
						}
						else {
							break;
						}
					}
					else if (key_element > root->get_key()) {
						if (root->right) {
							root = root->right;
						}
						else {
							break ;
						}
					}
				}
				return root;
			}
			return NULL;
//			while (root && key_element != *root) {
//				if (key_element < *root) {
//					root = root->left;
//				}
//				else if (key_element > *root) {
//					root = root->right;
//				}
//			}
//			return root;
		}

		static Node *next(Node *node_element) {
			if (node_element->is_end()) {
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
			if (node_element->is_end()) {
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
				lhs->left_swap(*rhs);
			}
			else if (lhs->right == rhs) {
				lhs->right_swap(*rhs);
			}
			else {
				lhs->swap(*rhs);
			}
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
			src->is_red() = false;
			bro->is_red() = false;
			parent->is_red() = true;
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
			bool color = src->is_red();
			src->is_red() = right->is_red();
			right->is_red() = color;
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
			bool color = src->is_red();
			src->is_red() = left->is_red();
			left->is_red() = color;
		}

		static void insertion_balance(Node *src, Node **root) {
			ft::pair<Node *, bool> uncle;
			while (src->is_red() && src->parent && src->parent->is_red()) {
				uncle = get_uncle(src);
				// когда мы получаем дядю для красного родителя, мы всегда знаем, что его родитель (дед) существует
				if (uncle.second) {
					if (uncle.first && uncle.first->is_red()) {
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
					src = src->parent;
//					insertion_balance(src->parent, root);
				}
			}
			(*root)->is_red() = false;
		}

		static void removal_balance(Node *src, Node **root) {
			while (src->parent && !src->is_red()) {
				Node *bro = get_bro(src).first;
				if (!get_bro(src).second) {
					break ;
				}
				if (bro && !bro->is_red()) {
					if (bro->right && bro->right->is_red()) {
						bro->right->is_red() = false;
						if (is_left_child(src)) {
							left_rotate(src->parent, root);
						}
						else {
							right_rotate(src->parent, root);
						}
						break;
					}
					else if (bro->left && bro->left->is_red()) {
						if (is_left_child(src)) {
							right_rotate(bro, root);
						}
						else {
							left_rotate(bro, root);
						}
					}
					else {
						bro->is_red() = true;
						if (bro->parent->is_red()) {
							bro->parent->is_red() = false;
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

//		static void removal_balance(Node *src, Node **root) {
//			while (src->parent && !src->is_red()) {
//				Node *bro = get_bro(src).first;
//				if (!get_bro(src).second) {
//					break ;
//				}
//				if (bro && !bro->is_red()) {
//					if (bro->right && bro->right->is_red()) {
//						bro->right->is_red() = false;
//						if (is_left_child(src)) {
//							left_rotate(src->parent, root);
//						}
//						else {
//							right_rotate(src->parent, root);
//						}
//						break;
//					}
//					else if (bro->left && bro->left->is_red()) {
//						if (is_left_child(src)) {
//							right_rotate(bro, root);
//						}
//						else {
//							left_rotate(bro, root);
//						}
//					}
//					else {
//						bro->is_red() = true;
//						if (bro->parent->is_red()) {
//							bro->parent->is_red() = false;
//							break;
//						}
//						else {
//							src = bro->parent;
//						}
//					}
//				}
//				else if (bro) {
//					if (is_left_child(src)) {
//						left_rotate(src->parent, root);
//					}
//					else {
//						right_rotate(src->parent, root);
//					}
//				}
//				else {
//					break ;
//				}
//			}
//		}
	};
}