#ifndef MAP_HPP
# define MAP_HPP

#include <algorithm>
#include "iterator.hpp"

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
    typedef const map_iterator<value_type>              const_iterator;
    typedef ft::reverse_iterator<iterator>					reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

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

	void	clear_map(node_pointer* root) {
		if (!(*root))
			return ;
		node_pointer temp = *root;
		delete (*root);
		*root = 0;
		clear_map(&temp->_left);
		clear_map(&temp->_right);
	}

	bool	append_node(node_pointer* root, node_pointer parent, node_pointer ptr) {
		if (!(*root)) {
			*root = ptr;
			(*root)->_parent = parent;
			return true;
		}
		if ((*root)->_val.first > ptr->_val.first) {
			return append_node(&(*root)->_left, *root, ptr);
		}
		else if ((*root)->_val.first < ptr->_val.first) {
			return append_node(&(*root)->_right, *root, ptr);
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
		return root;
	}

public:
	node_pointer	_root;

	explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
			  : _alloc(alloc), _key_comp(comp), _size(0), _super_node(make_node(pair<key_type, mapped_type>())), _root(NULL) {}
	
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
		if (!root)
			return iterator(_super_node);

		while (root->_left) {
			root = root->_left;
		}
		return iterator(root);
	}

	const_iterator begin() const {
		return static_cast<const_iterator>(begin());
	}

	iterator end() {
		if (!_root)
			return (iterator(_super_node));
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
			ret = append_node(&_root, _root->_parent, curr);
		}
		++_size;
		return make_pair<iterator, bool>(iterator(curr), true);
	}

	iterator insert (iterator position, const value_type& val) {
		
	}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		for (iterator it = first; it != last; ++it) {
			insert(pair<key_type, mapped_type>(*it));
		}
	}

    void erase (iterator position);

	size_type erase (const key_type& k);

	void erase (iterator first, iterator last);

	void swap (map& x);

	void clear() {
		clear_map(&_root);
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
		if (ptr == _root)
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
		return static_cast<const_iterator>(lower_bound(k));
	}

	iterator upper_bound (const key_type& k) {
		for (iterator it = begin(); it != end(); ++it) {
			if (_key_comp(k, it->first))
				return it;
		}
		return end();
	}

	const_iterator upper_bound (const key_type& k) const {
		return static_cast<const_iterator>(upper_bound(k));
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

}

#endif