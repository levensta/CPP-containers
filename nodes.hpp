//
// Created by Lorent Evenstar on 10/20/21.
//

#pragma once

namespace ft
{
	/*
 	*	PAIR
 	*/
	template <class T1, class T2>
	struct pair {

	public:
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		// default
		pair() : first(first_type()), second(second_type()) {}

		~pair() {}

		// copy
		template<class U, class V> pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

		// initialization
		pair (const first_type& a, const second_type& b) : first(a), second(b) {};

		pair& operator=(const pair& pr) {
			if (this != &pr) {
				this->first = pr.first;
				this->second = pr.second;
			}
			return *this;
		}

	};

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs < rhs);
	}

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {
		return (pair<T1,T2>(x,y));
	}

	/*
	 *	MAP NODE
	 */
	template <class T>
	class map_node {

	private:
		map_node() {}

	public:
		typedef T type;
		typedef typename T::first_type key;
		typedef typename T::second_type value;
		type		p;
		map_node	*parent;
		map_node	*left;
		map_node	*right;
		bool		isRed;

		map_node(const type &pr) : p(pr), parent(NULL), left(NULL), right(NULL), isRed(true) {}
		~map_node() {}
	};

	template <class T>
	bool operator==(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first == rhs.p.first;
	}

	template <class T>
	bool operator!=(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first != rhs.p.first;
	}
	template <class T>
	bool operator>=(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first >= rhs.p.first;
	}
	template <class T>
	bool operator<=(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first <= rhs.p.first;
	}
	template <class T>
	bool operator>(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first > rhs.p.first;
	}
	template <class T>
	bool operator<(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first < rhs.p.first;
	}

	/*
	 *	SET NODE
	 */
	template <class T>
	class set_node {

	private:
		set_node() {}

	public:
		typedef T type;
		typedef T key;
		type			p;
		set_node	*parent;
		set_node	*left;
		set_node	*right;
		bool		isRed;

		set_node(const type &pr) : p(pr), parent(NULL), left(NULL), right(NULL), isRed(true) {}
		~set_node() {}
	};

	template <class T>
	bool operator==(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p == rhs.p;
	}

	template <class T>
	bool operator!=(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p != rhs.p;
	}

	template <class T>
	bool operator>=(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p >= rhs.p;
	}

	template <class T>
	bool operator<=(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p <= rhs.p;
	}

	template <class T>
	bool operator>(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p > rhs.p;
	}

	template <class T>
	bool operator<(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p < rhs.p;
	}
}
