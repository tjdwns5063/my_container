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
typedef	std::map<int, int>::const_iterator s_cit;
typedef	std::map<int, int>::reverse_iterator s_rit;
typedef	std::map<int, int>::const_reverse_iterator s_crit;

typedef ft::map<int, int>::iterator	m_it;
typedef ft::map<int, int>::const_iterator	m_cit;
typedef ft::map<int, int>::reverse_iterator	m_rit;
typedef ft::map<int, int>::const_reverse_iterator m_crit;

int main()
{
	std::cout << "this is map\n";

	std::map<int, int>	m;
	ft::map<int, int> mm;
	ft::map<int, int>	cp_mm;

	mm.insert(ft::make_pair<int, int>(0,1));
	mm.insert(ft::make_pair<int, int>(1,2));
	mm.insert(ft::make_pair<int, int>(2,3));

	cp_mm.insert(mm.begin(), mm.end());

	for (m_it it = cp_mm.begin(); it != cp_mm.end(); ++it) {
		std::cout << it->first << " " << it->second << '\n';
	}

	m.insert(std::make_pair(0,1));
	m.insert(std::make_pair(1,2));
	m.insert(std::make_pair(2,3));


	// std::cout << "standart: " << m.lower_bound(1)->first << '\n';
	// std::cout << "standart: " << m.upper_bound(1)->first << '\n';

	// std::cout << "standart: " << m.lower_bound(2)->first << '\n';
	// std::cout << "standart: " << m.upper_bound(2)->first << '\n';

	// std::cout << "standart: " << m.equal_range(1).first->first << '\n';
	// std::cout << "standart: " << m.equal_range(1).second->first << '\n';

	// std::cout << "standart: " << m.equal_range(2).first->first << '\n';
	// std::cout << "standart: " << m.equal_range(2).second->first << '\n';


	// std::cout << "standart: " << mm.lower_bound(1)->first << '\n';
	// std::cout << "standart: " << mm.upper_bound(1)->first << '\n';

	// std::cout << "standart: " << mm.lower_bound(2)->first << '\n';
	// std::cout << "standart: " << mm.upper_bound(2)->first << '\n';

	// std::cout << "standart: " << mm.equal_range(1).first->first << '\n';
	// std::cout << "standart: " << mm.equal_range(1).second->first << '\n';

	// std::cout << "standart: " << mm.equal_range(2).first->first << '\n';
	// std::cout << "standart: " << mm.equal_range(2).second->first << '\n';

	// std::cout << mm.end()->first << '\n';
}