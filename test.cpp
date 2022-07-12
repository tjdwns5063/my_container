#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector.hpp"
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

template <typename T, typename ft::enable_if<ft::is_integral<T>::value, T>::type>
void    intFunc(T num) {
    std::cout << num << '\n';
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
    std::vector<char> v(5, 'a');
    std::vector<char> v2;

    v2.push_back('a');
    v2.push_back('b');
    v2.push_back('c');

    ft::vector<char> mv(5, 'a');
    ft::vector<char> mv2;

    mv2.push_back('a');
    mv2.push_back('b');
    mv2.push_back('c');
    // for (ft::vector<char>::reverse_iterator rit = mv2.rbegin(); rit != mv2.rend(); ++rit) {
    //     std::cout << *rit << ' ';
    // }
    swap(v, v2);
    swap(mv, mv2);

    print_vec(v);
    print_vec(v2);

    print_vec(mv);
    print_vec(mv2);
}