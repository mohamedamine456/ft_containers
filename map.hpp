#ifndef MAP_HPP
#define MAP_HPP

#include "namespace.hpp"
#include "utils/redBlackTree.hpp"
#include "utils/iterator.hpp"

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
        typedef ft::map_iterator<bidirectional_iterator_tag, value_type>			iterator;
        typedef ft::map_iterator<bidirectional_iterator_tag, const value_type >     const_iterator;
        typedef ft::reverse_iterator<iterator>										reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type				difference_type;
        typedef std::size_t															size_type;
        class value_compare {
            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}
            public:
                value_compare () {}
                typedef bool			result_type;
                typedef value_type		first_argumanet_type;
                typedef value_type		second_argument_type;
                bool operator() ( const value_type& x, const value_type& y) const {
                    return comp(x.first, y.first);
                }
        };
        typedef typename Allocator::template rebind<RedBlackTree<key_type, mapped_type, key_compare, Allocator> >::other       Tree_Allocator;
	private:
		// attributes
		
		allocator_type																__allocator;
        Tree_Allocator                                                              __tree_allocator;
		size_type																	__size;
		RedBlackTree<key_type, mapped_type, key_compare, Allocator>					__rbtree;
		key_compare																	__key_comp;
		value_compare																__value_compare;
	public:

        // constructors
		// default constructor
        explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) {
            (void)comp;
            (void)alloc;
            __size = 0;
        }

		// range constructor
        template < class Iterator >
        map ( Iterator first, Iterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) {
            (void)comp;
            (void)alloc;
            __size = 0;
            while (first != last) {
                Node<const Key, T> *tmp = __rbtree.searchNode(__rbtree.getRoot(), first->first);
                if (tmp != __rbtree.getNullNode())
                    tmp->data->second = first->second;
                else
                    __rbtree.insertNode(__rbtree.newNode(first->first, first->second));
                ++first;
                __size++;
            }
        }

		// copy constructor
        map ( const map& mp ) {
            *this = mp;
		}
        // destructor
        ~map() {
            Node<const Key, T>  *min_node = __rbtree.minimum(__rbtree.getRoot());
            if (min_node == nullptr || min_node == __rbtree.getNullNode())
                return;
            else
            {
                Node<const Key, T>  *next_min = __rbtree.successor(min_node);
                while (next_min != nullptr && next_min != __rbtree.getNullNode())
                {
                    __rbtree.deleteNode(next_min);
                    next_min = __rbtree.successor(min_node);
                    __size--;
                }
                __rbtree.deleteNode(min_node);
                __size--;
            }
        }

        // operator=
        map& operator= ( const map& mp ) {
            __tree_allocator.destroy(&(this)->__rbtree);
            __tree_allocator.construct(&(this->__rbtree));
            this->insert(mp.begin(), mp.end());
            this->__size = mp.__size;
            this->__value_compare = value_compare(mp.__value_compare);
            this->__key_comp = key_compare(mp.__key_comp);
            this->__allocator = allocator_type(mp.__allocator);
            return *this;
		}

        // (Iterators) begin & end
        iterator								begin() {
            return iterator(__rbtree.minimum(__rbtree.getRoot()), __rbtree.getRoot());
		}
        const_iterator							begin() const {
            return const_iterator(__rbtree.minimum(__rbtree.getRoot()), __rbtree.getRoot());
		}

        iterator								end() {
            iterator tmp(__rbtree.maximum(__rbtree.getRoot()), __rbtree.getRoot());
            tmp++;
            return iterator(tmp);
		}
        const_iterator							end() const {
            const_iterator tmp(__rbtree.maximum(__rbtree.getRoot()), __rbtree.getRoot());
            tmp++;
            return const_iterator(tmp);
		}

        // (Iterators) rbegin & rend
        reverse_iterator						rbegin() {
            return reverse_iterator(end());
		}
        const_reverse_iterator					rbegin() const {
            return const_reverse_iterator(end());
		}

        reverse_iterator						rend() {
            return reverse_iterator(begin());
		}
        const_reverse_iterator					rend() const {
            return const_reverse_iterator(begin());
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
            Node<const Key, T>    *tmp = __rbtree.searchNode(__rbtree.getRoot(), k);
            if (tmp != __rbtree.getNullNode()) {
                return tmp->data->second;
            }
            else {
                tmp = __rbtree.newNode(k, mapped_type());
                __rbtree.insertNode(tmp);
                __size++;
                return tmp->data->second;
            }
		}

        // (Modifiers) insert
        ft::pair<iterator, bool>					insert( const value_type& val ) {
            Node<const Key, T>    *tmp = __rbtree.searchNode(__rbtree.getRoot(), val.first);
            if (tmp != __rbtree.getNullNode()) {
                return ft::make_pair(iterator(tmp, __rbtree.getRoot()), false);
            }
            else {
                tmp = __rbtree.newNode(val.first, val.second);
                __rbtree.insertNode(tmp);
                __size++;
                return ft::make_pair(iterator(tmp, __rbtree.getRoot()), true);
            }
		}

        iterator								insert( iterator position, const value_type& val ) {
            (void)position;
            Node<const Key, T>    *tmp = __rbtree.searchNode(__rbtree.getRoot(), val.first);
            if (tmp != __rbtree.getNullNode()) {
                return iterator(tmp, __rbtree.getRoot());
            }
            else {
                tmp = __rbtree.newNode(val.first, val.second);
                __rbtree.insertNode(tmp);
                __size++;
                return iterator(tmp, __rbtree.getRoot());
            }
		}

        template < class InputIterator >
        void									insert( InputIterator first, InputIterator last ) {
            while (first != last) {
                Node<const Key, T>    *tmp = __rbtree.searchNode(__rbtree.getRoot(), first->first);
                if (tmp == __rbtree.getNullNode()) {
                    tmp = __rbtree.newNode(first->first, first->second);
                    __rbtree.insertNode(tmp);
                    __size++;
                }
                first++;
            }
		}

        // (Modifiers) erase
        void									erase( iterator position ) {
            Node<const Key, T>    *tmp = __rbtree.searchNode(__rbtree.getRoot(), (*position).first);
            if (tmp != __rbtree.getNullNode()) {
                __rbtree.deleteNode(tmp);
                __size--;
            }
		}
        size_type								erase( const key_type& k ) {
            Node<const Key, T>    *tmp = __rbtree.searchNode(__rbtree.getRoot(), k);
            if (tmp != __rbtree.getNullNode()) {
                __rbtree.deleteNode(tmp);
                __size--;
                return 1;
            }
            return 0;
		}
        void									erase( iterator first, iterator last ) {
            iterator    tmp_it = first;
            Node<const Key, T>    *tmp;
            while (tmp_it != last)
            {
                ++first;
                tmp = __rbtree.searchNode(__rbtree.getRoot(), (*tmp_it).first);
                if (tmp != nullptr && tmp != __rbtree.getNullNode()) {
                    __rbtree.deleteNode(tmp);
                    __size--;
                }
                tmp_it = first;
            }
		}

        // (Modifiers) swap
        void									swap( map& mp ) {
            allocator_type												tmp_alloc = mp.__allocator;
            size_type													tmp_size = mp.__size;
            RedBlackTree<key_type, mapped_type, key_compare, Allocator>	tmp_rbtree = mp.__rbtree;
			key_compare													tmp_key_comp = mp.__key_comp;
			value_compare												tmp_value_comp = mp.__value_compare;

			mp.__allocator = this->__allocator;
			mp.__size = this->__size;
			mp.__rbtree = this->__rbtree;
			mp.__key_comp = this->__key_comp;
			mp.__value_compare = this->__value_compare;

			this->__allocator = tmp_alloc;
			this->__size = tmp_size;
			this->__rbtree = tmp_rbtree;
			this->__key_comp = tmp_key_comp;
			this->__value_compare = tmp_value_comp;
		}

        // (Modifiers) clear
        void									clear() {
            Node<const Key, T>  *min_node = __rbtree.minimum(__rbtree.getRoot());
            if (min_node == nullptr || min_node == __rbtree.getNullNode())
                return;
            else
            {
                Node<const Key, T>  *next_min = __rbtree.successor(min_node);
                while (next_min != nullptr && next_min != __rbtree.getNullNode())
                {
                    __rbtree.deleteNode(next_min);
                    next_min = __rbtree.successor(min_node);
                    __size--;
                }
                __rbtree.deleteNode(min_node);
                __size--;
            }
		}

        // (Observers) key_comp & value_comp
        key_compare								key_comp() const {
            return this->__key_comp;
		}
        value_compare							value_comp() const {
            return this->__value_compare;
		}

        // (Operations) find
        iterator								find( const key_type& k ) {
            Node<const Key, T>    *tmp = __rbtree.searchNode(__rbtree.getRoot(), k);
            if (tmp != __rbtree.getNullNode()) {
                return iterator(tmp, __rbtree.getRoot());
            }
            else {
                return this->end();
            }
		}
        const_iterator							find( const key_type& k ) const {
            Node<const Key, T>    *tmp =__rbtree.searchNode(__rbtree.getRoot(), k);
            if (tmp != __rbtree.getNullNode()) {
                return const_iterator(tmp, __rbtree.getRoot());
            }
            else {
                return this->end();
            }
		}

        // (Operations) count
        size_type								count( const key_type& k ) const {
            Node<const Key, T>    *node = __rbtree.searchNode(__rbtree.getRoot(), k);
            if (node != __rbtree.getNullNode())
                return (1);
            return (0);
		}

        // (Operations) lower_bound & upper_bound
        iterator								lower_bound( const key_type& k ) {
            Node<const Key, T>    *tmp =__rbtree.searchNode(__rbtree.getRoot(), k);
			Node<const Key, T>    *tmp2;
			if (tmp != __rbtree.getNullNode())
				return iterator(tmp, __rbtree.getRoot());
			else {
				tmp = __rbtree.minimum(__rbtree.getRoot());
				tmp2 = tmp;
				while (tmp->data->first < k)
				{
					tmp2 = tmp;
					tmp = __rbtree.successor(tmp);
				}
				return iterator(tmp2, __rbtree.getRoot());
			}
		}
        const_iterator							lower_bound( const key_type& k ) const {
            Node<const Key, T>    *tmp =__rbtree.searchNode(__rbtree.getRoot(), k);
			Node<const Key, T>    *tmp2;
			if (tmp != __rbtree.getNullNode())
				return const_iterator(tmp, __rbtree.getRoot());
			else {
				tmp = __rbtree.minimum(__rbtree.getRoot());
				tmp2 = tmp;
				while (tmp->data->first < k)
				{
					tmp2 = tmp;
					tmp = __rbtree.successor(tmp);
				}
				return const_iterator(tmp2, __rbtree.getRoot());
			}
		}

        iterator								upper_bound( const key_type& k ) {
            Node<const Key, T>    *tmp =__rbtree.searchNode(__rbtree.getRoot(), k);
			Node<const Key, T>    *tmp2;
			if (tmp != __rbtree.getNullNode())
				return iterator(tmp, __rbtree.getRoot());
			else {
				tmp = __rbtree.maximum(__rbtree.getRoot());
				tmp2 = tmp;
				while (tmp->data->first < k)
				{
					tmp2 = tmp;
					tmp = __rbtree.predecessor(tmp);
				}
				return iterator(tmp2, __rbtree.getRoot());
			}
		}
        const_iterator							upper_bound( const key_type& k ) const {
            Node<const Key, T>    *tmp =__rbtree.searchNode(__rbtree.getRoot(), k);
			Node<const Key, T>    *tmp2;
			if (tmp != __rbtree.getNullNode())
				return const_iterator(tmp, __rbtree.getRoot());
			else {
				tmp = __rbtree.maximum(__rbtree.getRoot());
				tmp2 = tmp;
				while (tmp->data->first < k)
				{
					tmp2 = tmp;
					tmp = __rbtree.predecessor(tmp);
				}
				return const_iterator(tmp2, __rbtree.getRoot());
			}
		}

        // (Operations equal_range
        pair< const_iterator, const_iterator>	equal_range( const key_type& k ) const {
			Node<const Key, T>	*tmp1 =__rbtree.searchNode(__rbtree.getRoot(), k);
			Node<const Key, T>	*tmp2 = nullptr;
			if (tmp1 != __rbtree.getNullNode())
				return ft::pair<const_iterator, const_iterator>(const_iterator(tmp1, __rbtree.getRoot()), const_iterator(tmp2, __rbtree.getRoot()));
			return ft::pair<const_iterator, const_iterator>(const_iterator(tmp1, __rbtree.getRoot()), const_iterator(tmp2, __rbtree.getRoot()));
        }
        pair<iterator, iterator>				equal_range( const key_type& k) {
            (void)k;
			Node<const Key, T>	*tmp1 =__rbtree.searchNode(__rbtree.getRoot(), k);
			Node<const Key, T>	*tmp2 = nullptr;
			if (tmp1 != __rbtree.getNullNode())
				return ft::pair<iterator, iterator>(iterator(tmp1, __rbtree.getRoot()), iterator(tmp2, __rbtree.getRoot()));
			return ft::pair<iterator, iterator>(iterator(tmp1, __rbtree.getRoot()), iterator(tmp2, __rbtree.getRoot()));
        }

        // (Allocator) get_allocator
        allocator_type							get_allocator() const {
			return __allocator;
		}

        // should add relational operators & swap
};

template < class Key, class T, class Compare, class Alloc >
bool    operator== (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    if (lhs.size() != rhs.size())
        return false;
    return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template < class Key, class T, class Compare, class Alloc > 
bool    operator!= (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    return !(lhs == rhs);
}

template < class Key, class T, class Compare, class Alloc > 
bool    operator< (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template < class Key, class T, class Compare, class Alloc > 
bool    operator<= (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    return (lhs < rhs || lhs == rhs);
}

template < class Key, class T, class Compare, class Alloc > 
bool    operator> (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    return !(lhs < rhs) && (lhs != rhs);
}

template < class Key, class T, class Compare, class Alloc > 
bool    operator>= (const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs) {
    return !(lhs < rhs);
}

#endif
