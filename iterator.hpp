#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "namespace.hpp"


// advance function

template < class InputIterator >
void    _advance(InputIterator &inputIterator, typename ft::iterator_traits<InputIterator>::difference_type n, ft::input_iterator_tag)
{
    while (n > 0) {
        n--;
        inputIterator++;
    }
}

template < class BidirectionalIterator >
void    _advance(BidirectionalIterator &bidirectionalIterator, typename ft::iterator_traits<BidirectionalIterator>::difference_type n, ft::bidirectional_iterator_tag)
{
    while (n > 0) {
        n--;
        bidirectionalIterator++;
    }
    while (n < 0) {
        n++;
        bidirectionalIterator++;
    }
}

template < class RandomAccessIterator >
void    _advance(RandomAccessIterator &randomAccessIterator, typename ft::iterator_traits<RandomAccessIterator>::difference_type n, ft::random_access_iterator_tag)
{
    randomAccessIterator += n;
}

template < class InputIterator >
void	ft::advance(InputIterator &inputIterator, typename ft::iterator_traits<InputIterator>::difference_type n)
{
	_advance(inputIterator, n, ft::iterator_traits<InputIterator>::iterator_category());
}

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

template < class RandomAccessIterator >
typename ft::iterator_traits<RandomAccessIterator>::difference_type	_distance(RandomAccessIterator first, RandomAccessIterator last, ft::random_access_iterator_tag)
{
	return last - first;
}

template < class InputIterator >
typename ft::iterator_traits<InputIterator>::difference_type	ft::distance(InputIterator first, InputIterator last)
{
	_distance(first, last, ft::iterator_traits<InputIterator>::iterator_category());
}

// back_inserter

template < class Container>
ft::back_insert_iterator< Container > ft::back_inserter (Container &c)
{
    return ft::back_insert_iterator<Container>(c);
}


// front_inserter
template < class Container >
ft::front_insert_iterator< Container > ft::front_inserter (Container &c) {
    return front_insert_iterator<Container>(c);
}

// inserter
template < class Container >
ft::insert_iterator< Container > ft::inserter (Container &c, typename Container::iterator iter) {
    return insert_iterator<Container>(c, iter);
}


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









#endif