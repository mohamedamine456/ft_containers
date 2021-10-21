#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "namespace.hpp"

template < class T, class Allocator >
class ft::vector {
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
	typedef size_t														size_type;
};

#endif