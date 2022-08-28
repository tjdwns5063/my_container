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

void   large_erase_test() {
    std::cout << "-------------map_large_erase_test-----------------\n";

    std::map<int, std::string> s_m;
    ft::map<int, std::string> m_m;

    m_m[42] = "lol";

	m_m[50] = "mdr";
	m_m[25] = "funny";

	m_m[46] = "bunny";
	m_m[21] = "fizz";
	m_m[30] = "buzz";
	m_m[55] = "fuzzy";

	m_m[18] = "bee";
	m_m[23] = "coconut";
	m_m[28] = "diary";
	m_m[35] = "fiesta";
	m_m[44] = "hello";
	m_m[48] = "world";
	m_m[53] = "this is a test";
	m_m[80] = "hey";

	m_m[12] = "no";
	m_m[20] = "idea";
	m_m[22] = "123";
	m_m[24] = "345";
	m_m[27] = "27";
	m_m[29] = "29";
	m_m[33] = "33";
	m_m[38] = "38";

	m_m[43] = "1";
	m_m[45] = "2";
	m_m[47] = "3";
	m_m[49] = "4";
	m_m[51] = "5";
	m_m[54] = "6";
	m_m[60] = "7";
	m_m[90] = "8";

    m_m.preorder_traversal(m_m._root);
    std::cout << "-------------------------\n";
    m_m.erase(25);
    m_m.erase(55);
    m_m.erase(24);
    m_m.erase(54);
    m_m.erase(22);
    m_m.erase(51);
    m_m.erase(21);
    // m_m.erase(53);

    m_m.preorder_traversal(m_m._root);



}

void    map_erase_test() {
    // map_erase_single_item_test();
    // map_erase_range_test();
    large_erase_test();
}

int main() {
    map_erase_test();
}