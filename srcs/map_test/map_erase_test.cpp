#include "map_test.hpp"

void map_erase_single_item_test() {
    std::cout << "-------------map_erase_single_item_test-----------------\n";
    std::map<int, std::string> s_m;
    ft::map<int, std::string> m_m;

    for (int i = 0; i < 10; ++i) {
        s_m[i] = std::string(1, i + 'A');
        m_m[i] = std::string(1, i + 'A');
    }

    print_map(s_m);
    print_map(m_m);
    std::cout << "----------------------------------\n";

    s_m.erase(6);
    m_m.erase(6);
    print_map(s_m);
    print_map(m_m);
    std::cout << "----------------------------------\n";
    s_m.erase(++(++s_m.begin()));
    m_m.erase(++(++m_m.begin()));
    print_map(s_m);
    print_map(m_m);
    std::cout << "----------------------------------\n";
    s_m.erase(--(--s_m.end()));
    m_m.erase(--(--m_m.end()));
    print_map(s_m);
    print_map(m_m);
    std::cout << "----------------------------------\n";
    s_m.erase(9);
    m_m.erase(9);
    print_map(s_m);
    print_map(m_m);
    std::cout << "----------------------------------\n";
}

void map_erase_range_test() {
    std::cout << "-------------map_erase_range_test-----------------\n";
    std::map<int, std::string> s_m;
    ft::map<int, std::string> m_m;

    for (int i = 0; i < 10; ++i) {
        s_m[i] = std::string(1, i + 'A');
        m_m[i] = std::string(1, i + 'A');
    }

    print_map(s_m);
    print_map(m_m);
    std::cout << "----------------------------------\n";

    s_m.erase(++(++s_m.begin()), --s_m.end());
    m_m.erase(++(++m_m.begin()), --m_m.end());
    print_map(s_m);
    print_map(m_m);
    std::cout << "----------------------------------\n";
}

int main() {
    map_erase_single_item_test();
    map_erase_range_test();
}