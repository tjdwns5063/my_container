#include "map_test.hpp"

void    map_swap_test() {
    std::map<int, int> s_m1;
    ft::map<int, int> m_m1;
    std::map<int, int> s_m2;
    ft::map<int, int> m_m2;

    for (int i = 0; i < 5; ++i) {
        s_m1[i + 1] = i + 1;
        m_m1[i + 1]= i + 1;
    }

    std::map<int, int>::iterator before_sit = s_m1.begin();
    ft::map<int, int>::iterator before_mit = m_m1.begin();

    swap(s_m1, s_m2);
    swap(m_m1, m_m2);
    print_map(s_m1);
    print_map(m_m1);
    print_map(s_m2);
    print_map(m_m2);
    std::cout << std::boolalpha << "iterator_validity: [STD]=" << (before_sit == s_m2.begin()) << '\n';
    std::cout << std::boolalpha << "iterator_validity: [FT]=" << (before_mit == m_m2.begin()) << '\n';
}

int main() {
    map_swap_test();
}