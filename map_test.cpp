#include "map.hpp"
#include <map>

int main() {
    std::cout << "begin & end: " << std::endl << std::endl;
    {
        std::map<int, int> mpp;
        for (int i = 0; i < 10; i++) {
            mpp.insert(std::make_pair((i + 1) * 13, (i + 1)* 37));
        }

        ft::map<int, int> mp(mpp.begin(), mpp.end());
        ft::map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
    }
}