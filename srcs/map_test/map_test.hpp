#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

#include <map>
#include <__tree>
#include <iostream>
#include "map.hpp"

template <typename MAP>
void    print_map(MAP& map) {
    typedef typename MAP::iterator  iter;
    std::cout << "size: " << map.size() << '\n';

    std::cout << "[ ";
    for (iter it = map.begin(); it != map.end(); ++it) {
        std::cout << "( " << it->first << " " << it->second << " ) ";
    }
    std::cout << "]\n";
}

#endif