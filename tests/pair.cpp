#include <iostream>

int main()
{
    std::pair<std::string, int>  pr("Hello", 7);

    std::cout << "pair of: " << pr.first << " and " << pr.second << std::endl;

    std::pair<std::string, std::string> spr;
    spr = std::make_pair("Hello ", "World");
    std::cout << "pair of: " << spr.first << spr.second << std::endl;
}