#ifndef STACK_HPP
#define STACK_HPP

#include "namespace.hpp"

template < class T, class Container >
class ft::stack
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

#endif
