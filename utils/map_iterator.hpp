#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "../namespace.hpp"

// map iterator

template <class Category, class Pair>
class ft::map_iterator: public ft::iterator_base<ft::bidirectional_iterator_tag, Node<typename Pair::First, typename Pair::Second> >
{
    public:
        typedef typename Pair::First			Key;
		typedef typename Pair::Second			Value;
    private:
        Node<Key, Value>	*minimum(Node<Key, Value> *node) {
			Node<Key, Value>	*tmp = node;
			while (tmp->leftChild != nullptr && tmp->leftChild->empty != true)
				tmp = tmp->leftChild;
			return tmp;
        }

        Node<Key, Value>	*maximum(Node<Key, Value> *node) {
			Node<Key, Value>	*tmp = node;
			while (tmp->rightChild != nullptr && tmp->rightChild->empty != true)
				tmp = tmp->rightChild;
			return tmp;
        }
        Node<Key, Value>	*successor(Node<Key, Value> *node) {
			Node<Key, Value>	*tmp = node;
			Node<Key, Value>	*tmp1;
			if (tmp->rightChild->empty != true)
				return this->minimum(tmp->rightChild);
			tmp1 = tmp->parent;
			while (tmp1 != nullptr && tmp1->empty != true && tmp == tmp1->rightChild)
			{
				tmp = tmp1;
				tmp1 = tmp1->parent;
			}
			return tmp1;
        }

        Node<Key, Value>	*predecessor(Node<Key, Value> *node) {
			Node<Key, Value>	*tmp = node;
			Node<Key, Value>	*tmp1;
			if (tmp->leftChild->empty != true)
				return this->maximum(tmp->leftChild);
			tmp1 = tmp->parent;
			while (tmp1 != nullptr && tmp1->empty != true && tmp == tmp1->leftChild)
			{
				tmp = tmp1;
				tmp1 = tmp1->parent;
			}
			return tmp1;
        }

        // attributes
        Node<const Key, Value>	*__node;
		Node<const Key, Value>	*__root;

    public:

        typedef		std::ptrdiff_t          		    difference_type;
        typedef		ft::pair<const Key, Value>    		value_type;
        typedef		ft::pair<const Key, Value>*			pointer;
		typedef		ft::pair<const Key, Value>&			reference;
		typedef		ft::bidirectional_iterator_tag	    iterator_category;

        map_iterator () {}
		
        map_iterator (Node<Key, Value> *node, Node<Key, Value> *root): __node(node), __root(root) {}
        
        template<class T>
        map_iterator (Node<Key, T> *node, Node<Key, T> *root): __node(node), __root(root) {}
        
        template < class P >
        map_iterator( const map_iterator<ft::bidirectional_iterator_tag, P > &mp_it ) {
            this->__node = mp_it.base();
        }

        operator map_iterator<const Category, const Pair>() const{
            return map_iterator<const Category, const Pair>(this->__node, this->__root);
        }

        virtual ~map_iterator() {}

        map_iterator    &operator= ( const map_iterator &mp_it ) {
            this->__node = mp_it.__node;
            return *this;
        }
        Node<Key, Value>    *base() const {
            return this->__node;
        }
        
        map_iterator    &operator++() {
            this->__node = successor(this->__node);
            return *this;
        }
        map_iterator    operator++(int) {
            map_iterator    tmp(*this);
            this->__node = successor(this->__node);
            return tmp;
        }
		map_iterator    &operator--() {
            this->__node = predecessor(this->__node);
            return *this;
        }
        map_iterator    operator--(int) {
            map_iterator    tmp(*this);
            this->__node = predecessor(this->__node);
            return tmp;
        }
		ft::pair<Key, Value>	&operator*() const {
            return *(this->__node->data);
        }
        typename ft::pair<Key, Value>    *operator->() const {
            return this->__node->data;
        }


};

template< class Category, class Pair>
bool    operator== (ft::map_iterator<Category, Pair> fir, ft::map_iterator<Category, Pair> sec) {
    return fir.base() == sec.base();
}

template< class Category, class Pair >
bool    operator!= (ft::map_iterator<Category, Pair> fir, ft::map_iterator<Category, Pair> sec) {
    return fir.base() != sec.base();
}

#endif