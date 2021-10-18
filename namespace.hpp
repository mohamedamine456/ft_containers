#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <iostream>
#include <memory>

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector;

	template < class T, class Container = vector <T> >
	class stack;
	
	template < class key,
		class T,
		class Compare = std::less<key>,
		class Allocator = std::allocator<std::pair <const key, T> > >
	class map;
	
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
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	// iterator
	template < class Category, class T, class Distance = ptrdiff_t,
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

	// relational operators for reverse_iterator
	template < class Iterator >
	bool operator== ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs );

	template < class Iterator >
	bool operator!= ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs );

	template < class Iterator >
	bool operator< ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs );

	template < class Iterator >
	bool operator<= ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs );

	template < class Iterator >
	bool operator> ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs );

	template < class Iterator >
	bool operator>= ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs );

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

	// pair relational operators
	template < class T1, class T2 >
	bool operator== ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs );

	template < class T1, class T2 >
	bool operator!= ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs );

	template < class T1, class T2 >
	bool operator< ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs );

	template < class T1, class T2 >
	bool operator<= ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs );

	template < class T1, class T2 >
	bool operator> ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs );

	template < class T1, class T2 >
	bool operator>= ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs );

	// make_pair
	template < class T1, class T2 >
	pair< T1, T2> make_pair (T1 x, T2 y);
};

#endif