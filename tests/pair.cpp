#include <iostream>
#include "../pair.hpp"

int main()
{
   {
       std::pair<std::string, int>  pr("Hello", 7);
       std::cout << "std --> pair of: " << pr.first << " and " << pr.second << std::endl;
       
       std::pair<std::string, std::string> spr;
       spr = std::make_pair("Hello ", "World");
       std::cout << "std --> pair of: " << spr.first << spr.second << std::endl;
   }
   {
       ft::pair<std::string, int>  pr("Hello", 7);
       std::cout << "ft  --> pair of: " << pr.first << " and " << pr.second << std::endl;
       
       ft::pair<std::string, std::string> spr;
       spr = ft::make_pair("Hello ", "World");
       std::cout << "ft  --> pair of: " << spr.first << spr.second << std::endl;
   }
   {
       std::pair <int,int> foo;
       std::pair <int,int> bar;
       
       foo = std::make_pair (10,20);
       bar = std::make_pair (10.5,'A');
       
       std::cout << "std --> foo: " << foo.first << ", " << foo.second << '\n';
       std::cout << "std --> bar: " << bar.first << ", " << bar.second << '\n';
   }
   {
       ft::pair <int,int> foo;
       ft::pair <int,int> bar;
       
       foo = ft::make_pair (10,20);
       bar = ft::make_pair (10.5,'A');
       
       std::cout << "ft  --> foo: " << foo.first << ", " << foo.second << '\n';
       std::cout << "ft  --> bar: " << bar.first << ", " << bar.second << '\n';
   }
   {
       int n = 1;
       int a[5] = {1, 2, 3, 4, 5};
       // build a pair from two ints
       std::pair<int, int> p1 = std::make_pair(n, a[1]);
       std::cout << "The value of p1 is "
                 << "(" << p1.first << ", " << p1.second << ")\n";
       // build a pair from a reference to int and an array (decayed to pointer)
       std::pair<int &, int *> p2 = std::make_pair(std::ref(n), a);
       n = 7;
       std::cout << "The value of p2 is "
              << "(" << p2.first << ", " << *(p2.second + 4) << ")\n";
    }
    {
       int n = 1;
       int a[5] = {1, 2, 3, 4, 5};
       // build a pair from two ints
       ft::pair<int, int> p1 = ft::make_pair(n, a[1]);
       std::cout << "The value of p1 is "
                 << "(" << p1.first << ", " << p1.second << ")\n";
       // build a pair from a reference to int and an array (decayed to pointer)
       ft::pair<int &, int *> p2 = ft::make_pair(std::ref(n), a);
       n = 7;
       std::cout << "The value of p2 is "
              << "(" << p2.first << ", " << *(p2.second + 4) << ")\n";
    }
    return (0);
}