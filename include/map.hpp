#ifndef MAP_HPP
# define MAP_HPP

#include <algorithm>
#include "comp_algorithm.hpp"
#include "map_iterator.hpp"

namespace ft {

template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Allocator = std::allocator<pair<const Key,T> > >    // map::allocator_type 
class map {
public:
    typedef Key                                      	key_type;
    typedef T                                        	mapped_type;
    typedef pair<const key_type, mapped_type>        	value_type;
    typedef Compare                                  	key_compare;

    typedef Allocator                                	allocator_type;
    typedef typename allocator_type::reference       	reference;
    typedef typename allocator_type::const_reference 	const_reference;
    typedef typename allocator_type::pointer         	pointer;
    typedef typename allocator_type::const_pointer   	const_pointer;
    typedef typename allocator_type::size_type       	size_type;
    typedef typename allocator_type::difference_type 	difference_type;

    typedef map_iterator<value_type>					iterator;
    typedef map_const_iterator<value_type>              const_iterator;
    typedef ft::reverse_iterator<iterator>				reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	class value_compare: public std::binary_function<value_type, value_type, bool> {
	private:
        friend class map;
    protected:
        key_compare comp;

        value_compare(key_compare c): comp(c) {}
    public:
        bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
    };



private:
	typedef typename iterator::node_type		node;
	typedef typename iterator::node_pointer		node_pointer;
	typedef std::allocator<node>				node_allocator;

	enum	e_node_child_state {
		NO,
		ONE,
		TWO
	};

	enum	e_rotate_state {
		RR,
		LL,
		RL,
		LR
	};

	iterator									_iter;
	node_allocator								_node_alloc;
	allocator_type								_alloc;
	key_compare									_key_comp;
	size_type									_size;
	node_pointer								_super_node;

	node_pointer	make_node(value_type val) {
		node_pointer ret = _node_alloc.allocate(1);

		_node_alloc.construct(ret, Node<value_type>(val));
		return (ret);
	}

	void	clear_map(node_pointer* root) {
		if (!(*root))
			return ;
		node_pointer temp = *root;
		delete (*root);
		*root = 0;
		clear_map(&temp->_left);
		clear_map(&temp->_right);
	}

	bool	append_node(node_pointer root, node_pointer parent, node_pointer ptr) {
		if (!root) {
			root = ptr;
			root->_parent = parent;
			if (parent->_val.first < ptr->_val.first) {
				parent->_right = ptr;
			} else {
				parent->_left = ptr;
			}
			return true;
		}
		if (root->_val.first > ptr->_val.first) {
			return append_node(root->_left, root, ptr);
		}
		else if (root->_val.first < ptr->_val.first) {
			return append_node(root->_right, root, ptr);
		}
		return false;
	}

	node_pointer	search_node(const key_type& k, node_pointer root) {
		if (!root || k == root->_val.first)
			return root;
		node_pointer ret = search_node(k, root->_left);
		if (ret && ret->_val.first == k) {
			return ret;
		}
		ret = search_node(k, root->_right);
		if (ret && ret->_val.first == k) {
			return ret;
		}
		return NULL;
	}

	e_node_child_state	node_child_cnt(node_pointer p) {
		if (p->_left && p->_right)
			return TWO;
		else if (p->_left || p->_right)
			return ONE;
		return NO;
	}

	void	delete_leaf_node(node_pointer p) {
		// std::cout << "Leaf\n";
		if (p->_parent->_left == p)
			p->_parent->_left = NULL;
		else
			p->_parent->_right = NULL;
		if (p == _root)
			_root = p->_parent->_left;
		_node_alloc.deallocate(p, 1); // 메모리 해제
		_node_alloc.destroy(p); // 소멸자 호출
	}

	void	delete_one_child_node(node_pointer p) {
		// std::cout << "One\n";

		if (p->_parent->_left == p) {
			if (p->_left) {
				p->_parent->_left = p->_left;
				p->_left->_parent = p->_parent;
			}
			else if (p->_right) {
				p->_parent->_left = p->_right;
				p->_right->_parent = p->_parent;
			}
		} else {
			if (p->_left) {
				p->_parent->_right = p->_left;
				p->_left->_parent = p->_parent;
			}
			else if (p->_right) {
				p->_parent->_right = p->_right;
				p->_right->_parent = p->_parent;
			}
		}
		if (p == _root)
			_root = p->_parent->_left;
		_node_alloc.deallocate(p, 1);
		_node_alloc.destroy(p);
	}

	void	delete_two_child_node(node_pointer p) {
		// std::cout << "Two\n";

		node_pointer	min_left = p->_right;

		while (min_left->_left) {
			min_left = min_left->_left;
		}
		min_left->_left = p->_left;
		p->_left->_parent = min_left;
		min_left->_parent = p->_right;
		if (p->_parent->_left == p) {
			p->_parent->_left = p->_right;
			p->_right->_parent = p->_parent;
		} else {
			p->_parent->_right = p->_right;
			p->_right->_parent = p->_parent;
		}
		if (p == _root)
			_root = p->_parent->_left;
		_node_alloc.deallocate(p, 1);
		_node_alloc.destroy(p);
	}

	bool	delete_node(const key_type& k, node_pointer root) {
		node_pointer searched_node = search_node(k, root);

		if (!searched_node)
			return false;
		switch (node_child_cnt(searched_node)) {
			case NO:
				delete_leaf_node(searched_node);
				break ;
			case ONE:
				delete_one_child_node(searched_node);
				break ;
			case TWO:
				delete_two_child_node(searched_node);
				break ;
		}
		return true;
	}

	ssize_t	get_node_height(node_pointer ptr) {
		if (!ptr)
			return (0);
		return 1 + std::max(get_node_height(ptr->_left), get_node_height(ptr->_right));
	}

	ssize_t	get_balanced_factor(node_pointer ptr) {
		if (!ptr)
			return (0);
		return get_node_height(ptr->_left) - get_node_height(ptr->_right);
	}

	node_pointer	check_balanced_factor(node_pointer root, node_pointer target) {
		ssize_t balanced_factor = get_balanced_factor(root);

		if (!root) {
			return target;
		} else if (abs(balanced_factor) > 1) {
			target = root;
		}
		target = check_balanced_factor(root->_left, target);
		target = check_balanced_factor(root->_right, target);
		return target;
	}

	e_rotate_state	check_rotate_state(node_pointer target) {
		ssize_t balanced_factor = get_balanced_factor(target);
		if (balanced_factor > 1 && get_balanced_factor(target->_left) > 0)
			return (LL);
		else if (balanced_factor > 1 && get_balanced_factor(target->_left) < 0)
			return (LR);
		else if (balanced_factor < -1 && get_balanced_factor(target->_right) < 0)
			return (RR);
		return (RL);
	}

	void	rotate_right(node_pointer target) {
		node_pointer child = target->_left;

		target->_left = child->_right;
		if (child->_right) {
			child->_right->_parent = target;
		}
		child->_right = target;
		child->_parent = target->_parent;
		if (target->_parent->_left == target) {
			target->_parent->_left = child;
		} else {
			target->_parent->_right = child;
		}
		target->_parent = child;
		if (target == _root) {
			_root = child;
		}
	}

	void	rotate_left(node_pointer target) {
		node_pointer child = target->_right;

		target->_right = child->_left;
		if (child->_left) {
			child->_left->_parent = target;
		}
		child->_left = target;
		child->_parent = target->_parent;
		if (target->_parent->_left == target) {
			target->_parent->_left = child;
		} else {
			target->_parent->_right = child;
		}
		target->_parent = child;
		if (target == _root) {
			_root = child;
		}
	}

	bool	rotate_tree(node_pointer root) {
		node_pointer	target = check_balanced_factor(root, NULL);
		
		if (!target)
			return false;
		// std::cout << "root: " << root->_val.first << '\n';
		// std::cout << "target: " << target->_val.first << '\n';
		switch (check_rotate_state(target)) {
			case LL:
				// std::cout << "LL\n";
				rotate_right(target);
				break ;
			case RR:
				// std::cout << "RR\n";
				rotate_left(target);
				break ;
			case LR:
				// std::cout << "LR\n";
				rotate_left(target->_left);
				rotate_right(target);
				break ;
			case RL:
				// std::cout << "RL\n";
				rotate_right(target->_right);
				rotate_left(target);
				break ;
		}
		return true;
	}

public:
	node_pointer	_root;

	explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
			  : _alloc(alloc), _key_comp(comp), _size(0), _super_node(make_node(pair<key_type, mapped_type>())), _root(NULL) {}
	
	template <class InputIterator>
	map (InputIterator first, InputIterator last,
       const key_compare& comp = key_compare(),
       const allocator_type& alloc = allocator_type())
	   : _alloc(alloc), _key_comp(comp), _size(0), _super_node(make_node(pair<key_type, mapped_type>())), _root(NULL) {
		   insert(first, last);
	   }

	map (const map& x): _alloc(x._alloc), _key_comp(x._key_comp), _size(0), _super_node(make_node(pair<key_type, mapped_type>())), _root(NULL) {
		// std::cout << "copy constructor called\n";
		insert(x.begin(), x.end());
	}

	~map() { /*clear();*/ };


	map& operator= (const map& x) {
		// std::cout << "assign constructor called\n";
		if (*this == x)
			return (*this);
		if (empty()) {
			_alloc = x._alloc;
			_key_comp = x._key_comp;
			insert(x.begin(), x.end());
		} else {
			clear();
			_super_node = make_node(pair<key_type, mapped_type>());
			_alloc = x._alloc;
			_key_comp = x._key_comp;
			insert(x.begin(), x.end());
		}
		return (*this);
	}

	iterator begin() {
		node_pointer root = _root;
		if (!root)
			return iterator(_super_node);

		while (root->_left) {
			root = root->_left;
		}
		return iterator(root);
	}

	const_iterator begin() const {
		node_pointer root = _root;
		if (!root)
			return iterator(_super_node);

		while (root->_left) {
			root = root->_left;
		}
		return iterator(root);
	}

	iterator end() {
		if (!_root)
			return (iterator(_super_node));
		return (iterator(_root->_parent));
	}

	const_iterator	end() const {
		if (!_root)
			return (iterator(_super_node));
		return (iterator(_root->_parent));
	}

	reverse_iterator rbegin() {
		return reverse_iterator(end());
	}

	const_reverse_iterator rbegin() const {
		return static_cast<const_reverse_iterator>(rbegin());
	}

	reverse_iterator rend() {
		return reverse_iterator(begin());
	}

	const_reverse_iterator rend() const {
		return static_cast<const_reverse_iterator>(rend());
	}

	bool empty() const {
		if (_size == 0)
			return true;
		return false;
	}

	size_type size() const {
		return _size;
	}

	size_type max_size() const {
		return std::min<size_type>(_node_alloc.max_size(), std::numeric_limits<difference_type>::max());
	}

	mapped_type& operator[] (const key_type& k) {
		return search_node(k, _root)->_val.second;
	}

	mapped_type& at (const key_type& k) {
		return this->operator[](k);
	}

	const mapped_type& at (const key_type& k) const {
		return this->operator[](k);
	}

	pair<iterator,bool> insert (const value_type& val) {
		node_pointer	curr = make_node(val);
		bool			ret;
		
		if (!_root) {
			_root = curr;
			_super_node->_left = _root;
			_root->_parent = _super_node;
			ret = true;
		} else {
			ret = append_node(_root, _root->_parent, curr);
			rotate_tree(_root);
		}
		++_size;
		return make_pair<iterator, bool>(iterator(curr), true);
	}

	iterator insert (iterator position, const value_type& val) {
		pair<iterator, bool> pair = insert(val);
		(void)position;
		// position의 부모노드를 확인하여 subtree만 돌고도 추가 가능한지 여부 체크
		// 불가능하다면 기존의 insert로 트리 전부 순회
		// 가능하다면 position의 서브 트리만 순회하여 insert
		return pair.first;
	}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		for (InputIterator it = first; it != last; ++it) {
			insert(pair<key_type, mapped_type>(*it));
		}
	}

    void erase (iterator position) {
		erase(position->first);
	}

	size_type erase (const key_type& k) {
		if (delete_node(k, _root)) {
			// rotate_tree(_root);
			return 1;
		}
		return 0;
	}

	void erase (iterator first, iterator last) {
		iterator	prev;
		while (first != last) {
			prev = first;
			first = ++first;
			erase(prev);
		}
	}

	void swap (map& x) {
		map<key_type, mapped_type> temp(x);

		x = *this;
		*this = temp;
	}

	void clear() {
		clear_map(&_root);
		delete _super_node;
		_super_node = 0;
		_size = 0;
	}

	key_compare key_comp() const {
		return _key_comp;
	}

	value_compare value_comp() const {
		return value_compare(_key_comp);
	}

	iterator find (const key_type& k) {
		node_pointer ptr = search_node(k, _root);
		if (!ptr)
			return end();
		return iterator(ptr);
	}

	const_iterator find (const key_type& k) const {
		return static_cast<const_iterator>(find(k));
	}

	size_type count (const key_type& k) const {
		iterator find = find(k);

		if (find == end()) {
			return 0;
		}
		return 1;
	}

	iterator lower_bound (const key_type& k) {
		for (iterator it = begin(); it != end(); ++it) {
			if (!_key_comp(it->first, k))
				return it;
		}
		return end();
	}

	const_iterator lower_bound (const key_type& k) const {
		for (const_iterator it = begin(); it != end(); ++it) {
			if (!_key_comp(it->first, k))
				return it;
		}
		return end();
	}

	iterator upper_bound (const key_type& k) {
		for (iterator it = begin(); it != end(); ++it) {
			if (_key_comp(k, it->first))
				return it;
		}
		return end();
	}

	const_iterator upper_bound (const key_type& k) const {
		for (const_iterator it = begin(); it != end(); ++it) {
			if (_key_comp(k, it->first))
				return it;
		}
		return end();
	}

	pair<iterator,iterator>	equal_range (const key_type& k) {
		return make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));
	}

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		return make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
	}

	allocator_type get_allocator() const {
		return _alloc;
	}
};

template <class Key, class T, class Compare, class Allocator>
void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y) {
    x.swap(y);
}

template <class Key, class T, class Compare, class Alloc>
bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs ) {
	if (lhs.size() != rhs.size()) {
		return false;
	}
	return equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs ) {
	return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs ) {
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class T, class Compare, class Alloc>
bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs ) {
	return !(rhs < lhs);
}


template <class Key, class T, class Compare, class Alloc>
bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs ) {
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs ) {
	return !(lhs < rhs);
}
}

#endif