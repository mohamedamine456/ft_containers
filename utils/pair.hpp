#ifndef PAIR_HPP
#define PAIR_HPP

#include "../namespace.hpp"

template <class T1, class T2>
struct ft::pair
{
    T1 first;
    T2 second;
    pair() : first(), second() {}
    pair(const T1 &f, const T2 &s) : first(f), second(s) {}
    template <class U1, class U2>
    pair(const pair<U1, U2> &pr) : first(pr.first), second(pr.second) {}
    virtual ~pair() {}
    // pair relational operators

    friend bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    friend bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return lhs.first != rhs.first && lhs.second != rhs.second;
    }

    friend bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return lhs.first < rhs.first && lhs.second < rhs.second;
    }

    friend bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return lhs.first <= rhs.first && lhs.second <= rhs.second;
    }

    friend bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return lhs.first > rhs.first && lhs.second > rhs.second;
    }

    friend bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return lhs.first >= rhs.first && lhs.second >= rhs.second;
    }
};

// make_pair
template <class T1, class T2>
ft::pair<T1, T2> ft::make_pair(T1 x, T2 y)
{
    return ft::pair<T1, T2>(x, y);
}

#endif
