#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <ios>
#include "pair.hpp"
#include "node.hpp"

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

	template <class Iterator>
	class reverse_iterator
		: public iterator<typename iterator_traits<Iterator>::iterator_category,
						typename iterator_traits<Iterator>::value_type,
						typename iterator_traits<Iterator>::difference_type,
						typename iterator_traits<Iterator>::pointer,
						typename iterator_traits<Iterator>::reference>
	{
	protected:
		Iterator current;
	public:
		typedef Iterator                                            iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::reference       reference;
		typedef typename iterator_traits<Iterator>::pointer         pointer;

		reverse_iterator(): current() {}
		explicit reverse_iterator(Iterator x): current(x) {}
		template <class U> 
		reverse_iterator(const reverse_iterator<U>& u): current(u.base()) {}

		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U>& u) {
			current = u.base(); return (*this);
		}
		
		Iterator base() const { 
			return (current); 
		}

		reference operator*() const {
			Iterator __tmp = current;
			return *(--__tmp);
		}

		pointer   operator->() const {
			return (std::addressof(operator*()));
		}

		reverse_iterator& operator++() {
			--current;
			return (*this);
		}

		reverse_iterator  operator++(int) {
			reverse_iterator	temp(*this);
			
			--current;
			return (temp);
		}

		reverse_iterator& operator--() {
			++current;
			return (*this);
		}

		reverse_iterator  operator--(int) {
			reverse_iterator	temp(*this);

			++current;
			return (temp);
		}

		reverse_iterator  operator+ (difference_type n) const {
			reverse_iterator	temp(current - n);
			return (temp);
		}

		reverse_iterator& operator+=(difference_type n) {
			current -= n;
			return (*this);
		}

		reverse_iterator  operator- (difference_type n) const {
			reverse_iterator	temp(current + n);
			return (temp);
		}

		reverse_iterator& operator-=(difference_type n) {
			current += n;
			return (*this);
		}

		reference         operator[](difference_type n) const {
			return (*(*this + n));
		}
	};
		template <typename _Iterator>
		reverse_iterator<_Iterator>	operator+(ptrdiff_t size, const reverse_iterator<_Iterator>& rhs) {
			reverse_iterator<_Iterator> temp(rhs);
			temp += size;
			return (temp);
		}

		template <typename _Iter1, typename _Iter2>
		ptrdiff_t	operator-(const reverse_iterator<_Iter1>& lhs, const reverse_iterator<_Iter2>& rhs) {
			return (rhs.base() - lhs.base());
		}


		template <typename _Iter1, typename _Iter2>
		bool operator== (const reverse_iterator<_Iter1>& lhs,
			 const reverse_iterator<_Iter2>& rhs) {
				return (lhs.base() == rhs.base());
			}

		template <typename _Iter1, typename _Iter2>
		bool operator!= (const reverse_iterator<_Iter1>& lhs,
			 const reverse_iterator<_Iter2>& rhs) {
				return !(lhs == rhs);
			}

		template <typename _Iter1, typename _Iter2>
		bool operator< (const reverse_iterator<_Iter1>& lhs,
			const reverse_iterator<_Iter2>& rhs) {
				return (lhs.base() > rhs.base());
			}

		template <typename _Iter1, typename _Iter2>
		bool operator> (const reverse_iterator<_Iter1>& lhs,
			const reverse_iterator<_Iter2>& rhs) {
				return (rhs < lhs);
			}

		template <typename _Iter1, typename _Iter2>
		bool operator<= (const reverse_iterator<_Iter1>& lhs,
			const reverse_iterator<_Iter2>& rhs) {
				return !(lhs > rhs);
			}

		template <typename _Iter1, typename _Iter2>
		bool operator>= (const reverse_iterator<_Iter1>& lhs,
			const reverse_iterator<_Iter2>& rhs) {
				return !(lhs < rhs);
			}

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
		vector_iterator(): _p(NULL) {}
		vector_iterator(pointer p): _p(p) {}
		~vector_iterator() {}

		template <class _Up>
        vector_iterator(const vector_iterator<_Up>& p) : _p(p.base()) {}
    	template <class _Up>
        vector_iterator& operator=(const vector_iterator<_Up>& p)
            { _p = p.base(); return *this; }

		pointer	base() const {
			return (_p);
		}

		reference	operator*() const {
			return (*_p);
		}

		pointer		operator->() const {
			return (_p);
		}

		vector_iterator&	operator++() {
			++_p;
			return (*this);
		}

		vector_iterator	operator++(int) {
			vector_iterator<It> temp(*this);
			++(*this);
			return (temp);
		}

		vector_iterator&	operator--() {
			--_p;
			return (*this);
		}

		vector_iterator	operator--(int) {
			vector_iterator<It> temp(*this);
			--(*this);
			return (temp);
		}

		vector_iterator&	operator+=(difference_type size) {
			_p += size;
			return (*this);
		}

		vector_iterator	operator+(difference_type size) const {
			vector_iterator<It> temp(*this);
			temp += size;
			return (temp);
		}

		vector_iterator	operator-=(difference_type size) {
			_p += (-size);
			return (*this);
		}

		vector_iterator	operator-(difference_type size) const {
			vector_iterator<It> temp(*this);
			temp -= size;
			return (temp);
		}

		reference	operator[](difference_type idx) const {
			return (*(_p + idx));
		}
	};
		template <typename It1>
		vector_iterator<It1>	operator+(ptrdiff_t size, const vector_iterator<It1>& vit) {
			vector_iterator<It1> temp(vit);
			temp += size;
			return (temp);
		}

		template <typename It1, typename It2>
		ptrdiff_t	operator-(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return (vit1.base()) - vit2.base();
		}

		template <typename It1, typename It2>
		bool	operator==(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return (vit1.base() == vit2.base());	
		}

		template <typename It1, typename It2>
		bool	operator!=(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return !(vit1 == vit2);	
		}

		template <typename It1, typename It2>
		bool	operator<(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return (vit1 - vit2 < 0);	
		}

		template <typename It1, typename It2>
		bool	operator>(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return (vit2 < vit1);	
		}

		template <typename It1, typename It2>
		bool	operator>=(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return !(vit1 < vit2);
		}

		template <typename It1, typename It2>
		bool	operator<=(const vector_iterator<It1>& vit1, const vector_iterator<It2>& vit2) {
			return !(vit1 > vit2);
		}
}

#endif
