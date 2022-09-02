#include "vector_test.hpp"

typedef std::vector<int>::iterator s_it;
typedef std::vector<int>::reverse_iterator s_rit;
typedef std::vector<int>::const_iterator s_cit;
typedef std::vector<int>::const_reverse_iterator s_crit;

typedef ft::vector<int>::iterator m_it;
typedef ft::vector<int>::reverse_iterator m_rit;
typedef ft::vector<int>::const_iterator m_cit;
typedef ft::vector<int>::const_reverse_iterator m_crit;

std::vector<int> s_v;
ft::vector<int> m_v;

void	vector_iterator_test() {
	std::cout << "--------------vector_iterator_test--------------\n";
	
	s_it std_it = s_v.begin();
	m_it my_it = m_v.begin();

	std::cout << "*std_it: " << *std_it << '\n';
	std::cout << "*my_it: " << *my_it << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_it: " << *(++std_it) << '\n';
	std::cout << "*my_it: " << *(++my_it) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_it: " << *(--std_it) << '\n';
	std::cout << "*my_it: " << *(--my_it) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_it: " << *(std_it += 2) << '\n';
	std::cout << "*my_it: " << *(my_it += 2) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_it: " << *(std_it -= 2) << '\n';
	std::cout << "*my_it: " << *(my_it -= 2) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_it: " << *(2 + std_it) << '\n';
	std::cout << "*my_it: " << *(2 + my_it) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "std_diff: " << ((std_it + 2) - std_it) << '\n';
	std::cout << "my_diff: " << ((my_it + 2) - my_it) << '\n';
	std::cout << "---------------------------------\n";

	s_cit std_cit = std_it;
	m_cit my_cit = my_it;

	std::cout << "*std_cit: " << *(++std_cit) << '\n';
	std::cout << "*my_cit: " << *(++my_cit) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_cit: " << *(--std_cit) << '\n';
	std::cout << "*my_cit: " << *(--my_cit) << '\n';
	// *std_cit = 3;
	// *my_cit = 3;

	std::cout << "---------------------------------\n";
	std::cout << "==: " << (std_cit == std_it) << '\n';
	std::cout << "!=: " << (std_cit != std_it) << '\n';
	std::cout << "---------------------------------\n";
	++std_it;
	std::cout << "==: " << (std_cit == std_it) << '\n';
	std::cout << "!=: " << (std_cit != std_it) << '\n';
	std::cout << "---------------------------------\n";
	std::cout << ">: " << (std_cit > std_it) << '\n';
	std::cout << "<: " << (std_cit < std_it) << '\n';
	std::cout << "---------------------------------\n";
}

void	vector_reverse_iterator_test() {
	std::cout << "----------vector_reverse_iterator_test----------\n";
	
	s_rit std_rit = s_v.rbegin();
	m_rit my_rit = m_v.rbegin();

	std::cout << "*std_it: " << *std_rit << '\n';
	std::cout << "*my_it: " << *my_rit << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_it: " << *(++std_rit) << '\n';
	std::cout << "*my_it: " << *(++my_rit) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_it: " << *(--std_rit) << '\n';
	std::cout << "*my_it: " << *(--my_rit) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_it: " << *(std_rit += 2) << '\n';
	std::cout << "*my_it: " << *(my_rit += 2) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_it: " << *(std_rit -= 2) << '\n';
	std::cout << "*my_it: " << *(my_rit -= 2) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_it: " << *(2 + std_rit) << '\n';
	std::cout << "*my_it: " << *(2 + my_rit) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "std_diff: " << ((std_rit + 2) - std_rit) << '\n';
	std::cout << "my_diff: " << ((my_rit + 2) - my_rit) << '\n';
	std::cout << "---------------------------------\n";

	s_crit std_crit = std_rit;
	m_crit my_crit = my_rit;

	std::cout << "*std_crit: " << *(++std_crit) << '\n';
	std::cout << "*my_crit: " << *(++my_crit) << '\n';
	std::cout << "---------------------------------\n";

	std::cout << "*std_crit: " << *(--std_crit) << '\n';
	std::cout << "*my_crit: " << *(--my_crit) << '\n';
	// *std_crit = 3;
	// *my_crit = 3;
	std::cout << "---------------------------------\n";
	std::cout << "*std_crit: " << *(std_crit) << '\n';
	std::cout << "*my_crit: " << *(my_crit) << '\n';
	std::cout << "*std_rit: " << *(std_rit) << '\n';
	std::cout << "*my_rit: " << *(my_rit) << '\n';
	std::cout << "---------------------------------\n";
	std::cout << "==: " << (std_crit == std_rit) << '\n';
	std::cout << "==: " << (my_crit == my_rit) << '\n';
	std::cout << "!=: " << (std_crit != std_rit) << '\n';
	std::cout << "!=: " << (my_crit != my_rit) << '\n';
	std::cout << "---------------------------------\n";
	++std_rit;
	++my_rit;
	std::cout << "*std_crit: " << *(std_crit) << '\n';
	std::cout << "*std_crit: " << *(my_crit) << '\n';
	std::cout << "*std_rit: " << *(std_rit) << '\n';
	std::cout << "*my_rit: " << *(my_rit) << '\n';
	std::cout << "---------------------------------\n";
	std::cout << "==: " << (std_crit == std_rit) << '\n';
	std::cout << "==: " << (my_crit == my_rit) << '\n';
	std::cout << "!=: " << (std_crit != std_rit) << '\n';
	std::cout << "!=: " << (my_crit != my_rit) << '\n';
	std::cout << "---------------------------------\n";
	std::cout << ">: " << (std_crit > std_rit) << '\n';
	std::cout << ">: " << (my_crit > my_rit) << '\n';
	std::cout << "<: " << (std_crit < std_rit) << '\n';
	std::cout << "<: " << (my_crit < my_rit) << '\n';
	std::cout << "---------------------------------\n";
}

int main(void) {
	vector_iterator_test();
	vector_reverse_iterator_test();
}