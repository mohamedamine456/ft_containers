#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "../namespace.hpp"

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

#endif