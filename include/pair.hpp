#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
	template <class T1, class T2>
	struct pair {
	public:
		typedef	T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		//constructor and assignment operator
		pair(): first(), second() {}
		pair(T1 const& _t1, T2 const& _t2): first(_t1), second(_t2) {}
		template <class _U1, class _U2>
		pair(const pair<_U1, _U2>& _p): first(_p.first), second(_p.second) {}
		pair& operator= (const pair& pr) {
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};

	// compare operator
	template <class _T1, class _T2>
	bool operator== (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) {
		return (lhs.first == rhs.first) && (lhs.second == rhs.second);
	}

	template <class _T1, class _T2>
	bool operator!= (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class _T1, class _T2>
	bool operator< (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class _T1, class _T2>
	bool operator<= (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) {
		return !(rhs < lhs);
	}

	template <class _T1, class _T2>
	bool operator> (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) {
		return rhs < lhs;
	}

	template <class _T1, class _T2>
	bool operator>= (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) {
		return !(lhs < rhs);
	}
	
	template <typename T1, typename T2>
	pair<T1, T2>	make_pair(T1 _first, T2 _second) {
		return pair<T1, T2>(_first, _second);
	}
}

#endif