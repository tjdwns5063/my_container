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
	ft::map<int, int> mm;

	auto pair = mm.insert(ft::make_pair<int, int>(1, 2));
	auto pair2 = mm.insert(ft::make_pair<int, int>(1, 3));
	auto pair3 = mm.insert(ft::make_pair<int, int>(0, 1));
	auto pair4 = mm.insert(ft::make_pair<int, int>(2, 3));


	m_it it = pair.first;

	std::cout << it->first << " " << it->second << '\n';
	std::cout << pair2.second << '\n';
	--it;
	std::cout << it->first << " " << it->second << '\n';
	std::cout << mm.size() << '\n';	
	std::cout << mm[0] << '\n';
}