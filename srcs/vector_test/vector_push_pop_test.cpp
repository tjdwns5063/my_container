#include "vector_test.hpp"

void    vector_push_pop_test(void) {
    std::cout << "--------------------vector_push_pop_test-------------------------\n";
    std::vector<int> s_v;
    ft::vector<int> m_v;

    s_v.push_back(1);
    m_v.push_back(1);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";

    s_v.push_back(3);
    m_v.push_back(3);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";

    s_v.push_back(7);
    m_v.push_back(7);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";

    s_v.pop_back();
    m_v.pop_back();

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";
}

int main(void) {
    vector_push_pop_test();
}