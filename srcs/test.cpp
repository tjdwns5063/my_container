#include <iostream>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
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
    std::stack<int> s;
    ft::stack<int>  ms;

    // ft::vector<int> v;
    s.push(1);
    ms.push(1);
    std::cout << s.size() << '\n';
    std::cout << ms.size() << '\n';
    std::cout << s.empty() << '\n';
    std::cout << ms.empty() << '\n';
    s.push(2);
    ms.push(2);
    std::cout << s.top() << '\n';
    std::cout << ms.top() << '\n';
    s.pop();
    ms.pop();
    std::cout << s.top() << '\n';
    std::cout << ms.top() << '\n';
    std::cout << s.size() << '\n';
    std::cout << ms.size() << '\n';
    s.pop();
    ms.pop();
    std::cout << s.size() << '\n';
    std::cout << ms.size() << '\n';
    std::cout << s.empty() << '\n';
    std::cout << ms.empty() << '\n';
}