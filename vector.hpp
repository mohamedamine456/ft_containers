#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"

template < class T, class Allocator>
class ft::vector
{
    private:
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
        typedef ft::iterator<random_access_iterator_tag, const	T>			const_iterator;
        typedef ft::reverse_iterator<iterator>								reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
        typedef std::size_t													size_type;
        // constructors
        explicit vector ( const allocator_type& alloc = allocator_type() ) {													// default constructor
			__sequence = __allocator.allocate(0);
			__capacity = 0;
			__size = 0;
        }
        explicit vector ( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type () ) {	// construct with range initialize
			try {
				__sequence = __allocator.allocate(n);
				for (int i = 0; i < n; i++)
					__sequence[i] = val;
				__capacity = n;
				__size = n;
			} catch (std::exception &ex) {
				throw ft::LengthError("vector");
			}
		}
        template < class InputIterator >
        vector ( InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
                typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type* = NULL ) {						// constructor with iterators
			__size = ft::distance(first, last);
            try {
				__sequence = __allocator.allocate(__size);
				for (int i = 0; first != last; i++, first++)
                    __sequence[i] = *first;
                __capacity = __size;
                
			} catch (std::exception &ex) {
				throw ft::LengthError("vector");
			}
		}

		vector ( const vector& vec ) {							// copy constructor
            *this = vec;
        }

        // destructor
        ~vector() {
            __allocator.deallocate(__sequence, __capacity);
            __size = 0;
            __capacity = 0;
        }

        // operator=
        vector&	operator= ( const vector& vec ) {
			__allocator.deallocate(__sequence, this->__capacity);
			this->__sequence = __allocator.allocate(vec.__size);
            for (int i = 0; i < vec.__size; i++)
				this->__sequence[i] = vec.__sequence[i];
            this->__size = vec.__size;
            this->__capacity = vec.__capacity;
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
            return reverse_iterator(__sequence - 1);
        }
        const_reverse_iterator	rend() const {
            return const_reverse_iterator(__sequence - 1);
        }

        // (capacity) size & max_size & capacity
        size_type				size() const {
			return this->__size;
		}
        size_type				max_size() const {
			return std::numeric_limits<difference_type>::max();
		}
        size_type				capacity() const {
			return this->__capacity;
		}
        
        // (capacity) resize
        void					resize( size_type n, value_type val = value_type() ) {
			if (n < __size) {
				__size = n;
			}
			else {

			}
		}

        // (capacity) empty
        bool					empty() const {
			return this->begin() == this->end();
		}

        // (capacity) reserve
        void					reserve( size_type n ) {
			if (n > __capacity) {
				__capacity = n;
				__sequence = __allocator.allocate(__capacity);
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
			return *(this->__sequence + n);
		}
        const_reference			at ( size_type n ) const {
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
					__sequence[__size] = *first;
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
				__sequence[__size] = val;
				// __sequence[__size] = *(new value_type(val));
		}

        // (Modifiers) push_back
        void					push_back( const value_type& val ) {
			if (__size == __capacity) {
				if (__capacity == 0)
					__capacity += 1;
				else
					__capacity *= 2;
				pointer		tmp = __allocator.allocate(__capacity);
				for (int i = 0; i < __size; i++) {
					tmp[i] = __sequence[i];
					// tmp[i]] = *(new value_type(__sequence[i]));
				}
				__allocator.deallocate(__sequence, __size);
				__sequence = tmp;
			}
			__sequence[__size] = val;
			// __sequence[__size] = *(new value_type(val));
			__size++;
		}

        // (Modifiers) pop_back
        void					pop_back() {
			if (__size > 0)
				__size--;
		}

        // (Modifiers) insert
        iterator				insert( iterator position, const value_type& val ) {
			if (__size == __capacity) {
				if (__capacity == 0)
					__capacity += 1;
				else
					__capacity *= 2;
				pointer		tmp = __allocator.allocate(__capacity);
				for (int i = 0; i < __size; i++) {
					tmp[i] = __sequence[i];
				}
				__allocator.deallocate(__capacity);
				__sequence = tmp;
			}
			iterator	pos = this->begin();
			int			pp = 0;
			while (pos != position) {
				pos++;
				pp++;
			}
		}
        void					insert( iterator position, size_type n, const value_type& val ) {

		}
        template < class InputIterator >
        void					insert( iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type* = NULL ) {

		}

        // (Modifiers) erase
        iterator				erase( iterator position ) {

		}
        iterator				erase( iterator first, iterator last ) {

		}

        // (Modifiers) swap
        void					swap( vector &vec );

        // (Modifiers) clear
        void					clear() {
			// __allocator.destroy(__sequence);
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
	return !(lhs < rhs);
}

template < class U, class Alloc >
bool	operator>= (const ft::vector<U, Alloc>& lhs, const ft::vector<U, Alloc>&rhs) {
	return (lhs > rhs || lhs == rhs);;
}

#endif