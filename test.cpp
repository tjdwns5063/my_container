#include <iostream>
#include "enable_if.hpp"
#include "is_input_iterator.hpp"
#include "is_integral.hpp"
#include "vector.hpp"
#include <vector>

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
    std::vector<int> v(10, 5);
    std::vector<int> v2(5, 50);
    ft::vector<int> mv(10, 5);
    ft::vector<int> mv2(5, 50);

    // v = v2;
    // v[0] = 0;
    // v2 = v;

    v.swap(v2);
    print_vec(v);
    print_vec(v2);

    // mv2 = mv;

    // mv2[0] = 0;

    mv.swap(mv2);
    print_vec(mv);
    print_vec(mv2);

    v.clear();
    print_vec(v);
    std::cout << *(v.end() + 1) << '\n';

    mv.clear();
    print_vec(mv);
    std::cout << *(mv.end() + 1) << '\n';
}