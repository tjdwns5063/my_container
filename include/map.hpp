#ifndef MAP_HPP
# define MAP_HPP

#include <algorithm>
#include <iostream>
#include "vector.hpp"
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
		LR,
		NONE
	};

	iterator									_iter;
	node_allocator								_node_alloc;
	allocator_type								_alloc;
	key_compare									_key_comp;
	size_type									_size;
	node_pointer								_super_node;
	node_pointer								_root;



	node_pointer	make_node(value_type val) {
		node_pointer ret = NULL;
		try {
			ret = _node_alloc.allocate(1);
		} catch (std::bad_alloc& e) {
			std::cout << "alloc_error\n";
		}
		_node_alloc.construct(ret, Node<value_type>(val));
		return (ret);
	}

	void	clear_map(node_pointer root) {
		if (!root)
			return ;
		node_pointer left = root->_left;
		node_pointer right = root->_right;

		// delete (*root);
		// std::cout << "clear: " << root->_val.first << '\n';
		_node_alloc.deallocate(root, sizeof(node));
		// _node_alloc.destroy(root);
		root = 0;
		clear_map(left);
		clear_map(right);
	}

	node_pointer	search_insert_at(const value_type& val) const {
		node_pointer	node = _root;

		if (!node) {
			return _super_node;
		}
		while (node) {
			if (_key_comp(node->_val.first, val.first)) {
				if (node->_right)
					node = node->_right;
				else
					return (node);
			}
			else if (_key_comp(val.first, node->_val.first)) {
				if (node->_left)
					node = node->_left;
				else
					return (node);
			}
			else
				return (node);
		}
		return (NULL);
	}

	void	release_height(node_pointer node) {
		size_type	curr_height = node->_height;
		while (node != _super_node) {
			node->_height = std::max(curr_height, node->_height);
			node = node->_parent;
			++curr_height;
		}
	}

	void	release_height_delete(node_pointer node) {
		while (node != _super_node) {
			size_type l_h = (node->_parent->_left) ? node->_parent->_left->_height : 0;
			size_type r_h = (node->_parent->_right) ? node->_parent->_right->_height : 0;
			node->_parent->_height = std::max(l_h, r_h) + 1;
			node = node->_parent;
		}
	}

	pair<iterator, bool>	append_node(node_pointer parent, const value_type& val) {
		if (parent == _super_node) {
			_root = make_node(val);
			_root->_parent = parent;
			parent->_left = _root;
			return (ft::make_pair(iterator(_root), true));
		}
		if (_key_comp(parent->_val.first, val.first)) {
			parent->_right = make_node(val);
			parent->_right->_parent = parent;
			release_height(parent->_right);
			return (ft::make_pair(iterator(parent->_right), true));
		} else if (_key_comp(val.first, parent->_val.first)) {
			parent->_left = make_node(val);
			parent->_left->_parent = parent;
			release_height(parent->_left);
			return (ft::make_pair(iterator(parent->_left), true));
		} else {
			return (ft::make_pair(iterator(parent), false));
		}
	}

	node_pointer	search_node_iterate(const key_type& k) const {
		node_pointer	curr_root = _root;

		while (curr_root) {
			if (curr_root->_val.first == k) {
				return (curr_root);
			}
			if (_key_comp(curr_root->_val.first, k)) {
				curr_root = curr_root->_right;
			} else if (curr_root->_val.first != k) {
				curr_root = curr_root->_left;
			}
		}
		return (NULL);
	}

	e_node_child_state	node_child_cnt(node_pointer p) {
		if (p->_left && p->_right)
			return TWO;
		else if (p->_left || p->_right)
			return ONE;
		return NO;
	}

	void	delete_leaf_node(node_pointer p) {
		if (p->_parent->_left == p)
			p->_parent->_left = NULL;
		else
			p->_parent->_right = NULL;
		if (p == _root)
			_root = p->_parent->_left;
		if (node_child_cnt(p->_parent) == NO)
			release_height_delete(p);
		_node_alloc.deallocate(p, 1); // 메모리 해제
		_node_alloc.destroy(p); // 소멸자 호출
		p = 0;
		// preorder_traversal(_root);
		// std::cout << "check_end\n";
	}

	void	delete_one_child_node(node_pointer p) {
		release_height_delete(p);
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
		p = 0;
	}

	void	delete_two_child_node(node_pointer p) {
		node_pointer	min_left = p->_right;

		while (min_left->_left) {
			min_left = min_left->_left;
		}
		if (min_left != p->_right) {
			min_left->_parent->_left = min_left->_right;
			if (min_left->_right) {
				// --min_left->_right->_height;
				min_left->_right->_parent = min_left->_parent;
			}
			min_left->_right = p->_right;
			min_left->_right->_parent = min_left;
		}
		min_left->_left = p->_left;
		min_left->_left->_parent = min_left;

		if (p->_parent->_left == p) {
			min_left->_parent = p->_parent;
			min_left->_parent->_left = min_left;
		} else {
			min_left->_parent = p->_parent;
			min_left->_parent->_right = min_left;
		}
		if (p == _root) {
			_root = min_left;
		}
		min_left->_height = get_node_height(min_left);
		release_height_delete(min_left);
		// size_type l_h = (p->_right->_left) ? p->_right->_left->_height : 0;
		// size_type r_h = (p->_right->_right) ? p->_right->_right->_height : 0;
		// p->_right->_height = std::max(l_h, r_h) + 1;
		// min_left->_height = p->_right->_height + 1;
		_node_alloc.deallocate(p, 1);
		_node_alloc.destroy(p);
		p = 0;
	}

	node_pointer	delete_node(const key_type& k) {
		node_pointer searched_node = search_node_iterate(k);

		if (!searched_node)
			return NULL;
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
		// rotate_tree(k);
		return searched_node;
	}

	size_type	get_node_height(node_pointer ptr) { // 알맞은 높이를 계산.
		size_type	l_h = 0;
		size_type	r_h = 0;

		if (!ptr)
			return 0;
		if (ptr->_left)
			l_h = ptr->_left->_height;
		if (ptr->_right)
			r_h = ptr->_right->_height;
		return 1 + std::max(l_h, r_h);
	}

	difference_type	get_balanced_factor(node_pointer ptr) {
		size_type	left_h = (ptr->_left) ? ptr->_left->_height : 0;
		size_type	right_h = (ptr->_right) ? ptr->_right->_height : 0;

		return left_h - right_h;
	}

	// node_pointer	check_balanced_factor(node_pointer root, node_pointer target) {
	// 	ssize_t balanced_factor = get_balanced_factor(root);

	// 	if (!root) {
	// 		return target;
	// 	} else if (abs(balanced_factor) > 1) {
	// 		target = root;
	// 	}
	// 	target = check_balanced_factor(root->_left, target);
	// 	target = check_balanced_factor(root->_right, target);
	// 	return target;
	// }

	pair<node_pointer, difference_type>	check_balanced_factor(const key_type& k) {
		node_pointer	curr_root = _root;
		node_pointer	target = NULL;
		difference_type target_bf = 0;
		difference_type	balanced_factor = 0;

		while (curr_root && curr_root->_val.first != k) {
			balanced_factor = get_balanced_factor(curr_root);
			if (abs(balanced_factor) > 1) {
				target = curr_root;
				target_bf = balanced_factor;
			}
			if (_key_comp(curr_root->_val.first, k)) {
				curr_root = curr_root->_right;
			} else if (_key_comp(k, curr_root->_val.first)) {
				curr_root = curr_root->_left;
			}
		}
		return ft::make_pair(target, target_bf);
	}

	e_rotate_state	check_rotate_state(node_pointer target, difference_type target_bf) {
		if (target_bf > 1) {
			if (target->_left->_left)
				return (LL);
			else if (target->_left->_right)
				return (LR);
		} else if (target_bf < 1) {
			if (target->_right->_right)
				return (RR);
			else if (target->_right->_left)
				return (RL);
		}
		return (NONE);
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
		if (child->_left)
			child->_left->_height = get_node_height(child->_left);
		if (child->_right)
			child->_right->_height = get_node_height(child->_right);
		child->_height = get_node_height(child);
		child->_parent->_height = get_node_height(child->_parent);
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
		if (child->_left)
			child->_left->_height = get_node_height(child->_left);
		if (child->_right)
			child->_right->_height = get_node_height(child->_right);
		child->_height = get_node_height(child);
		child->_parent->_height = get_node_height(child->_parent);
	}

	bool	rotate_tree(const key_type& k) {
		pair<node_pointer, difference_type>	target_info = check_balanced_factor(k);

		if (!target_info.first) {
			return false;
		}
		switch (check_rotate_state(target_info.first, target_info.second)) {
			case NONE:
				return false;
			case LL:
				// std::cout << "LL\n";
				rotate_right(target_info.first);
				break ;
			case RR:
				// std::cout << "RR\n";
				rotate_left(target_info.first);
				break ;
			case LR:
				// std::cout << "LR\n";
				rotate_left(target_info.first->_left);
				rotate_right(target_info.first);
				break ;
			case RL:
				// std::cout << "RL\n";
				rotate_right(target_info.first->_right);
				rotate_left(target_info.first);
				break ;
		}
		return true;
	}

public:
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

	~map() { clear(); }


	map& operator= (const map& x) {
		// std::cout << "assign constructor called\n";
		// if (*this == x)
		// 	return (*this);
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

	void	preorder_traversal(node_pointer root) {
		if (!root)
			return ;
		std::cout << "key: " << root->_val.first << " value: " << root->_val.second << " height: " << root->_height << '\n';
		preorder_traversal(root->_left);
		preorder_traversal(root->_right);
	}

	node_pointer	get_root(void) const {
		return (_root);
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
		return (iterator(_super_node));
	}

	const_iterator	end() const {
		return (iterator(_super_node));
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
		node_pointer	searched = search_node_iterate(k);
		value_type		value = ft::make_pair(k, mapped_type());

		if (searched) {
			return searched->_val.second;
		}
		pair<iterator, bool> insert_ret = insert(value);
		return insert_ret.first->second;
	}

	mapped_type& at (const key_type& k) {
		return this->operator[](k);
	}

	const mapped_type& at (const key_type& k) const {
		return this->operator[](k);
	}

	pair<iterator,bool> insert (const value_type& val) {
		node_pointer			insert_at;
		pair<iterator, bool>	ret;

		insert_at = search_insert_at(val);
		ret = append_node(insert_at, val);
		if (ret.second) {
			++_size;
			rotate_tree(val.first);
		}
		return (ret);
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
		if (delete_node(k)) {
			--_size;
			rotate_tree(k);
			return 1;
		}
		return 0;
	}

	void erase (iterator first, iterator last) {
		iterator prev;

		while (first != last) {
			prev = first;
			++first;
			if (delete_node(prev->first)) {
				--_size;
				rotate_tree(first->first);
			}
		}
	}

	void swap (map& x) {
		node_pointer	temp_root = x._root;
		node_pointer	temp_super_node = x._super_node;
		size_type		temp_size = x._size;

		x._root = this->_root;
		x._super_node = this->_super_node;
		x._size = this->_size;
		this->_super_node = temp_super_node;
		this->_root = temp_root;
		this->_size = temp_size;
	}

	void clear() {
		clear_map(_root);
		_node_alloc.deallocate(_super_node, sizeof(node));
		_root = 0;
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
		node_pointer ptr = search_node_iterate(k);
		if (!ptr)
			return end();
		return iterator(ptr);
	}

	const_iterator find (const key_type& k) const {
		node_pointer ptr = search_node_iterate(k);
		if (!ptr)
			return end();
		return iterator(ptr);
	}

	size_type count (const key_type& k) const {
		const_iterator found_iter = find(k);

		if (found_iter == end()) {
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
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs ) {
	return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
                    const map<Key,T,Compare,Alloc>& rhs ) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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