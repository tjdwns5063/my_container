#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "iterator.hpp"
#include "pair.hpp"
#include "node.hpp"

namespace ft {
	template <class _Tp>
	class map_iterator_base {
		typedef Node<_Tp>					node_type;
		typedef typename node_type::pointer	node_pointer;
		typedef _Tp							value_type;
		typedef ptrdiff_t					difference_type;
		typedef value_type&					reference;
		typedef value_type*					pointer;

	public:
		map_iterator_base(node_pointer p): _p(p) {}
		map_iterator_base(const map_iterator_base& ref): _p(ref._p) {}
	protected:
		node_pointer	_p;

		node_pointer	tree_min(node_pointer _ptr) {
			while (_ptr->_left != NULL)
        		_ptr = _ptr->_left;
    		return _ptr;
		}

		bool is_left_child(node_pointer _ptr) {
    		return _ptr == _ptr->_parent->_left;
		}

		node_pointer	tree_max(node_pointer _ptr) {
			while (_ptr->_right != NULL)
				_ptr = _ptr->_right;
			return _ptr;
		}

		void	inc() {
			if (_p->_right != NULL) {
				_p = tree_min(_p->_right);
				return ;
			}
			while (!is_left_child(_p)) {
				_p = _p->_parent;
			}
			_p = _p->_parent;
		}

		void	dec() {
			if (_p->_left != NULL) {
				_p = tree_max(_p->_left);
				return ;
			}
			while (is_left_child(_p)) {
				_p = _p->_parent;
			}
			_p = _p->_parent;
		}

		template <typename _T>
        friend bool operator==(const map_iterator_base<_T>& lhs, const map_iterator_base<_T>& rhs);
    	
		template <typename _T>
        friend bool operator!=(const map_iterator_base<_T>& lhs, const map_iterator_base<_T>& rhs);
	};
	template <typename T>
	bool operator==(const map_iterator_base<T>& lhs, const map_iterator_base<T>& rhs) {
		return (lhs._p == rhs._p);
	}

	template <typename T>
	bool operator!=(const map_iterator_base<T>& lhs, const map_iterator_base<T>& rhs) {
		return !(lhs == rhs);
	}

	template <class _Tp>
	class map_iterator: public map_iterator_base<_Tp> {
	public:
		typedef Node<_Tp>					node_type;
		typedef typename node_type::pointer	node_pointer;
		typedef bidirectional_iterator_tag	iterator_category;
		typedef _Tp							value_type;
		typedef ptrdiff_t					difference_type;
		typedef value_type&					reference;
		typedef value_type*					pointer;
	protected:
		// node_pointer _p;
	public:
		map_iterator(): map_iterator_base<_Tp>(NULL) {}
		map_iterator(node_pointer p): map_iterator_base<_Tp>(p) {}
		map_iterator(const map_iterator& ref): map_iterator_base<_Tp>(ref._p) {}
		map_iterator&	operator=(const map_iterator& ref) {
			this->_p = ref._p;
			return (*this);
		}

		reference	operator*() const {
			return (this->_p->_val);
		}

		pointer		operator->() const {
			return &(this->_p->_val);
		}

		map_iterator&	operator++() {
			this->inc();
			return (*this);
		}

		map_iterator	operator++(int) {
			map_iterator	temp(*this);
			++(*this);
			return (temp);
		}

		map_iterator&	operator--() {
			this->dec();
			return (*this);
		}

		map_iterator	operator--(int) {
			map_iterator	temp(*this);
			--(*this);
			return (temp);
		}

		template <typename _T>
        friend bool operator==(const map_iterator<_T>& lhs, const map_iterator<_T>& rhs);
    	
		template <typename _T>
        friend bool operator!=(const map_iterator<_T>& lhs, const map_iterator<_T>& rhs);
	};

	template <typename T>
	bool operator==(const map_iterator<T>& lhs, const map_iterator<T>& rhs) {
		return (lhs._p == rhs._p);
	}

	template <typename T>
	bool operator!=(const map_iterator<T>& lhs, const map_iterator<T>& rhs) {
		return !(lhs == rhs);
	}

	template <class _Tp>
	class map_const_iterator: public map_iterator_base<_Tp> {
	public:
		typedef Node<_Tp>					node_type;
		typedef typename node_type::pointer	node_pointer;
		typedef bidirectional_iterator_tag	iterator_category;
		typedef _Tp							value_type;
		typedef ptrdiff_t					difference_type;
		typedef value_type&					reference;
		typedef value_type*					pointer;
	private:
		typedef	map_iterator<_Tp>			non_const_iterator;
		// node_pointer _p;
		map_const_iterator(node_pointer p): map_iterator_base<_Tp>(p) {}

	public:
		map_const_iterator(): map_iterator_base<_Tp>(NULL) {}
		map_const_iterator(non_const_iterator it): map_iterator_base<_Tp>(it) {}
		map_const_iterator(const map_const_iterator& ref): map_iterator_base<_Tp>(ref._p) {}

		reference	operator*() const {
			return (this->_p->_val);
		}

		pointer		operator->() const {
			return &(this->_p->_val);
		}

		map_const_iterator&	operator++() {
			this->inc();
			return (*this);
		}

		map_const_iterator	operator++(int) {
			map_const_iterator	temp(*this);
			++(*this);
			return (temp);
		}

		map_const_iterator&	operator--() {
			this->dec();
			return (*this);
		}

		map_const_iterator	operator--(int) {
			map_const_iterator	temp(*this);
			--(*this);
			return (temp);
		}

		template <typename _T>
        friend bool operator==(const map_const_iterator<_T>& lhs, const map_const_iterator<_T>& rhs);
    	
		template <typename _T>
        friend bool operator!=(const map_const_iterator<_T>& lhs, const map_const_iterator<_T>& rhs);
	};

	template <typename T>
	bool operator==(const map_const_iterator<T>& lhs, const map_const_iterator<T>& rhs) {
			return (lhs._p == rhs._p);
	}

	template <typename T>
	bool operator!=(const map_const_iterator<T>& lhs, const map_const_iterator<T>& rhs) {
			return !(lhs == rhs);
	}
}

#endif