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
	 *	LESS
	 */
	template <class T>
	struct less : std::binary_function <T, T, bool> {
		bool operator() (const T& x, const T& y) const {
			return x < y;
		}
	};

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
		map_node	*end;
		bool		isRed;

		map_node(type pr, map_node<T> *end) : p(pr), parent(NULL), left(NULL), right(NULL), end(end), isRed(true) {}
		virtual ~map_node() {}
		key &get_key() {
			return p.first;
		}

		type &operator*() {
			return p;
		}
	};

	template <class T>
	bool operator==(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first == rhs.p.first;
	}

	template <class T>
	bool operator==(const map_node<T>& lhs, const T& rhs) {
		return lhs.p.first == rhs.first;
	}

	template <class T>
	bool operator==(const T& lhs, const map_node<T>& rhs) {
		return lhs.first == rhs.p.first;
	}

	template <class T>
	bool operator==(const typename map_node<T>::key& lhs, const map_node<T>& rhs) {
		return lhs == rhs.p.first;
	}

	template <class T>
	bool operator==(const map_node<T>& lhs, const typename map_node<T>::key& rhs) {
		return lhs.p.first == rhs;
	}

	template <class T>
	bool operator!=(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first != rhs.p.first;
	}

	template <class T>
	bool operator!=(const map_node<T>& lhs, const T& rhs) {
		return lhs.p.first != rhs.first;
	}

	template <class T>
	bool operator!=(const T& lhs, const map_node<T>& rhs) {
		return lhs.first != rhs.p.first;
	}

	template <class T>
	bool operator!=(const typename map_node<T>::key& lhs, const map_node<T>& rhs) {
		return lhs != rhs.p.first;
	}

	template <class T>
	bool operator!=(const map_node<T>& lhs, const typename map_node<T>::key& rhs) {
		return lhs.p.first != rhs;
	}

	template <class T>
	bool operator>=(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first >= rhs.p.first;
	}

	template <class T>
	bool operator>=(const map_node<T>& lhs, const T& rhs) {
		return lhs.p.first >= rhs.first;
	}

	template <class T>
	bool operator>=(const T& lhs, const map_node<T>& rhs) {
		return lhs.first >= rhs.p.first;
	}

	template <class T>
	bool operator>=(const typename map_node<T>::key& lhs, const map_node<T>& rhs) {
		return lhs >= rhs.p.first;
	}

	template <class T>
	bool operator>=(const map_node<T>& lhs, const typename map_node<T>::key& rhs) {
		return lhs.p.first >= rhs;
	}

	template <class T>
	bool operator<=(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first <= rhs.p.first;
	}

	template <class T>
	bool operator<=(const map_node<T>& lhs, const T& rhs) {
		return lhs.p.first <= rhs.first;
	}

	template <class T>
	bool operator<=(const T& lhs, const map_node<T>& rhs) {
		return lhs.first <= rhs.p.first;
	}

	template <class T>
	bool operator<=(const typename map_node<T>::key& lhs, const map_node<T>& rhs) {
		return lhs <= rhs.p.first;
	}

	template <class T>
	bool operator<=(const map_node<T>& lhs, const typename map_node<T>::key& rhs) {
		return lhs.p.first <= rhs;
	}

	template <class T>
	bool operator>(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first > rhs.p.first;
	}

	template <class T>
	bool operator>(const map_node<T>& lhs, const T& rhs) {
		return lhs.p.first > rhs.first;
	}

	template <class T>
	bool operator>(const T& lhs, const map_node<T>& rhs) {
		return lhs.first > rhs.p.first;
	}

	template <class T>
	bool operator>(const typename map_node<T>::key& lhs, const map_node<T>& rhs) {
		return lhs > rhs.p.first;
	}

	template <class T>
	bool operator>(const map_node<T>& lhs, const typename map_node<T>::key& rhs) {
		return lhs.p.first > rhs;
	}

	template <class T>
	bool operator<(const map_node<T>& lhs, const map_node<T>& rhs) {
		return lhs.p.first < rhs.p.first;
	}

	template <class T>
	bool operator<(const map_node<T>& lhs, const T& rhs) {
		return lhs.p.first < rhs.first;
	}

	template <class T>
	bool operator<(const T& lhs, const map_node<T>& rhs) {
		return lhs.first < rhs.p.first;
	}

	template <class T>
	bool operator<(const typename map_node<T>::key& lhs, const map_node<T>& rhs) {
		return lhs < rhs.p.first;
	}

	template <class T>
	bool operator<(const map_node<T>& lhs, const typename map_node<T>::key& rhs) {
		return lhs.p.first < rhs;
	}

	/*
	 *	END MAP NODE
	 */
	template <class T>
	class end_map_node : public map_node<T> {

	public:
		end_map_node() : map_node<T>(T(), NULL) {}
		virtual ~end_map_node() {}
	};

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
		type		p;
		set_node	*parent;
		set_node	*left;
		set_node	*right;
		set_node	*end;
		bool		isRed;

		set_node(type pr) : p(pr), parent(NULL), left(NULL), right(NULL), isRed(true) {}
		virtual ~set_node() {}
		key &get_key() {
			return p;
		}

		type &operator*() {
			return p;
		}
	};

	template <class T>
	bool operator==(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p == rhs.p;
	}

	template <class T>
	bool operator==(const set_node<T>& lhs, const T& rhs) {
		return lhs.p == rhs;
	}

	template <class T>
	bool operator==(const T& lhs, const set_node<T>& rhs) {
		return lhs == rhs.p;
	}

	template <class T>
	bool operator!=(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p != rhs.p;
	}

	template <class T>
	bool operator!=(const set_node<T>& lhs, const T& rhs) {
		return lhs.p != rhs;
	}

	template <class T>
	bool operator!=(const T& lhs, const set_node<T>& rhs) {
		return lhs != rhs.p;
	}

	template <class T>
	bool operator>=(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p >= rhs.p;
	}

	template <class T>
	bool operator>=(const set_node<T>& lhs, const T& rhs) {
		return lhs.p >= rhs;
	}

	template <class T>
	bool operator>=(const T& lhs, const set_node<T>& rhs) {
		return lhs >= rhs.p;
	}

	template <class T>
	bool operator<=(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p <= rhs.p;
	}

	template <class T>
	bool operator<=(const set_node<T>& lhs, const T& rhs) {
		return lhs.p <= rhs;
	}

	template <class T>
	bool operator<=(const T& lhs, const set_node<T>& rhs) {
		return lhs <= rhs.p;
	}

	template <class T>
	bool operator>(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p > rhs.p;
	}

	template <class T>
	bool operator>(const set_node<T>& lhs, const T& rhs) {
		return lhs.p > rhs;
	}

	template <class T>
	bool operator>(const T& lhs, const set_node<T>& rhs) {
		return lhs > rhs.p;
	}

	template <class T>
	bool operator<(const set_node<T>& lhs, const set_node<T>& rhs) {
		return lhs.p < rhs.p;
	}

	template <class T>
	bool operator<(const set_node<T>& lhs, const T& rhs) {
		return lhs.p < rhs;
	}

	template <class T>
	bool operator<(const T& lhs, const set_node<T>& rhs) {
		return lhs < rhs.p;
	}

	/*
	 *	END SET NODE
	 */
	template <class T>
	class end_set_node : public set_node<T> {

	public:
		end_set_node() : end_set_node<T>(NULL) {}
		virtual ~end_set_node() {}
	};
}
