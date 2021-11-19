#ifndef MAP_HPP
#define MAP_HPP

#include "namespace.hpp"
#include "utils/redBlackTree.hpp"

template < class Key, class T, class Compare, class Allocator >
class ft::map
{
    private:
        // properties
		
		Allocator																	__allocator;
		size_t																		__size;
        RedBlackTree                                                    			__rbtree;
    public: 
        typedef Key																	key_type;
        typedef T																	mapped_type;
        typedef ft::pair<const key_type, mapped_type>								value_type;
        typedef	Compare																key_compare;
        typedef Allocator															allocator_type;
        typedef value_type&															reference;
        typedef const value_type&													const_reference;
        typedef typename allocator_type::pointer									pointer;
        typedef typename allocator_type::const_pointer								const_pointer;
        typedef ft::bidirectional_iterator<bidirectional_iterator_tag, T>			iterator;
        typedef ft::bidirectional_iterator<bidirectional_iterator_tag, const T>		const_iterator;
        typedef ft::reverse_iterator<iterator>										reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type				difference_type;
        typedef std::size_t															size_type;
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
		// default constructor
        explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) {

        }

		// range constructor
        template < class InputIterator >
        map ( InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) {

        }

		// copy constructor
        map ( const map& mp ) {

		}
        // destructor
        ~map() {

		}

        // operator=
        map& operator= ( const map& mp ) {

		}

        // (Iterators) begin & end
        iterator								begin() {

		}
        const_iterator							begin() const {

		}

        iterator								end() {

		}
        const_iterator							end() const {

		}

        // (Iterators) rbegin & rend
        reverse_iterator						rbegin() {

		}
        const_reverse_iterator					rbegin() const {

		}

        reverse_iterator						rend() {

		}
        const_reverse_iterator					rend() const {

		}

        // (Capacity) empty
        bool									empty() const {

		}

        // (Capacity) size & max_size
        size_type								size() const {

		}
        size_type								max_size() const {

		}

        // (Element access) operator[]
        mapped_type&							operator[] ( const key_type& k ) {

		}

        // (Modifiers) insert
        pair<iterator, bool>					insert( const value_type& val ) {

		}
        iterator								insert( iterator position, const value_type& val ) {

		}
        template < class InputIterator >
        void									insert( InputIterator first, InputIterator last ) {

		}

        // (Modifiers) erase
        void									erase( iterator position ) {

		}
        size_type								erase( const key_type& k ) {

		}
        void									erase( iterator first, iterator last ) {

		}

        // (Modifiers) swap
        void									swap( map& mp ) {

		}

        // (Modifiers) clear
        void									clear() {

		}

        // (Observers) key_comp & value_comp
        key_compare								key_comp() const {

		}
        value_compare							value_comp() const {

		}

        // (Operations) find
        iterator								find( const key_type& k ) {

		}
        const_iterator							find( const key_type& k ) const {

		}

        // (Operations) count
        size_type								count( const key_type& k ) const {

		}

        // (Operations) lower_bound & upper_bound
        iterator								lower_bound( const key_type& k ) {

		}
        const_iterator							lower_bound( const key_type& k ) const {

		}

        iterator								upper_bound( const key_type& k ) {

		}
        const_iterator							upper_bound( const key_type& k ) const {

		}

        // (Operations equal_range
        pair< const_iterator, const_iterator>	equal_range( const key_type& k ) const;
        pair<iterator, iterator>				equal_range( const key_type& k);

        // (Allocator) get_allocator
        allocator_type							get_allocator() const {
			return __allocator;
		}

        // should add relational operators & swap
};

template < class Key, class T, class Compare, class Alloc >
bool    operator== (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {

}

template < class Key, class T, class Compare, class Alloc > 
bool    operator!= (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    
}

template < class Key, class T, class Compare, class Alloc > 
bool    operator< (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    
}

template < class Key, class T, class Compare, class Alloc > 
bool    operator<= (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    
}

template < class Key, class T, class Compare, class Alloc > 
bool    operator> (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    
}

template < class Key, class T, class Compare, class Alloc > 
bool    operator>= (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    
}

template < class Key, class T, class Compare, class Alloc >
void swap(ft::map<Key, T, Compare, Alloc> &lhs, ft::map<Key, T, Compare, Alloc> &rhs) {
    lhs.swap(rhs);
}

#endif
