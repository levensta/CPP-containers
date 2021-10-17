//
// Created by Lorent Evenstar on 10/16/21.
//

#pragma once

#include <iostream>

namespace ft
{
	/*
	 *	IS_INTEGRAL
	 */

	template <class T>
	struct	is_integral : std::false_type {};
	template <> struct	is_integral<bool> : std::true_type {};
	template <> struct	is_integral<char> : std::true_type {};
	template <> struct	is_integral<char16_t> : std::true_type {};
	template <> struct	is_integral<char32_t> : std::true_type {};
	template <> struct	is_integral<wchar_t> : std::true_type {};
	template <> struct	is_integral<signed char> : std::true_type {};
	template <> struct	is_integral<int> : std::true_type {};
	template <> struct	is_integral<short int> : std::true_type {};
	template <> struct	is_integral<long int> : std::true_type {};
	template <> struct	is_integral<long long int> : std::true_type {};
	template <> struct	is_integral<unsigned char> : std::true_type {};
	template <> struct	is_integral<unsigned short int> : std::true_type {};
	template <> struct	is_integral<unsigned int> : std::true_type {};
	template <> struct	is_integral<unsigned long int> : std::true_type {};
	template <> struct	is_integral<unsigned long long int> : std::true_type {};

	/*
	 *	ENABLE_IF
	 */

	template <class T>
	class is_pointer : public std::false_type {};

	template <class T>
			class is_pointer<T *> : public std::true_type {};

	template <class T>
			class is_pointer<const T *> : public std::true_type {};

	template<class Iterator>
	class is_iterator {
	public:
		typedef char yes;
		typedef int no;

		template<class Any>
			static yes &test(typename Any::iterator_category * = 0) {};
		template<class Any>
			static no &test(...) {};
		static bool const value = sizeof(test<Iterator>(0)) == sizeof(yes) || is_pointer<Iterator>::value;

	};

	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	/*
	 *	CHECK_CONST
	 */
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
}