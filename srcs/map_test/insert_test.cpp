#include "map_test.hpp"

void    std_map_single_item_insert_test(std::map<int, std::string>& std_map, std::pair<int, std::string> value) {
    typedef std::map<int, std::string>::iterator iter;

    std::pair<iter, bool> ret = std_map.insert(value);
    
    std::cout << "key: " << ret.first->first << '\n';
    std::cout << "inserted: " << ret.second << '\n';

    print_map(std_map);
    std::cout << "-------------------------------------\n";
}

void    ft_map_single_item_insert_test(ft::map<int, std::string>& ft_map, ft::pair<int, std::string> value) {
    typedef ft::map<int, std::string>::iterator iter;

    ft::pair<iter, bool> ret = ft_map.insert(value);
    
    std::cout << "key: " << ret.first->first << '\n';
    std::cout << "inserted: " << ret.second << '\n';

    print_map(ft_map);
    std::cout << "-------------------------------------\n";
}

void    ft_map_range_insert_test() {
    std::map<int, std::string> s_m;
    ft::map<int, std::string> m_m;

    std::map<int, std::string> s_origin_m;
    ft::map<int, std::string> m_origin_m;

    for (int i = 0; i < 10; ++i) {
        s_m.insert(std::make_pair(i, std::string(1, i + 'A')));
        m_m.insert(ft::make_pair(i, std::string(1, i + 'A')));
    }

    s_m.insert(s_origin_m.begin(), s_origin_m.end());
    m_m.insert(m_origin_m.begin(), m_origin_m.end());

    print_map(s_m);
    print_map(m_m);
}

void    map_insert_test() {
    std::map<int, std::string> s_m;
    ft::map<int, std::string> m_m;

    std_map_single_item_insert_test(s_m, std::make_pair(0, "zero"));
    ft_map_single_item_insert_test(m_m, ft::make_pair(0, "zero"));

    std_map_single_item_insert_test(s_m, std::make_pair(1, "42"));
    ft_map_single_item_insert_test(m_m, ft::make_pair(1, "42"));

    std_map_single_item_insert_test(s_m, std::make_pair(1, "110"));
    ft_map_single_item_insert_test(m_m, ft::make_pair(1, "110"));

    std_map_single_item_insert_test(s_m, std::make_pair(2, "abc"));
    ft_map_single_item_insert_test(m_m, ft::make_pair(2, "abc"));

    std_map_single_item_insert_test(s_m, std::make_pair(3, "seoul"));
    ft_map_single_item_insert_test(m_m, ft::make_pair(3, "seoul"));

    std_map_single_item_insert_test(s_m, std::make_pair(7, "seongjki"));
    ft_map_single_item_insert_test(m_m, ft::make_pair(7, "seongjki"));

    std_map_single_item_insert_test(s_m, std::make_pair(5, "five"));
    ft_map_single_item_insert_test(m_m, ft::make_pair(5, "five"));

    ft_map_range_insert_test(); 
}

int main() {
    map_insert_test();
}