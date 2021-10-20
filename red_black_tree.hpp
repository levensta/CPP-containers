//
// Created by Lorent Evenstar on 10/20/21.
//

#pragma once

#include <iostream>
#include "nodes.hpp"

namespace ft
{
	template<class Node, class Alloc = std::allocator<Node> >
	class red_black_tree {

	public:
		typedef typename Node::key key;
		typedef typename Node::type type;
		typedef Alloc allocator_type;

		red_black_tree() {}
		~red_black_tree() {}

		static pair<type, bool>	insert(Node *root, type &type_node, allocator_type &alloc) {}
		static void erase(Node *root, key key_element, allocator_type &alloc) {}
		static Node *find_key(Node *root, key key_element) {}
		static void next(Node *node_element) {}
		static void prev(Node *node_element) {}
		static void	clear(Node *root, allocator_type &alloc) {}

	private:
		static void balance(Node *root) {}

	};
}