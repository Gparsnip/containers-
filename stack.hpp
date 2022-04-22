#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;
	private:
		container_type contr;
	public:
		explicit stack (const container_type& ctnr = container_type()) : contr(ctnr) {}

		bool empty() const
        {
            return (contr.empty());
        }

		size_type size() const
        {
            return (contr.size());
        }

		value_type& top()
        {
            return (contr.back());
        }

		const value_type& top() const
        {
            return (contr.back());
        }

		void push (const value_type& val)
        {
            contr.push_back(val);
        }

		void pop()
        {
            contr.pop_back();
        }

		friend bool operator== (const stack<T,Container>& lco, const stack<T,Container>& rco)
		{
			return (lco.contr == rco.contr);
		}

		friend bool operator!= (const stack<T,Container>& lco, const stack<T,Container>& rco)
		{
			return (lco.contr != rco.contr);
		}

		friend bool operator<  (const stack<T,Container>& lco, const stack<T,Container>& rco)
		{
			return (lco.contr < rco.contr);
		}

		friend bool operator<= (const stack<T,Container>& lco, const stack<T,Container>& rco)
		{
			return (lco.contr <= rco.contr);
		}

		friend bool operator>  (const stack<T,Container>& lco, const stack<T,Container>& rco)
		{
			return (lco.contr > rco.contr);
		}

		friend bool operator>= (const stack<T,Container>& lco, const stack<T,Container>& rco)
		{
			return (lco.contr >= rco.contr);
		}

	};
}

#endif