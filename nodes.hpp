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
		type							_data;

	public:

		node() : parent(NULL), left(NULL), right(NULL), end(NULL), _isRed(false) {}
		node(type pr, node *end) : parent(NULL), left(NULL), right(NULL), end(end), _isRed(true), _data(pr) {}
		node(const node &x) : parent(x.parent), left(x.left), right(x.right), end(x.end), _isRed(x._isRed), _data(x._data) {}

		virtual			~node() {}

		type		&is_data() {
			return _data;
		}

		bool			&is_red() {
			return _isRed;
		}

		type 			&operator*() {
			return _data;
		}

		key		&get_key() {
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

				bool 	is = x.is_red();
				x.is_red() = this->is_red();
				this->is_red() = is;
			}
		}

		void 			left_swap(node &x) {
			if (this != &x) {
				node	*tmp = x.left;
				x.left = this;
				this->left = tmp;

				tmp = x.right;
				x.right = this->right;
				this->right = this;

//				tmp = x.parent;
				x.parent = this->parent;
				this->parent = &x;

				tmp = x.end;
				x.end = this->end;
				this->end = tmp;

				bool 	is = x.is_red();
				x.is_red() = this->is_red();
				this->is_red() = is;
			}
		}

		void 			right_swap(node &x) {
			if (this != &x) {
				node	*tmp = x.left;
				x.left = this->left;
				this->left = tmp;

				tmp = x.right;
				x.right = this;
				this->right = tmp;

//				tmp = x.parent;
				x.parent = this->parent;
				this->parent = &x;

				tmp = x.end;
				x.end = this->end;
				this->end = tmp;

				bool 	is = x.is_red();
				x.is_red() = this->is_red();
				this->is_red() = is;
			}
		}

		bool 	is_end() {
			return (this->end == NULL);
		}
	};
	
}
