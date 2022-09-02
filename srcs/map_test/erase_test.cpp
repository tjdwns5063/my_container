#include "map_test.hpp"

template <typename MAP, typename A1, typename A2>
void    map_erase_execute(MAP& map, A1 arg1, A2 arg2) {
    struct timeval start;
    struct timeval end;
    long    micro_sec;
    std::string map_type;

    map_type = (typeid(map).name() == typeid(std::map<typename MAP::key_type, typename MAP::mapped_type>).name()) ? "STD" : "FT";
    std::cout << "[ " << map_type  << " ]\n";
    gettimeofday(&start, NULL);
    map.erase(arg1, arg2);
    gettimeofday(&end, NULL);
    micro_sec = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    std::cout << "micro sec: " << micro_sec << "us\n";
}

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

    // for (std::map<int, std::string>::iterator it = s_m.begin(); it != s_m.end(); ++it) {
    //     std::cout << it->first << '\n';
    //     s_m.erase(it);
    // }
    // for (ft::map<int, std::string>::iterator it = m_m.begin(); it != m_m.end(); ++it) {
    //     m_m.erase(it);
    // }
    // print_map(s_m);
    // print_map(m_m);
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

    // s_m.erase(s_m.begin(), s_m.end());
    // m_m.erase(m_m.begin(), m_m.end());
    s_m.erase(++(++s_m.begin()), --s_m.end());
    m_m.erase(++(++m_m.begin()), --m_m.end());
    print_map(s_m);
    print_map(m_m);
    std::cout << "----------------------------------\n";
}

void    map_erase_performance_test() {
    std::cout << "---------map_erase_performance_test---------\n";

    std::map<int, int> s_m;
    ft::map<int, int> m_m;

    for (int i = 0; i < 200000; ++i) {
        s_m.insert(std::make_pair(i, i + 1));
        m_m.insert(ft::make_pair(i, i + 1));
    }
    // m_m.preorder_traversal(m_m.get_root());
    map_erase_execute(s_m, s_m.begin(), s_m.end());
    map_erase_execute(m_m, m_m.begin(), m_m.end());
}

int main() {
    // map_erase_single_item_test();
    // map_erase_range_test();
    map_erase_performance_test();
}