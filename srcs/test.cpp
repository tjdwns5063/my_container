#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <vector>
// #include <algorithm>
// #include <map>
// #include <stack>
// #include <utility>

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
    std::vector<int> s;
    ft::vector<int>  ms;

    // ft::vector<int> v;

    for (int i = 0; i < 5; ++i) {
        s.push_back(i + 1);
        ms.push_back(i + 1);
    }
    auto it = s.begin();
    auto it2 = ms.begin();

    std::cout << "it: " << *it << '\n';
    std::cout << "it2: " << *it2 << '\n';
    *(it.base()) = 3;
    *(it2.base()) = 3;
    std::cout << "it: " << *it << '\n';
    std::cout << "it2: " << *it2 << '\n';
}