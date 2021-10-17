//
// Created by Lorent Evenstar on 9/16/21.
//

#pragma once

#include <iostream>

namespace ft
{
	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator {
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	/*
	 *	ITERATOR TRAITS
	 */
	template<class Iterator>
	class iterator_traits {
	public:
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template<class T>
	class iterator_traits<T *> {
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<class T>
	class iterator_traits<const T *> {
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	/*
	 *	FUNCTION DISTANCE()
	 */

	template<class RandomAccessIterator>
	typename iterator_traits<RandomAccessIterator>::difference_type \
	distance(RandomAccessIterator first, RandomAccessIterator last, std::random_access_iterator_tag)
	{
		return last - first;
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type \
	distance(InputIterator first, InputIterator last, std::input_iterator_tag)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;
		for (; first != last; ++first) {
			++n;
		}
		return n;
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		return ft::distance(first, last, typename InputIterator::iterator_category());
	}

	template<class T>
	typename iterator_traits<T*>::difference_type distance(T *first, T *last)
	{
		return last - first;
	}

	/*
	 *	FUNCTION ADVANCE()
	 */

	template <class RandomAccessIterator, class Distance>
	void advance (RandomAccessIterator& it, Distance n, std::random_access_iterator_tag)
	{
		it = it + n;
	}

	template <class BidirectionalIterator, class Distance>
	void advance (BidirectionalIterator& it, Distance n, std::bidirectional_iterator_tag)
	{
		if (n < 0) {
			for (Distance i = n; i < 0; ++i) {
				--it;
			}
		}
		else {
			for (Distance i = 0; i < n; ++i) {
				++it;
			}
		}
	}

	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n, std::input_iterator_tag)
	{
		if (n > 0) {
			for (Distance i = 0; i < n; ++i) {
				++it;
			}
		}
	}

	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n)
	{
		advance(it, n, typename InputIterator::iterator_category());
	}

	/*
	 *	REVERSE ITERATOR
	 */
	template <class Iterator>
	class reverse_iterator {

	public:
		typedef Iterator iterator_type;

	private:
		typedef iterator_traits<iterator_type> type_traits;

	public:
		typedef typename type_traits::value_type value_type;
		typedef typename type_traits::difference_type difference_type;
		typedef typename type_traits::pointer pointer;
		typedef typename type_traits::reference reference;
		typedef typename type_traits::iterator_category iterator_category;

	private:
		iterator_type	ptrElement;

	public:
		reverse_iterator() {}

		explicit reverse_iterator (iterator_type it) : ptrElement(it) {}

		iterator_type base() const {		// getter for ptrElement (iterator_type);
			return ptrElement;
		}

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) {
			this->base() = rev_it.base();
		}

		reference operator*() const {
			return *ptrElement;
		}

		pointer operator->() const {
			return &(operator*());
		}

		reverse_iterator &operator++() {
			--ptrElement;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator tmpElement(ptrElement);

			--ptrElement;
			return tmpElement;
		}

		reverse_iterator operator--() {
			++ptrElement;
			return *this;
		}

		reverse_iterator operator--(int) {
			reverse_iterator tmpElement(ptrElement);

			++ptrElement;
			return tmpElement;
		}

		reverse_iterator operator+(difference_type n) const {
			return reverse_iterator(ptrElement - n);
		}

		reverse_iterator operator-(difference_type n) const {
			return reverse_iterator(ptrElement + n);
		}

		reverse_iterator &operator+=(difference_type n) {
			ptrElement -= n;
			return *this;
		}

		reverse_iterator &operator-=(difference_type n) {
			ptrElement += n;
			return *this;
		}

		reference operator[](int index) const {
			return *(ptrElement - index);
		}
	};

	template<class T>
	reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T> &vec) {
		return reverse_iterator<T>(vec.base() - n);
	}

	template<class T>
	typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return lhs.base() - rhs.base();
	}

	template<class T>
	bool operator==(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return lhs.base() == rhs.base();
	}

	template<class T>
	bool operator!=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return !(lhs == rhs);
	}

	template<class T>
	bool operator<(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return lhs.base() > rhs.base();
	}

	template<class T>
	bool operator>(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return lhs.base() < rhs.base();
	}

	template<class T>
	bool operator<=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return lhs.base() >= rhs.base();
	}

	template<class T>
	bool operator>=(const reverse_iterator<T> &lhs, const reverse_iterator<T> &rhs) {
		return lhs.base() <= rhs.base();
	}

}
