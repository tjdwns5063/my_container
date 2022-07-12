#include <iostream>
#include "enable_if.hpp"
#include "is_input_iterator.hpp"
#include "is_integral.hpp"
#include "vector.hpp"
#include <vector>
#include <algorithm>

template <typename T, typename ft::enable_if<ft::is_integral<T>::value, T>::type>
void    intFunc(T num) {
    std::cout << num << '\n';
}

template <typename It, typename ft::enable_if<ft::is_input_iterator<It>::value, int>::type>
void    iterFunc(It it, It it2) {
    std::cout << "iterFunc\n";
}

template <typename T>
void    print_vec(T& vec) {
    for (typename T::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
    std::cout << "capacitiy : " << vec.capacity() << '\n';
    std::cout << "size : " << vec.size() << '\n';
}

int main(void) {
    std::vector<int> v(5, 5);
    std::vector<int> v2(5, 5);
    ft::vector<int> mv(5, 5);
    ft::vector<int> mv2(5, 5);

    mv.assign<ft::vector<int>::iterator, 0>(mv2.begin(), mv2.end());
}