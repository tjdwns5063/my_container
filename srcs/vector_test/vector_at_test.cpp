#include "vector_test.hpp"

void    at_test(void) {
    std::vector<int> s_v(10);
    ft::vector<int> m_v(10);

    for (size_t i = 0; i < s_v.size(); ++i) {
        s_v.at(i) = i + 1;
        m_v.at(i) = i + 1;
    }
    print_vec(s_v);
    print_vec(m_v);

    std::cout << "m_v.front(): " << m_v.front() << '\n';
    std::cout << "m_v.back(): " << m_v.back() << '\n';

    try {
        m_v.at(15);
    } catch (std::out_of_range& e) {
        std::cout << "exception called\n";
    }

    const std::vector<int> c_s_v(s_v);
    const ft::vector<int> c_m_v(m_v);

    // c_s_v.at(0) = 0;
    // c_m_v.at(0) = 0;
    std::cout << "c_m_v.front(): " << c_m_v.front() << '\n';
    std::cout << "c_m_v.back(): " << c_m_v.back() << '\n';
}

int main(void) {
    at_test();
}