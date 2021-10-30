//
// Created by Lorent Evenstar on 10/25/21.
//

#pragma once

#include "iterator.hpp"
//#include "red_black_tree.hpp"

#include "new_tree.hpp"
namespace ft
{
	template <class Node, class EndNode, class Tree = ft::red_black_tree<Node, EndNode> >
	class tree_iterator {
	private:
		typedef iterator_traits<typename Node::type *> type_traits;
		typedef red_black_tree<Node, EndNode>			tree;

	public:
		typedef typename type_traits::value_type value_type;
		typedef typename type_traits::difference_type difference_type;
		typedef typename type_traits::pointer pointer;
		typedef typename type_traits::reference reference;
		typedef typename std::bidirectional_iterator_tag iterator_category;

	private:
		Node  *ptrElement;

	public:
		tree_iterator() : ptrElement(NULL) {}

		tree_iterator(Node *element) : ptrElement(element) {}

		tree_iterator(EndNode *element) : ptrElement(element) {}

		tree_iterator(const tree_iterator &copy) : ptrElement(NULL) {
			*this = copy;
		}

		tree_iterator &operator=(const tree_iterator &copy) {
			if (this != &copy) {
				this->ptrElement = copy.ptrElement;
			}
			return *this;
		}

		Node *base() const {		// getter for ptrElement (Node *);
			return ptrElement;
		}

		reference operator*() const {
			return **ptrElement;
		}

		pointer operator->() const {
			return &(**ptrElement);
		}
		
		tree_iterator &operator++() {
			ptrElement = tree::next(ptrElement);
			return *this;
		}

		tree_iterator operator++(int) {
			tree_iterator tmpElement(ptrElement);

			ptrElement = tree::next(ptrElement);
			return tmpElement;
		}

		tree_iterator &operator--() {
			ptrElement = tree::prev(ptrElement);
			return *this;
		}

		tree_iterator operator--(int) {
			tree_iterator tmpElement(ptrElement);

			ptrElement = tree::prev(ptrElement);
			return tmpElement;
		}
	};
	
	template<class Node, class EndNode>
	bool operator==(const tree_iterator<Node, EndNode> &lhs, const tree_iterator<Node, EndNode> &rhs) {
		return lhs.base() == rhs.base();
	}

	template<class Node, class EndNode>
	bool operator!=(const tree_iterator<Node, EndNode> &lhs, const tree_iterator<Node, EndNode> &rhs) {
		return !(lhs == rhs);
	}

}
