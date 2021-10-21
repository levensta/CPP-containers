//
// Created by Lorent Evenstar on 10/20/21.
//

#pragma once

#include <iostream>
#include "nodes.hpp"

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

		static pair<Node *, bool>	insert(Node **root, type *type_node, allocator_type &alloc) {
//			if (dynamic_cast<ft::end_map_node<ft::pair<int, int> > *>(&p) != 0)
			if (dynamic_cast<EndNode*>(*root) != 0) {
				std::cout << "NEW TREE" << std::endl;
				Node *new_node = create_node(type_node, *root, alloc);
				new_node->end = *root;
				(*root)->parent = new_node;
				*root = new_node;
				return (ft::make_pair(*root, true));
			}
			else {
				Node *tmp = *root;

				while (tmp) {
					if (*type_node == *tmp) {
						std::cout << "ELEMENT EXIST" << std::endl;
						break;
					}
					else if (*type_node < *tmp) {
						if (tmp->left == NULL) {
							std::cout << "INPUT LEFT" << std::endl;
							tmp->left = create_node(type_node, (*root)->end, alloc);
							change_links(tmp->left, tmp, NULL, NULL);
							tmp->left->end = (*root)->end;
							return (ft::make_pair(tmp->left, true));
						}
						std::cout << "GO LEFT" << std::endl;
						tmp = tmp->left;
					}
					else if (*type_node > *tmp) {
						if (tmp->right == NULL) {
							std::cout << "INPUT RIGHT" << std::endl;
							tmp->right = create_node(type_node, (*root)->end, alloc);
							change_links(tmp->right, tmp, NULL, NULL);
							tmp->right->end = (*root)->end;
							return (ft::make_pair(tmp->right, true));
						}
						std::cout << "GO RIGHT" << std::endl;
						tmp = tmp->right;
					}
				}
				// balance
				return (ft::make_pair(tmp, false));
			}
		}

		static void erase(Node **root, key key_element, allocator_type &alloc) {
			Node *foundNode = find_key(*root, key_element);
			if (foundNode) {
				std::cout << "NODE EXISTS" << std::endl;
				Node *replacement = foundNode;
				Node *save = NULL;
				if (foundNode->left) {
					std::cout << "GO LEFT (FIND MAX NODE)" << std::endl;
					replacement = max_node(foundNode->left);
					save = replacement->left;
				}
				else if (foundNode->right) {
					std::cout << "GO RIGHT (FIND MIND NODE)" << std::endl;
					replacement = min_node(foundNode->right);
					save = replacement->right;
				}
				if (replacement->parent) {
					if (replacement == replacement->parent->left) {
						std::cout << "SAVE RIGHT BRANCH TO LEFT" << std::endl;
						replacement->parent->left = save;
					}
					else {
						std::cout << "SAVE LEFT BRANCH TO RIGHT" << std::endl;
						replacement->parent->right = save;
					}
				}
				foundNode->p = replacement->p;
				if (*root == replacement) {
					*root = (*root)->end;
					(*root)->parent = NULL;
				}
				std::cout << "DELETED NODE" << std::endl;
				delete_node(replacement, alloc);
				// balance
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
			if (node_element->right) {
				node_element = min_node(node_element->right);
			}
			else if (node_element->parent) {
				while (node_element->parent->right == node_element) {
					node_element = node_element->parent;
				}
				node_element = node_element->parent;
			}
		}

//		static Node *prev(Node *node_element) {}
//
		static void	clear(Node **root, allocator_type &alloc) {
			while (*root && (*root)->end) {
				erase(root, (*root)->get_key(), alloc);
			}
		}

	private:
		static void balance(Node *root) {}

		static Node *create_node(type *type_node, Node *end, allocator_type &alloc) {
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

		static Node *max_node(Node *src, bool fromRoot = false) {
			if (fromRoot && src && src->end) {
				src = src->end->parent;
			}
			while (src && src->right) {
				src = src->right;
			}
			return src;
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

	};
}