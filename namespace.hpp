#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <iostream>
#include <deque>
#include <memory>

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
			class vector;

	template < class T, class Container = ft::vector <T> >
			class stack;
	
	template < class key,
			 class T,
			 class Compare = std::less<key>,
			 class Allocator = std::allocator<std::pair <const key, T> > >
		class map;
}

#endif
