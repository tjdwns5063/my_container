#include "vector_test.hpp"

void    vector_resize_case_less_than_current_size_test() {
    std::cout << "-------------vector_resize_case_less_than_current_size_test----------------\n";
    std::vector<int> s_v(10);
    ft::vector<int> m_v(10);

    s_v.resize(6);
    m_v.resize(6);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";


    s_v.resize(0);
    m_v.resize(0);

    print_vec(s_v);
    print_vec(m_v);
}

void vector_resize_case_larger_than_current_size_and_less_than_capacity_test() {
    std::cout << "-----vector_resize_case_larger_than_current_size_and_less_than_capacity_test----\n";
    std::vector<int> s_v;
    ft::vector<int> m_v;

    s_v.reserve(10);
    m_v.reserve(10);

    print_vec(s_v);
    print_vec(m_v); 

    s_v.resize(6);
    m_v.resize(6);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";
}

void vector_resize_case_larger_than_current_size_and_larger_than_capacity_test() {
        std::cout << "-----vector_resize_case_larger_than_current_size_and_less_than_capacity_test----\n";
    std::vector<int> s_v(10);
    ft::vector<int> m_v(10);

    print_vec(s_v);
    print_vec(m_v); 

    s_v.resize(14);
    m_v.resize(14);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";
    s_v.reserve(s_v.capacity() + 1);
    m_v.reserve(m_v.capacity() + 1);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";
}

int main(void) {
    vector_resize_case_less_than_current_size_test();
    vector_resize_case_larger_than_current_size_and_less_than_capacity_test();
    vector_resize_case_larger_than_current_size_and_larger_than_capacity_test();
}