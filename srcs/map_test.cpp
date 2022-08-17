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

template <typename Map>
void	print_map(Map& m) {
	typedef typename Map::iterator iter;
	for (iter it = m.begin(); it != m.end(); ++it) {
		std::cout << it->first << " " << it->second << '\n';
	}
}

int main()
{
	std::cout << "this is map\n";

	std::map<int, int>	m;
	ft::map<int, int> mm;

	mm.insert(ft::make_pair<int, int>(7,0));
	mm.insert(ft::make_pair<int, int>(2,1));
	mm.insert(ft::make_pair<int, int>(10,2));
	mm.insert(ft::make_pair<int, int>(8,3));
	mm.insert(ft::make_pair<int, int>(9,4));
	mm.insert(ft::make_pair<int, int>(12,5));
	mm.insert(ft::make_pair<int, int>(13,6));


	m.insert(std::make_pair<int, int>(7,0));
	m.insert(std::make_pair<int, int>(2,1));
	m.insert(std::make_pair<int, int>(10,2));
	m.insert(std::make_pair<int, int>(8,3));
	m.insert(std::make_pair<int, int>(9,4));
	m.insert(std::make_pair<int, int>(12,5));
	m.insert(std::make_pair<int, int>(13,6));

	std::map<int, int>	cp_m;
	ft::map<int, int>	cp_mm;

	cp_m = m;
	cp_mm = mm;

	print_map(cp_m);
	print_map(cp_mm);

	// std::cout << m.erase(2) << '\n';
	// std::cout << m.erase(7) << '\n';
	// std::cout << m.erase(8) << '\n';

	// std::cout << mm.erase(2) << '\n';
	// std::cout << mm.erase(7) << '\n';
	// std::cout << mm.erase(8) << '\n';

	// m.erase(m.begin(), m.end());
	// mm.erase(mm.begin(), mm.end());

	// print_map<std::map<int, int> >(m);
	// std::cout << "-----------------------------\n";
	// std::cout << "-----------------------------\n";
	// print_map<ft::map<int, int> >(mm);

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