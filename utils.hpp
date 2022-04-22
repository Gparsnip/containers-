#pragma once
#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstddef>
#include "iterator.hpp"

namespace ft
{
    template <typename T, bool is_integral>
	struct is_integral_res
	{
		typedef T type;
		static const bool value = is_integral;
	};

	template <typename>
	struct is_integral_type : public is_integral_res<bool, false> {};

	template <>
	struct is_integral_type<bool> : public is_integral_res<bool, true> {};

	template <>
	struct is_integral_type<char> : public is_integral_res<char, true> {};

	template <>
	struct is_integral_type<wchar_t> : public is_integral_res<wchar_t, true> {};

	template <>
	struct is_integral_type<signed char> : public is_integral_res<signed char, true> {};

	template <>
	struct is_integral_type<short int> : public is_integral_res<short int, true> {};

	template <>
	struct is_integral_type<int> : public is_integral_res<int, true> {};

	template <>
	struct is_integral_type<long int> : public is_integral_res<long int, true> {};

	template <>
	struct is_integral_type<long long int> : public is_integral_res<long long int, true> {};

	template <>
	struct is_integral_type<unsigned char> : public is_integral_res<unsigned char, true> {};

	template <>
	struct is_integral_type<unsigned short int> : public is_integral_res<unsigned short int, true> {};

	template <>
	struct is_integral_type<unsigned int> : public is_integral_res<unsigned int, true> {};

	template <>
	struct is_integral_type<unsigned long int> : public is_integral_res<unsigned long int, true> {};

	template <>
	struct is_integral_type<unsigned long long int> : public is_integral_res<unsigned long long int, true> {};

	template<class T>
	struct is_integral : ft::is_integral_type<T> {};

	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

    template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1) return false;
			else if (*first1 < *first2) return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

    template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2,
								  Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1)) return false;
			else if (comp(*first1, *first2)) return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template<class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1,
			   InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;

		pair () : first(T1()), second(T2()) {};

		template<class U, class V>
		pair (const pair<U,V>& src) : first(src.first), second(src.second) {};

		pair (const first_type& a, const second_type& b) : first(a), second(b) {};

		pair& operator=(const pair& src)
		{
			if (*this == src)
				return (*this);
			this->first = src.first;
			this->second = src.second;
			return (*this);
		}
	};

	template <class T>
	struct less
	{
		bool operator() (const T& x, const T& y) const { return (x < y); }
		typedef T first_argument_type;
		typedef T second_argument_type;
		typedef bool result_type;
	};

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lco, const pair<T1,T2>& rco)
	{
		return lco.first == rco.first && lco.second == rco.second;
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lco, const pair<T1,T2>& rco)
	{
		return !(lco == rco);
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lco, const pair<T1,T2>& rco)
	{
		return lco.first < rco.first || (!(rco.first < lco.first) && lco.second < rco.second);
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lco, const pair<T1,T2>& rco)
	{
		return !(rco < lco);
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lco, const pair<T1,T2>& rco)
	{
		return rco < lco;
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lco, const pair<T1,T2>& rco)
	{
		return !(lco < rco);
	}
}
#endif