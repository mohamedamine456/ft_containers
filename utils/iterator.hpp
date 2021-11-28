#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../namespace.hpp"
#include "pair.hpp"
#include "redBlackTree.hpp"
#include "reverse_iterator.hpp"
#include "map_iterator.hpp"

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