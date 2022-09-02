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

template <typename MAP, typename A1, typename A2>
void    map_insert_execute(MAP& map, A1 arg1, A2 arg2) {
    struct timeval start;
    struct timeval end;
    long    micro_sec;
    std::string map_type;

    map_type = (typeid(map).name() == typeid(std::map<typename MAP::key_type, typename MAP::mapped_type>).name()) ? "STD" : "FT";
    std::cout << "[ " << map_type  << " ]\n";
    gettimeofday(&start, NULL);
    map.insert(arg1, arg2);
    gettimeofday(&end, NULL);
    micro_sec = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    std::cout << "micro sec: " << micro_sec << "us\n";
}

void    map_insert_performance_test() {
    std::cout << "----------map_insert_performance_test-----------\n";
    std::map<int, std::string> s_origin;
    std::map<int, std::string> s_m;
    ft::map<int, std::string> m_origin;
    ft::map<int, std::string> m_m;

    for (int i = 0; i < 100000; ++i) {
        s_origin.insert(std::make_pair(i, std::string(1, (i % 10) + 'a')));
        m_origin.insert(ft::make_pair(i, std::string(1, (i % 10) + 'a')));
    }
    map_insert_execute(s_m, s_origin.begin(),s_origin.end());
    map_insert_execute(m_m, m_origin.begin(), m_origin.end());
}

void    map_erase_performance_test() {
    std::cout << "---------map_erase_performance_test---------\n";

    std::map<int, int> s_m;
    ft::map<int, int> m_m;

    for (int i = 0; i < 100000; ++i) {
        s_m.insert(std::make_pair(i, i + 1));
        m_m.insert(ft::make_pair(i, i + 1));
    }
    map_erase_execute(s_m, ++s_m.begin(), --s_m.end());
    map_erase_execute(m_m, ++m_m.begin(), --m_m.end());

    print_map(s_m);
    print_map(m_m);
}

int main() {
    map_insert_performance_test();
    map_erase_performance_test();
}