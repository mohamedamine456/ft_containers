#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../namespace.hpp"
#include "pair.hpp"
#include "redBlackTree.hpp"

// iterator class
template < class Category, class T >
class ft::iterator : public ft::iterator_base <ft::random_access_iterator_tag, T>
{
    private:
        T*  __p;
    public:
        iterator () {}
        iterator ( T* x ) : __p(x) {}
        template < class U>
        iterator ( const iterator<ft::random_access_iterator_tag, U>& cp ) : __p(cp.base()) {}
        virtual ~iterator() {}
        T*  base() const {
            return this->__p;
        }
        iterator& operator= ( const iterator& cp ) {
            this->__p = cp.__p;
            return *this;
        } 
        iterator& operator++ () {
            ++__p;
            return *this;
        }
        iterator operator++ ( int ) {
            iterator tmp(*this);
            ++__p;
            return tmp;
        }
        iterator& operator-- () {
            --__p;
            return *this;
        }
        iterator operator-- ( int ) {
            iterator tmp(*this);
            --__p;
            return tmp;
        }
        typename ft::iterator_base<Category, T>::reference operator*() const {
            return *__p;
        }
        typename ft::iterator_base<Category, T>::pointer operator-> () const {
            return __p;
        }
        iterator operator+ ( typename ft::iterator_base<Category, T>::difference_type n ) const {
            return iterator(__p + n);
        }
        iterator operator- ( typename ft::iterator_base<Category, T>::difference_type n ) const {
            return iterator(__p - n);
        }
        iterator& operator+= ( typename ft::iterator_base<Category, T>::difference_type n ) {
            __p += n;
            return *this;
        }
        iterator& operator-= ( typename ft::iterator_base<Category, T>::difference_type n ) {
            __p -= n;
            return *this;
        }
        T &operator[] ( typename ft::iterator_base<Category, T>::difference_type n ) const {
            return *(*this + n);
        }
        typename ft::iterator_base<Category, T>::difference_type operator- (iterator<Category, T> sec) {
            return this->__p - sec.__p;
        }
};

// relational operators for iterator
template< class Category, class T>
bool    operator== (ft::iterator<Category, T> fir, ft::iterator<Category, T> sec) {
    return fir.base() == sec.base();
}

template< class Category, class T>
bool    operator!= (ft::iterator<Category, T> fir, ft::iterator<Category, T> sec) {
    return fir.base() != sec.base();
}

template< class Category, class T>
bool    operator> (ft::iterator<Category, T> fir, ft::iterator<Category, T> sec) {
    return fir.base() > sec.base();
}

template< class Category, class T>
bool    operator>= (ft::iterator<Category, T> fir, ft::iterator<Category, T> sec) {
    return fir.base() >= sec.base();
}

template< class Category, class T>
bool    operator< (ft::iterator<Category, T> fir, ft::iterator<Category, T> sec) {
    return fir.base() < sec.base();
}

template< class Category, class T>
bool    operator<= (ft::iterator<Category, T> fir, ft::iterator<Category, T> sec) {
    return fir.base() <= sec.base();
}

template< class Category, class T>
ft::iterator<Category, T> operator+ (
    typename ft::iterator<Category, T>::difference_type n,
    ft::iterator<Category, T>& it)
{
    return ft::iterator<Category, T>(it.base() + n);
}

template< class Category, class T>
typename ft::iterator<Category, T>::difference_type operator- (
    ft::iterator<Category, T>& fir,
    ft::iterator<Category, T>& sec)
{
    return fir.base() - sec.base();
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
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
			while (tmp != nullptr && tmp->leftChild != nullptr && tmp->leftChild->empty != true)
				tmp = tmp->leftChild;
			return tmp;
        }

        Node<Key, Value>	*maximum(Node<Key, Value> *node) {
			Node<Key, Value>	*tmp = node;
			while (tmp != nullptr && tmp->rightChild != nullptr && tmp->rightChild->empty != true)
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
            this->__root = mp_it.root();
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
        Node<Key, Value>    *root() const {
            return this->__root;
        }
        
        map_iterator    &operator++() {
            if (this->__node->empty == false)
            {
                if (this->__node == maximum(this->__root))
                    this->__node = this->__node->rightChild;
                else
                    this->__node = successor(this->__node);
            }
            return *this;
        }
        map_iterator    operator++(int) {
            map_iterator    tmp(*this);
            if (this->__node != nullptr && this->__node->rightChild != nullptr)
            {
                if (this->__node == maximum(this->__root))
                    this->__node = this->__node->rightChild;
                else
                    this->__node = successor(this->__node);
            }
            return tmp;
        }
		map_iterator    &operator--() {
            if (this->__node->empty == true) {
                this->__node = maximum(this->__root);
            }
            else
                this->__node = predecessor(this->__node);
            return *this;
        }
        map_iterator    operator--(int) {
            map_iterator    tmp(*this);
            if (this->__node->empty == true) {
                this->__node = maximum(this->__root);
            }
            else
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

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// reverse_iterator class
template < class Iter >
class ft::reverse_iterator: public ft::iterator_base<typename ft::iterator_traits<Iter>::iterator_category,
                                    typename ft::iterator_traits<Iter>::value_type,
                                    typename ft::iterator_traits<Iter>::difference_type,
                                    typename ft::iterator_traits<Iter>::pointer,
                                    typename ft::iterator_traits<Iter>::reference>
{
    protected:
        Iter    __current;
    public:
        typedef Iter												iterator_type;
        typedef typename ft::iterator_traits<Iter>::reference		reference;
        typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
        typedef typename ft::iterator_traits<Iter>::pointer			pointer;

        reverse_iterator(): __current() {}
        explicit reverse_iterator(iterator_type c): __current(c) {}
        template < class U >
        reverse_iterator(const reverse_iterator<U>& rv_iter): __current(rv_iter.base()) {}
        virtual ~reverse_iterator() {}
        Iter    base() const {
            return __current;
        }
        reference operator*() const {
            Iter tmp = __current;
            return *(--tmp);
        }
        pointer operator-> () const {
			return &(operator*());
        }
        reverse_iterator& operator++ () {
            --__current;
            return *this;
        }
        reverse_iterator operator++ (int) {
            reverse_iterator tmp(*this);
            --__current;
            return tmp;
        }
        reverse_iterator& operator-- () {
            ++__current;
            return *this;
        }
        reverse_iterator operator-- (int) {
            reverse_iterator tmp(*this);
            ++__current;
            return tmp;
        }
        reverse_iterator operator+ (difference_type n) const {
            return reverse_iterator(__current - n);
        }
        reverse_iterator operator- (difference_type n) const {
            return reverse_iterator(__current + n);
        }
        reverse_iterator& operator+= (difference_type n) {
            __current -= n;
            return *this;
        }
        reverse_iterator& operator-= (difference_type n) {
            __current += n;
            return *this;
        }
        reference operator[] (difference_type n) const {
            return *(*this + n);
        }
};

// relational operators for reverse_iterator
template < class Iterator >
bool operator== ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs ) {
    return lhs.base() == rhs.base();
}

template < class Iterator >
bool operator!= ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs ) {
    return lhs.base() != rhs.base();
}

template < class Iterator >
bool operator< ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs ) {
    return lhs.base() > rhs.base();
}

template < class Iterator >
bool operator<= ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs ) {
    return lhs.base() >= rhs.base();
}

template < class Iterator >
bool operator> ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs ) {
    return lhs.base() < rhs.base();
}
template < class Iterator >
bool operator>= ( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs ) {
    return lhs.base() <= rhs.base();
}

template < class Iterator >
ft::reverse_iterator<Iterator> operator+ (
    typename ft::reverse_iterator<Iterator>::difference_type n,
    const ft::reverse_iterator<Iterator>& it)
{
    return ft::reverse_iterator<Iterator>(it.base() - n);
}

template < class Iterator >
typename ft::reverse_iterator<Iterator>::difference_type operator- (
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs) {
        return static_cast<typename ft::reverse_iterator<Iterator>::difference_type>(rhs.base() - lhs.base());
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// advance function
template < class It >
void    _advance(It &inputIterator,
    typename ft::iterator_traits<It>::difference_type n,
    ft::input_iterator_tag)
{
    while (n > 0) {
        --n;
        ++inputIterator;
    }
}

template < class It >
void    _advance(It &bidirectionalIterator,
    typename ft::iterator_traits<It>::difference_type n,
    ft::bidirectional_iterator_tag)
{
    while (n > 0) {
        --n;
        ++bidirectionalIterator;
    }
    while (n < 0) {
        ++n;
        ++bidirectionalIterator;
    }
}

template < class It >
void    _advance(It &randomAccessIterator,
    typename ft::iterator_traits<It>::difference_type n,
    ft::random_access_iterator_tag)
{
    randomAccessIterator += n;
}

template < class InputIterator, class Distance >
void	ft::advance(InputIterator &inputIterator, Distance n)
{
	_advance(inputIterator, (typename ft::iterator_traits<InputIterator>::difference_type)(n) , typename ft::iterator_traits<InputIterator>::iterator_category());
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// distance function
template < class InputIterator >
typename ft::iterator_traits<InputIterator>::difference_type	_distance(InputIterator first, InputIterator last, ft::input_iterator_tag)
{
	typename ft::iterator_traits<InputIterator>::difference_type result = 0;

	while (first != last) {
		first++;
		result++;
	}
	return (result);
}

template < class InputIterator >
typename ft::iterator_traits<InputIterator>::difference_type	_distance(InputIterator first, InputIterator last, ft::random_access_iterator_tag)
{
	return last - first;
}

template < class InputIterator >
typename ft::iterator_traits<InputIterator>::difference_type	ft::distance(InputIterator first, InputIterator last)
{
	return _distance(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// equal
template < class InputIterator1, class InputIterator2 >
bool ft::equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    while (first1 != last1) {
        if (!(*first1 == *first2))
            return false;
        ++first1;
        ++first2;
    }
    return true;
}

template < class InputIterator1, class InputIterator2, class BinaryPredicate >
bool ft::equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
    while (first1 != last1) {
        if (!pred(*first1, *first2))
            return false;
        ++first1;
        ++first2;
    }
    return true;	
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// lexicographical_compare
template < class InputIterator1, class InputIterator2 >
bool ft::lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1) {
        if (first2 == last2 || *first2 < *first1)
            return (false);
        else if (*first1 < *first2)
            return true;
        ++first1;
        ++first2;
    }
    return first2 != last2;
}

template < class InputIterator1, class InputIterator2, class Compare >
bool ft::lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp)
{
    while (first1 != last1) {
        if (first2 == last2 || comp(*first2, *first1))
            return (false);
        else if (comp(*first1, *first2))
            return true;
        ++first1;
        ++first2;
    }
    return first2 != last2;
}

#endif