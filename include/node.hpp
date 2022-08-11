#ifndef NODE_HPP
# define NODE_HPP

namespace ft {
	template <typename _Pair>
	class Node {
		public:
			typedef	_Pair	value_type;
			typedef	Node	node;				
			typedef	node*	pointer;

			pointer			_parent;
			value_type		_val;
			pointer			_left;
			pointer			_right;

			Node(void): _parent(NULL), _left(NULL), _right(NULL) {}
			Node(value_type& val): _parent(NULL), _val(val), _left(NULL), _right(NULL) {}
			Node(const node& ref): _parent(ref._parent), _val(ref._val), _right(ref._right) {}
			~Node() {}
			
			node&	operator= (const node& ref) {
				_parent = ref._parent;
				_val = ref._val;
				_left = ref._left;
				_right = ref._right;
				return (*this);
			}

			void	setParent(pointer p) {
				_parent = p;
			}

			void	setVal(value_type& val) {
				_val = val;
			}

			void	setLeft(pointer p) {
				_left = p;
			}

			void	setRight(pointer p) {
				_right = p;
			}
	};
}

#endif