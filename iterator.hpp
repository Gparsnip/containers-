#pragma once
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include "utils.hpp"

namespace ft
{
    template<class Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

    template<class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

    template<class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

    template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T        	value_type;
		typedef Distance 	difference_type;
		typedef Pointer  	pointer;
		typedef Reference	reference;
		typedef Category 	iterator_category;
	};

    template <class T>
	class random_access_iterator : public iterator<std::random_access_iterator_tag, T>
	{
	public:
		typedef typename iterator<std::random_access_iterator_tag, T>::value_type			value_type;
		typedef typename iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
		typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef T*																			pointer;
		typedef T&																			reference;
    private:
        pointer	_i;
    public:

        random_access_iterator(void) : _i(0){}
		random_access_iterator(pointer elem) : _i(elem){}
		random_access_iterator(const random_access_iterator& src) : _i(src._i){}
		virtual ~random_access_iterator() {}

		random_access_iterator& operator=(const random_access_iterator& src)
		{
			this->_i = src._i;
			return (*this);
		}

		random_access_iterator &operator++(void)
		{
			this->_i++;
			return(*this);
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator tmp(*this);
			this->_i++;
			return(tmp);
		}

		random_access_iterator &operator--(void)
		{
			this->_i--;
			return(*this);
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator tmp(*this);
			this->_i--;
			return(tmp);
		}

		reference operator*() const
		{
			return (*_i);
		}

		pointer operator->() const
		{
			return (this->_i);
		}

		random_access_iterator operator+(difference_type n) const
		{
			return (this->_i + n);
		}

		pointer base() const
		{
			return (this->_i);
		}

		friend random_access_iterator operator+(difference_type n, const random_access_iterator& it)
		{
			return (it.base() + n);
		}

		random_access_iterator operator-(difference_type n) const
		{
			return (this->_i - n);
		}

		friend difference_type operator-(const random_access_iterator& it, const random_access_iterator& it_2)
		{
			return (it.base() - it_2.base());
		}

		random_access_iterator &operator+=(difference_type n)
		{
			this->_i += n;
			return (*this);
		}

		random_access_iterator &operator-=(difference_type n)
		{
			this->_i -= n;
			return (*this);
		}

		reference operator[](difference_type n) const
		{
			return (*(this->_i + n));
		}

		friend bool operator==(const random_access_iterator& lco, const random_access_iterator& rco)
		{
			return (lco._i == rco._i);
		}

		friend bool operator!=(const random_access_iterator& lco, const random_access_iterator& rco)
		{
			return (lco._i != rco._i);
		}

		friend bool operator<(const random_access_iterator& lco, const random_access_iterator& rco)
		{
			return (lco._i < rco._i);
		}

		friend bool operator>(const random_access_iterator& lco, const random_access_iterator& rco)
		{
			return (lco._i > rco._i);
		}

		friend bool operator>=(const random_access_iterator& lco, const random_access_iterator& rco)
		{
			return (lco._i >= rco._i);
		}

		friend bool operator<=(const random_access_iterator& lco, const random_access_iterator& rco)
		{
			return (lco._i <= rco._i);
		}

		operator ft::random_access_iterator<const T>() const
		{
			return ft::random_access_iterator<const T>(this->_i);
		}
	};

	template<typename ItL, typename ItR>
	typename random_access_iterator<ItL>::difference_type
	operator-(const random_access_iterator<ItL> &lco, const random_access_iterator<ItR> &rco)
	{
		return lco.base() - rco.base();
	}

	template<typename It>
	typename random_access_iterator<It>::difference_type
	operator-(const random_access_iterator<It> &lco,
			  const random_access_iterator<It> &rco)
	{
		return (lco.base() - rco.base());
	}

	template<typename It>
	random_access_iterator<It>
	operator+(typename random_access_iterator<It>::difference_type n, const random_access_iterator<It> &i)
	{
		return (random_access_iterator<It>(i.base() + n));
	}

	template <class Iter>
	class reverse_iterator
	{
	public:
		typedef Iter												iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;
	private:
		iterator_type	rev_i;
	public:
		reverse_iterator() : rev_i(){}
		explicit reverse_iterator(iterator_type it) : rev_i(it){}
		template <class Iterator>
			reverse_iterator (const reverse_iterator<Iterator>& it) : rev_i(it.base()){}
		virtual ~reverse_iterator() {}

		iterator_type base() const
		{
			return (this->rev_i);
		}

		reference operator*() const
		{
			iterator_type tmp = rev_i;
			return (*(--tmp));
		}

		reverse_iterator operator-(difference_type n) const 
		{
			return (reverse_iterator(this->rev_i + n));
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(this->rev_i - n));
		}

		reverse_iterator &operator+=(difference_type n)
		{
			this->rev_i -= n;
			return (*this);
		}
		reverse_iterator &operator--(void)
		{
			this->rev_i++;
			return(*this);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp(*this);
			this->rev_i++;
			return(tmp);
		}

		reverse_iterator &operator++(void)
		{
			this->rev_i--;
			return(*this);
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(*this);
			this->rev_i--;
			return(tmp);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			this->rev_i += n;
			return (*this);
		}

		pointer operator->() const
		{
			return (&(this->operator*()));
		}

		reference operator[](difference_type n) const
		{
			return (*(*this + n));
		}
	};

	template <class Iter>
	bool operator==(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter>& rco)
	{
		return (lco.base() == rco.base());
	}
	template <class Iter>
	bool operator!=(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter>& rco)	
	{
		return (lco.base() != rco.base());
	}
	template <class Iter>
	bool operator<(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter>& rco)
	{ 
		return (lco.base() > rco.base());
	}
	template <class Iter>
	bool operator<=(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter>& rco)
	{
		return (lco.base() >= rco.base());
	}
	template <class Iter>
	bool operator>(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter>& rco)
	{
		return (lco.base() < rco.base());
	}
	template <class Iter>
	bool operator>=(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter>& rco)
	{
		return (lco.base() <= rco.base());
	}
	template<typename Iter>
	typename reverse_iterator<Iter>::difference_type
	operator-(const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y)
	{
		return (y.base() - x.base());
	}

	template <class Iter, class Iter_2>
	typename reverse_iterator<Iter>::difference_type
	operator-(const reverse_iterator<Iter> &x, const reverse_iterator<Iter_2> &y)
	{
		return (y.base() - x.base());
	}

	template<typename Iter>
	reverse_iterator<Iter>
	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &x)
	{
		return (reverse_iterator<Iter>(x.base() - n));
	}

	template <class Iter, class Iter_2>
	bool operator==(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter_2>& rco)
	{
		return (lco.base() == rco.base());
	}
	template <class Iter, class Iter_2>
	bool operator!=(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter_2>& rco)
	{
		return (lco.base() != rco.base());
	}
	template <class Iter, class Iter_2>
	bool operator<(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter_2>& rco)
	{
		return (lco.base() > rco.base());
	}
	template <class Iter, class Iter_2>
	bool operator<=(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter_2>& rco)
	{
		return (lco.base() >= rco.base());
	}
	template <class Iter, class Iter_2>
	bool operator>(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter_2>& rco)
	{
		return (lco.base() < rco.base());
	}
	template <class Iter, class Iter_2>
	bool operator>=(const reverse_iterator<Iter>& lco, const reverse_iterator<Iter_2>& rco)
	{
		return (lco.base() <= rco.base());
	}
	template <class Iterator>
	typename iterator_traits<Iterator>::difference_type distance (Iterator first, Iterator last)
	{
		typename iterator_traits<Iterator>::difference_type n = 0;
		while (first != last)
		{
			first++;
			n++;
		}
		return (n);
	}
	
	template <class value_type>
	struct binary_tree
	{
	public:
		value_type	_value;
		binary_tree *_left_node;
		binary_tree *_right_node;
		binary_tree *_parent_node;
		bool red;

		binary_tree() : _value(value_type()), _left_node(NULL), _right_node(NULL), _parent_node(NULL), red(true) {}
		explicit binary_tree(const value_type &value, binary_tree *parent = NULL, binary_tree *left = NULL, binary_tree *right = NULL) :
				_value(value), _left_node(left), _right_node(right), _parent_node(parent), red(true) {}
		binary_tree(const binary_tree &src) :
				_value(src._value), _left_node(src._left_node), _right_node(src._right_node), _parent_node(src._parent_node), red(src.red) {};

		binary_tree &operator=(const binary_tree &src)
		{
			if (*this == src)
				return (*this);
			_value = src._value;
			_left_node = src._left_node;
			_right_node = src._right_node;
			_parent_node = src._parent_node;
			//this->red = src.red;
			return (*this);
		}
		bool operator== (const binary_tree& tree)
		{
			if (_value == tree._value && _left_node == tree._left_node && _right_node == tree._right_node && _parent_node == tree._parent_node)
				return (true);
			return (false);
		}

		bool operator!= (const binary_tree& tree)
		{
			return (!(this == tree));
		}

		~binary_tree() {};
	};
	
	template <class T, class T2>
	class map_iterator : public iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		typedef typename iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
		typedef typename iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
		typedef typename iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
		typedef T*																			pointer;
		typedef T&																			reference;
	private:
		T2 *node;
		T2 *last;
		T2 *null_node;
	public:
		map_iterator(void) : node(NULL), last(NULL), null_node(NULL){}
		map_iterator(T2 *elem) : node(elem), last(elem), null_node(NULL){}
		map_iterator(T2 *_node, T2 *_last) : node(_node), last(_last), null_node(NULL){}
		map_iterator(const map_iterator& it) : node(it.node), last(it.last), null_node(it.null_node){}
		virtual ~map_iterator() {}

		map_iterator& operator=(const map_iterator& it)
		{
			this->node = it.node;
			this->last = it.last;
			this->null_node = it.null_node;
			return (*this);
		}

		map_iterator &operator++(void)
		{
			if (node == null_node)
				return (*this);
			if (node->_right_node != null_node)
			{
				node = node->_right_node;
				while (node->_left_node != null_node)
					node = node->_left_node;
				last = node;
				return (*this);
			}
			while (true)
			{
				if (node->_parent_node == null_node)
				{
					node = node->_parent_node;
					return (*this);
				}
				if (node->_parent_node->_left_node == node)
				{
					node = node->_parent_node;
					last = node;
					return (*this);
				}
				node = node->_parent_node;
			}
		}

		map_iterator operator++(int)
		{
			map_iterator tmp(*this);
			this->operator++();
			return (tmp);
		}

		map_iterator &operator--(void)
		{
			if (node == null_node)
			{
				node = last;
				return (*this);
			}
			if (node->_left_node != null_node)
			{
				node = node->_left_node;
				while (node->_right_node != null_node)
					node = node->_right_node;
				return (*this);
			}
			while (true)
			{
				if (node->_parent_node == null_node)
				{
					node = node->_parent_node;
					return (*this);
				}
				if (node->_parent_node->_right_node == node)
				{
					node = node->_parent_node;
					return (*this);
				}
				node = node->_parent_node;
			}
		}

		map_iterator operator--(int)
		{
			map_iterator tmp(*this);
			this->operator--();
			return (tmp);
		}

		bool operator==(const map_iterator& it) const
		{
			return (this->node == it.node && this->null_node == it.null_node);
		}

		bool operator!=(const map_iterator& it) const
		{
			return (!(*this == it));
		}

		T2 *base() const
		{
			return (node);
		}

		reference operator*() const
		{
			return (node->_value);
		}

		pointer operator->() const
		{
			return (&(node->_value));
		}

		operator ft::map_iterator<const T, const T2>() const
		{
			return ft::map_iterator<const T, const T2>(node, last);
		}
	};
}
#endif