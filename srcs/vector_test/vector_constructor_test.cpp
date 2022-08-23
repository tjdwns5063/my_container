#include "vector_test.hpp"

void    vector_default_consturctor_test(void) {
    std::cout << "--------------------vector_default_constructor_test-------------------------\n";
    std::vector<std::string> s_v;
    ft::vector<std::string> m_v;

    print_vec(s_v);
    print_vec(m_v);
}

void    vector_fill_constructor_test(void) {
    std::cout << "--------------------vector_fill_constructor_test-------------------------\n";
    std::vector<std::string> s_v(10, "fill");
    ft::vector<std::string> m_v(10, "fill");

    print_vec(s_v);
    print_vec(m_v);
}

void    vector_range_constructor_test(void) {
    std::cout << "--------------------vector_range_constructor_test-------------------------\n";
    std::vector<std::string> origin_s_v(10, "origin");
    ft::vector<std::string> origin_m_v(10, "origin");

    std::vector<std::string> s_v(origin_s_v.begin(), origin_s_v.end());
    ft::vector<std::string> m_v(origin_m_v.begin(), origin_m_v.end());

    print_vec(s_v);
    print_vec(m_v);
}

void    vector_copy_constructor_test(void) {
    std::cout << "--------------------vector_copy_constructor_test-------------------------\n";
    std::vector<std::string> origin_s_v(10, "origin");
    ft::vector<std::string> origin_m_v(10, "origin");
    
    std::vector<std::string> a_s_v = origin_s_v;
    ft::vector<std::string> a_m_v = origin_m_v;

    print_vec(a_s_v);
    print_vec(a_m_v);

    std::vector<std::string> c_s_v(origin_s_v);
    ft::vector<std::string> c_m_v(origin_m_v);

    print_vec(c_s_v);
    print_vec(c_m_v);
}

int main(void) {
    vector_default_consturctor_test();
    vector_fill_constructor_test();
    vector_range_constructor_test();
    vector_copy_constructor_test();
}