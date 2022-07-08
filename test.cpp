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
}

int main(void) {
    ft::vector<int> v;
    ft::vector<int> mv;

    std::vector<int> temp;

    temp.push_back(3);
    temp.push_back(3);
    temp.push_back(3);
    temp.push_back(3);
    temp.push_back(3);



    // mv.assign<ft::vector<int>::iterator, 0>(temp.begin(), temp.end());
    // mv.assign(5, 3);
    // v.assign(5, 3);
    mv.assign<std::vector<int>::iterator, 0>(temp.begin(), temp.end());
    v.assign<std::vector<int>::iterator, 0>(temp.begin(), temp.end());
    

    for (int i = 0; i < 13; i++) {
        v.push_back(i + 1);
        mv.push_back(i + 1);
    }
    // std::cout << "hereee\n";
    std::cout << "v_capacity: " << v.capacity() << '\n';
    std::cout << "v_size: " << v.size() << '\n';
    print_vec(v);

    std::cout << "mv_capacity: " << mv.capacity() << '\n';
    std::cout << "mv_size: " << mv.size() << '\n';
    print_vec(mv);

    std::cout << *(v.begin().base()) << '\n';
    std::cout << *(mv.begin().base() + 12) << '\n';
}