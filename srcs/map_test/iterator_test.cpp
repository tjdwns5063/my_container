#include "map_test.hpp"

class Temp {
public:
    void    print(ft::map<int, int>::iterator& it) {
        std::cout << "*it: " << it->first << '\n';
        std::cout << "this is iterator\n";
    }

    void    print(ft::map<int, int>::const_iterator& it) const {
        std::cout << "*it: " << it->first << '\n';
        std::cout << "this is const iterator\n";
    }
};

void    map_iterator_test() {
    std::map<int, int> s_m;
    std::map<int, int>::iterator s_it(s_m.begin());
    std::map<int, int>::const_iterator s_cit(s_m.begin());

    ft::map<int, int> m_m;
    ft::map<int, int>::iterator m_it(m_m.begin());
    ft::map<int, int>::const_iterator m_cit(m_m.begin());

    Temp t;

    t.print(m_it);
    t.print(m_cit);

    std::cout << "s_cit: " << typeid(s_cit).name() << '\n';
    std::cout << "s_it : " << typeid(s_it->first).name() << typeid(s_it->second).name() << '\n';
    std::cout << "s_cit : " << typeid(s_cit->first).name() << typeid(s_cit->second).name() << '\n';
    std::cout << "m_it : " << typeid(m_it->first).name() << typeid(m_it->second).name() << '\n';
    std::cout << "m_cit : " << typeid(m_cit->first).name() << typeid(m_cit->second).name() << '\n';
}

struct ft_more {
	bool	operator()(const int &first, const int &second) const {
		return (first > second);
	}
};

int main() {
    map_iterator_test();
    std::map<int, int, ft_more> s_m;
    ft::map<int, int, ft_more> m_m;

    s_m.insert(std::make_pair(1, 2));
    s_m.insert(std::make_pair(2, 2));
    s_m.insert(std::make_pair(3, 2));
    
    m_m.insert(ft::make_pair(1, 2));
    m_m.insert(ft::make_pair(2, 2));
    m_m.insert(ft::make_pair(3, 2));

    for (std::map<int, int, ft_more>::iterator it = s_m.begin(); it != s_m.end(); ++it) {
        std::cout << it->first << '\n';
    }
    std::cout << "------------------------\n";
    for (ft::map<int, int, ft_more>::iterator it = m_m.begin(); it != m_m.end(); ++it) {
        std::cout << it->first << '\n';
    }
}