#include <memory>
#include <iostream>
#include "iterator.hpp"

namespace ft {
	template<
		class T,
		class Allocator = std::allocator<T>
	> class vector {
		public:
			typedef T												value_type;
			typedef Allocator										allocator_type;
			typedef	size_t											size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef	const value_type*								const_pointer;
			typedef	typename ft::iterator_traits<pointer>			iterator;
			typedef typename ft::iterator_traits<const_pointer>		const_iterator;	
		private:
			iterator		_begin;
			iterator		_end;
			allocator_type	_alloc;
		public:	
		//캐노니컬폼
			explicit vector (const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _begin(iterator(0)), _end(iterator(0)) {}
			explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()): _alloc(alloc) {
					_begin = iterator(_alloc.allocate(n));
					_end = _begin + 5;
				 }
			template <class InputIterator>
         		vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
			vector (const vector& x);
			~vector() {
				std::cout << "destruct call\n";
			}
			vector& operator=( const vector& other );
		
			// void assign( size_type count, const T& value ) {
			// 	_alloc.allocate(count)
			// }
			// template< class InputIt >
			// void assign( InputIt first, InputIt last );
			// iterator begin();
			// const_iterator begin() const;
	};
}
