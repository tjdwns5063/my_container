#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "comp_algorithm.hpp"

namespace ft {
	template<
		class T,
		class Allocator = std::allocator<T>
	> class vector {
		public:
			typedef T															value_type;
			typedef Allocator													allocator_type;
			typedef	size_t														size_type;
			typedef std::ptrdiff_t												difference_type;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;
			typedef value_type*													pointer;
			typedef	const value_type*											const_pointer;
			typedef	ft::vector_iterator<ft::iterator_traits<pointer> >			iterator;
			typedef ft::vector_iterator<ft::iterator_traits<const_pointer> >	const_iterator;	
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
		private:
			iterator		_begin;
			// iterator		_end;
			allocator_type	_alloc;
			size_type		_capacity;
			size_type		_size;

			void	_copy_value(iterator& t_begin, size_type capacity) {
				iterator	temp;

				if (_begin == end())
					return ;
				temp = t_begin;
				for (iterator it = _begin; it != end(); it++)
					*(temp++) = *it;
				_alloc.deallocate(_begin.base(), capacity);
			}

			void	_allocate(size_type n) {
				iterator	t_begin;
				size_type	capacity = _capacity;
				if (_capacity >= n)
					return ;
				_capacity = n;
				try {
					t_begin = iterator(_alloc.allocate(_capacity));
					_copy_value(t_begin, capacity);
					_begin = t_begin;
				} catch (std::bad_alloc& err) {
					// std::cout << "allocate_error\n";
				}
			}

			void	_shallow_copy(vector& x, vector& y) {
				x._alloc = y._alloc;
				x._capacity = y._capacity;
				x._size = y._size;
				x._begin = y._begin;
				// x._end = y._end;
			}

		public:	
		//Constructor, Destructor, Assign operator
			explicit vector (const allocator_type& alloc = allocator_type())
				: _begin(iterator(0)), _alloc(alloc), _capacity(0), _size(0) {}

			explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()): _begin(iterator(0)), _alloc(alloc), _capacity(0), _size(0) {
					assign(n, val);
				 }

			template <typename InputIterator>
				vector (typename enable_if<!is_integral<InputIterator>::value, InputIterator >::type first, InputIterator last, 
					const allocator_type& alloc = allocator_type()): _begin(iterator(0)), _alloc(alloc), _capacity(0), _size(0) {
					assign(first, last);
				 }

			vector (const vector& x): _begin(iterator(0)), _alloc(allocator_type()), _capacity(0), _size(0) {
				*this = x;
			}

			~vector() {
				_alloc.deallocate(_begin.base(), _capacity);
				// _alloc.destroy(_begin.base());
				// std::cout << "destruct call\n";
				// system("leaks a.out");
			}

			vector& operator=( const vector& other ) {
				assign(other.begin(), other.end());
				return (*this);
			}

			//Iterator		
			iterator begin() {
				return (_begin);
			}
			const_iterator begin() const {
				return (static_cast<const_iterator>(_begin));
			}

			iterator end() {
				return (_begin + _size);
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(_begin + _size));
			}

			const_reverse_iterator	rbegin() const {
				return (const_reverse_iterator(_begin + _size));
			}

			reverse_iterator rend() {
				return (reverse_iterator(_begin));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(_begin));
			}

			const_iterator end() const {
				return (static_cast<const_iterator>(_begin + _size));
			}
		//Capacity
			size_type	capacity(void) const {
				return (_capacity);
			}

			size_type	size(void) const {
				return (_size);
			}

			void	resize(size_type n, value_type val = value_type()) {
				if (n < _size) {
					_size = n;
				}
				else if (n > _size && n <= _capacity) {
					for (iterator it = end(); it < _begin + n; it++)
						*it = val;
					_size = n;
				}
				else if (n > _capacity) {
					_allocate(_capacity * 2);
					for (iterator it = end(); it < _begin + n; it++)
						*it = val;
					_size = n;
				}
			}

			size_type	max_size(void) const {
				return (_alloc.max_size());
			}

			bool empty() const {
				return (_size == 0);
			}

			void reserve (size_type n) {
				_allocate(n);
			}
		//Element Access
			reference operator[] (size_type n) {
				return (*(_begin + n));
			}

			const_reference operator[] (size_type n) const {
				return (*(_begin + n));
			}

			reference at (size_type n) {
				if (n >= _size) throw std::out_of_range("vector");
				return (*(_begin + n));
			}

			const_reference at (size_type n) const {
				if (n >= _size) throw std::out_of_range("vector");
				return (*(_begin + n));
			}

			reference front() {
				return (*_begin);
			}

			const_reference front() const {
				return (*_begin);
			}

			reference back() {
				return (*(end() - 1));
			}

			const_reference back() const {
				return (*(end() - 1));
			}
		// Modifiers
			void assign( size_type count, const value_type& value ) {
				_allocate(count);
				for (size_type i = 0; i < _capacity; i++) {
					if (i < count)
						_begin[i] = value;
					else
						_begin[i] = (value_type)0;
				}
				_size = count;
			}

			template <typename InputIt>
			void assign( typename enable_if<!is_integral<InputIt>::value, InputIt >::type first, InputIt last ) {
				difference_type	size = last - first;

				// std::cout << size << '\n';
				_allocate(size);
				_size = size;
				size = 0;
				for (InputIt it = first; it != last; it++) {
					_begin[size++] = *it;
				}
			}

			void push_back( const value_type& val ) {
				if (_size >= _capacity) {
					size_t capacity = (_capacity == 0) ? 1 : _capacity * 2;
					_allocate(capacity);
				}
				*end() = val;
				// _end += 1;
				_size += 1;
			}

			void pop_back() {
				_size -= 1;
				// _end[_size] = 0;
				// _end -= 1;
			}

			iterator insert (iterator position, const value_type& val) {
				difference_type offset = position - _begin;
				if (_size == 0) {
					_allocate(_size + 1);
					*_begin = val;
					_size += 1;
					return (_begin);
				}
				_allocate(_size + 1);
				for (iterator it = end(); it != _begin + offset; --it) {
					*it = *(it - 1);
					// std::cout << "*it : " << *it << '\n';
				}
				*(_begin + offset) = val;
				_size += 1;
				return (_begin + offset);
			}

			void insert (iterator position, size_type n, const value_type& val) {
				size_type	offset;

				offset = position - _begin;
				_allocate(_size + n);
				for (iterator it = end() + n; it != _begin + offset; it--) {
					*it = *(it - n);
				}
				for (iterator it = _begin + offset; it != _begin + offset + n; it++) {
					*it = val;
				}
				_size += n;
			}

			template< typename InputIt>
    		void insert( iterator position, typename enable_if<!is_integral<InputIt>::value, InputIt >::type first, InputIt last ) {
				size_type	offset;
				size_type	len;
				iterator	pos;

				offset = position - _begin;
				len = 0;
				for (InputIt it = first; it != last; it++)
					++len;
				_allocate(_size + len);
				for (iterator it = end() + len; it != _begin + offset; it--)
					*it = *(it - len);
				pos = _begin + offset;
				for (InputIt it = first; it != last; it++)
					*(pos++) = *it;
				_size += len;
			}

			iterator erase (iterator position) {
				for (iterator it = position; it != end(); it++)
					*it = *(it + 1);
				_size -= 1;
				return (position);
			}

			iterator erase (iterator first, iterator last) {
				size_type	len;

				len = last - first;

				for (size_type i = 0; i < len; ++i) {
					erase(first);
				}
				return first;
			}

			void swap (vector& x) {
				vector temp;

				_shallow_copy(temp, x);
				_shallow_copy(x, *this);
				_shallow_copy(*this, temp);
				temp._begin = 0;
			}

			void clear() {
				end() = _begin;
				_size = 0;
			}
		// Allocator
			allocator_type get_allocator() const {
				return (_alloc);
			}
	};
		// relation operators
		template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return (false);
			return (equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return !(lhs == rhs);
		}

		template <class T, class Alloc>
		bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}
		
		template <class T, class Alloc>
		bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return (rhs < lhs);
		}
		
		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return !(lhs > rhs);
		}

		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return !(lhs < rhs);
		}

		template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
			x.swap(y);
		}
}

#endif
