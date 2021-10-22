#include "iterator.hpp"

int main() {
    ft::iterator<ft::input_iterator_tag, int> It;
    ft::iterator<ft::input_iterator_tag, int> It0;
    ft::iterator<ft::bidirectional_iterator_tag, int> It1;
    ft::iterator<ft::bidirectional_iterator_tag, int> It10;
    ft::iterator<ft::random_access_iterator_tag, int> It2;
    ft::iterator<ft::random_access_iterator_tag, int> It20;
    ft::advance(It, 5);
    ft::advance(It1, 5);
    ft::advance(It2, 5);

    ft::distance(It, It0);
    ft::distance(It1, It10);
    ft::distance(It2, It20);
    return 0;
}