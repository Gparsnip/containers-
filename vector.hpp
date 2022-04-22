#pragma once
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include "iterator.hpp"

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef ft::random_access_iterator<value_type>					iterator;
		typedef ft::random_access_iterator<const value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef typename allocator_type::size_type						size_type;
    private:
        allocator_type  _alloc;
		pointer         _start;
		pointer         _end;
		pointer         _end_capacity;
    public:
        explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc),
		    _start(NULL), _end(NULL), _end_capacity(NULL) {}
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_start = _alloc.allocate(n);
			_end = _start;
			_end_capacity = _start + n;
			while(_end != _end_capacity)
			{
				_alloc.construct(_end, val);
				_end++;
			}
		}

        template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			difference_type n = ft::distance(first, last);
			_alloc = alloc;
			_start = _alloc.allocate(n);
			_end = _start;
			_end_capacity = _start + n;
			while(_end != _end_capacity)
			{
				_alloc.construct(_end, *first);
				_end++;
				first++;
			}
		}
        
        vector (const vector& x) :
		_alloc(x._alloc),
		_start(NULL),
		_end(NULL),
		_end_capacity(NULL)
		{
			this->operator=(x);
		}

		vector& operator= (const vector& x)
		{
			if (this == &x)
				return (*this);
			clear();
			this->_start = this->_alloc.allocate(x.size());
			this->_end = this->_start;
			this->_end_capacity = this->_start + x.size();
			for (const_iterator it = x.begin(); it != x.end(); it++)
			{
				this->_alloc.construct(this->_end, *it);
				this->_end++;
			}
            return (*this);
		}

        ~vector()
        {
			clear();
			_alloc.deallocate(_start, capacity());
		}

        size_type capacity (void) const
        {
            return (this->_end_capacity - this->_start);
        }

		size_type size(void) const
        {
            return (this->_end - this->_start);
        }

		size_type max_size() const
        {
            return (allocator_type().max_size());
        }

		bool empty() const
        {
            return (size() == 0);
        }

		allocator_type get_allocator() const
        {
            return (_alloc);
        }

		iterator begin()
        {
            return (iterator(_start));
        }

		const_iterator begin() const
        {
            return (const_iterator(_start));
        }

		iterator end()
        {
            return (iterator(_end));
        }

		const_iterator end() const
        {
            return (const_iterator(_end));
        }

		reverse_iterator rbegin()
        {
            return (reverse_iterator(_end));
        }

		const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(_end));
        }

		reverse_iterator rend()
        {
            return (reverse_iterator(_start));
        }

		const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(_start));
        }

        void reserve (size_type n)
		{
			if (n > max_size())
			{
				throw std::length_error("error vector::max_size");
				return ;
			}
			if (n > this->capacity())
			{
				pointer	old_start = _start;
				pointer	old_end = _end;
				pointer	old_cap = _end_capacity;
				_start = _alloc.allocate(n);
				_end = _start;
				_end_capacity = _start + n;
				if (old_end != NULL)
					while (old_start != old_end)
						_alloc.construct(_end++, *old_start++);
				_alloc.deallocate(old_end - size(), old_cap - old_start);
			}
		}

        void resize (size_type n, value_type val = value_type ())
		{
			if (n > max_size())
			{
				throw std::length_error("error vector::max_size");
				return ;
			}
			if (n < size())
			{
				while (size() != n)
				{
					_end--;
					_alloc.destroy(_end);
				}
			}
			else
				this->insert(this->end(), n - this->size(), val);
		}

        iterator erase (iterator position)
		{
			pointer pos = position.base();
			if (pos == _end)
				_alloc.destroy(pos - 1);
			else
			{
				_alloc.destroy(pos);
				for (pointer tmp = pos + 1; tmp < _end; tmp++)
				{
					_alloc.construct(tmp - 1, *tmp);
					_alloc.destroy(tmp);
				}
			}
			_end--;
			return (position);
		}

        iterator erase (iterator first, iterator last)
		{
			difference_type n = ft::distance(first, last);

			pointer left = first.base();
			pointer right = last.base();
			if (right == _end)
			{
				while (left != right)
					_alloc.destroy(left++);
			}
			else
			{
				while (left != right)
					_alloc.destroy(left++);
				while (right != _end)
				{
					_alloc.construct(right - n, *right);
					_alloc.destroy(right);
					right++;
				}
			}
			_end -= n;
			return (first);
			/*while (n--)
				erase(first);
			return (first);*/
		}

        iterator insert (iterator position, const value_type& val)
		{
			difference_type ret = ft::distance(this->begin(), position);
			difference_type ret1 = ft::distance(position, this->end());
			if (size() == capacity())
			{
				if(size() == 0)
                	reserve (1);
				else
					reserve (size() * 2);
            }
			iterator it;
			/*if (_end + 1 != _end_capacity)
				it = _end + 1;
			else
            	it = _end;*/
			it = _end;
			for (; ret1 != 0; ret1--, it--)
				_alloc.construct(it.base(), *(it - 1));
			_alloc.construct(iterator(begin() + ret).base(), val);
			_end++;
			return (ret + _start);
		}

        void insert (iterator position, size_type n, const value_type& val)
		{
			if (size() + n > max_size())
			{
				throw std::length_error("error vector::max_size");
				return;
			}
			if (n == 0)
				return ;
			difference_type ret1 = ft::distance(position, end());
			difference_type ret = ft::distance(begin(), position);
			if (size() + n > capacity())
            {
                if (size() == 0)
					reserve(1);
				else
					reserve(size() + n);
            }
			iterator it;
			if (_end + n != _end_capacity)
				it = _end + n;
			else
				it = _end_capacity;
			for (; ret1 + n - 1 != 0; ret1--, it--)
				_alloc.construct(it.base(), *(it - n));
			while (n--)
			{
				_alloc.construct(iterator(begin() + ret).base(), val);
				ret++;
				_end++;
			}
		}

        template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
						 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			difference_type range = ft::distance(first, last);
			if (range == 0)
				return;
			difference_type ret1 = ft::distance(position, end());
			difference_type ret = ft::distance(begin(), position);
			if (size() + range > capacity())
			{
                reserve (size() + range);
            }
			iterator it;
			/*if (_end + range != _end_capacity)
				it = _end + range;
			else
				it = _end_capacity;*/
			it = _end + range - 1;
			for (;range + ret1 - 1!= 0; it--, ret1--)
				_alloc.construct(it.base(), *(it - range));
			while (first != last)
			{
				_alloc.construct(iterator(begin() + ret).base(), *first);
				ret++;
				first++;
				_end++;
			}
		}

        void clear()
		{
			size_type save_size = this->size();
				for (size_type i = 0; i < save_size; i++)
				{
					_end--;
					_alloc.destroy(_end);
				}
		}

        void push_back (const value_type& val)
		{
			if(_end_capacity == _end)
			{
				if (this->size() == 0)
					reserve(1);
				else
					reserve(this->size() * 2);
			}
			_alloc.construct(_end, val);
			_end++;
		}

        template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
					 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			difference_type range = ft::distance(first, last);
			clear();
			if ((size_type)range <= capacity())
			{
				_end = _start;
				for (; first != last; first++, _end++)
					_alloc.construct(_end, *first);
			}
			else
			{
				_alloc.deallocate(_start, capacity());
				_start = _alloc.allocate(range);
				_end = _start;
				_end_capacity = _start + range;
				for (; first != last; first++, _end++)
					_alloc.construct(_end, *first);
			}
		}

        void assign (size_type n, const value_type& val)
		{
			if (n > max_size())
			{
				throw std::length_error("error vector::max_size");
				return ;
			}
			clear();
			if (n <= capacity())
			{
				_end = _start;
				for (; _end != _start + n; _end++)
					_alloc.construct(_end, val);
			}
			else
			{
				_alloc.deallocate(_start, capacity());
				pointer new_start = _alloc.allocate(n);
				pointer new_end = new_start;
				iterator it;
				for (; new_end != new_start + n; new_end++)
					_alloc.construct(new_end, val);
				_start = new_start;
				_end = new_end;
				_end_capacity = _start + n;
			}
		}

        void pop_back()
		{
			_alloc.destroy(_end - 1);
			_end--;
		}

        void swap (vector& x)
		{
			allocator_type  _alloc_tmp = x._alloc;
			pointer         _start_tmp = x._start;
			pointer         _end_tmp = x._end;
			pointer         _end_capacity_tmp = x._end_capacity;

			x._alloc = this->_alloc;
			x._start = this->_start;
			x._end = this->_end;
			x._end_capacity = this->_end_capacity;
			this->_alloc = _alloc_tmp;
			this->_start = _start_tmp;
			this->_end = _end_tmp;
			this->_end_capacity = _end_capacity_tmp;
		}

        reference operator[] (size_type n)
        {
            return (*(_start + n));
        }

		const_reference operator[] (size_type n) const
        {
            return (*(_start + n));
        }

		reference at (size_type n)
		{
			if (n > size())
				throw std::out_of_range("vector::_M_range_check");
			return (*(_start + n));
		}

		const_reference at (size_type n) const
		{
			if (n > size())
				throw std::out_of_range("vector::_M_range_check:" );
			return (*(_start + n));
		}

		reference front()
        {
            return (*_start);
        }

		const_reference front() const
        {
            return (*_start);
        }

		reference back()
        {
            return (*(_end - 1));
        }

		const_reference back() const
        {
            return (*(_end - 1));
        }
    };

    template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }

	template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T,Alloc>::const_iterator it_lhs = lhs.begin();
		typename ft::vector<T,Alloc>::const_iterator it_rhs = rhs.begin();
		while (true)
		{
			if (it_rhs == rhs.end() && it_lhs == lhs.end())
				break;
			if (*it_rhs != *it_lhs || (it_rhs == rhs.end() && it_lhs != lhs.end()))
				return (false);
			it_rhs++;
			it_lhs++;
		}
		return (true);
	}

	template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

	template <class T, class Alloc>
		bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
		bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
}
#endif