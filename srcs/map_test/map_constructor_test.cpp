#include "map_test.hpp"

void copy_construct_test(void) {
    std::map<int, int> s_m;
    ft::map<int, int> m_m;

    for (int i = 0; i < 10; ++i) {
        s_m.insert(std::make_pair(i, i + 1));
        m_m.insert(ft::make_pair(i, i + 1));
    }
    std::map<int, int> s_cpy(s_m);
    std::map<int, int> s_range(s_m.begin(), --(--s_m.end()));

    ft::map<int, int> m_cpy(m_m);
    ft::map<int, int> m_range(m_m.begin(), --(--m_m.end()));

    print_map(s_m);
    print_map(s_cpy);
    print_map(s_range);

    print_map(m_m);
    print_map(m_cpy);
    print_map(m_range);
    
    // s_range.clear();
    m_m = m_cpy;
    m_cpy = m_range;
    m_m.clear();

    print_map(m_m);
    print_map(m_cpy);
    print_map(m_range);
}

int main(void) {
    copy_construct_test();
}