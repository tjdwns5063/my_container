#include <vector>
#include <iostream>
#include <sys/time.h>
#include "vector.hpp"

template <typename VEC>
void    print_vec(VEC& vec) {
    std::string vec_type;

    vec_type = (typeid(vec).name() == typeid(std::vector<typename VEC::value_type>).name()) ? "STD" : "FT";
    std::cout << "[ " << vec_type  << " ]\n";

    std::cout << "size: " << vec.size() << '\n';
    std::cout << "capacity: " << vec.capacity() << '\n';

    std::cout << "[";
    for (typename VEC::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << ' ' << *it << ' ';
    }
    std::cout << "]\n\n";
}