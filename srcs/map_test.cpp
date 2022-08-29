#include <map>
#include <iostream>
#include <utility>
#include "pair.hpp"
#include <__tree>
#include <memory>
#include <list>
#include <iterator>
// #include "iterator.hpp"
#include "map.hpp"
// #include "node.hpp"

typedef	std::map<int, int>::iterator s_it;
typedef	std::map<int, int>::const_iterator s_cit;
typedef	std::map<int, int>::reverse_iterator s_rit;
typedef	std::map<int, int>::const_reverse_iterator s_crit;

typedef ft::map<int, int>::iterator	m_it;
typedef ft::map<int, int>::const_iterator	m_cit;
// typedef ft::map<int, int>::reverse_iterator	m_rit;
// typedef ft::map<int, int>::const_reverse_iterator m_crit;

template <typename Map>
void	print_map(Map& m) {
	typedef typename Map::iterator iter;
	for (iter it = m.begin(); it != m.end(); ++it) {
		std::cout << it->first << " " << it->second << '\n';
	}
}

void	preorder_traversal(ft::Node<ft::pair<const int, int> >* root) {
	if (!root)
		return ;
	std::cout << root->_val.first << " " << root->_val.second << '\n';
	preorder_traversal(root->_left);
	preorder_traversal(root->_right);
}

int main()
{
	std::list<ft::pair<int,int> > lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(ft::make_pair(i + 1, (i + 1) * 3));

	// ft::map<int, int> mm(lst.begin(), lst.end());

	ft::map<int, int> m;

	m.insert(ft::make_pair(1, 3));
	m.insert(ft::make_pair(2, 6));
	m.insert(ft::make_pair(3, 9));
	m.insert(ft::make_pair(4, 12));
	m.insert(ft::make_pair(5, 15));
	m.insert(ft::make_pair(6, 18));
	m.insert(ft::make_pair(7, 21));
	// m.insert(ft::make_pair(8, 24));
	// m.insert(ft::make_pair(9, 27));
	// m.insert(ft::make_pair(10, 30));

	for (m_cit it = m.begin(); it != m.end(); ++it) {
		std::cout << it->first << " " << it->second << '\n';
	}

	preorder_traversal(m._root);
}