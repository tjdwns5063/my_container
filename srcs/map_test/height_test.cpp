#include "map.hpp"
#include <iostream>

int main(void) {
    ft::map<int, int> m;

    for (int i = 5; i >= 0; --i) {
        m.insert(ft::make_pair(i * 2 + 1, i + 1));
    }
    m.insert(ft::make_pair(8, 1));
    m.insert(ft::make_pair(6, 1));
    m.preorder_traversal(m.get_root());

    m.erase(5);
    std::cout << "-----------------------------------------\n";
    m.preorder_traversal(m.get_root());
}