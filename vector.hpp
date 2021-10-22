#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "namespace.hpp"

template < class T, class Allocator>
class ft::vector
{
    private:
        // properties
        T*																	sequence;
        // T*																	arr;
        Allocator															alloc;
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
			sequence = alloc.allocate(0);

        }
        explicit vector ( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() );	// construct with range initialize
        template < class InputIterator >
        vector ( InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type() );						// constructor with iterators
        vector ( const vector& vec );																							// copy constructor

        // destructor
        ~vector();

        // operator=
        vector&	operator= ( const vector& vec );

        // (Iterators) begin & end
        iterator				begin();
        const_iterator			begin() const;
        
        iterator				end();
        const_iterator			end() const;

        // (Iterators) rbegin & rend
        reverse_iterator		rbegin();
        const_reverse_iterator	rbegin() const;
        
        reverse_iterator		rend();
        const_reverse_iterator	rend() const;

        // (capacity) size & max_size & capacity
        size_type				size() const;
        size_type				max_size() const;
        size_type				capacity() const;
        
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