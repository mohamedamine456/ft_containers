#ifndef MAP_HPP
#define MAP_HPP

#include "namespace.hpp"
#include "utils/redBlackTree.hpp"

template < class Key, class T, class Compare, class Allocator >
class ft::map
{
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
        typedef ft::map_iterator<Key, T>                                            iterator;
        typedef ft::map_iterator<const Key, const T>                                const_iterator;
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
	private:
		// attributes
		
		allocator_type																__allocator;
		size_type																	__size;
		RedBlackTree<Key, T, Compare, Allocator>									__rbtree;
		key_compare																	__key_comp;
		value_compare																__value_compare;
	public:

        // constructors
		// default constructor
        explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) {
            (void)alloc;
            (void)comp;
            __size = 0;
        }

		// range constructor
        template < class InputIterator >
        map ( InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) {
            while (first!= last) {
                __rbtree.insertNode(*first);
                first++;
            }
        }

		// copy constructor
        map ( const map& mp ) {
            *this = mp;
		}
        // destructor
        ~map() {

		}

        // operator=
        map& operator= ( const map& mp ) {
            this->__rbtree = mp.__rbtree;
            this->__size = mp.__size;
            this->__value_compare = mp.__value_compare;
            this->__key_comp = mp.__key_comp;
            this->__allocator = mp.__allocator;
            return *this;
		}

        // (Iterators) begin & end
        iterator								begin() {
            return iterator(__rbtree.minimum());
		}
        const_iterator							begin() const {
            return const_iterator(__rbtree.minimum());
		}

        iterator								end() {
            return iterator(__rbtree.maximum());
		}
        const_iterator							end() const {
            return const_iterator(__rbtree.maximum());
		}

        // (Iterators) rbegin & rend
        reverse_iterator						rbegin() {
            return reverse_iterator(__rbtree.maximum());
		}
        const_reverse_iterator					rbegin() const {
            return const_reverse_iterator(__rbtree.maximum());
		}

        reverse_iterator						rend() {
            return reverse_iterator(__rbtree.minimum());
		}
        const_reverse_iterator					rend() const {
            return const_reverse_iterator(__rbtree.minimum());
		}

        // (Capacity) empty
        bool									empty() const {
            if (__rbtree.getRoot() == __rbtree.getNullNode()) {
                return true;
            }
            return false;
		}

        // (Capacity) size & max_size
        size_type								size() const {
            return this->__size;
		}
        size_type								max_size() const {
            return __allocator.max_size();
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
            Node<Key, T>    *node = __rbtree.searchNode(__rbtree.getRoot(), k);
            if (node != __rbtree.nullNode())
                return (1);
            return (0);
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
        pair< const_iterator, const_iterator>	equal_range( const key_type& k ) const {

        }
        pair<iterator, iterator>				equal_range( const key_type& k) {
            
        }

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
