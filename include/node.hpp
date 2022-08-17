#ifndef NODE_HPP
# define NODE_HPP

namespace ft {
	template <typename _Pair>
	class Node {
		public:
			typedef	_Pair								value_type;
			typedef	typename value_type::first_type		first_type;
			typedef	typename value_type::second_type	second_type;
			typedef	Node								node;				
			typedef	node*								pointer;

			pointer			_parent;
			value_type		_val;
			pointer			_left;
			pointer			_right;

			Node(void): _parent(0), _val(pair<first_type, second_type>()), _left(0), _right(0) {}
			Node(value_type& val): _parent(0), _val(val), _left(0), _right(0) {}
			Node(const node& ref): _parent(ref._parent), _val(ref._val), _left(ref._left), _right(ref._right) {}
			~Node() {}
			
			node&	operator= (const node& ref) {
				if (*this == ref)
					return (*this);
				_parent = ref._parent;
				_val = ref._val;
				_left = ref._left;
				_right = ref._right;
				return (*this);
			}
	};
}

#endif