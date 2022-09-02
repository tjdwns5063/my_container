#include "map_test.hpp"

template <typename MAP>
void    map_comp_test_impl(MAP& map) {
    typedef typename MAP::iterator iter;
    typedef typename MAP::value_compare value_compare;
    typedef typename MAP::key_compare key_compare;

    value_compare value_comp = map.value_comp();
    key_compare key_comp = map.key_comp();

    
    for (iter it1 = map.begin(); it1 != map.end(); ++it1) {
        for (iter it2 = map.begin(); it2 != map.end(); ++it2) {
            std::cout << "key_comp: " << key_comp(it1->first, it2->first) << '\n';
            std::cout << "value_comp: " << value_comp(*it1, *it2) << '\n';
        }
     }
     std::cout << "----------------------------------\n";
}

void    map_comp_test() {
    std::map<char, float> s_m;
    ft::map<char, float> m_m;

    s_m['a'] = 1.0;
    m_m['a'] = 1.0;

    s_m['b'] = 2.0;
    m_m['b'] = 2.0;

    s_m['c'] = 3.0;
    m_m['c'] = 3.0;

    s_m['d'] = 3.23;
    m_m['d'] = 3.23;

    print_map(s_m);
    print_map(m_m);

    map_comp_test_impl(s_m);
    map_comp_test_impl(m_m);
}

int main() {
    map_comp_test();
}