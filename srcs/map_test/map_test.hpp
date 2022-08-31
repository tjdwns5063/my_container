#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

#include <map>
#include <iostream>
#include <sys/time.h>
#include "map.hpp"

template <typename MAP>
void    print_map(MAP& map) {
    typedef typename MAP::iterator  iter;
    std::string map_type;

    map_type = (typeid(map).name() == typeid(std::map<typename MAP::key_type, typename MAP::mapped_type>).name()) ? "STD" : "FT";
    std::cout << "[ " << map_type  << " ]\n";

    std::cout << "size: " << map.size() << '\n';
    std::cout << "[ ";
    for (iter it = map.begin(); it != map.end(); ++it) {
        std::cout << "( " << it->first << " " << it->second << " ) ";
    }
    std::cout << "]\n";
}

#endif