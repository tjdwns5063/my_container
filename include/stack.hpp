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
	protected:
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

		template <typename T1, typename _C1>
		friend bool operator==(const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);

		template <typename T1, typename _C1>
		friend bool operator< (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);
	};
		template <typename T, typename Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.v == rhs.v);
		}

		template <typename T, typename Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return !(lhs == rhs);
		}

		template <typename T, typename Container>
		bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.v < rhs.v);
		}

		template <typename T, typename Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (rhs < lhs);
		}

		template <typename T, typename Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return !(lhs > rhs);
		}

		template <typename T, typename Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return !(lhs < rhs);
		}
}

#endif