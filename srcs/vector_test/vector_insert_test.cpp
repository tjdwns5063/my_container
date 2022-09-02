#include "vector_test.hpp"

template <typename VEC, typename A1, typename A2, typename A3>
void    vector_insert_execute(VEC& vec, A1 arg1, A2 arg2, A3 arg3) {
    struct timeval start;
    struct timeval end;
    long    micro_sec;
    std::string vec_type;

    vec_type = (typeid(vec).name() == typeid(std::vector<typename VEC::value_type>).name()) ? "STD" : "FT";
    std::cout << "[ " << vec_type  << " ]\n";
    gettimeofday(&start, NULL);
    vec.insert(arg1, arg2, arg3);
    gettimeofday(&end, NULL);
    micro_sec = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    std::cout << "micro sec: " << micro_sec << "us\n";
}

void    vector_insert_single_elem_test(void) {
    std::cout << "--------------------vector_insert_single_elem_test-------------------------\n";
    std::vector<int> s_v;
    ft::vector<int> m_v;
    std::vector<int>::iterator s_it;
    ft::vector<int>::iterator m_it;


    s_it = s_v.insert(s_v.begin(), 1);
    m_it = m_v.insert(m_v.begin(), 1);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "*s_it: " << *s_it << '\n';
    std::cout << "*m_it: " << *m_it << '\n';
    std::cout << "-----------------------------\n";

    s_it = s_v.insert(s_v.begin(), 2);
    m_it = m_v.insert(m_v.begin(), 2);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "*s_it: " << *s_it << '\n';
    std::cout << "*m_it: " << *m_it << '\n';
    std::cout << "-----------------------------\n";

    s_it = s_v.insert(s_v.begin() + 1, 4);
    m_it = m_v.insert(m_v.begin() + 1, 4);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "*s_it: " << *s_it << '\n';
    std::cout << "*m_it: " << *m_it << '\n';
    std::cout << "-----------------------------\n";

    s_it = s_v.insert(s_v.begin() + 1, 3);
    m_it = m_v.insert(m_v.begin() + 1, 3);

    print_vec(s_v);
    print_vec(m_v);
    std::cout << "*s_it: " << *s_it << '\n';
    std::cout << "*m_it: " << *m_it << '\n';
}

void    vector_insert_fill_test(void) {
    std::cout << "--------------------vector_insert_fill_test-------------------------\n";
    std::vector<int> s_v;
    ft::vector<int> m_v;

    s_v.insert(s_v.begin(), 3, 4);
    m_v.insert(m_v.begin(), 3, 4);
    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";

    s_v.insert(s_v.begin() + 1, 2, 2);
    m_v.insert(m_v.begin() + 1, 2, 2);
    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";

    s_v.insert(s_v.begin() + 4, 1, 5);
    m_v.insert(m_v.begin() + 4, 1, 5);
    print_vec(s_v);
    print_vec(m_v);
    std::cout << "------vector_fill_insert_performance_test-------\n";
    vector_insert_execute(s_v, s_v.end(), 1000, 3);
    vector_insert_execute(m_v, m_v.end(), 1000, 3);
}

void    vector_insert_range_test(void) {
    std::cout << "--------------------vector_insert_range_test-------------------------\n";
    std::vector<int> s_v;
    ft::vector<int> m_v;

    std::vector<int> origin_s_v(10);
    ft::vector<int> origin_m_v(10);

    for (int i = 0; i < 10; ++i) {
        origin_s_v[i] = i;
        origin_m_v[i] = i;
    }

    s_v.insert(s_v.begin(), origin_s_v.begin(), origin_s_v.begin() + 3);
    m_v.insert(m_v.begin(), origin_m_v.begin(), origin_m_v.begin() + 3);
    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";

    s_v.insert(s_v.begin() + 2, origin_s_v.begin() + 3, origin_s_v.begin() + 6);
    m_v.insert(m_v.begin() + 2, origin_m_v.begin() + 3, origin_m_v.begin() + 6);
    print_vec(s_v);
    print_vec(m_v);
    std::cout << "-----------------------------\n";

    s_v.insert(s_v.begin() + 5, origin_s_v.end() - 4, origin_s_v.end());
    m_v.insert(m_v.begin() + 5, origin_m_v.end() - 4, origin_m_v.end());
    print_vec(s_v);
    print_vec(m_v);

    std::vector<int> s_origin;
    ft::vector<int> m_origin;

    for (int i = 0; i < 100000; ++i) {
        s_origin.push_back(i + 1);
        m_origin.push_back(i + 1);
    }
    std::cout << "------vector_range_insert_performance_test-------\n";
    vector_insert_execute(s_v, s_v.end(), s_origin.begin(), s_origin.end());
    vector_insert_execute(m_v, m_v.end(), m_origin.begin(), m_origin.end());
}

int main(void) {
    vector_insert_single_elem_test();
    vector_insert_fill_test();
    vector_insert_range_test();
}