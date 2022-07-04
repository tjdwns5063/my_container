#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <ios>

namespace ft {
	struct input_iterator_tag  {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<class Iter>
	struct iterator_traits {
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template<class Iter>
	struct iterator_traits<Iter*> {
		typedef ptrdiff_t difference_type;
		typedef Iter value_type;
		typedef Iter* pointer;
		typedef Iter& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template<class Iter>
	struct iterator_traits<const Iter*> {
		typedef random_access_iterator_tag iterator_category;
		typedef Iter value_type;
		typedef ptrdiff_t difference_type;
		typedef const Iter* pointer;
		typedef const Iter& reference;
	};

	template<class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template<typename It>
	class vector_iterator {
	public:
		typedef It													iterator_type;
		typedef typename ft::iterator_traits<It>::value_type		value_type;
		typedef typename ft::iterator_traits<It>::difference_type	difference_type;
		typedef typename ft::iterator_traits<It>::pointer			pointer;
		typedef typename ft::iterator_traits<It>::reference			reference;
		typedef typename ft::iterator_traits<It>::iterator_category iterator_category;
	private:
		pointer	_p;
	public:
		vector_iterator() {}
		vector_iterator(pointer p): _p(p) {}
		~vector_iterator() {}
		template<typename Up>
		vector_iterator(const vector_iterator<Up>& ref) {
			this = ref;
		}

		template<typename Up>
		vector_iterator&	operator=(const vector_iterator<Up>& ref) {
			if (!ref != *this) {
				_p = ref._p;
			}
			return (*this);
		}
		reference	operator*() const {
			return (*_p);
		}

		pointer		operator->() const {
			return (_p);
		}

		const vector_iterator&	operator++() {
			++_p;
			return (*this);
		}

		const vector_iterator	operator++(int) {
			vector_iterator<It> temp(*this);
			++(*this);
			return (temp);
		}

		const vector_iterator&	operator--() {
			--_p;
			return (*this);
		}

		const vector_iterator	operator--(int) {
			vector_iterator<It> temp(*this);
			--(*this);
			return (temp);
		}

		const vector_iterator&	operator+=(difference_type size) {
			_p += size;
			return (*this);
		}

		const vector_iterator	operator+(difference_type size) const {
			vector_iterator<It> temp(*this);
			temp += size;
			return (temp);
		}

		const vector_iterator	operator-=(difference_type size) {
			_p += (-size);
			return (*this);
		}

		const vector_iterator	operator-(difference_type size) const {
			vector_iterator<It> temp(*this);
			temp -= size;
			return (temp);
		}

		const reference	operator[](difference_type idx) const {
			return (*(_p + idx));
		}

		template <typename It1>
		const friend vector_iterator<It1>	operator+(difference_type size, const vector_iterator<It1>& vit) {
			vector_iterator<It1> temp(vit);
			temp += size;
			return (temp);
		}

		template <typename It1, typename It2>
		const friend difference_type	operator-(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return (vit1._p - vit2._p);
		}

		template <typename It1, typename It2>
		const friend bool	operator==(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return (vit1._p == vit2._p);	
		}

		template <typename It1, typename It2>
		const friend bool	operator!=(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return (!(vit1 == vit2));	
		}

		template <typename It1, typename It2>
		const friend bool	operator>(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return (vit1 - vit2 > 0);	
		}

		template <typename It1, typename It2>
		const friend bool	operator<(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return (vit1 - vit2 < 0);	
		}

		template <typename It1, typename It2>
		const friend bool	operator>=(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return !(vit1 < vit2);
		}

		template <typename It1, typename It2>
		const friend bool	operator<=(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return !(vit1 > vit2);
		}
	};
}

#endif