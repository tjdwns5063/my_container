#include "vector_test.hpp"

template <typename VEC>
void	print_ret(VEC& lhs, VEC& rhs) {
	std::cout << std::boolalpha << "==: " << (lhs == rhs) << '\n';
	std::cout << std::boolalpha << "!=: " << (lhs != rhs) << '\n';
	std::cout << std::boolalpha << ">: " << (lhs > rhs) << '\n';
	std::cout << std::boolalpha << "<: " << (lhs < rhs) << '\n';
	std::cout << std::boolalpha << ">=: " << (lhs >= rhs) << '\n';
	std::cout << std::boolalpha << "<=: " << (lhs <= rhs) << '\n';
	std::cout << "-----------------------------------------------\n";
}

void	vector_operator_test(void) {
	std::cout << "------------vector_operator_test-------------\n";
	std::vector<int> s_v(5);
	std::vector<int> c_s_v(s_v);
	ft::vector<int> m_v(5);
	ft::vector<int> c_m_v(m_v);

	print_ret(s_v, c_s_v);
	print_ret(m_v, c_m_v);

	c_s_v.resize(10);
	c_m_v.resize(10);

	print_ret(s_v, c_s_v);
	print_ret(m_v, c_m_v);

	s_v.resize(12);
	m_v.resize(12);

	print_ret(s_v, c_s_v);
	print_ret(m_v, c_m_v);
}

void	vector_swap_test() {
	std::cout << "------------vector_swap_test-------------\n";
	std::vector<int> s_v;
	std::vector<int> s_s_v;
	ft::vector<int> m_v;
	ft::vector<int> m_s_v;

	for (int i = 0; i < 5; ++i) {
		s_v.push_back(i + 1);
		m_v.push_back(i + 1);
	}
	for (int i = 10; i > -1; --i) {
		s_s_v.push_back(i + 1);
		m_s_v.push_back(i + 1);
	}
	print_vec(s_v);
	print_vec(s_s_v);
	print_vec(m_v);
	print_vec(m_s_v);
	std::cout << "---------------------\n";

	std::swap(s_v, s_s_v);
	ft::swap(m_v, m_s_v);

	print_vec(s_v);
	print_vec(s_s_v);
	print_vec(m_v);
	print_vec(m_s_v);
}

int main(void) {
	vector_operator_test();
	vector_swap_test();
}