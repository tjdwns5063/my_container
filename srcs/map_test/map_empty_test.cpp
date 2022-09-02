#include "map_test.hpp"

void    map_empty_test() {
    std::map<int, int> s_m;
    ft::map<int, int> m_m;

    std::cout << std::boolalpha << "[STD] EMPTY: " << s_m.empty() << '\n';
    std::cout << std::boolalpha << "[FT] EMPTY: " << m_m.empty() << '\n';

    print_map(s_m);
    print_map(m_m);

    s_m[4] = 4;
    m_m[4] = 4;

    std::cout << std::boolalpha << "[STD] EMPTY: " << s_m.empty() << '\n';
    std::cout << std::boolalpha << "[FT] EMPTY: " << m_m.empty() << '\n';

    print_map(s_m);
    print_map(m_m);
    
    s_m.clear();
    m_m.clear();

    std::cout << std::boolalpha << "[STD] EMPTY: " << s_m.empty() << '\n';
    std::cout << std::boolalpha << "[FT] EMPTY: " << m_m.empty() << '\n';

    print_map(s_m);
    print_map(m_m);
}

int main() {
    map_empty_test();
}