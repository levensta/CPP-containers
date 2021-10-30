//
// Created by Lorent Evenstar on 10/30/21.
//

#pragma once

#include "new_nodes.hpp"

namespace ft
{
	template<class Node, class EndNode, class Alloc = std::allocator<Node> >
	class red_black_tree {

	public:
//		typedef ft::node<int, int> Node;
//		typedef ft::end_node<int, int> EndNode;
//		typedef std::allocator<Node>	Alloc;
		typedef typename Node::key key;
		typedef typename Node::type type;
		typedef Alloc allocator_type;

		red_black_tree() {}
		~red_black_tree() {}

		static Node *create_node(type type_node, Node *end, bool left, allocator_type &alloc) {
			Node *new_node = alloc.allocate(1);
			Node tmp(type_node, end, left);
			alloc.construct(new_node, tmp);
			return new_node;
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

		static void delete_node(Node *removement, allocator_type &alloc) {
			if (removement) {
				alloc.destroy(removement);
				alloc.deallocate(removement, 1);
			}
		}

		static ft::pair<Node *, bool>	find_node(Node *root, key key_element) {
			if (root->end) {
				while (root &&  *root != key_element) {
					if (key_element < root->get_key()) {
						if (root->left)
							root = root->left;
						return ft::make_pair(root, false);
					}
					else if (key_element > root->get_key()) {
						if (root->right)
							root = root->right;
						return ft::make_pair(root, false);
					}
				}
				return ft::make_pair(root, true);;
			}
			return ft::make_pair<Node *, bool>(NULL, false);
		}

		static pair<Node *, bool>	insert(Node **root, type type_node, allocator_type &alloc) {
			ft::pair<Node *, bool>	found = find_node(*root, type_node.first);
			if (!found.second) {
				Node	*new_node = NULL;
				if (!found.first) {
					new_node = create_node(type_node, (*root), true, alloc);
					*root = new_node;
					new_node->end->left = new_node;
					new_node->end->parent = new_node;
					new_node->end->right = new_node;
				}
				else if (*(found.first) < type_node.first) {
					new_node = create_node(type_node, (*root)->end, true, alloc);
					found.first->left = new_node;
					found.first->left->parent = found.first;
					if (found.first->end->left->get_key() > new_node->get_key()) {
						found.first->end->left = new_node;
					}
				}
				else if (*(found.first) > type_node.first) {
					new_node = create_node(type_node, (*root)->end, false, alloc);
					found.first->right = new_node;
					found.first->right->parent = found.first;
					if (found.first->end->right->get_key() < new_node->get_key()) {
						found.first->end->right = new_node;
					}
				}
				insertion_balance(new_node, root);
				return ft::make_pair(new_node, true);
			}
			return ft::make_pair(found.first, false);
		}

		static void insertion_balance(Node *src, Node **root) {
			while (src->get_color() && src->parent && src->parent->get_color()) {
				// когда мы получаем дядю для красного родителя, мы всегда знаем, что его родитель (дед) существует
				ft::pair<Node *, bool> uncle = get_uncle(src);
				if (uncle.second) {
					if (uncle.first && uncle.first->get_color()) {
						swap_colors(src->parent, uncle.first, get_grand(src).first);
					}
					else {
						if (src->parent->is_left()) {
							if (!src->is_left()) {
								left_rotate(src->parent, root);
								src = src->left;
							}
							right_rotate(get_grand(src).first, root);
						}
						else {
							if (src->is_left()) {
								right_rotate(src->parent, root);
								src = src->right;
							}
							left_rotate(get_grand(src).first, root);
						}
					}
					src = src->parent;
				}
				(*root)->set_color(false);
			}
		}

		static void erase(Node **root, key key_element, allocator_type &alloc) {
			ft::pair<Node *, bool>	foundNode = find_node(*root, key_element);
			if (foundNode.second) {
				Node *replacement = foundNode.first;
				Node *save = NULL;
				if (foundNode.first->left) {
					replacement = max_node(foundNode.first->left);
					save = replacement->left;
				}
				else if (foundNode.first->right) {
					replacement = min_node(foundNode.first->right);
					save = replacement->right;
				}
				foundNode.first->swap(*replacement);
				removal_balance(foundNode.first, save, root);
				delete_node(foundNode.first, alloc);
			}
		}

		static Node *min_node(Node *src, bool fromRoot = false) {
			if (fromRoot && src && src->end) {
				return src->end->left;
			}
			while (src && src->left) {
				src = src->left;
			}
			return src;
		}

		static Node *max_node(Node *src, bool fromRoot = false) {
			if (fromRoot && src && src->end) {
				return src->end->right;
			}
			while (src && src->right) {
				src = src->right;
			}
			return src;
		}

		static void removal_balance(Node *src, Node *child, Node **root) {
			Node 	*save = src;
			if (!src->get_color() && child && child->get_color()) {
				child->set_color(false);
			}
			else {
				while (src->parent && !src->get_color()) {
					Node *bro = get_bro(src).first;
					if (!get_bro(src).second) {
						break ;
					}
					if (bro && !bro->get_color()) {
						if (bro->right && bro->right->get_color()) {
							bro->right->set_color(false);
							if (src->is_left()) {
								left_rotate(src->parent, root);
							}
							else {
								right_rotate(src->parent, root);
							}
							break;
						}
						else if (bro->left && bro->left->get_color()) {
							if (src->is_left()) {
								right_rotate(bro, root);
							}
							else {
								left_rotate(bro, root);
							}
						}
						else {
							bro->set_color(true);
							if (bro->parent->get_color()) {
								bro->parent->set_color(false);
								break;
							}
							else {
								src = bro->parent;
							}
						}
					}
					else {
						if (src->is_left()) {
							left_rotate(src->parent, root);
						}
						else {
							right_rotate(src->parent, root);
						}
					}
				}
			}
			if (save->parent) {
				if (save->is_left()) {
					save->parent->left = child;
				}
				else {
					save->parent->right = child;
				}
			}
			child->parent = save->parent;
		}

		static void swap_colors(Node *src, Node *bro, Node *parent) {
			src->set_color(false);
			bro->set_color(false);
			parent->set_color(true);
		}

		static void left_rotate(Node *src, Node **root) {
			if (!src || !src->right)
				return;
			Node	*right = src->right;

			if (src->parent) {
				if (src->is_left()) {
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

			bool color = src->get_color();
			src->set_color(right->get_color());
			right->set_color(color);

			right->set_left(src->is_left());
			src->set_left(true);
			if (right->left) {
				right->left->set_left(false);
			}
		}

		static void right_rotate(Node *src, Node **root) {
			if (!src || !src->left)
				return;
			Node	*left = src->left;

			if (src->parent) {
				if (src->is_left()) {
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

			bool color = src->get_color();
			src->set_color(left->get_color());
			left->set_color(color);

			left->set_left(src->is_left());
			src->set_left(false);
			if (left->right) {
				left->right->set_left(true);
			}
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
				erase(root, (*root)->get_key(), alloc);
			}
		}
	};
}
