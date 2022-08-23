#include <vector>
#include "vector.hpp"

template <typename VEC>
void    print_vec(VEC& vec) {
    std::cout << "size: " << vec.size() << '\n';
    std::cout << "capacity: " << vec.capacity() << '\n';

    std::cout << "[";
    for (typename VEC::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << ' ' << *it << ' ';
    }
    std::cout << "]\n\n";
}