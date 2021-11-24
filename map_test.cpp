#include "map.hpp"
#include <map>

int main() {
    std::cout << "begin & end: " << std::endl << std::endl;
    {
        std::map<int, int> mpp;
        for (int i = 0; i < 10; i++) {
            mpp.insert(std::make_pair((i + 1) * 13, (i + 1)* 37));
        }

        ft::map<int, int> const mp(mpp.begin(), mpp.end());
        // mp.insert(ft::make_pair(13, 841));
        // mp.insert(ft::make_pair(15, 78));
        ft::map<int, int>::const_iterator it = mp.begin();
        // it++;
        // it++;
        // mp.insert(it, ft::make_pair(45, 654));
        // mp[23] = 1450;
        // mp[25] = 784;
        // mp[25] = 1;
        for (it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << "key: " << it->first << ", value: " << it->second << std::endl;

        std::cout << "-----------------------------------------------------\n";
        // ft::map<int, int>::iterator itf = mp.find(25);
        // std::cout << "key: " << itf->first << ", value: " << itf->second << std::endl;

        ft::map<int, int>::const_iterator itc = mp.find(52);
        std::cout << "key: " << itc->first << ", value: " << itc->second << std::endl;
        std::cout << "Size: " << mp.size() << std::endl;
    }
}