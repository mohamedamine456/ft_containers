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
		explicit stack( const container_type& ctnr = container_type() ) {	// default constructor
			(void)ctnr;
			__container = container_type();
		}
		// destructor
		virtual ~stack(

		);

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
			__container.back();
		}
		const value_type&	top() const {
			__container.back();
		}

		// push
		void				push( const value_type& val ) {
			__container.push_back(val);
		}

		// pop
		void				pop() {
			__container.pop_back();
		}

		// should add relational operators
		
	};

#endif
