#include "vector_test.hpp"

void    assign_empty_test(void) {
    std::cout << "--------------------assign to empty vector-------------------------\n";
    std::vector<int> s_v;
    ft::vector<int> m_v;

    s_v.assign(5, 5);
    m_v.assign(5, 5);

    print_vec(s_v);
    print_vec(m_v);

}

void    assign_less_than_capacity_test(void) {
    std::cout << "----------assign to vector that is less than capacity--------------\n";
    std::vector<int> s_v(10);
    ft::vector<int> m_v(10);

    s_v.assign(5, 5);
    m_v.assign(5, 5);

    print_vec(s_v);
    print_vec(m_v);
}

void    assign_more_than_capacity_test(void) {
    std::cout << "----------assign to vector that is more than capacity--------------\n";
    std::vector<int> s_v(5);
    ft::vector<int> m_v(5);

    s_v.assign(10, 5);
    m_v.assign(10, 5);

    print_vec(s_v);
    print_vec(m_v);
}

int main(void) {
    assign_empty_test();
    assign_less_than_capacity_test();
    assign_more_than_capacity_test();
}