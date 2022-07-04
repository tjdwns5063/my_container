#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "iterator.hpp"

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

			void	_allocate(size_type n) {
				iterator	t_begin;

				if (_capacity >= n)
					return ;
				try {
					t_begin = iterator(_alloc.allocate(n));
					_alloc.destroy(_begin.base());
					_begin = t_begin;
					_end = _begin + n;
					_capacity = n;
				} catch (std::bad_alloc& err) {
					std::cout << "allocate_error\n";
				}
			}

			// void	_reallocate() {
			// 	try {
			// 		iterator new_begin = iterator(_alloc.allocate(_capacity * 2));
			// 		iterator new_end = iterator(new_begin + _size);
			// 		for (int i = 0; i < _size; i++)
			// 			new_begin[i] = _begin[i];
			// 		_alloc.destroy(_begin._p);
			// 		_begin = new_begin;
			// 		_end = new_end;
			// 	} catch (std::bad_alloc& err) {
			// 		std::cout << "allocate error\n";
			// 	}
			// }
		public:	
		//캐노니컬폼
			explicit vector (const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _begin(iterator(0)), _end(iterator(0)), _capacity(0), _size(0) {}

			explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()): _alloc(alloc), _capacity(0), _size(0) {
					assign(n, 0);
				 }

			template <class InputIterator>
         		vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type()) {
					 
				 }

			vector (const vector& x);

			~vector() {
				_alloc.destroy(_begin.base());
				std::cout << "destruct call\n";
			}
			vector& operator=( const vector& other );
		
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

			template< class InputIt >
			void assign( InputIt first, InputIt last ) {
				size_type	size = 0;

				for (InputIt it = first; it != last; it++)
					size++;
				_allocate(size);
				_size = size;
				_end = _begin + _size;
				for (InputIt it = first; it != last; it++) {
					_begin[--size] = *it;
				}
			}

			iterator begin() {
				return (_begin);
			}

			const_iterator begin() const {
				return (static_cast<const_iterator>(_begin));
			}

			iterator end() {
				return (_end);
			}

			const_iterator end() const {
				reutrn (static_cast<const_iterator>(_end));
			}

			size_type	capacity(void) const {
				return (_capacity);
			}

			size_type	size(void) const {
				return (_size);
			}
	}; 
}

#endif
