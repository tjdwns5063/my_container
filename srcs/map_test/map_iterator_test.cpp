#include "map_test.hpp"

typedef std::map<int, int>::iterator s_it;
typedef std::map<int, int>::const_iterator s_cit;
typedef std::map<int, int>::reverse_iterator s_rit;
typedef std::map<int, int>::const_reverse_iterator s_crit;

typedef ft::map<int, int>::iterator m_it;
typedef ft::map<int, int>::const_iterator m_cit;
typedef ft::map<int, int>::reverse_iterator m_rit;
typedef ft::map<int, int>::const_reverse_iterator m_crit;

void    map_iterator_test() {
    std::map<int, int> s_m;
    ft::map<int, int> m_m;

    for (int i = 0; i < 10; ++i) {
        s_m[i] = i + 1;
        m_m[i] = i + 1;
    }
    std::cout << "----------------map_iterator_test-------------------\n";
    std::cout << "[STD]\n";
    for (s_it it = s_m.begin(); it != s_m.end(); ++it) {
        std::cout  << it->first << " ";
    }
    std::cout << "\n[FT]\n";
    for (m_it it = m_m.begin(); it != m_m.end(); ++it) {
        std::cout << it->first << " ";
    }
    std::cout << "\n------------map_reverse_iterator_test---------------\n";
    std::cout << "[STD]\n";
    for (s_rit it = s_m.rbegin(); it != s_m.rend(); ++it) {
        std::cout  << it->first << " ";
    }
    std::cout << "\n[FT]\n";
    for (m_rit it = m_m.rbegin(); it != m_m.rend(); ++it) {
        std::cout << it->first << " ";
    }

    const std::map<int, int> s_cm(s_m);
    const ft::map<int, int> m_cm(m_m);

    std::cout << "\n----------------map_iterator_test-------------------\n";
    std::cout << "[STD]\n";
    for (s_cit it = s_cm.begin(); it != s_cm.end(); ++it) {
        std::cout  << it->first << " ";
    }
    std::cout << "\n[FT]\n";
    for (m_cit it = m_cm.begin(); it != m_cm.end(); ++it) {
        std::cout << it->first << " ";
    }
    std::cout << "\n------------map_reverse_iterator_test---------------\n";
    std::cout << "[STD]\n";
    for (s_crit it = s_cm.rbegin(); it != s_cm.rend(); ++it) {
        std::cout  << it->first << " ";
    }
    std::cout << "\n[FT]\n";
    for (m_crit it = m_cm.rbegin(); it != m_cm.rend(); ++it) {
        std::cout << it->first << " ";
    }
    s_it sit = s_m.begin();
    s_cit scit = s_m.begin();
    s_rit srit = s_m.rbegin();
    s_crit scrit = s_m.rbegin();

    m_it mit = m_m.begin();
    m_cit mcit = m_m.begin();
    m_rit mrit = m_m.rbegin();
    m_crit mcrit = m_m.rbegin();

    std::cout << std::boolalpha << "\niterator == const_iterator: [STD]=" << (sit == scit) << '\n';
    std::cout << std::boolalpha << "iterator == const_iterator: [FT]=" << (mit == mcit) << '\n';
    std::cout << std::boolalpha << "reverse_iterator == const_reverse_iterator: [STD]=" << (srit == scrit) << '\n';
    std::cout << std::boolalpha << "reverse_iterator == const_reverse_iterator: [FT]=" << (mrit == mcrit) << '\n';

    std::cout << std::boolalpha << "iterator == const_iterator: [STD]=" << (sit != scit) << '\n';
    std::cout << std::boolalpha << "iterator == const_iterator: [FT]=" << (mit != mcit) << '\n';
    std::cout << std::boolalpha << "reverse_iterator == const_reverse_iterator: [STD]=" << (srit != scrit) << '\n';
    std::cout << std::boolalpha << "reverse_iterator == const_reverse_iterator: [FT]=" << (mrit != mcrit) << '\n';
}

int main() {
    map_iterator_test();
}