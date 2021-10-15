//
// Created by Lorent Evenstar on 10/15/21.
//

#pragma once

#include "vector_iterator.hpp"
#include <memory>

namespace ft
{

	template <class T>
	class check_const {

	public:
		typedef T value;

	};

	template <class T>
	class check_const<const T> {

	public:
		typedef T value;

	};

	template <class T, class Alloc = std::allocator<T> >
	class vector {

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef vector_iterator<value_type> iterator;
		typedef vector_iterator<const check_const<value_type>::value> const_iterator;
		typedef reverse_iterator<const_iterator> const_reverse_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef iterator_traits<iterator>::difference_type difference_type;
		typedef size_t size_type;

	private:
		value_type *_array;
		size_type _size;
		size_type _capacity;
		allocator_type _allocator;

	public:
		// default
		explicit vector(const allocator_type& alloc = allocator_type())
			: _size(0), _capacity(0), _array(NULL), _allocator(alloc) {}

		// fill
		explicit vector(size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type())
		 	: _size(0), _capacity(0), _array(NULL), _allocator(alloc) {
			this->assign(n, val);
		}

		// range
		template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: _size(0), _capacity(0), _array(NULL), _allocator(alloc) {
			this->assign(first, last);
		}

		// copy
		vector (const vector& x) : _size(0), _capacity(0), _array(NULL), _allocator(alloc) {
			*this = x;
		}

		// destructor
		~vector() {
			this->clear();
			if (_capacity != 0) {
				_allocator.deallocate(_array, _capacity);
				_capacity = 0;
				_array = 0;
			}
		}

		// assignation operator
		vector& operator= (const vector& x) {
			if (this != &x) {
				if (_capacity != 0) {
					this->~vector();
				}
				_allocator = x._allocator;
				this->assign(x.begin(), x.end());
			}
		}

		/*
		 *	ITERATORS
		 */

		iterator begin() {
			return iterator(_array);
		}

		const_iterator begin() const {
			return const_iterator(_array);
		}

		iterator end() {
			if (_size != 0) {
				return iterator(_array + _size + 1);
			}
			return iterator(_array + _size);
		}

		const_iterator end() const {
			if (_size != 0) {
				return const_iterator(_array + _size + 1);
			}
			return const_iterator(_array + _size);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(this->end() - 1);
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(this->end() - 1);
		}

		reverse_iterator rend() {
			return reverse_iterator(this->begin() - 1);
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(this->begin() - 1);
		}

		/*
		 *	CAPACITY
		 */

		size_type size() const {
			return _size;
		}

		size_type max_size() const {
			return _allocator.max_size();
		}

		size_type capacity() const {
			return _capacity;
		}

		bool empty() const {
			return !_size;
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n < _size) {
				for (; size != n; --size) {
					_allocator.destroy(_array + size);
				}
			}
			if (n > _size) {
				this->insert(this->end(), n - _size, val);
			}
		}

		void reserve (size_type n) {
			if (n > this->max_size()) {
				throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
			}
			if (n > _capacity) {
				pointer tmp = _array;
				_array = _allocator.allocate(n);
				for (size_type i = 0; i < _size; ++i) {
					_allocator.construct(_array + i, tmp[i]);
					_allocator.destroy(tmp + i);
				}
				_allocator.deallocate(tmp);
				_capacity = n;
			}
		}

		/*
		 *	ELEMENT ACCESS
		 */

		reference operator[] (size_type n) {
			return _array[n];
		}

		const_reference operator[] (size_type n) const {
			return _array[n];
		}

		reference at (size_type n) {
			if (n >= _size) {
				throw std::out_of_range("vector"); // lol, check the original exception message
			}
			return _array[n];
		}

		const_reference at (size_type n) const {
			if (n >= _size) {
				throw std::out_of_range("vector"); // lol, check the original exception message
			}
			return _array[n];
		}

		reference front() {
			return _array[0];
		}

		const_reference front() const {
			return _array[0];
		}

		reference back() {
			return _array[_size - 1];
		}

		const_reference back() const {
			return _array[_size - 1];
		}

		/*
		 *	MODIFIERS
		 */

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			size_type dist = ft::distance(first, last);
			this->reserve(dist);
			for (size_type i = 0; i < _size || i < dist; ++i, ++first) {
				_allocator.destroy(_array + i);
				if (i < dist) {
					_allocator.construct(_array + i, *first);
				}
			}
		}

		void assign (size_type n, const value_type& val) {
			this->reserve(n);
			for (size_type i = 0; i < _size || i < n; ++i) {
				_allocator.destroy(_array + i);
				if (i < n) {
					_allocator.construct(_array + i, val);
				}
			}
		}

		void insert (iterator position, size_type n, const value_type& val) {
			size_type index = position - this->begin();
			this->reserve(_size + n);

			for (size_type i = _size + n; i > index; --i) {
				if (i > _size) {
					if (i < index + n) {
						_allocator.construct(_array + i, val);
					}
					else {
						_allocator.construct(_array + i, _array[i - n]);
					}
				}
				else {
					if (i < index + n) {
						_array[i] = val;
					}
					else {
						_array[i] = _array[i - n];
					}
				}
			}
			_size += n;
		}
	};

}


