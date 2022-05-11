#ifndef SET_HPP
#define SET_HPP

#include "namespace.hpp"
#include "utils/setRedBlackTree.hpp"
#include "utils/iterator.hpp"
#include "vector.hpp"

template < class T, class Compare, class Allocator >
class ft::set
{
	public:
		typedef T																	key_type;
		typedef T																	value_type;
		typedef Compare																key_compare;
		typedef Compare																value_compare;
		typedef Allocator															allocator_type;
		typedef typename allocator_type::reference									reference;
		typedef typename allocator_type::const_reference							const_reference;
		typedef typename allocator_type::pointer									pointer;
		typedef typename allocator_type::const_pointer								const_pointer;
		typedef ft::set_iterator<bidirectional_iterator_tag, value_type>			iterator;
		typedef ft::set_iterator<bidirectional_iterator_tag, value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>										reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type				difference_type;
		typedef std::size_t															size_type;

		typedef typename Allocator::template rebind<SetRedBlackTree<value_type, key_compare, Allocator> >::other	Tree_Allocator;
		typedef typename Allocator::template rebind<SetNode<value_type> >::other								Node_Allocator;
	
	private:
		allocator_type																__allocator;
		Tree_Allocator																__tree_alloc;
		Node_Allocator																__node_alloc;
		size_type																	__size;
		SetRedBlackTree<value_type, key_compare, Allocator>							__srbtree;
		key_compare																	__key_comp;
		value_compare																__value_compare;
	
	public:
		explicit set ( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) {
			(void)comp;
			(void)alloc;
			__size = 0;
		}

		template < class Iterator >
		set ( Iterator first, Iterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) {
			(void)comp;
			(void)alloc;
			__size = 0;
			while (first != last) {
				SetNode<value_type> *tmp = __srbtree.searchNode(__srbtree.getRoot(), *first);
				if (tmp != __srbtree.getNullNode())
					return;
				else {
					tmp = __srbtree.newNode(*first);
					__srbtree.insertNode(tmp);
					__size++;
				}
				++first;
			}
		}

		set ( const set& st ) {
			*this = st;
		}

		~set() {
			SetNode<value_type> *min_node = __srbtree.minimum(__srbtree.getRoot());
			if (min_node == nullptr || min_node == __srbtree.getNullNode())
			{
				__srbtree.deallocate(__srbtree.getNullNode());
				__node_alloc.deallocate(__srbtree.getNullNode(), 1);
				return ;
			}
			else {
				SetNode<value_type> *next_min = __srbtree.successor(min_node);
				while (next_min != nullptr && next_min != __srbtree.getNullNode()) {
					__srbtree.deleteNode(next_min);
					next_min = __srbtree.successor(min_node);
					__size--;
				}
				__srbtree.deleteNode(min_node);
				__size--;
			}
			__srbtree.deallocate(__srbtree.getNullNode());
			__node_alloc.deallocate(__srbtree.getNullNode(), 1);
		}

		set&	operator= ( const set& st ) {
			if (this != &st) {
				this->clear();
				__srbtree.deallocate(__srbtree.getNullNode());
				__node_alloc.deallocate(__srbtree.getNullNode(), 1);
				__tree_alloc.destroy(&__srbtree);
				__tree_alloc.construct(&(this->__srbtree));
				this->insert(st.begin(), st.end());
				this->__size = st.__size;
				this->__value_compare = value_compare(st.__value_compare);
				this->__key_comp = key_compare(st.__key_comp);
				this->__allocator = allocator_type(st.__allocator);
			}
			return *this;
		}

		// (Iterators) begin & end
		iterator								begin() {
			return iterator(__srbtree.minimum(__srbtree.getRoot()), __srbtree.getRoot());
		}
		const_iterator							begin() const {
			return const_iterator(__srbtree.minimum(__srbtree.getRoot()), __srbtree.getRoot());
		}

		iterator								end() {
			iterator tmp(__srbtree.maximum(__srbtree.getRoot()), __srbtree.getRoot());
			tmp++;
			return iterator(tmp);
		}
		const_iterator							end() const {
			const_iterator tmp(__srbtree.maximum(__srbtree.getRoot()), __srbtree.getRoot());
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
			if (__srbtree.getRoot() == __srbtree.getNullNode()) {
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

		// (Modifiers) insert
		ft::pair<iterator, bool>					insert( const value_type& val ) {
			SetNode<value_type>    *tmp = __srbtree.searchNode(__srbtree.getRoot(), val);
			if (tmp != __srbtree.getNullNode()) {
				return ft::make_pair(iterator(tmp, __srbtree.getRoot()), false);
			}
			else {
				tmp = __srbtree.newNode(val);
				__srbtree.insertNode(tmp);
				__size++;
				return ft::make_pair(iterator(tmp, __srbtree.getRoot()), true);
			}
		}

		iterator								insert( iterator position, const value_type& val ) {
			(void)position;
			SetNode<value_type>    *tmp = __srbtree.searchNode(__srbtree.getRoot(), val);
			if (tmp != __srbtree.getNullNode()) {
				return iterator(tmp, __srbtree.getRoot());
			}
			else {
				tmp = __srbtree.newNode(val);
				__srbtree.insertNode(tmp);
				__size++;
				return iterator(tmp, __srbtree.getRoot());
			}
		}

		template < class InputIterator >
		void									insert( InputIterator first, InputIterator last ) {
			while (first != last) {
				SetNode<value_type>    *tmp = __srbtree.searchNode(__srbtree.getRoot(), *first);
				if (tmp == __srbtree.getNullNode()) {
					tmp = __srbtree.newNode(*first);
					__srbtree.insertNode(tmp);
					__size++;
				}
				first++;
			}
		}

		// (Modifiers) erase
		void									erase( iterator position ) {
			SetNode<value_type>    *tmp = __srbtree.searchNode(__srbtree.getRoot(), *position);
			if (tmp != __srbtree.getNullNode()) {
				__srbtree.deleteNode(tmp);
				__size--;
			}
		}

		size_type								erase( const key_type& val ) {
			SetNode<value_type>    *tmp = __srbtree.searchNode(__srbtree.getRoot(), val);
			if (tmp != __srbtree.getNullNode()) {
				__srbtree.deleteNode(tmp);
				__size--;
				return 1;
			}
			return 0;
		}
		void									erase( iterator first, iterator last ) {
			SetNode<value_type>	*tmp;
			ft::vector<SetNode<value_type> *> nodes;
			while (first != last)
			{
				tmp = __srbtree.searchNode(__srbtree.getRoot(), *first);
				if (tmp != nullptr && tmp != __srbtree.getNullNode()) {
					nodes.push_back(tmp);
				}
				else
					return;
				++first;
			}
			for (size_t i = 0; i < nodes.size(); i++)
			{
				__srbtree.deleteNode(nodes[i]);
				__size--;
			}
			nodes.clear();
		}

		// (Modifiers) swap
		void									swap( set& st ) {
			allocator_type												tmp_alloc = st.__allocator;
			size_type													tmp_size = st.__size;
			SetRedBlackTree<value_type, key_compare, Allocator>			tmp_rbtree = st.__srbtree;
			key_compare													tmp_key_comp = st.__key_comp;
			value_compare												tmp_value_comp = st.__value_compare;
			Tree_Allocator												tmp_tree_alloc = st.__tree_alloc;
			Node_Allocator												tmp_node_alloc = st.__node_alloc;

			st.__allocator = this->__allocator;
			st.__tree_alloc = this->__tree_alloc;
			st.__node_alloc = this->__node_alloc;
			st.__size = this->__size;
			st.__srbtree = this->__srbtree;
			st.__key_comp = this->__key_comp;
			st.__value_compare = this->__value_compare;

			this->__allocator = tmp_alloc;
			this->__tree_alloc = tmp_tree_alloc;
			this->__node_alloc = tmp_node_alloc;
			this->__size = tmp_size;
			this->__srbtree = tmp_rbtree;
			this->__key_comp = tmp_key_comp;
			this->__value_compare = tmp_value_comp;
		}

		void									clear() {
			SetNode<value_type> *min_node = __srbtree.minimum(__srbtree.getRoot());
			if (min_node == nullptr || min_node == __srbtree.getNullNode())
				return;
			else
			{
				SetNode<value_type>  *next_min = __srbtree.successor(min_node);
				while (next_min != nullptr && next_min != __srbtree.getNullNode())
				{
					__srbtree.deleteNode(next_min);
					next_min = __srbtree.successor(min_node);
					__size--;
				}
				__srbtree.deleteNode(min_node);
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
		iterator								find( const value_type& val ) {
			SetNode<value_type>    *tmp = __srbtree.searchNode(__srbtree.getRoot(), val);
			if (tmp != __srbtree.getNullNode()) {
				return iterator(tmp, __srbtree.getRoot());
			}
			else {
				return this->end();
			}
		}

		// (Operations) count
		size_type								count( const value_type& val ) const {
			SetNode<value_type>	*node = __srbtree.searchNode(__srbtree.getRoot(), val);
			if (node != __srbtree.getNullNode())
				return (1);
			return (0);
		}

		// (Operations) lower_bound & upper_bound
		iterator								lower_bound( const value_type& val ) const {
			SetNode<value_type>	*tmp =__srbtree.searchNode(__srbtree.getRoot(), val);
			if (tmp != __srbtree.getNullNode())
				return iterator(tmp, __srbtree.getRoot());
			else {
				tmp = __srbtree.minimum(__srbtree.getRoot());
				while (*(tmp->data) < val)
					tmp = __srbtree.successor(tmp);
				return iterator(tmp, __srbtree.getRoot());
			}
		}

		iterator								upper_bound( const value_type& val ) const {
			SetNode<value_type>    *tmp =__srbtree.searchNode(__srbtree.getRoot(), val);
			if (tmp == __srbtree.getNullNode())
			{
				tmp = __srbtree.maximum(__srbtree.getRoot());
				while (__key_comp(val, *(tmp->data)))
					tmp = __srbtree.predecessor(tmp);
			}
			tmp = __srbtree.successor(tmp);
			return iterator(tmp, __srbtree.getRoot());
		}

		// (Operations equal_range
		pair<iterator, iterator>				equal_range( const value_type& val) const {
			SetNode<value_type>	*tmp =__srbtree.searchNode(__srbtree.getRoot(), val);
			if (tmp != __srbtree.getNullNode())
			{
				iterator it1(tmp, __srbtree.getRoot());
				iterator it2(__srbtree.successor(tmp), __srbtree.getRoot());
				return ft::pair<iterator, iterator>(it1, it2);
			}
			else {
				tmp = __srbtree.maximum(__srbtree.getRoot());
				while (__key_comp(val, *(tmp->data)))
					tmp = __srbtree.predecessor(tmp);
				tmp = __srbtree.successor(tmp);
				iterator it1(tmp, __srbtree.getRoot());
				return ft::pair<iterator, iterator>(it1, it1);
			}
		}

		// (Allocator) get_allocator
		allocator_type							get_allocator() const {
			return __allocator;
		}
};

// should add relational operators & swap

template < class T, class Compare, class Alloc >
bool    operator== (const ft::set<T, Compare, Alloc> &lhs, const ft::set<T, Compare, Alloc> &rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template < class T, class Compare, class Alloc > 
bool    operator!= (const ft::set<T, Compare, Alloc> &lhs, const ft::set<T, Compare, Alloc> &rhs) {
	return !(lhs == rhs);
}

template <  class T, class Compare, class Alloc > 
bool    operator< (const ft::set<T, Compare, Alloc> &lhs, const ft::set<T, Compare, Alloc> &rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template < class T, class Compare, class Alloc > 
bool    operator<= (const ft::set<T, Compare, Alloc> &lhs, const ft::set<T, Compare, Alloc> &rhs) {
	return (lhs < rhs || lhs == rhs);
}

template < class T, class Compare, class Alloc > 
bool    operator> (const ft::set<T, Compare, Alloc> &lhs, const ft::set<T, Compare, Alloc> &rhs) {
	return !(lhs < rhs) && (lhs != rhs);
}

template < class T, class Compare, class Alloc > 
bool    operator>= (const ft::set<T, Compare, Alloc> &lhs, const ft::set<T, Compare, Alloc> &rhs) {
	return !(lhs < rhs);
}

template < class T, class Compare, class Alloc >
void    swap (ft::set<T, Compare, Alloc> &lhs, ft::set<T, Compare, Alloc> &rhs) {
	lhs.swap(rhs);
}

#endif