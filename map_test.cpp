#include "map.hpp"

int main() {
    std::cout << "begin & end: " << std::endl << std::endl;
    {
        ft::map<int, int> mp;
        ft::map<int, int>::iterator it = mp.begin();
        std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
    }
}