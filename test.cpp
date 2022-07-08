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
    for (typename T::iterator it = vec.begin(); it < vec.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}

int main(void) {
    std::vector<int> temp;

    temp.push_back(5);
    temp.push_back(4);
    temp.push_back(3);
    temp.push_back(2);
    temp.push_back(1);
    ft::vector<int> mv;
    std::vector<int> v;

    // std::cout << std::boolalpha << ft::is_input_iterator<std::vector<int>::iterator>::value << '\n';
    mv.assign<std::vector<int>::iterator, 0>(temp.begin(), temp.end());
    v.assign(temp.begin(), temp.end());

    std::cout << "v_capacity: " << v.capacity() << '\n';
    std::cout << "v_size: " << v.size() << '\n';
    print_vec(v);

    std::cout << "mv_capacity: " << mv.capacity() << '\n';
    std::cout << "mv_size: " << mv.size() << '\n';
    print_vec(mv);
}