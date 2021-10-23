#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "namespace.hpp"
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
        template < class InputIterator >
        vector ( InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type() ) {						// constructor with iterators
			__size = ft::distance(first, last);
            try {
				__sequence = __allocator.allocate(__size);
				for (int i = 0; first != last; i++, first++)
                    __sequence[i] = *first;
                __capacity = __size;
                
			} catch (std::exception &ex) {
				throw LengthError();
			}
		}
		vector ( const vector& vec ) {
            *this = vec;
        }																							// copy constructor

        // destructor
        ~vector() {
            __allocator.deallocate(__capacity);
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
            iterator	it;
        }
        const_iterator			begin() const;
        
        iterator				end();
        const_iterator			end() const;

        // (Iterators) rbegin & rend
        reverse_iterator		rbegin();
        const_reverse_iterator	rbegin() const;
        
        reverse_iterator		rend();
        const_reverse_iterator	rend() const;

        // (capacity) size & max_size & capacity
        size_type				size() const {
			return this->__size;
		}
        size_type				max_size() const {
			return this->__max_size;
		}
        size_type				capacity() const {
			return this->__capacity;
		}
        
        // (capacity) resize
        void					resize( size_type n, value_type val = value_type() );

        // (capacity) empty
        bool					empty() const;

        // (capacity) reserve
        void					reserve( size_type n );

        // (Element access) operator[]
        reference				operator[] ( size_type n );
        const_reference			operator[] ( size_type n ) const;

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
        void					push_back( const value_type& val );

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