//
// Created by Lorent Evenstar on 9/15/21.
//

#ifndef FT_CONTAINERS_VECTOR_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template<class T>
	class vector_iterator {
	private:
		typedef iterator_traits<T> type_traits;

	public:
		typedef typename type_traits::value_type value_type;
		typedef typename type_traits::difference_type difference_type;
		typedef typename type_traits::pointer pointer;
		typedef typename type_traits::reference reference;
		typedef typename type_traits::iterator_category iterator_category;

	private:
		pointer ptrElement;

	public:
		vector_iterator() : ptrElement(NULL) {}

		vector_iterator(pointer element) : ptrElement(element) {}

		vector_iterator(const vector_iterator<T> &copy) : ptrElement(NULL) {
			*this = copy;
		}

		vector_iterator &operator=(const vector_iterator<T> &copy) {
			if (this != &copy) {
				this->ptrElement = copy.ptrElement;
			}
			return *this;
		}

		pointer base() const {		// getter for ptrElement (pointer);
			return ptrElement;
		}

		reference operator*() const {
			return *ptrElement;
		}

		pointer operator->() const {
			return &(*ptrElement);
		}

		vector_iterator &operator++() {
			++ptrElement;
			return *this;
		}

		vector_iterator operator++(int) {
			vector_iterator tmpElement(ptrElement);

			++ptrElement;
			return tmpElement;
		}

		vector_iterator &operator--() {
			--ptrElement;
			return *this;
		}

		vector_iterator operator--(int) {
			vector_iterator tmpElement(ptrElement);

			--ptrElement;
			return tmpElement;
		}

		vector_iterator operator+(difference_type n) const {
			return vector_iterator<T>(ptrElement + n);
		}

		vector_iterator operator-(difference_type n) const {
			return vector_iterator<T>(ptrElement - n);
		}

		vector_iterator &operator+=(difference_type n) {
			ptrElement += n;
			return *this;
		}

		vector_iterator &operator-=(difference_type n) {
			ptrElement -= n;
			return *this;
		}

		reference operator[](difference_type index) const {
			return *(ptrElement + index);
		}

		~vector_iterator() {}
	};

	template<class T>
			vector_iterator<T> operator+(typename vector_iterator<T>::difference_type n, const vector_iterator<T> &vec) {
		return vector_iterator<T>(vec.base() + n);
	}

	template<class T>
	typename vector_iterator<T>::difference_type operator-(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() - rhs.base();
	}

	template<class T>
	bool operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() == rhs.base();
	}

	template<class T>
	bool operator!=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return !(lhs == rhs);
	}

	template<class T>
	bool operator<(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() < rhs.base();
	}

	template<class T>
	bool operator>(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() > rhs.base();
	}

	template<class T>
	bool operator<=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() <= rhs.base();
	}

	template<class T>
	bool operator>=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() >= rhs.base();
	}
}


#endif //FT_CONTAINERS_VECTOR_ITERATOR_HPP
