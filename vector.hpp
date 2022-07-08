#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "is_input_iterator.hpp"

namespace ft {
	template<
		class T,
		class Allocator = std::allocator<T>
	> class vector {
		public:
			typedef T																	value_type;
			typedef Allocator															allocator_type;
			typedef	size_t																size_type;
			typedef std::ptrdiff_t														difference_type;
			typedef value_type&															reference;
			typedef const value_type&													const_reference;
			typedef value_type*															pointer;
			typedef	const value_type*													const_pointer;
			typedef	typename ft::vector_iterator<ft::iterator_traits<pointer> >			iterator;
			typedef typename ft::vector_iterator<ft::iterator_traits<const_pointer> >	const_iterator;	
		private:
			iterator		_begin;
			iterator		_end;
			allocator_type	_alloc;
			size_type		_capacity;
			size_type		_size;

			void	_copy_value(iterator& t_begin, size_type capacity) {
				iterator	temp;

				if (_begin == _end)
					return ;
				temp = t_begin;
				for (iterator it = _begin; it != _end; it++)
					*(temp++) = *it;
				_alloc.deallocate(_begin.base(), capacity);
			}

			void	_allocate(size_type n) {
				iterator	t_begin;
				size_type	capacity = _capacity;

				if (_capacity >= n)
					return ;
				_capacity = (_capacity == 0) ? n : _capacity * 2;
				try {
					t_begin = iterator(_alloc.allocate(_capacity));
					_copy_value(t_begin, capacity);
					_begin = t_begin;
					_end = _begin + _size;
				} catch (std::bad_alloc& err) {
					std::cout << "allocate_error\n";
				}
			}

		public:	
		//Constructor, Destructor, Assign operator
			explicit vector (const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _begin(iterator(0)), _end(iterator(0)), _capacity(0), _size(0) {}

			explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()): _alloc(alloc), _begin(iterator(0)), _end(iterator(0)), _capacity(0), _size(0) {
					assign(n, 0);
				 }

			template <class InputIterator>
         		vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type()) {
					 
				 }

			vector (const vector& x);

			~vector() {
				_alloc.deallocate(_begin.base(), _capacity);
				std::cout << "destruct call\n";
				// system("leaks a.out");
			}
			vector& operator=( const vector& other );
					iterator begin() {
				return (_begin);
			}
		//Iterator
			const_iterator begin() const {
				return (static_cast<const_iterator>(_begin));
			}

			iterator end() {
				return (_end);
			}

			const_iterator end() const {
				reutrn (static_cast<const_iterator>(_end));
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
					_end = _begin + n;	
				}
				else if (n > _size && n <= _capacity) {
					for (iterator it = _end; it < _begin + n; it++)
						*it = val;
					_end += n;
					_size = n;
				}
				else if (n > _capacity) {
					_allocate(n);
					for (iterator it = _end; it < _begin + n; it++)
						*it = val;
					_end = _begin + n;
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
				iterator	t_begin;

				if (_capacity >= n)
					return ;
				_capacity = n;
				try {
					t_begin = iterator(_alloc.allocate(n));
					_copy_value(t_begin);
					_alloc.deallocate(_begin.base(), _capacity);
					_begin = t_begin;
					_end = _begin + _size;
				} catch (std::bad_alloc& err) {
					std::cout << "allocate_error\n";
				}
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
				return (*(_end - 1));
			}

			const_reference back() const {
				return (*(_end - 1));
			}
		// Modifiers
			void assign( size_type count, const T& value ) {
				_allocate(count);
				for (int i = 0; i < _capacity; i++) {
					if (i < count)
						_begin[i] = value;
					else
						_begin[i] = 0;
				}
				_size = count;
				_end = _begin + _size;
			}

			template< typename InputIt, 
			typename ft::enable_if<ft::is_input_iterator<InputIt>::value, int >::type>
			void assign( InputIt first, InputIt last ) {
				size_type	size = 0;

				for (InputIt it = first; it != last; it++)
					size++;
				_allocate(size);
				_size = size;
				_end = _begin + _size;
				size = 0;
				for (InputIt it = first; it != last; it++) {
					_begin[size++] = *it;
				}
			}

			void push_back( const value_type& val ) {
				if (_size >= _capacity)
					_allocate(_capacity + 1);
				*(_end) = val;
				_end += 1;
				_size += 1;
			}

			void pop_back() {
				_size -= 1;
				_end[_size] = 0;
				_end -= 1;
			}

			iterator insert (iterator position, const value_type& val) {
				size_type	offset;

				offset = position - _begin;
				_allocate(_size + 1);
				for (iterator it = _end; it != _begin + offset; it--) {
					*it = *(it - 1);
				}
				*(_begin + offset) = val;
				_size += 1;
				_end += 1;
				return (_begin + offset);
			}

			void insert (iterator position, size_type n, const value_type& val) {
				size_type	offset;

				offset = position - _begin;
				_allocate(_size + n);
				for (iterator it = _end + n; it != _begin + offset; it--) {
					*it = *(it - n);
				}
				for (iterator it = _begin + offset; it != _begin + offset + n; it++) {
					*it = val;
				}
				_size += n;
				_end += n;
			}

			template< typename InputIt, 
			typename ft::enable_if<ft::is_input_iterator<InputIt>::value, int >::type>
    		void insert( iterator position, InputIt first, InputIt last ) {
				size_type	offset = position - _begin;
				size_type	len;
				iterator	pos;

				offset = position - _begin;
				len = 0;
				for (InputIt it = first; it != last; it++)
					++len;
				_allocate(_size + len);
				for (iterator it = _end + len; it != _begin + offset; it--)
					*it = *(it - len);
				pos = _begin + offset;
				for (InputIt it = first; it != last; it++)
					*(pos++) = *it;
				_size += len;
				_end += len;
			}

			iterator erase (iterator position) {
				for (iterator it = position; it != _end; it++)
					*it = *(it + 1);
				_size -= 1;
				_end -= 1;
				return (position);
			}

			iterator erase (iterator first, iterator last) {
				for (int i = 0; i < last - first; i++)
					erase(first);
				return (first);
			}
	};
}

#endif
