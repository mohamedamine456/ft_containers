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

void iterator_tests(void)
{
    /*------------ std::map ---------*/
    std::map<int, char> m;
    std::map<int, char>::iterator it, it1;

    ft::map<int, char> my_m;
    ft::map<int, char>::iterator my_it, my_it1, tmp;

    for (int i = 0; i < 10; ++i)
    {
        my_m.insert(ft::make_pair(i, static_cast<char>(i + 97)));
        m.insert(std::make_pair(i, static_cast<char>(i + 97)));
    }

    it = m.begin();
    it1 = ++(m.begin());
    my_it = my_m.begin();
    my_it1 = ++(my_m.begin());
    /*----------------------------------*/
    {
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1e6; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            // start = get_time();
            // for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
            //     ;
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            // ualarm(diff * 1e3, 0);
            // for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
            //     ;
            // ualarm(0, 0);
        }
        bool cond(false);
        {
            int res(0);
            int myints[] = {12, 82, 37, 64, 15};
            ft::map<int, int> m;
            for (size_t i = 0; i < 5; ++i)
                m.insert(ft::make_pair(myints[i], i));
            for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
                res += it->first;
            cond = res == 210;
        }
        {
            int res(0), tmp;
            int myints[] = {12, 82, 37, 64, 15};
            ft::map<int, int> m;
            for (size_t i = 0; i < 5; ++i)
                m.insert(ft::make_pair(myints[i], i));
            ft::map<int, int>::iterator it = m.begin(), eit = --m.end();
            tmp = eit->first;
            m.erase(eit);
            for (; it != m.end(); ++it)
                res += it->first;
            cond = cond && (res == (210 - tmp));
        }
        ++my_it; // I incremented here to make sure that the object changes
        EQUAL(*my_it == *my_it1);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --it operator "
              << "] --------------------]\t\t\033[0m";
    {
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1e6; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            start = get_time();
            std::map<int, std::string>::iterator it = --m.end();
            for (; it != m.begin(); --it)
                ;
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            ualarm(diff * 1e3, 0);
            ft::map<int, std::string>::iterator ft_it = --ft_m.end();
            for (; ft_it != ft_m.begin(); --ft_it)
                ;
            ualarm(0, 0);
        }
        int res(0);
        {
            int myints[] = {12, 82, 37, 64, 15};
            ft::map<int, int> m;
            for (size_t i = 0; i < 5; ++i)
                m.insert(ft::make_pair(myints[i], i));
            ft::map<int, int>::iterator it = --m.end();
            for (;; --it)
            {
                if (it == m.begin())
                {
                    res += it->first;
                    break;
                }
                res += it->first;
            }
        }
        --my_it; // I decremented here to make sure that the object changes
        EQUAL(*my_it != *my_it1);
    }
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it++ operator "
              << "] --------------------]\t\t\033[0m";
    tmp = my_it++;
    EQUAL(*my_it != *tmp && *my_it == *my_it1);
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it-- operator "
              << "] --------------------]\t\t\033[0m";
    tmp = my_it--;
    EQUAL(*my_it != *tmp && *my_it == *(my_m.begin()));
}

int main() {
    // std::cout << "begin & end: " << std::endl << std::endl;
    // {
    //     std::map<int, int> mpp;
    //     for (int i = 0; i < 10; i++) {
    //         mpp.insert(std::make_pair((i + 1) * 13, (i + 1)* 37));
    //     }

    //     std::map<int, int> mpp2;
    //     for (int i = 0; i < 10; i++) {
    //         mpp2.insert(std::make_pair((i + 20) * 13, (i + 20)* 37));
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
    //     for (it = mp.begin(); it != mp.end(); ++it)
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
    iterator_tests();
}