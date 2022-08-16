#ifndef MAP_HPP
# define MAP_HPP

#include <__tree>
#include <algorithm>
#include "iterator.hpp"

namespace ft {

template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Allocator = std::allocator<pair<const Key,T> > >    // map::allocator_type 
class map {
public:
    typedef Key                                      key_type;
    typedef T                                        mapped_type;
    typedef pair<const key_type, mapped_type>        value_type;
    typedef Compare                                  key_compare;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;

    typedef map_iterator<value_type>					iterator;
    typedef const map_iterator<value_type>              const_iterator;
    typedef reverse_iterator<iterator>					reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    	const_reverse_iterator;


private:
	typedef typename iterator::node_type		node;
	typedef typename iterator::node_pointer		node_pointer;
	typedef std::allocator<node>				node_allocator;

	iterator									_iter;
	node_allocator								_node_alloc;
	allocator_type								_alloc;
	key_compare									_key_comp;
	size_type									_size;
	node_pointer								_super_node;

	node_pointer	make_node(value_type val) {
		node_pointer ret = _node_alloc.allocate(1);
		// value_type	container = make_pair<int, int>(k, v);
		_node_alloc.construct(ret, Node<value_type>(val));
		return (ret);
	}

	node_pointer	append_node(node_pointer root, node_pointer ptr) {
		if (!root) {
			return ptr;
		}
		if (root->_val.first > ptr->_val.first) {
			root->_left = append_node(root->_left, ptr);
			root->_left->_parent = root;
			return root->_left;
		}
		else if (root->_val.first < ptr->_val.first) {
			root->_right = append_node(root->_right, ptr);
			root->_right->_parent = root;
			return root->_right;
		}
		return NULL;
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
		return root;
	}

public:
	node_pointer	_root;

	explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
			  : _alloc(alloc), _key_comp(comp), _size(0), _super_node(NULL), _root(NULL) {}
	
	// template <class InputIterator>
	// map (InputIterator first, InputIterator last,
    //    const key_compare& comp = key_compare(),
    //    const allocator_type& alloc = allocator_type())
	//    : _alloc(alloc), _key_comp(comp), _size(0), _root(NULL) {}

	// map (const map& x): _alloc(x._alloc), _key_comp(x._key_comp), _size(x._size) {
	// 	//insert(x.begin(), x.end());
	// }

	~map() {}


	map& operator= (const map& x) {
		if (*this != x) {
			_alloc = x._alloc;
			_key_comp = x._key_comp;
			_size = x._size;
			// insert(x.begin(), x.end());
		}
		return (*this);
	}

	iterator begin() {
		node_pointer root = _root;

		while (root->_left) {
			root = root->_left;
		}
		return iterator(root);
	}

	const_iterator begin() const {
		return static_cast<const_iterator>(begin());
	}

	iterator end() {
		return (iterator(_root->_parent));
	}

	const_iterator	end() const {
		return static_cast<const_iterator>(end());
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
		if (_size != 0)
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

	pair<iterator,bool> insert (const value_type& val) {
		node_pointer	root = append_node(_root, make_node(val));

		if (_size == 0) {
			_root = root;
		}
		if (!root) {
			return make_pair<iterator, bool>(iterator(root), false);
		} else {
			++_size;
			return make_pair<iterator, bool>(iterator(root), true);
		}
	}

	iterator insert (iterator position, const value_type& val);

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last);

    void erase (iterator position);

	size_type erase (const key_type& k);

	void erase (iterator first, iterator last);

	void swap (map& x);

	void clear();

	key_compare key_comp() const;

	// value_compare value_comp() const;

	iterator find (const key_type& k) {
		iterator ret = iterator(search_node(k, _root));
		return ret;
	}

	// const_iterator find (const key_type& k) const;

	size_type count (const key_type& k) const;

	iterator lower_bound (const key_type& k);

	// const_iterator lower_bound (const key_type& k) const;

	iterator upper_bound (const key_type& k);

	// const_iterator upper_bound (const key_type& k) const;

	// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

	pair<iterator,iterator>             equal_range (const key_type& k);

	allocator_type get_allocator() const {
		return _alloc;
	}
};
}


#endif