#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"

template < class T, class Allocator>
class ft::vector
{
    private:
        // properties
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
		class LengthError: public std::exception {
			virtual const char * what() const throw() {
				return "vector: length_error";
			}
		};

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
				throw LengthError();
			}
		}
        // template < class InputIterator >
        // vector ( InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type() ) {						// constructor with iterators
		// 	__size = ft::distance(first, last);
        //     try {
		// 		__sequence = __allocator.allocate(__size);
		// 		for (int i = 0; first != last; i++, first++)
        //             __sequence[i] = *first;
        //         __capacity = __size;
                
		// 	} catch (std::exception &ex) {
		// 		throw LengthError();
		// 	}
		// }

		vector ( const vector& vec ) {
            *this = vec;
        }																							// copy constructor

        // destructor
        ~vector() {
            __allocator.deallocate(__sequence, __capacity);
            __allocator.destroy(__sequence);
            __size = 0;
            __capacity = 0;
        }

        // operator=
        vector&	operator= ( const vector& vec ) {
            this->__sequence = vec.__sequence;
            this->__size = vec.__size;
            this->__capacity = vec.__capacity;
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
			// return reverse_iterator (__sequence);
		}
        const_reverse_iterator	rbegin() const {
			// return const_reverse_iterator (__sequence);
		}
        
        reverse_iterator		rend();
        const_reverse_iterator	rend() const;

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
        void					reserve( size_type n );

        // (Element access) operator[]
        reference				operator[] ( size_type n ) {
			return *(this->__sequence + n);
		}
        const_reference			operator[] ( size_type n ) const {
			return *(this->__sequence + n);
		}

        // (Element access) at
        reference				at ( size_type n );
        const_reference			at ( size_type n ) const;

        // (Element access) front
        reference				front ( size_type n );
        const_reference			front ( size_type n ) const;

        // (Element access) back
        reference				back ( size_type n );
        const_reference			back ( size_type n ) const;

        // (Modifiers) assign
        template < class InputIterator >
        void					assign ( InputIterator first, InputIterator last );

        void					assign ( size_type n, const value_type& val );

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
				}
				__allocator.deallocate(__sequence, __size);
				__sequence = tmp;
			}
			__sequence[__size] = val;
			__size++;
		}

        // (Modifiers) pop_back
        void					pop_back();

        // (Modifiers) insert
        iterator				insert( iterator position, const value_type& val );
        void					insert( iterator position, size_type n, const value_type& val );
        template < class InputIterator >
        void					insert( iterator position, InputIterator first, InputIterator last );

        // (Modifiers) erase
        iterator				erase( iterator position );
        iterator				erase( iterator first, iterator last );

        // (Modifiers) swap
        void					swap( vector &vec );

        // (Modifiers) clear
        void					clear();

        // (Allocator) get_allocator
        allocator_type			get_allocator() const;

        // should add relational operators and swap function     
};

#endif