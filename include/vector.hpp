#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
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
			pointer			_begin;
			pointer			_end;
			allocator_type	_alloc;
			size_type		_capacity;
			size_type		_size;

			void	_copy_value(pointer start, pointer end, pointer dest) {
				difference_type len = end - start;

				for (difference_type i = 0; i < len; ++i) {
					*(dest + i) = *(start + i);
				}
			}

			void	_allocate(size_type n) {
				pointer	t_begin = 0;
				size_type	capacity = _capacity;
				if (_capacity >= n)
					return ;
				_capacity = n;
				try {
					t_begin = _alloc.allocate(_capacity);
					_copy_value(_begin, _end, t_begin);
					_alloc.deallocate(_begin, capacity);
					_begin = t_begin;
					_end = _begin + _size;
				} catch (std::bad_alloc& err) {
					// std::cout << "allocate_error\n";
				}
			}

			void	_shallow_copy(vector& x, vector& y) {
				x._alloc = y._alloc;
				x._capacity = y._capacity;
				x._size = y._size;
				x._begin = y._begin;
				x._end = y._end;
			}

		public:	
		//Constructor, Destructor, Assign operator
			explicit vector (const allocator_type& alloc = allocator_type())
				: _begin(NULL), _end(NULL), _alloc(alloc), _capacity(0), _size(0) {}

			explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()): _begin(NULL), _end(NULL), _alloc(alloc), _capacity(0), _size(0) {
					assign(n, val);
				 }

			template <typename InputIterator>
				vector (typename enable_if<!is_integral<InputIterator>::value, InputIterator >::type first, InputIterator last, 
					const allocator_type& alloc = allocator_type()): _begin(NULL), _end(NULL), _alloc(alloc), _capacity(0), _size(0) {
					assign(first, last);
				 }

			vector (const vector& x): _begin(), _end(), _alloc(allocator_type()), _capacity(0), _size(0) {
				*this = x;
			}

			~vector() {
				// _alloc.deallocate(_begin, _capacity);
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
				return (iterator(_begin));
			}
			const_iterator begin() const {
				return (const_iterator(_begin));
			}

			iterator end() {
				return (iterator(_end));
			}

			const_iterator end() const {
				return (const_iterator(_end));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(_end));
			}

			const_reverse_iterator	rbegin() const {
				return (const_reverse_iterator(_end));
			}

			reverse_iterator rend() {
				return (reverse_iterator(_begin));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(_begin));
			}

		//Capacity
			size_type	capacity(void) const {
				return (_capacity);
			}

			size_type	size(void) const {
				return (_size);
			}

			void	resize(size_type n, value_type val = value_type()) {
				// if (n < _size) {
				// 	std::cout << "1\n";
				// 	_size = n;
				// }
				// else if (n > _size && n <= _capacity) {
				// 	std::cout << "2\n";
				// 	for (pointer ptr = _end; ptr != _begin + n; ++ptr)
				// 		*ptr = val;
				// 	_size = n;
				// }
				// else if (n > _capacity) {
				// 	std::cout << "3\n";
				// 	_allocate(_capacity * 2);
				// 	for (pointer ptr = _end; ptr != _begin + n; ++ptr)
				// 		*ptr = val;
				// 	_size = n;
				// }
				if (n < _size) {
					_size = n;
					_end = _begin + _size;
				} else if (n < _capacity) {
					for (size_type i = _end - _begin; i < n; ++i)
						*(_begin + i) = val;
					_size = n;
					_end = _begin + _size;
				} else {
					size_type capacity = (n > _capacity * 2) ? n : _capacity * 2;
					_allocate(capacity);
					for (size_type i = _end - _begin; i < n; ++i)
						*(_begin + i) = val;
					_size = n;
					_end = _begin + _size;
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
						*(_begin + i) = value;
					else
						*(_begin + i) = (value_type)0;
				}
				_size = count;
				_end = _begin + _size;
			}

			template <typename InputIt>
			void assign( typename enable_if<!is_integral<InputIt>::value, InputIt >::type first, InputIt last ) {
				difference_type	size = 0;
				
				for (InputIt it = first; it != last; ++it) {
					++size;
				}
				_allocate(size);
				_size = size;
				size = 0;
				for (InputIt it = first; it != last; it++) {
					*(_begin + size++) = *it;
				}
				_end = _begin + _size;
			}

			void push_back( const value_type& val ) {
				if (_size >= _capacity) {
					size_t capacity = (_capacity == 0) ? 1 : _capacity * 2;
					_allocate(capacity);
				}
				*(_begin + _size) = val;
				_size += 1;
				_end = _begin + _size;
			}

			void pop_back() {
				_size -= 1;
				_end = _begin + _size;
			}

			iterator insert (iterator position, const value_type& val) {
				difference_type offset = position.base() - _begin;

				// std::cout << "offset : " << offset << '\n';
				if (_begin + offset == _end) {
					push_back(val);
				} else {
					if (_size + 1 >= _capacity) {
						size_t capacity = (_capacity == 0) ? 1 : _capacity * 2;
						_allocate(capacity);
					}
					difference_type temp_size = _size - offset;
					pointer temp = _alloc.allocate(temp_size);

					_copy_value(_begin + offset, _end, temp);
					*(_begin + offset) = val;
					_copy_value(temp, temp + (temp_size), _begin + offset + 1);
					_alloc.deallocate(temp, temp_size);
					++_size;
					_end = _begin + _size;
				}
				return (iterator(_begin + offset));
			}

			void insert (iterator position, size_type n, const value_type& val) {
				difference_type offset = position.base() - _begin;

				if (n <= 0)
					return ;
				_allocate(_size + n);
				if (_begin + offset == _end) {
					for (size_type i = 0; i < n; ++i) {
						*(_begin + offset + i) = val;
					}
				} else {
					difference_type temp_size = _size - offset;
					pointer temp_ptr = _alloc.allocate(temp_size);
					_copy_value(_begin + offset, _begin + _size, temp_ptr);
					for (size_type i = 0; i < n; ++i) {
						*(_begin + offset + i) = val;
					}
					_copy_value(temp_ptr, temp_ptr + temp_size, _begin + offset + n);
				}
				_size += n;
				_end = _begin + _size;
			}

			template< typename InputIt>
    		void insert( iterator position, typename enable_if<!is_integral<InputIt>::value, InputIt >::type first, InputIt last ) {
				size_type	offset;
				difference_type	len;
				iterator	pos;
				
				offset = position.base() - _begin;
				len = 0;
				for (InputIt it = first; it != last; it++)
					++len;
				if (_size + len >= _capacity) {
					size_t capacity = (len + _size > _capacity * 2) ? len + _size : _capacity * 2;//std::max(len, _capacity * 2);
					_allocate(capacity);
				}
				if (_begin + offset == _end) {
					for (difference_type i = 0; i < len; ++i) {
						*(_begin + offset + i) = *first++;
					}
				} else {
					difference_type temp_size = _size - offset;
					pointer temp_ptr = _alloc.allocate(temp_size);
					_copy_value(_begin + offset, _begin + _size, temp_ptr);
					for (difference_type i = 0; i < len; ++i) {
						*(_begin + offset + i) = *first++;
					}
					_copy_value(temp_ptr, temp_ptr + temp_size, _begin + offset + len);
				}
				// for (iterator it = end() + len; it != begin() + offset; it--)
				// 	*it = *(it - len);
				// pos = _begin + offset;
				// for (InputIt it = first; it != last; it++)
				// 	*(pos++) = *it;
				_size += len;
				_end = _begin + _size;
			}
			// template <class _Tp, class _Allocator>
			// inline _LIBCPP_INLINE_VISIBILITY
			// void
			// __vector_base<_Tp, _Allocator>::__destruct_at_end(pointer __new_last) _NOEXCEPT
			// {
			// 	pointer __soon_to_be_end = __end_;
			// 	while (__new_last != __soon_to_be_end)
			// 		__alloc_traits::destroy(__alloc(), _VSTD::__to_address(--__soon_to_be_end));
			// 	__end_ = __new_last;
			// }


			iterator erase (iterator position) {
				difference_type	pos = position - begin();

				pointer p = _begin + pos;
				// _alloc.destroy(p);

				_copy_value(_begin + pos + 1, _end, _begin + pos);
				_size -= 1;
				_end = _begin + _size;
				return (iterator(p));
			}

			iterator erase (iterator first, iterator last) {
				difference_type pos = first - begin();
				difference_type	len;

				len = last - first;

				_copy_value(_begin + pos + len, _end, _begin + pos);
				_size -= len;
				_end = _begin + _size;
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
				_size = 0;
				_end = _begin + _size;
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
