#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "./utils/iterator.hpp"

template < class T, class Allocator>
class ft::vector
{
    protected:
        T*																	__sequence;
        Allocator															__allocator;
        std::size_t															__size;
        std::size_t															__capacity;
    public:
        typedef T															value_type;
        typedef Allocator													allocator_type;
        typedef value_type&													reference;
        typedef const value_type&											const_reference;
        typedef typename allocator_type::pointer							pointer;
        typedef typename allocator_type::const_pointer						const_pointer;
        typedef ft::iterator<random_access_iterator_tag, T>					iterator;
        typedef ft::iterator<random_access_iterator_tag, const T>			const_iterator;
        typedef ft::reverse_iterator<iterator>								reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
        typedef std::size_t													size_type;
        // constructors
        explicit vector ( const allocator_type& alloc = allocator_type() ) {													// default constructor
			(void)alloc;
			__sequence = __allocator.allocate(0);
			__capacity = 0;
			__size = 0;
        }
        explicit vector ( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type () ) {	// construct with range initialize
			(void)alloc;
			try {
				__sequence = __allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					__allocator.construct(&__sequence[i], val);
				__capacity = n;
				__size = n;
			} catch (std::exception &ex) {
				throw ft::LengthError("vector");
			}
		}
        template < class Iterator >
        vector ( Iterator first, Iterator last, const allocator_type &alloc = allocator_type(),
                typename ft::enable_if<!(ft::is_integral<Iterator>::value), Iterator>::type* = NULL ) {						// constructor with iterators
			(void)alloc;
			__size = ft::distance(first, last);
            try {
				__sequence = __allocator.allocate(__size);
				for (size_type i = 0; first != last; i++, first++)
                    __allocator.construct(&__sequence[i], *first);
                __capacity = __size;
                
			} catch (std::exception &ex) {
				throw ft::LengthError("vector");
			}
		}

		vector ( const vector& vec ) {							// copy constructor
            try {
				this->__sequence = __allocator.allocate(vec.__capacity);
				for (size_type i = 0; i < vec.__size; i++)
					__allocator.construct(&this->__sequence[i], vec.__sequence[i]);
				this->__size = vec.__size;
				this->__capacity = vec.__capacity;
			} catch (std::exception &ex) {
				throw ft::LengthError("vector");
			}
        }

        // destructor
        ~vector() {
			for (size_type i = 0; i < __size; i++)
				__allocator.destroy(__sequence + i);
            __allocator.deallocate(__sequence, __capacity);
            __size = 0;
            __capacity = 0;
        }

        // operator=
        vector&	operator= ( const vector& vec ) {
			if (this != &vec) {
				try {
					this->clear();
					__allocator.deallocate(__sequence, __capacity);
					this->__sequence = __allocator.allocate(vec.__size);
					for (size_type i = 0; i < vec.__size; i++)
						__allocator.construct(&this->__sequence[i], vec.__sequence[i]);
					this->__size = vec.__size;
					this->__capacity = vec.__capacity;
				} catch (std::exception &ex) {
					throw ft::LengthError("vector");
				}
			}
			return *this;
        }

        // (Iterators) begin & end
        iterator				begin() {
			return	iterator(__sequence);
		};
        const_iterator			begin() const {
			return	const_iterator(__sequence);
		}
        
        iterator				end() {
			return	iterator(__sequence + __size);
		}
        const_iterator			end() const {
			return	const_iterator(__sequence + __size);
		}

        // (Iterators) rbegin & rend
        reverse_iterator		rbegin() {
			return reverse_iterator (__sequence + __size);
		}
        const_reverse_iterator	rbegin() const {
			return const_reverse_iterator (__sequence + __size);
		}
        
        reverse_iterator		rend() {
            return reverse_iterator(__sequence);
        }
        const_reverse_iterator	rend() const {
            return const_reverse_iterator(__sequence);
        }

        // (capacity) size & max_size & capacity
        size_type				size() const {
			return this->__size;
		}
        size_type				max_size() const {
			return __allocator.max_size();
		}
        size_type				capacity() const {
			return this->__capacity;
		}
        
        // (capacity) resize
        void					resize( size_type n, value_type val = value_type() ) {
			if (n < __size) {
				while (__size > n) {
					__allocator.destroy(__sequence + __size - 1);
					__size--;
				}
			}
			else {
				if (n <= __capacity) {
					for (size_type i = __size; i < n; i++) {
						__allocator.construct(&__sequence[i], val);
					}
					__size = n;
				}
				else {
					this->insert(iterator(__sequence + __size), n - __size, val);
				}
			}
		}

        // (capacity) empty
        bool					empty() const {
			return this->__size == 0;
		}

        // (capacity) reserve
        void					reserve( size_type n ) {
			if (n > this->max_size())
				throw ft::LengthError("vector");
			if (n > __capacity) {
				T*	tmp = __allocator.allocate(n);
				for (size_type i = 0; i < __size; i++) {
					__allocator.construct(&tmp[i], __sequence[i]);
					__allocator.destroy(&__sequence[i]);
				}
				__allocator.deallocate(__sequence, __capacity);
				__capacity = n;
				__sequence = tmp;
			}
		}

        // (Element access) operator[]
        reference				operator[] ( size_type n ) {
			return *(this->__sequence + n);
		}
        const_reference			operator[] ( size_type n ) const {
			return *(this->__sequence + n);
		}

        // (Element access) at
        reference				at ( size_type n ) {
			if (n > __size)
				throw ft::OutOfRange("vector");
			return *(this->__sequence + n);
		}
        const_reference			at ( size_type n ) const {
			if (n > __size)
				throw ft::OutOfRange("vector");
			return *(this->__sequence + n);
		}

        // (Element access) front
        reference				front () {
            return __sequence[0];
        }
        const_reference			front () const {
			return __sequence[0];
		}

        // (Element access) back
        reference				back () {
			return __sequence[__size - 1];
		}
        const_reference			back () const {
			return __sequence[__size - 1];
		}

        // (Modifiers) assign
        template < class InputIterator >
        void					assign ( InputIterator first, InputIterator last,
			typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type* = NULL ) {
				size_type n = last - first;
				if (n > __capacity) {
					try {
						__allocator.deallocate(__sequence, __capacity);
						__capacity = n;
						__sequence = __allocator.allocate(__capacity);
					} catch (std::exception &ex) {
						throw ft::LengthError("vector");
					}
				}
				__size = 0;
				while (first != last) {
					__allocator.construct(&__sequence[__size], *first);
					__size++;
					first++;
				}
		}

        void					assign ( size_type n, const value_type& val ) {
			if (n < 0)
				throw ft::LengthError("vector");
			if (n > __capacity) {
				try {
					__allocator.deallocate(__sequence, __capacity);
					__capacity = n;
					__sequence = __allocator.allocate(__capacity);
				} catch (std::exception &ex) {
					throw ft::LengthError("vector");
				}
			}
			for (__size = 0; __size < n; __size++)
				__allocator.construct(&__sequence[__size], val);
		}

        // (Modifiers) push_back
        void					push_back( const value_type& val ) {
			try {
				if (__size == __capacity) {
					if (__capacity == 0)
						__capacity += 1;
					else
						__capacity *= 2;
					pointer		tmp = __allocator.allocate(__capacity);
					for (size_type i = 0; i < __size; i++) {
						__allocator.construct(&tmp[i], __sequence[i]);
						__allocator.destroy(&__sequence[i]);
					}
					__allocator.deallocate(__sequence, __size);
					__sequence = tmp;
				}
				__allocator.construct(&__sequence[__size], val);
				__size++;
			} catch (std::exception &ex) {
				throw ft::LengthError("vector");
			}
		}

        // (Modifiers) pop_back
        void					pop_back() {
			if (__size > 0) {
				__allocator.destroy(__sequence + __size - 1);
				__size--;
			}
		}

        // (Modifiers) insert
        iterator				insert( iterator position, const value_type& val ) {
			try {
				iterator	pos = this->begin();
				size_type	pp = 0;
				while (pos != position) {
					pos++;
					pp++;
				}
				if (__size == __capacity) {
					size_type	__old_capacity = __capacity;
					if (__capacity == 0)
						__capacity += 1;
					else
						__capacity *= 2;
					T*		tmp = __allocator.allocate(__capacity);
					for (size_type i = 0; i < pp; i++) {
						__allocator.construct(&tmp[i], __sequence[i]);
						__allocator.destroy(&__sequence[i]);
					}
					tmp[pp] = val;
					__size++;
					for (size_type i = pp + 1; i < __size; i++) {
						__allocator.construct(&tmp[i], __sequence[i - 1]);
						__allocator.destroy(&__sequence[i - 1]);
					}
					__allocator.deallocate(__sequence, __old_capacity);
					__sequence = tmp;
				}
				else
				{
					for (size_type i = pp + 1; i < __size + 1; i++) {
						__allocator.construct(&__sequence[i], __sequence[i - 1]);
						__allocator.destroy(&__sequence[i - 1]);
					}
					__allocator.construct(&__sequence[pp], val);
					__size++;
				}
				return iterator(__sequence + pp);
			} catch (std::exception &ex) {
				throw ft::LengthError("vector");
			}
		}
        void					insert( iterator position, size_type n, const value_type& val ) {
			try {
				iterator	pos = this->begin();
				size_type	pp = 0;
				while (pos != position) {
					pos++;
					pp++;
				}
				if (__size + n > __capacity) {
					size_type	__old_capacity = __capacity;
					if (__size + n <= __capacity * 2)
						__capacity *= 2;
					else
						__capacity = __size + n;
					T*		tmp = __allocator.allocate(__capacity);
					for (size_type i = 0; i < pp; i++) {
						__allocator.construct(&tmp[i], __sequence[i]);
						__allocator.destroy(&__sequence[i]);
					}
					for (size_type i = 0; i < n; i++)
						__allocator.construct(&tmp[i + pp], val);
					__size += n;
					for (size_type i = pp + n; i < __size; i++) {
						__allocator.construct(&tmp[i], __sequence[i - n]);
						__allocator.destroy(&__sequence[i - n]);
					}
					__allocator.deallocate(__sequence, __old_capacity);
					__sequence = tmp;
				}
				else {
					for (size_type i = pp + n; i < __size + n; i++) {
						__allocator.construct(&__sequence[i], __sequence[i - n]);
						__allocator.destroy(&__sequence[i - n]);
					}

					for (size_type i = 0; i < n; i++) {
						__sequence[pp + i] = val;
					}
					__size += n;
				}
			} catch (std::exception &ex) {
				throw ft::LengthError("vector");
			}
		}
        template < class InputIterator >
        void					insert( iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type* = NULL ) {
			try {
				iterator it (first);
				size_type	n = ft::distance(first, last);
				iterator	pos = this->begin();
				size_type	pp = 0;
				while (pos != position) {
					pos++;
					pp++;
				}
				if (__size + n > __capacity) {
					size_type	__old_capacity = __capacity;
					if (__size + n <= __capacity * 2)
						__capacity *= 2;
					else
						__capacity = __size + n;
					T*		tmp = __allocator.allocate(__capacity);
					for (size_type i = 0; i < pp; i++) {
						__allocator.construct(&tmp[i], __sequence[i]);
						__allocator.destroy(&__sequence[i]);
					}
					for (size_type i = 0; i < n; i++)
						__allocator.construct(&tmp[i + pp], *it++);
					__size += n;
					for (size_type i = pp + n; i < __size; i++) {
						__allocator.construct(&tmp[i], __sequence[i - n]);
						__allocator.destroy(&__sequence[i - n]);
					}
					__allocator.deallocate(__sequence, __old_capacity);
					__sequence = tmp;
				}
				else {
					for (size_type i = pp + n; i < __size + n; i++) {
						__allocator.construct(&__sequence[i], __sequence[i - n]);
						__allocator.destroy(&__sequence[i - n]);
					}

					for (size_type i = 0; i < n; i++) {
						__allocator.construct(&__sequence[pp + i], *it);
						it++;
					}
					__size += n;
				}
			} catch (std::exception &ex) {
				throw ft::LengthError("vector");
			}
		}

        // (Modifiers) erase
        iterator				erase( iterator position ) {
			iterator	pos = this->begin();
			size_type	pp = 0;
			while (pos != position) {
				pos++;
				pp++;
			}
			for (size_type i = pp; i + 1 < __size; i++) {
				__allocator.destroy(__sequence + i);
				__allocator.construct(&__sequence[i], __sequence[i + 1]);
			}
			__size--;
			return iterator(__sequence + pp);
		}
        iterator				erase( iterator first, iterator last ) {
			size_type	n = ft::distance(first, last);
			iterator	pos = this->begin();
			size_type	pp = 0;
			while (pos != first) {
				pos++;
				pp++;
			}
			for (size_type i = pp; i + n < __size; i++) {
				__allocator.destroy(__sequence + i);
				__allocator.construct(&__sequence[i], __sequence[i + n]);
			}
			__size -= n;
			return iterator(__sequence + pp);
		}

        // (Modifiers) swap
        void					swap( vector &vec ) {
			try {
				T*			__tmp__sequence = vec.__sequence;
				size_type	__tmp_cap = vec.__capacity;
				size_type	__tmp_size = vec.__size;
				allocator_type __tmp_alloc = vec.__allocator;

				vec.__sequence = this->__sequence;
				vec.__capacity = this->__capacity;
				vec.__size = this->__size;
				vec.__allocator = this->__allocator;

				this->__sequence = __tmp__sequence;
				this->__capacity = __tmp_cap;
				this->__size = __tmp_size;
				this->__allocator = __tmp_alloc;
			} catch (std::exception &ex) {
				throw ft::LengthError("vector");
			}
		}

        // (Modifiers) clear
        void					clear() {
			for (size_type i = 0; i < __size; i++)
				__allocator.destroy(__sequence + i);
			__size = 0;
		}

        // (Allocator) get_allocator
        allocator_type			get_allocator() const {
			return __allocator;
		}
};



template < class U, class Alloc >
bool	operator== (const ft::vector<U, Alloc>& lhs, const ft::vector<U, Alloc>&rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template < class U, class Alloc >
bool	operator!= (const ft::vector<U, Alloc>& lhs, const ft::vector<U, Alloc>&rhs) {
	return !(lhs == rhs);
}

template < class U, class Alloc >
bool	operator< (const ft::vector<U, Alloc>& lhs, const ft::vector<U, Alloc>&rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template < class U, class Alloc >
bool	operator<= (const ft::vector<U, Alloc>& lhs, const ft::vector<U, Alloc>&rhs) {
	return (lhs < rhs || lhs == rhs);
}

template < class U, class Alloc >
bool	operator> (const ft::vector<U, Alloc>& lhs, const ft::vector<U, Alloc>&rhs) {
	return !(lhs < rhs) && (lhs != rhs);
}

template < class U, class Alloc >
bool	operator>= (const ft::vector<U, Alloc>& lhs, const ft::vector<U, Alloc>&rhs) {
	return (lhs > rhs || lhs == rhs);;
}

template < class U, class Alloc >
void	swap ( ft::vector<U, Alloc> &lhs, ft::vector<U, Alloc> &rhs) {
	lhs.swap(rhs);
}

#endif
