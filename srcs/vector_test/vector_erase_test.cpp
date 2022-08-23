#include "vector_test.hpp"

void    vector_erase_one_item_test(void) {
    std::cout << "--------------------vector_erase_single_elem_test-------------------------\n";

    std::vector<std::string> s_v;
    ft::vector<std::string> m_v;

    s_v.assign(5, "item");
    m_v.assign(5, "item");

    for (int i = 0; i < 5; ++i) {
        s_v[i] += (i + '1');
        m_v[i] += (i + '1');
    }

    print_vec(s_v);
    print_vec(m_v);

    std::vector<std::string> c_s_v(s_v);
    ft::vector<std::string> c_m_v(m_v);

    c_s_v.erase(c_s_v.begin() + 4);
    c_m_v.erase(c_m_v.begin() + 4);

    print_vec(c_s_v);
    print_vec(c_m_v);

    c_s_v.erase(c_s_v.begin() + 2);
    c_m_v.erase(c_m_v.begin() + 2);
    
    print_vec(c_s_v);
    print_vec(c_m_v);

    c_s_v.erase(c_s_v.begin());
    c_m_v.erase(c_m_v.begin());

    print_vec(c_s_v);
    print_vec(c_m_v);
}

void    vector_erase_range_test(void) {
    std::cout << "--------------------vector_erase_range_test-------------------------\n";
    std::vector<std::string> s_v(10);
    ft::vector<std::string> m_v(10);

    for (int i = 0; i < 10; ++i) {
        s_v[i] = i +'A';
        m_v[i] = i+'A';
    }
    //A B C D E F G H I J
    s_v.erase(s_v.begin() + 2);
    m_v.erase(m_v.begin() + 2);

    print_vec(s_v);
    print_vec(m_v);
    // A B D E F G H I J

    s_v.erase(s_v.begin());
    m_v.erase(m_v.begin());
    // B D E F G H I J

    print_vec(s_v);
    print_vec(m_v);

    s_v.erase(s_v.end() - 1);
    m_v.erase(m_v.end() - 1);
    // B D E F G H I
    print_vec(s_v);
    print_vec(m_v);

    s_v.erase(s_v.begin(), s_v.begin() + 3);
    m_v.erase(m_v.begin(), m_v.begin() + 3);
    // F G H I
    print_vec(s_v);
    print_vec(m_v);

    s_v.erase(s_v.end() - 3, s_v.end() - 1);
    m_v.erase(m_v.end() - 3, m_v.end() - 1);
    // F I
    print_vec(s_v);
    print_vec(m_v);

    s_v.erase(s_v.end() - 3, s_v.end());
    m_v.erase(m_v.end() - 3, m_v.end());

    print_vec(s_v);
    print_vec(m_v);
}

int main(void) {
    vector_erase_one_item_test();
    vector_erase_range_test();
}