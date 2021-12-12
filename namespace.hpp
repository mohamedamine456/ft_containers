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
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	// iterator
	template < class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T& >
	struct iterator_base
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template < class Category, class T >
	class iterator;

	// iterator functions
	template < class InputIterator, class Distance >
	void	advance(InputIterator &inputIterator, Distance n);

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


	// map iterator
	template <class Category, class Pair>
	class map_iterator;

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
	template < class T >
	struct is_integral { static const bool value = false; };
	template <> struct is_integral<bool> { static const bool value = true; };
	template <> struct is_integral<char> { static const bool value = true; };
	template <> struct is_integral<char16_t> { static const bool value = true; };
	template <> struct is_integral<char32_t> { static const bool value = true; };
	template <> struct is_integral<wchar_t> { static const bool value = true; };
	template <> struct is_integral<signed char> { static const bool value = true; };
	template <> struct is_integral<short int> { static const bool value = true; };
	template <> struct is_integral<int> { static const bool value = true; };
	template <> struct is_integral<long int> { static const bool value = true; };
	// template <> struct is_integral<long long int> { static const bool value = true; };
	template <> struct is_integral<unsigned char> { static const bool value = true; };
	template <> struct is_integral<unsigned short int> { static const bool value = true; };
	template <> struct is_integral<unsigned int> { static const bool value = true; };
	template <> struct is_integral<unsigned long int> { static const bool value = true; };
	// template <> struct is_integral<unsigned long long int> { static const bool value = true; };

	// vector
	template < class T, class Allocator = std::allocator<T> >
	class vector;

	// stack
	template < class T, class Container = vector <T> >
	class stack;
	
	// map
	template < class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair <const Key, T> > >
	class map;

	// set
	template < class Key, class T, class Compare, class Allocator >
	class set;

	// Exceptions
	class LengthError: public std::exception {
		private:
			const char	*error;
		public:
			LengthError( const char *err ) : error(err) {}
			virtual const char * what() const throw() {
				return error;
			}
	};

	class OutOfRange: public std::exception {
		private:
			const char *error;
		public:
			OutOfRange( const char *err ) : error(err) {}
			virtual const char * what() const throw () {
				return error;
			}
	};
}

#endif
