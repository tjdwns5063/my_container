#include <map>
#include <iostream>
// #include <utility>
#include "pair.hpp"
#include <__tree>
#include <memory>
// #include "iterator.hpp"
#include "map.hpp"
// #include "node.hpp"

typedef	std::map<int, int>::iterator s_it;
typedef	std::map<int, int>::reverse_iterator s_rit;

typedef ft::map<int, int>::iterator	m_it;
typedef ft::map<int, int>::reverse_iterator	m_rit;

int main()
{
	std::cout << "this is map\n";

	std::map<int, int>	m;
	// ft::map<int, int> mm;
	m.insert(std::make_pair(5, 1));
	m.insert(std::make_pair(3, 2));
	m.insert(std::make_pair(6, 3));
	m.insert(std::make_pair(1, 4));
	m.insert(std::make_pair(4, 5));

	// for (s_it it = --m.end(); it != --m.begin(); --it) {
		// std::cout << it->first << '\n';
	// }

	for (s_rit rit = m.rbegin(); rit != m.rend(); --rit) {
		std::cout << rit->first << '\n';
	}
}