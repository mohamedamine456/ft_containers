#ifndef PAIT_HPP
#define PAIR_HPP

#include "namespace.hpp"

template < class T1, class T2 >
struct ft::pair
{
    T1  first;
    T2  second;
    pair(): first(), second() {}
    pair(const T1 &f, const T2 &s): first(f), second(s) {}
    template< class U1, class U2 >
    pair(const pair<U1, U2> &pr): first(pr.first), second(pr.second) {}
    pair & operator= (const pair &pr) {
        this->first = pr.first;
        this->second = pr.second;
        return *this;
    }
};

// pair relational operators
template < class T1, class T2 >
bool operator== ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs ) {
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

template < class T1, class T2 >
bool operator!= ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs ) {
    return lhs.first != rhs.first && lhs.second != rhs.second;
}

template < class T1, class T2 >
bool operator< ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs ) {
    return lhs.first < rhs.first && lhs.second < rhs.second;
}

template < class T1, class T2 >
bool operator<= ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs ) {
    return lhs.first <= rhs.first && lhs.second <= rhs.second;
}

template < class T1, class T2 >
bool operator> ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs ) {
    return lhs.first > rhs.first && lhs.second > rhs.second;
}

template < class T1, class T2 >
bool operator>= ( const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs ) {
    return lhs.first >= rhs.first && lhs.second >= rhs.second;
}

// make_pair
template < class T1, class T2 >
ft::pair< T1, T2> ft::make_pair (T1 x, T2 y) {
    return ft::pair(x, y);
}

#endif