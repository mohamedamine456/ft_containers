#ifndef MAP_HPP
#define MAP_HPP

#include "namespace.hpp"

template < class key,
		 class T,
		 class Compare = std::less<key>,
		 class Allocator = std::allocator<std::pair <const key, T> > >
class map {
};

#endif
