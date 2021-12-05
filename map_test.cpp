#include "map.hpp"
#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 4

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

int main() {
    // std::cout << "begin & end: " << std::endl << std::endl;
    // {
    //     ft::map<int, int> mpp;
    //     for (int i = 0; i < 10; i++) {
    //         mpp.insert(ft::make_pair((i + 1) * 13, (i + 1)* 37));
    //     }

    //     ft::map<int, int> mpp2;
    //     for (int i = 0; i < 10; i++) {
    //         mpp2.insert(ft::make_pair((i + 20) * 13, (i + 20)* 37));
    //     }

    //     ft::map<int, int> mp(mpp.begin(), mpp.end());
    //     mp.insert(ft::make_pair(13, 841));
    //     mp.insert(ft::make_pair(15, 78));
    //     ft::map<int, int>::iterator it = mp.begin();
    //     it++;
    //     it++;
    //     --it;
    //     mp.insert(it, ft::make_pair(45, 654));
    //     mp.insert(it, ft::make_pair(45, 456));
    //     mp[23] = 1450;
    //     mp[25] = 784;
    //     mp[25] = 1;

    //     mp.insert(mpp2.begin(), mpp2.end());
    //     // it = mp.begin();
    //     // ft::map<int, int>::iterator ite = mp.end();
    //     // std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
    //     // ite--;
    //     // std::cout << "key: " << ite->first << ", value: " << ite->second << std::endl;
    //     for (it = mp.begin(); it != mp.end(); it++)
    //         std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
    //     std::cout << "-----------------------------------------------------\n";
    //     ft::map<int, int>::iterator itf = mp.find(25);
    //     std::cout << "key: " << itf->first << ", value: " << itf->second << std::endl;

    //     ft::map<int, int>::const_iterator itc = mp.find(25);
    //     std::cout << "key: " << itc->first << ", value: " << itc->second << std::endl;
    //     std::cout << "Size: " << mp.size() << std::endl;

    //     ft::map<int, int>::reverse_iterator rit = mp.rbegin();
    //     rit++;
    //     std::cout << "key: " << rit->first << ", value: " << rit->second << std::endl;
    // }
    std::map<int, std::string> m1;
    ft::map<int, std::string> ft_m1;

    for (size_t i = 0; i < 10; i++)
    {
        m1.insert(std::make_pair(i, "string2"));
        ft_m1.insert(ft::make_pair(i, "string2"));
    }

    std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
    ft::map<int, std::string> const ft_m2(ft_m1.rbegin(), ft_m1.rend());

    // for (std::map<int, std::string>::reverse_iterator rit = m1.rbegin(); rit != m1.rend(); ++rit) // fill c_res from const m1
    // {
    //     std::cout << rit->first << ", " << rit->second << "\n";       
    // }

    // std::cout << "/*----------------------------------------------------*/\n"; 

    // for (ft::map<int, std::string>::reverse_iterator rit = ft_m1.rbegin(); rit != ft_m1.rend(); ++rit) // fill c_ft_res from const ft_m1
    // {
    //     std::cout << rit->first << ", " << rit->second << "\n";      
    // }

    /*-----------------------------------------------------*/
    /*------------------ ft::maps ---------------------*/
    /*----------------------------------------------------*/
    /*------------------ strings to store the results ----*/
    std::string c_res, c_ft_res;
    /*----------------------------------------------------*/
    // for (std::map<int, std::string>::const_reverse_iterator rit = m2.rbegin(); rit != m2.rend(); ++rit) // fill c_res from const m1
    // {
    //     std::cout << rit->first << ", " << rit->second << "\n";
    //     c_res += rit->second;        
    // }

    std::cout << "/*----------------------------------------------------*/\n"; 

    // for (ft::map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin(); rit != ft_m2.rend(); ++rit) // fill c_ft_res from const ft_m1
    // {
    //     std::cout << rit->first << ", " << rit->second << "\n";
    //     c_ft_res += rit->second;        
    // }

    // ft::map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin();

    EQUAL(c_res == c_ft_res);
}