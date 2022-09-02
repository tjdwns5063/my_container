#include "map_test.hpp"

void    map_find_test() {
    std::cout << "----------map_find_test-----------\n";
    std::map<int, int> s_m;
    ft::map<int, int> m_m;

    for (int i = 0; i < 10; ++i) {
        s_m.insert(std::make_pair(i + 1, i + 2));
        m_m.insert(ft::make_pair(i + 1, i + 2));
    }
    print_map(s_m);
    print_map(m_m);

    std::map<int, int>::iterator s_found = s_m.find(5);
    ft::map<int, int>::iterator m_found = m_m.find(5);
    std::cout << "s_found : " << s_found->first << '\n';
    std::cout << "m_found : " << m_found->first << '\n';
    s_m.erase(s_found);
    m_m.erase(m_found);
    s_found = s_m.find(8);
    m_found = m_m.find(8);
    std::cout << "s_found : " << s_found->first << '\n';
    std::cout << "m_found : " << m_found->first << '\n';
    s_m.erase(s_found);
    m_m.erase(m_found);

    print_map(s_m);
    print_map(m_m);
}

int main() {
    map_find_test();
}