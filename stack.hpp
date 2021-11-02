#ifndef STACK_HPP
#define STACK_HPP

#include "namespace.hpp"

template < class T, class Container >
class ft::stack
{
	private:
		Container															__container;
	public:
		typedef T															value_type;
		typedef Container													container_type;
		typedef std::size_t													size_type;

		// constructor
		explicit stack( const container_type& ctnr = container_type() ): __container(ctnr) {	// default constructor	
		}
		// destructor
		virtual ~stack() {

		}

		const container_type container() const {
			return this->__container;
		}

		// Member functions
		// empty
		bool				empty() const {
			return __container.empty();
		}

		// size
		size_type			size() const {
			return __container.size();
		}

		// top
		value_type&			top() {
			return __container.back();
		}
		const value_type&	top() const {
			return __container.back();
		}

		// push
		void				push( const value_type& val ) {
			__container.push_back(val);
		}

		// pop
		void				pop() {
			__container.pop_back();
		}
};

// relational operators

template < class T, class Container >
bool operator== (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return lhs.container() == rhs.container();
}

template < class T, class Container >
bool operator!= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return lhs.container() != rhs.container();
}

template < class T, class Container >
bool operator< (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return lhs.container() < rhs.container();
}

template < class T, class Container >
bool operator<= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return lhs.container() <= rhs.container();
}

template < class T, class Container >
bool operator> (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return lhs.container() > rhs.container();
}

template < class T, class Container >
bool operator>= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs) {
	return lhs.container() >= rhs.container();
}

#endif
