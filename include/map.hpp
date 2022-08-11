#ifndef MAP_HPP
# define MAP_HPP

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

    typedef map_iterator<value_type>                 iterator;
    // typedef implementation-defined                   const_iterator;
    // typedef std::reverse_iterator<iterator>          reverse_iterator;
    // typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;


private:
	typedef typename iterator::node_type		node;
	typedef typename iterator::node_pointer		node_pointer;
	typedef std::allocator<node>				node_allocator;

	iterator									_iter;
	node_allocator								_node_alloc;
	allocator_type								_alloc;
	key_compare									_key_comp;
	size_type									_size;

	node_pointer	make_node(key_type k, mapped_type v) {
		node_pointer ret = _node_alloc.allocate(1);
		value_type	container = make_pair<int, int>(k, v);
		_node_alloc.construct(ret, Node<value_type>(container));
		return (ret);
	}

	node_pointer	append_node(node_pointer root, node_pointer ptr) {
		if (!root)
			return ptr;
		if (root->_val.first > ptr->_val.first)
			root->_left = append_node(root->_left, ptr);
		if (root->_val.first < ptr->_val.first)
			root->_right = append_node(root->_right, ptr);
		return root;
	}

public:
	node_pointer	_root;

	explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
			  : _alloc(alloc), _key_comp(comp), _size(0), _root(NULL) {}
	
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

	iterator begin();

	// const_iterator begin() const;

	// reverse_iterator rbegin();

	// const_reverse_iterator rbegin() const;

	// reverse_iterator rend();

	// const_reverse_iterator rend() const;

	bool empty() const {
		if (_size != 0)
			return true;
		return false;
	}

	size_type size() const {
		return _size;
	}

	size_type max_size() const;

	mapped_type& operator[] (const key_type& k);

	pair<iterator,bool> insert (const value_type& val);

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

	iterator find (const key_type& k);

	// const_iterator find (const key_type& k) const;

	size_type count (const key_type& k) const;

	iterator lower_bound (const key_type& k);

	// const_iterator lower_bound (const key_type& k) const;

	iterator upper_bound (const key_type& k);

	// const_iterator upper_bound (const key_type& k) const;

	// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

	pair<iterator,iterator>             equal_range (const key_type& k);

	allocator_type get_allocator() const;
};
}


#endif