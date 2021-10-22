#include <iostream>
#include <vector>
#include <math.h>

struct test1_vec
{
    int a;
    double b;
    float c;
    char d;
    char e;
};


int main()
{
    std::cout << "assign & at: " << std::endl;
    std::vector<int> vec;
    vec.assign(5, 124);
    std::vector<int>::iterator first = vec.begin();
    std::vector<int>::iterator last = vec.end();
    while (first != last)
    {
        std::cout << *first << " ";
        first++;
    }
    std::cout << std::endl;

    vec.at(0) = 500;
    vec.at(2) = 300;
    vec.at(4) = 100;
    first = vec.begin();
    last = vec.end();
    while (first != last)
    {
        std::cout << *first << " ";
        first++;
    }
    std::cout << std::endl;
    // std::cout << sizeof(int) << " " << sizeof(char) << " " << sizeof(float) << " " << sizeof(double) << " " << sizeof(test1_vec) << std::endl;
    std::cout << std::numeric_limits<std::vector<test1_vec>::difference_type>::max() << std::endl;
    std::vector<test1_vec> vv;
    std::cout << vv.max_size() << std::endl;
}