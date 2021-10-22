#include <iostream>
#include <type_traits>
#include "../namespace.hpp"

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}

template <class T>
typename ft::enable_if<ft::is_integral<T>::value,bool>::type
  is_oddd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T, class = typename ft::enable_if<ft::is_integral<T>::value>::type>
bool is_evenn (T i) {return !bool(i%2);}

int main() {
    {
        short int i = 1;    // code does not compile if type of i is not integra
        std::cout << std::boolalpha;
        std::cout << "enable_if:" << std::endl;
        std::cout << "i is odd: " << is_odd(i) << std::endl;
        std::cout << "i is even: " << is_even(i) << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << std::boolalpha;
        std::cout << "is_integral:" << std::endl;
        std::cout << "char: " << std::is_integral<char>::value << std::endl;
        std::cout << "int: " << std::is_integral<int>::value << std::endl;
        std::cout << "float: " << std::is_integral<float>::value << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        short int i = 1;    // code does not compile if type of i is not integra
        std::cout << std::boolalpha;
        std::cout << "enable_if:" << std::endl;
        std::cout << "i is odd: " << is_oddd(i) << std::endl;
        std::cout << "i is even: " << is_evenn(i) << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << std::boolalpha;
        std::cout << "is_integral:" << std::endl;
        std::cout << "char: " << ft::is_integral<char>::value << std::endl;
        std::cout << "int: " << ft::is_integral<int>::value << std::endl;
        std::cout << "float: " << ft::is_integral<float>::value << std::endl;
    }
    return 0;
}