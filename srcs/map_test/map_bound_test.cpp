#include "map_test.hpp"

std::map<int, std::string> s_m;
ft::map<int, std::string> m_m;

typedef std::map<int, std::string>::iterator s_it;
typedef ft::map<int, std::string>::iterator m_it;

void    map_bound_test() {
    for (int i = 0; i < 10; ++i) {
        s_m.insert(std::make_pair(i, std::string(1, i + 'a')));
        m_m.insert(ft::make_pair(i, std::string(1, i + 'a')));
    }

    s_it s_begin = s_m.lower_bound(2); // point at 2
    m_it m_begin = m_m.lower_bound(2);
    s_it s_end = s_m.upper_bound(7); // point at 8
    m_it m_end = m_m.upper_bound(7);

    s_m.erase(s_begin, s_end);
    print_map(s_m);
    std::cout << "----------------------------------------------\n";
    m_m.erase(m_begin, m_end);
    print_map(m_m);
    std::cout << "----------------------------------------------\n";
}

int main() {
    map_bound_test();
}