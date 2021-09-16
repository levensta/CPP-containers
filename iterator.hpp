//
// Created by Lorent Evenstar on 9/16/21.
//

#ifndef FT_CONTAINERS_ITERATOR_HPP
#define FT_CONTAINERS_ITERATOR_HPP

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

}

#endif //FT_CONTAINERS_ITERATOR_HPP
