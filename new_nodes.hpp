//
// Created by Lorent Evenstar on 10/30/21.
//

#pragma once
#include <iostream>

namespace  ft
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

	template<class Key, class Value = Key>
	class node {

	public:
		typedef ft::pair<Key, Value> 	type;
		typedef Key						key;
		typedef Value					value;
		node							*parent;
		node							*left;
		node							*right;
		node							*end;

	private:
		bool							_isRed;
		bool 							_isLeft;
		type							_data;

	public:

		node(type pr, node *end, bool left) : parent(NULL), left(NULL), right(NULL), end(end), _isRed(true), _isLeft(left), _data(pr) {}
		node(const node &x) : parent(x.parent), left(x.left), right(x.right), end(x.end), _isRed(x.get_color()), _isLeft(x.is_left()), _data(x.get_data()) {}

		virtual			~node() {}

		bool 			is_left() const {
			return _isLeft;
		}

		void 			set_left(bool left) {
			_isLeft = left;
		}

		const type 		&get_data() const {
			return _data;
		}

		value &get_value() {
			return _data.second;
		}

		bool			get_color() const {
			return _isRed;
		}

		void 			set_color(bool color) {
			_isRed = color;
		}

		type 			&operator*() {
			return _data;
		}

		const key		&get_key() const {
			return _data.first;
		}

		void 			swap(node &x) {
			if (this != &x) {
				node	*tmp = x.left;
				x.left = this->left;
				this->left = tmp;

				tmp = x.right;
				x.right = this->right;
				this->right = this;

				tmp = x.parent;
				x.parent = this->parent;
				this->parent = tmp;

				tmp = x.end;
				x.end = this->end;
				this->end = tmp;

				bool 	is = x.get_color();
				x.set_color(this->get_color());
				this->set_color(is);

				is = x.is_left();
				x.set_left(this->is_left());
				this->set_left(is);
			}
		}
	};

	template <class T, class U>
	bool operator==(const node<T, U>& lhs, const node<T, U>& rhs) {
		return lhs.get_key() == rhs.get_key();
	}

	template <class T, class U>
	bool operator==(const node<T, U>& lhs, const typename node<T, U>::key& rhs) {
		return lhs.get_key() == rhs;
	}

	template <class T, class U>
	bool operator==(const node<T, U>& lhs, const ft::pair<T, U>& rhs) {
		return lhs.get_key() == rhs.first;
	}

	template <class T, class U>
	bool operator!=(const node<T, U>& lhs, const node<T, U>& rhs) {
		return lhs.get_key() != rhs.get_key();
	}

	template <class T, class U>
	bool operator!=(const node<T, U>& lhs, const typename node<T, U>::key& rhs) {
		return lhs.get_key() != rhs;
	}

	template <class T, class U, class T1, class T2>
	bool operator!=(const node<T, U>& lhs, const ft::pair<T, U>& rhs) {
		return lhs.get_key() != rhs.first;
	}

	template <class T, class U>
	bool operator<(const node<T, U>& lhs, const node<T, U>& rhs) {
		return lhs.get_key() < rhs.get_key();
	}

	template <class T, class U>
	bool operator<(const node<T, U>& lhs, const typename node<T, U>::key& rhs) {
		return lhs.get_key() < rhs;
	}

	template <class T, class U>
	bool operator<(const node<T, U>& lhs, const ft::pair<T, U>& rhs) {
		return lhs.get_key() < rhs.first;
	}

	template <class T, class U>
	bool operator>(const node<T, U>& lhs, const node<T, U>& rhs) {
		return lhs.get_key() > rhs.get_key();
	}

	template <class T, class U>
	bool operator>(const node<T, U>& lhs, const typename node<T, U>::key& rhs) {
		return lhs.get_key() > rhs;
	}

	template <class T, class U>
	bool operator>(const node<T, U>& lhs, const ft::pair<T, U>& rhs) {
		return lhs.get_key() > rhs.first;
	}

	template<class Key, class Value = Key>
	class end_node : public node<Key, Value> {
	public:
		end_node() : node<Key, Value>(ft::make_pair(Key(), Value()), NULL, true) {}
		end_node(const end_node &x) : node<Key, Value>(x) {}

		virtual ~end_node() {}

		node<Key, Value>	*get_root() {
			return this->parent;
		}

		node<Key, Value>	*get_max() {
			return this->right;
		}

		node<Key, Value>	*get_min() {
			return this->left;
		}
	};
}