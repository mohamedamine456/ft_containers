#include "map.hpp"
#include <iostream>
#include <map>

int main() {
    std::cout << "begin & end: " << std::endl << std::endl;
    {
        std::map<int, int> mpp;
        for (int i = 0; i < 10; i++) {
            mpp.insert(std::make_pair((i + 1) * 13, (i + 1)* 37));
        }

        std::map<int, int> mpp2;
        for (int i = 0; i < 10; i++) {
            mpp2.insert(std::make_pair((i + 20) * 13, (i + 20)* 37));
        }

        std::map<int, int> mp(mpp.begin(), mpp.end());
        mp.insert(std::make_pair(13, 841));
        mp.insert(std::make_pair(15, 78));
        std::map<int, int>::iterator it = mp.begin();
        it++;
        it++;
        --it;
        mp.insert(it, std::make_pair(45, 654));
        mp.insert(it, std::make_pair(45, 456));
        mp[23] = 1450;
        mp[25] = 784;
        mp[25] = 1;

        mp.insert(mpp2.begin(), mpp2.end());
        // it = mp.begin();
        // std::map<int, int>::iterator ite = mp.end();
        // std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        // ite--;
        // std::cout << "key: " << ite->first << ", value: " << ite->second << std::endl;
        for (it = mp.begin(); it != mp.end(); it++)
            std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        ++it;
        std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
        std::cout << "-----------------------------------------------------\n";
        std::map<int, int>::iterator itf = mp.find(25);
        std::cout << "key: " << itf->first << ", value: " << itf->second << std::endl;

        std::map<int, int>::const_iterator itc = mp.find(25);
        std::cout << "key: " << itc->first << ", value: " << itc->second << std::endl;
        std::cout << "Size: " << mp.size() << std::endl;

        std::map<int, int>::reverse_iterator rit = mp.rbegin();
        rit++;
        std::cout << "key: " << rit->first << ", value: " << rit->second << std::endl;
    }
}