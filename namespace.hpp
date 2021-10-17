#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP

#include <iostream>
#include <memory>

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector;

	template < class T, class Container = vector <T> >
	class stack;
	
	template < class key,
		class T,
		class Compare = std::less<key>,
		class Allocator = std::allocator<std::pair <const key, T> > >
	class map;
	
	// iterators_tags
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


	// terator_traits
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	// iterator
	template < class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T& >
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	// iterator functions
	template < class InputIterator >
	void	advance(InputIterator &inputIterator, typename iterator_traits<InputIterator>::difference_type n);

	template < class InputIterator >
	typename iterator_traits<InputIterator>::difference_type	distance(InputIterator first, InputIterator last);

	// back_insert_iterator
	template < class Container >
	class back_insert_iterator: public iterator<output_iterator_tag, void, void, void, void>
	{
		protected:
			Container *container;
		public:
			typedef Container container_type;
			back_insert_iterator (Container &c) : container(c) {}
			back_insert_iterator<Container>& operator= (typename Container::const_reference value) {
				container->push_back(value);
				return (*this);
			}
			back_insert_iterator<Container>& operator* () {
				return *this;   
			}
			back_insert_iterator<Container>& operator++() {
				return (*this);
			}
			back_insert_iterator<Container> operator++(int) {
				return *this;
			}
	};

	// back_inserter function
	template < class Container>
	back_insert_iterator< Container > back_inserter (Container &c);

	// front_insert_iterator

	template < class Container >
	class front_insert_iterator: public iterator<output_iterator_tag, void, void, void, void>
	{
		protected:
			Container *container;
		public:
			typedef Container container_type;
			front_insert_iterator (Container &c): container(&c) {}
			front_insert_iterator<Container>& operator= (typename Container::const_reference value) {
				container->push_front(value);
				return *this;
			}
			front_insert_iterator<Container>& operator* () {
				return *this;
			}
			front_insert_iterator<Container>& operator++ () {
				return *this;
			}
			front_insert_iterator<Container>& operator++(int) {
				return *this;
			}
	};

	// front_inserter function
	template < class Container >
	front_insert_iterator< Container > front_inserter (Container &c);


	// insert_iterator
	template < class Container >
	class insert_iterator: public iterator<output_iterator_tag, void, void,void, void>
	{
		protected:
			Container *container;
			typename Container::iterator    iter;
		public:
			insert_iterator(Container &c, typename Container::iterator i) : container(c), iter(i) {}
			insert_iterator<Container>& operator= (typename Container::const_reference value) {
				iter = container->insert(iter, value);
				++iter;
				return *this;
			}
			insert_iterator<Container>& operator* () {
				return *this;
			}
			insert_iterator<Container>& operator++ () {
				return *this;
			}
			insert_iterator<Container>& operator++(int) {
				return *this;
			}
	};

	// inserter
	template < class Container >
	insert_iterator< Container > inserter (Container &c, typename Container::iterator iter);

	// reverse_iterator class
	template < class Iter >
	class reverse_iterator: public iterator<typename iterator_traits<Iter>::iterator_category,
                                        typename iterator_traits<Iter>::value_type,
                                        typename iterator_traits<Iter>::difference_type,
                                        typename iterator_traits<Iter>::pointer,
                                        typename iterator_traits<Iter>::reference>
	{
		protected:
			Iter    current;
		public:
			typedef Iter                                            iterator_type;
			typedef typename iterator_traits<Iter>::reference       reference;
			typedef typename iterator_traits<Iter>::difference_type difference_type;
			typedef typename iterator_traits<Iter>::pointer         pointer;

			reverse_iterator(): current() {}
			reverse_iterator(Iter c): current(c) {}
			reverse_iterator(const reverse_iterator<Iter>& rv_iter): current(rv_iter.base()) {}
			
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
				current--;
				return *this;
			}
			reverse_iterator& operator++ (int) {
				reverse_iterator tmp(*this);
				current--;
				return tmp;
			}
			reverse_iterator& operator-- () {
				current++;
				return *this;
			}
			reverse_iterator& operator-- (int) {
				reverse_iterator tmp(*this);
				current++;
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
};

#endif
