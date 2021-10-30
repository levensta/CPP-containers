//
// Created by Lorent Evenstar on 10/25/21.
//

#pragma once

#include "tree_iterator.hpp"
#include "utils.hpp"

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>, \
	class Alloc = std::allocator<pair<const Key,T> > >
	class map {

	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef ft::less<value_type> value_compare;
		typedef Alloc allocator_type;
	private:
		typedef ft::node<const typename check_const<key_type>::value, mapped_type>	node;
		typedef const ft::node<const typename check_const<key_type>::value, mapped_type>	const_node;
		typedef std::allocator<node>	allocator_type_node;
		typedef red_black_tree<node, allocator_type_node>			tree;
	public:
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ft::tree_iterator<node>	iterator;
		typedef ft::tree_iterator<node>	const_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef ft::reverse_iterator<iterator>	reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef size_t size_type;

	private:
		node				*_n;
		node				_end;
		size_type			_size;
		allocator_type		_alloc;
		allocator_type_node _alloc_node;
		key_compare 		_key_comp;
		value_compare		_pair_comp;

	public:
		// empty
		explicit map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type())
					  : _n(NULL), _size(0), _alloc(alloc), _key_comp(comp) {
			_n = &_end;
		}

		// range
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), \
		const allocator_type& alloc = allocator_type()) : _n(NULL), _size(0), _alloc(alloc), _key_comp(comp) {
			 _n = &_end;
			 this->insert(first, last);
		}

		// copy
		map (const map& x) : _n(NULL), _size(0), _alloc(x._alloc), _key_comp(x._key_comp) {
			_n = &_end;
			*this = x;
		}

		~map() {
			this->clear();
		}

		// overload assignation
		map& operator= (const map& x) {
			if (this != &x) {
				std::cout << "=" << _size << std::endl;
				this->clear();
				std::cout << "Clear" << std::endl;
				this->_key_comp = x._key_comp;
				this->insert(x.begin(), x.end());
				std::cout << "Done" << _size << std::endl;
			}
			return *this;
		}

		/*
		 *	ITERATORS
		 */
		iterator begin() {
			return iterator(tree::min_node(_n, true));
		}

		const_iterator begin() const {
			return const_iterator(tree::min_node(_n, true));
		}

		iterator end() {
			if (_n->end != NULL) {
				return iterator(_n->end);
			}
			return iterator(_n);
		}

		const_iterator end() const {
			if (_n->end != NULL) {
				return const_iterator(_n->end);
			}
			return const_iterator(_n);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(--this->end());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(--this->end());
		}

		reverse_iterator rend() {
			return reverse_iterator(this->end());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(this->end());
		}

		/*
		 *	CAPACITY
		 */

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return _alloc_node.max_size();
		}

		bool empty() const {
			return !_size;
		}

		/*
		 *	ELEMENT ACCESS
		 */
		mapped_type& operator[] (const key_type& k) {
			bool ret = true;
			value_type tmp = ft::make_pair(k, mapped_type());
			node	*p = tree::insert(&_n, tmp, ret, _alloc_node);
			if (p && ret) {
				++_size;
			}
			return p->is_data().second;
		}

		/*
		 *	MODIFIERS
		 */

		// single element
		ft::pair<iterator, bool> insert (const value_type& val) {
			bool ret = true;
			node *p = tree::insert(&_n, val, ret, _alloc_node);
			if (p) {
				if (ret) {
					++_size;
				}
				return ft::make_pair(iterator(p), ret);
			}
			return ft::make_pair(this->end(), false);
		}

		// with hint
		iterator insert (iterator position, const value_type& val) {
			return this->insert(val).first;
		}

		// range
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			size_t 	n = 0;
			while (first != last) {
				this->insert(*first);
				++first;
			}
		}

		size_type erase (const key_type& k) {
			if (tree::find_key(_n, k) != NULL) {
				tree::erase(&_n, k, _alloc_node);
				--_size;
				return 1;
			}
			return 0;
		}

		void erase (iterator position) {
			this->erase(position->first);
		}

		void erase (iterator first, iterator last) {
			while (first != last) {
				this->erase(first++);
			}
		}

		void swap (map& x) {
			map tmp(x);
			x = *this;
			*this = tmp;
		}

		void clear() {
			tree::clear(&_n, _alloc_node);
			_size = 0;
		}

		/*
		 *	OBSERVERS
		 */
		key_compare key_comp() const {
			return _key_comp;
		}

		value_compare value_comp() const {
			return _pair_comp;
		}

		/*
		 *	OPERATIONS
		 */
		iterator find (const key_type& k) {
			node *tmp = tree::find_key(_n, k);
			if (tmp) {
				return (iterator(tmp));
			}
			return this->end();
		}

		const_iterator find(const key_type& k) const {
			node *tmp = tree::find_key(_n, k);
			if (tmp) {
				return (const_iterator(tmp));
			}
			return this->end();
		}

		size_type count(const key_type& k) const {
			return static_cast<size_type>(tree::find_key(_n, k) != NULL);
		}

		iterator lower_bound(const key_type& k) {
			iterator it = this->begin();
			iterator ite = this->end();

			while (it != ite && _key_comp(it->first, k)) {
				++it;
			}
			return it;
		}
		const_iterator lower_bound(const key_type& k) const {
			const_iterator it = this->begin();
			const_iterator ite = this->end();

			while (it != ite && _key_comp(it->first, k)) {
				++it;
			}
			return it;
		}
		
		iterator upper_bound(const key_type& k) {
			iterator it = this->lower_bound(k);
			iterator ite = this->end();

			while (it != ite && !_key_comp(k, it->first)) {
				++it;
			}
			return it;
		}

		const_iterator upper_bound(const key_type& k) const {
			const_iterator it = this->lower_bound(k);
			const_iterator ite = this->end();

			while (it != ite && !_key_comp(k, it->first)) {
				++it;
			}
			return it;
		}

		ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
			return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
		}

		ft::pair<iterator,iterator> equal_range(const key_type& k) {
			return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
		}

		allocator_type get_allocator() const {
			return _alloc;
		}
	};
}

