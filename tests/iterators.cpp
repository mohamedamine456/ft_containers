#include <iostream>
#include <iterator>
#include <list>

int main () {
    std::list<int> mylist;
    
    for (int i = 0; i < 10; i++) {
        mylist.push_back((i + 1) * 10);
    }

    std::list<int>::iterator it = mylist.begin();

    std::cout << "before advance iterator points on: " << *it << std::endl;

    std::advance(it, 5);
    std::cout << "After advance iterator points on: " << *it << std::endl;

    std::list<int>::iterator first = mylist.begin();
    std::list<int>::iterator last = mylist.end();

    std::cout << "The distance is: " << std::distance(first, it) << std::endl;
    return (0);
}