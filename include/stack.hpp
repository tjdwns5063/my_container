#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {
	template <class T, class Container = vector<T> >
	class stack {
	public:
		typedef	T			value_type;
		typedef	Container	container_type;
		typedef	size_t		size_type;
	private:
		container_type	v;
	public:
		explicit stack (const container_type& c = container_type())
			: v(c) {}
		
		bool empty() const {
			return (v.empty());
		}

		size_type size() const {
			return (v.size());
		}

		value_type& top() {
			return (v.back());
		}

		const value_type& top() const {
			return (v.back());
		}

		void push (const value_type& val) {
			v.push_back(val);
		}

		void pop() {
			v.pop_back();
		}

		friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs == rhs);
		}

		friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs != rhs);
		}

		friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs < rhs);
		}

		friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs <= rhs);
		}

		friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs > rhs);
		}

		friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs >= rhs);
		}
	};
}



#endif