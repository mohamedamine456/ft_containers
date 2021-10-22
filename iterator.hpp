#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "namespace.hpp"

template < class Category, class T >
class ft::iterator : public ft::iterator_base <ft::random_access_iterator_tag, T>
{
    private:
        T*	p;
    public:
        iterator () {}
        iterator (T* x) : p(x) {}
        iterator ( const iterator& cp) : p(cp.p) {}
        iterator& operator++ () {
            ++p;
            return *this;
        }
        iterator& operator++ (int) {
            iterator tmp (*this);
            ++p;
            return tmp;
        }
        iterator& operator-- () {
            --p;
            return *this;
        }
        iterator& operator-- (int) {
            iterator tmp (*this);
            --p;
            return tmp;
        }
        // reference operator*() const {
        //     Iter tmp = current;
        //     return *--tmp;
        // }
        // pointer operator-> () const {
        //     return &(operator*());
        // }
        T operator*() const {

        }
        iterator operator-> () const {
            return &(operator*());
        }
        iterator operator+ (int n) const {
            return iterator(p - n);
        }
        iterator operator- (int n) const {
            return iterator(p + n);
        }
        iterator& operator+= (int n) {
            p -= n;
            return *this;
        }
        iterator& operator-= (int n) {
            p += n;
            return *this;
        }
        T operator[] (int n) const {
            return *(*this + n);
        }
        bool operator< ( const iterator<Category, T> fr,
                            const iterator<Category, T> & sc ) {
            
        }

        bool operator<= ( const iterator<Category, T>, T>& fr,
                            const iterator<Category, T>, T>& sc ) {
            
        }

        bool operator> ( const iterator<Category, T>, T>& fr,
                            const iterator<Category, T>, T>& sc ) {
            
        }
        bool operator>= ( const iterator<Category, T>, T>& fr,
                            const iterator<Category, T>, T>& sc ) {
            
        }
};

template < class Iterator >
ft::reverse_iterator<Iterator> operator+ (
    typename ft::reverse_iterator<Iterator>::difference_type n,
    const ft::reverse_iterator<Iterator>& it)
{
    return ft::reverse_iterator<Iterator>(it.base() - n);
}

template < class Iterator >
ft::reverse_iterator<Iterator> operator+ (
    typename ft::reverse_iterator<Iterator>::difference_type n,
    const ft::reverse_iterator<Iterator>& it)
{
    return ft::reverse_iterator<Iterator>(it.base() - n);
}


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

// distance function
template < class It >
typename ft::iterator_traits<It>::difference_type	_distance(It first, It last, ft::input_iterator_tag)
{
	typename ft::iterator_traits<It>::difference_type result = 0;

	while (first != last) {
		first++;
		result++;
	}
	return (result);
}

template < class It >
typename ft::iterator_traits<It>::difference_type	_distance(It first, It last, ft::random_access_iterator_tag)
{
	return last - first;
}

template < class InputIterator >
typename ft::iterator_traits<InputIterator>::difference_type	ft::distance(InputIterator first, InputIterator last)
{
	_distance(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
}

// back_insert_iterator
template < class Container >
class ft::back_insert_iterator: public ft::iterator<ft::output_iterator_tag, void, void, void, void>
{
    protected:
        Container *container;
    public:
        typedef Container container_type;
        back_insert_iterator (Container &c) : container(c) {}
        ft::back_insert_iterator<Container>& operator= (typename Container::const_reference value) {
            container->push_back(value);
            return (*this);
        }
        ft::back_insert_iterator<Container>& operator* () {
            return *this;   
        }
        ft::back_insert_iterator<Container>& operator++() {
            return (*this);
        }
        ft::back_insert_iterator<Container> operator++(int) {
            return *this;
        }
        virtual ~back_insert_iterator() {}
};

// back_inserter
template < class Container>
ft::back_insert_iterator< Container > ft::back_inserter (Container &c)
{
    return ft::back_insert_iterator<Container>(c);
}

// front_insert_iterator
template < class Container >
class ft::front_insert_iterator: public ft::iterator<ft::output_iterator_tag, void, void, void, void>
{
    protected:
        Container *container;
    public:
        typedef Container container_type;
        front_insert_iterator (Container &c): container(&c) {}
        ft::front_insert_iterator<Container>& operator= (typename Container::const_reference value) {
            container->push_front(value);
            return *this;
        }
        ft::front_insert_iterator<Container>& operator* () {
            return *this;
        }
        ft::front_insert_iterator<Container>& operator++ () {
            return *this;
        }
        ft::front_insert_iterator<Container>& operator++(int) {
            return *this;
        }
        virtual ~front_insert_iterator() {}
};

// front_inserter
template < class Container >
ft::front_insert_iterator< Container > ft::front_inserter (Container &c) {
    return front_insert_iterator<Container>(c);
}

// insert_iterator
template < class Container >
class ft::insert_iterator: public ft::iterator<ft::output_iterator_tag, void, void,void, void>
{
    protected:
        Container *container;
        typename Container::iterator    iter;
    public:
        insert_iterator(Container &c, typename Container::iterator i) : container(c), iter(i) {}
        ft::insert_iterator<Container>& operator= (typename Container::const_reference value) {
            iter = container->insert(iter, value);
            ++iter;
            return *this;
        }
        ft::insert_iterator<Container>& operator* () {
            return *this;
        }
        ft::insert_iterator<Container>& operator++ () {
            return *this;
        }
        ft::insert_iterator<Container>& operator++(int) {
            return *this;
        }
        virtual ~insert_iterator() {}
};

// inserter
template < class Container >
ft::insert_iterator< Container > ft::inserter (Container &c, typename Container::iterator iter) {
    return insert_iterator<Container>(c, iter);
}

// reverse_iterator class
template < class Iter >
class ft::reverse_iterator: public ft::iterator<typename ft::iterator_traits<Iter>::iterator_category,
                                    typename ft::iterator_traits<Iter>::value_type,
                                    typename ft::iterator_traits<Iter>::difference_type,
                                    typename ft::iterator_traits<Iter>::pointer,
                                    typename ft::iterator_traits<Iter>::reference>
{
    protected:
        Iter    current;
    public:
        typedef Iter                                            iterator_type;
        typedef typename ft::iterator_traits<Iter>::reference       reference;
        typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iter>::pointer         pointer;

        reverse_iterator(): current() {}
        explicit reverse_iterator(iterator_type c): current(c) {}
        template < class U >
        reverse_iterator(const reverse_iterator<U>& rv_iter): current(rv_iter.base()) {}
        
        Iter    base() const {
            return current;
        }
        reference operator*() const {
            Iter tmp = current;
            return *--tmp;
        }
        pointer operator-> () const {
            return &(operator*());
        }
        reverse_iterator& operator++ () {
            --current;
            return *this;
        }
        reverse_iterator operator++ (int) {
            reverse_iterator tmp(*this);
            --current;
            return tmp;
        }
        reverse_iterator& operator-- () {
            ++current;
            return *this;
        }
        reverse_iterator operator-- (int) {
            reverse_iterator tmp(*this);
            ++current;
            return tmp;
        }
        reverse_iterator operator+ (difference_type n) const {
            return reverse_iterator(current - n);
        }
        reverse_iterator operator- (difference_type n) const {
            return reverse_iterator(current + n);
        }
        reverse_iterator& operator+= (difference_type n) {
            current -= n;
            return *this;
        }
        reverse_iterator& operator-= (difference_type n) {
            current += n;
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