#include <map>
#include <iostream>
#include <utility>
#include <pair.hpp>

int main()
{
	std::cout << "this is map\n";
	std::pair<float, int> p(1.1, 2);
	std::pair<float, float> c_p(p);
	std::cout << "first: " << p.first << " second: " << p.second << '\n';
	std::cout << "first: " << c_p.first << " second: " << c_p.second << '\n';

	ft::pair<int, int> cp = ft::make_pair<int, int>(1, 2);
	ft::pair<int, int> m_p(3, 2);
	// ft::pair<float, float> c_m_p(cp);
	std::cout << "first: " << cp.first << " second: " << cp.second << '\n';
	std::cout << "first: " << m_p.first << " second: " << m_p.second << '\n';
	std::cout <<  std::boolalpha << (cp == m_p) << '\n';
	std::cout <<  std::boolalpha << (cp <= m_p) << '\n';
	std::cout <<  std::boolalpha << (cp >= m_p) << '\n';
}