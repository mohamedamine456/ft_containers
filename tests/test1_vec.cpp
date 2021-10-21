#include <iostream>
#include <vector>

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
}