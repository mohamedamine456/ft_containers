#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <iostream>
#include <memory>

namespace ft {
	
	// iterators_tags
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// terator_traits
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t				difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t				difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	// iterator
	template < class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T& >
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	// iterator functions
	template < class InputIterator >
	void	advance(InputIterator &inputIterator, typename iterator_traits<InputIterator>::difference_type n);

	template < class InputIterator >
	typename iterator_traits<InputIterator>::difference_type	distance(InputIterator first, InputIterator last);

	// back_insert_iterator
	template < class Container >
	class back_insert_iterator;

	// back_inserter function
	template < class Container>
	back_insert_iterator< Container > back_inserter (Container &c);

	// front_insert_iterator
	template < class Container >
	class front_insert_iterator;

	// front_inserter function
	template < class Container >
	front_insert_iterator< Container > front_inserter (Container &c);


	// insert_iterator
	template < class Container >
	class insert_iterator;

	// inserter
	template < class Container >
	insert_iterator< Container > inserter (Container &c, typename Container::iterator iter);

	// reverse_iterator class
	template < class Iter >
	class reverse_iterator;

	// equal
	template < class InputIterator1, class InputIterator2 >
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

	template < class InputIterator1, class InputIterator2, class BinaryPredicate >
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred);

	// lexicographical_compare
	template < class InputIterator1, class InputIterator2 >
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2);

	template < class InputIterator1, class InputIterator2, class Compare >
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2,
									Compare comp);

	// pair
	template < class T1, class T2 >
	struct pair;

	// make_pair
	template < class T1, class T2 >
	pair< T1, T2> make_pair (T1 x, T2 y);

	// enable_if
	template < bool B, class T = void >
	struct	enable_if {};

	template < class T >	// define type if B is true otherwise don't
	struct enable_if <true, T>
	{
		typedef T type;
	};

	// is_integral
	

	// vector
	template < class T, class Allocator = std::allocator<T> >
	class vector;
	// {
	// 	private:
	// 		// properties
	// 		T*																	sequence;
	// 		T*																	arr;
	// 		Allocator															alloc;
	// 	public:
	// 		typedef T															value_type;
	// 		typedef Allocator													allocator_type;
	// 		typedef value_type&													reference;
	// 		typedef const value_type&											const_reference;
	// 		typedef typename allocator_type::pointer							pointer;
	// 		typedef typename allocator_type::const_pointer						const_pointer;
	// 		typedef ft::iterator<random_access_iterator_tag, T>					iterator;
	// 		typedef ft::iterator<random_access_iterator_tag, const	T>			const_iterator;
	// 		typedef ft::reverse_iterator<iterator>								reverse_iterator;
	// 		typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
	// 		typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
	// 		typedef std::size_t													size_type;


	// 		// constructors
	// 		explicit vector ( const allocator_type& alloc = allocator_type() );														// default
	// 		explicit vector ( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() );	// construct with range initialize
	// 		template < class InputIterator >
	// 		vector ( InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type() );						// constructor with iterators
	// 		vector ( const vector& vec );																							// copy constructor

	// 		// destructor
	// 		~vector();

	// 		// operator=
	// 		vector&	operator= ( const vector& vec );

	// 		// (Iterators) begin & end
	// 		iterator				begin();
	// 		const_iterator			begin() const;
			
	// 		iterator				end();
	// 		const_iterator			end() const;

	// 		// (Iterators) rbegin & rend
	// 		reverse_iterator		rbegin();
	// 		const_reverse_iterator	rbegin() const;
			
	// 		reverse_iterator		rend();
	// 		const_reverse_iterator	rend() const;

	// 		// (capacity) size & max_size & capacity
	// 		size_type				size() const;
	// 		size_type				max_size() const;
	// 		size_type				capacity() const;
			
	// 		// (capacity) resize
	// 		void					resize( size_type n, value_type val = value_type() );

	// 		// (capacity) empty
	// 		bool					empty() const;

	// 		// (capacity) reserve
	// 		void					reserve( size_type n );

	// 		// (Element access) operator[]
	// 		reference				operator[] ( size_type n );
	// 		const_reference			operator[] ( size_type n ) const;

	// 		// (Element access) at
	// 		reference				at ( size_type n );
	// 		const_reference			at ( size_type n ) const;

	// 		// (Element access) front
	// 		reference				front ( size_type n );
	// 		const_reference			front ( size_type n ) const;

	// 		// (Element access) back
	// 		reference				back ( size_type n );
	// 		const_reference			back ( size_type n ) const;

	// 		// (Modifiers) assign
	// 		template < class InputIterator >
	// 		void					assign ( InputIterator first, InputIterator last );

	// 		void					assign ( size_type n, const value_type& val );

	// 		// (Modifiers) push_back
	// 		void					push_back( const value_type& val );

	// 		// (Modifiers) pop_back
	// 		void					pop_back();

	// 		// (Modifiers) insert
	// 		iterator				insert( iterator position, const value_type& val );
	// 		void					insert( iterator position, size_type n, const value_type& val );
	// 		template < class InputIterator >
	// 		void					insert( iterator position, InputIterator first, InputIterator last );

	// 		// (Modifiers) erase
	// 		iterator				erase( iterator position );
	// 		iterator				erase( iterator first, iterator last );

	// 		// (Modifiers) swap
	// 		void					swap( vector &vec );

	// 		// (Modifiers) clear
	// 		void					clear();

	// 		// (Allocator) get_allocator
	// 		allocator_type			get_allocator() const;

	// 		// should add relational operators and swap function
			
	// };

	// stack
	template < class T, class Container = vector <T> >
	class stack
	{
		private:
			// properties
		public:
			typedef T															value_type;
			typedef Container													container_type;
			typedef std::size_t													size_type;

			// constructor
			explicit stack( const container_type& ctnr = container_type() );	// default constructor

			// destructor
			~stack();

			// Member functions
			// empty
			bool				empty() const;

			// size
			size_type			size() const;

			// top
			value_type&			top();
			const value_type&	top() const;

			// push
			void				push( const value_type& val );

			// pop
			void				pop();

			// should add relational operators

	};
	
	// map
	template < class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair <const Key, T> > >
	class map
	{
		private:
			// properties
		public:
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef pair<const key_type, mapped_type>							value_type;
			typedef	Compare														key_compare;
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
			class value_compare {
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}	// constructor;
				public:
					typedef bool			result_type;
					typedef value_type		first_argumanet_type;
					typedef value_type		second_argument_type;
					bool operator() ( const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};

			// constructors
			explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() );	// default constructor
			template < class InputIterator >
			map ( InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() );	// range constructor

			map ( const map& mp );		// copy constructor

			// destructor
			~map();

			// operator=
			map& operator= ( const map& mp );

			// (Iterators) begin & end
			iterator								begin();
			const_iterator							begin() const;

			iterator								end();
			const_iterator							end() const;

			// (Iterators) rbegin & rend
			reverse_iterator						rbegin();
			const_reverse_iterator					rbegin() const;

			reverse_iterator						rend();
			const_reverse_iterator					rend() const;

			// (Capacity) empty
			bool									empty() const;

			// (Capacity) size & max_size
			size_type								size() const;
			size_type								max_size() const;

			// (Element access) operator[]
			mapped_type&							operator[] ( const key_type& k );

			// (Modifiers) insert
			pair<iterator, bool>					insert( const value_type& val );
			iterator								insert( iterator position, const value_type& val );
			template < class InputIterator >
			void									insert( InputIterator first, InputIterator last );

			// (Modifiers) erase
			void									erase( iterator position );
			size_type								erase( const key_type& k );
			void									erase( iterator first, iterator last );

			// (Modifiers) swap
			void									swap( map& mp );

			// (Modifiers) clear
			void									clear();

			// (Observers) key_comp & value_comp
			key_compare								key_comp() const;
			value_compare							value_comp() const;

			// (Operations) find
			iterator								find( const key_type& k );
			const_iterator							find( const key_type& k ) const;

			// (Operations) count
			size_type								count( const key_type& k ) const;

			// (Operations) lower_bound & upper_bound
			iterator								lower_bound( const key_type& k );
			const_iterator							lower_bound( const key_type& k ) const;

			iterator								upper_bound( const key_type& k );
			const_iterator							upper_bound( const key_type& k ) const;

			// (Operations equal_range
			pair< const_iterator, const_iterator>	equal_range( const key_type& k ) const;
			pair<iterator, iterator>				equal_range( const key_type& k);

			// (Allocator) get_allocator
			allocator_type							get_allocator() const;

			// should add relational operators & swap
	};
};

#endif