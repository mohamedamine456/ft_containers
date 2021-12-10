#include "map.hpp"
#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>
#include <utility>

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 20

typedef std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> iter_def;
typedef ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ft_iter_def;
typedef std::pair<std::map<int, std::string>::const_iterator, std::map<int, std::string>::const_iterator> const_iter_def;
typedef ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator> ft_const_iter_def;

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}


template <typename Iter1, typename Iter2>
bool comparemaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

void testModifiers()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " erase method "
              << "] --------------------]\t\t\033[0m";

    {
        bool cond(false);
        // erasing all the elements in the map;
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, "string2"));
            }

            start = get_time();
            m1.erase(m1.begin(), m1.end());
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.erase(ft_m1.begin(), ft_m1.end());
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        std::map<char, int> m;
        ft::map<char, int> ft_m;
        std::map<char, int>::iterator it;
        ft::map<char, int>::iterator ft_it;

        // insert some values:
        ft_m['a'] = 10;
        ft_m['b'] = 20;
        ft_m['c'] = 30;
        ft_m['d'] = 40;
        ft_m['e'] = 50;
        ft_m['f'] = 60;

        m['a'] = 10;
        m['b'] = 20;
        m['c'] = 30;
        m['d'] = 40;
        m['e'] = 50;
        m['f'] = 60;

        cond = m.size() == ft_m.size() && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        it = m.find('b');
        ft_it = ft_m.find('b');

        cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second);
        m.erase(it);       // erasing by iterator
        ft_m.erase(ft_it); // erasing by iterator

        cond = cond && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        int ret = m.erase('c');       // erasing by key
        int ft_ret = ft_m.erase('c'); // erasing by key

        cond = cond && ret == ft_ret && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        it = m.find('e');
        ft_it = ft_m.find('e');

        cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second) && m.size() == ft_m.size();

        m.erase(it, m.end());          // erasing by range
        ft_m.erase(ft_it, ft_m.end()); // erasing by range

        cond = cond && m.empty() == ft_m.empty() && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        // /* ---------- Testing some edge cases ---------- */

        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m2;

        for (size_t i = 0; i < 1e5; i++)
        {
            m2.insert(std::make_pair(i, "string1"));
            ft_m2.insert(ft::make_pair(i, "string1"));
        }

        std::map<int, std::string>::reverse_iterator it2 = m2.rbegin();
        ft::map<int, std::string>::reverse_iterator ft_it2 = ft_m2.rbegin();

        m2.erase(m2.begin());
        ft_m2.erase(ft_m2.begin());

        cond = cond && m2.size() == ft_m2.size() && comparemaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

        m2.erase(it2->first);
        ft_m2.erase(ft_it2->first);

        cond = cond && m2.size() == ft_m2.size() && comparemaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

        // std::map<int, std::string> m3;
        // ft::map<int, std::string> ft_m3;
        // std::vector<int> vec;
        // std::vector<int> ft_vec;
        // std::random_device randDev;
        // std::mt19937 generator(randDev());
        // std::uniform_int_distribution<int> distr(0, 1e8);

        // for (size_t i = 0; i < 1e6; i++)
        // {
        //     m3.insert(std::make_pair(i, "string1"));
        //     ft_m3.insert(ft::make_pair(i, "string1"));
        // }

        // for (size_t i = 0; i < 1e6; ++i)
        // {
        //     int n = distr(generator);
        //     int ret1 = m3.erase(n);
        //     int ret2 = ft_m3.erase(n);

        //     if (ret1 != ret2)
        //     {
        //         cond = false;
        //         break;
        //     }
        // }

        // if (!m3.empty())
        // {
        //     m3.erase(m3.begin(), m3.end());
        //     m3.erase(m3.begin(), m3.end());
        // }
        // if (!ft_m3.empty())
        // {
        //     ft_m3.erase(ft_m3.begin(), ft_m3.end());
        //     ft_m3.erase(ft_m3.begin(), ft_m3.end());
        // }
        // cond = cond && (m3.size() == ft_m3.size() && comparemaps(m3.begin(), m3.end(), ft_m3.begin(), ft_m3.end()));

        EQUAL(cond);
    }
}







void testOperations()
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " upper_bound method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond;
        // /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            int res, ft_res;

            std::map<int, std::string> m;
            ft::map<int, std::string> ft_m;
            for (size_t i = 0; i < 1e6; ++i)
            {
                m.insert(std::make_pair(i, "value"));
                ft_m.insert(ft::make_pair(i, "value"));
            }
            start = get_time();
            res = m.upper_bound(1e5)->first;
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

            ualarm(diff * 1e3, 0);
            ft_res = ft_m.upper_bound(1e5)->first;
            ualarm(0, 0);
            cond = ft_res == res;
        }
        std::map<int, std::string> m;
        ft::map<int, std::string> ft_m;
        int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
        for (size_t i = 0; i < 9; ++i)
        {
            m.insert(std::make_pair(arr[i], "value"));
            ft_m.insert(ft::make_pair(arr[i], "value"));
        }
        std::map<int, std::string> const c_m(m.begin(), m.end());
        ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());
        cond = (cond && (m.upper_bound(15)->first == ft_m.upper_bound(15)->first));
        std::cout << "std: " << m.upper_bound(15)->first << ", ft: " << ft_m.upper_bound(15)->first << "\n";
        std::cout << "std: " << m.upper_bound(65)->first << ", ft: " << ft_m.upper_bound(65)->first << "\n";
        std::cout << "std: " << m.upper_bound(63)->first << ", ft: " << ft_m.upper_bound(63)->first << "\n";
        std::cout << "std: " << m.upper_bound(120)->first << ", ft: " << ft_m.upper_bound(120)->first << "\n";
        std::cout << "std: " << m.upper_bound(70)->first << ", ft: " << ft_m.upper_bound(70)->first << "\n";
        std::cout << "std: " << m.upper_bound(150)->first << ", ft: " << ft_m.upper_bound(150)->first << "\n";
        cond = (cond && (m.upper_bound(65)->first == ft_m.upper_bound(65)->first));
        cond = (cond && (m.upper_bound(63)->first == ft_m.upper_bound(63)->first));
        cond = (cond && (m.upper_bound(120)->first == ft_m.upper_bound(120)->first));
        cond = (cond && (m.upper_bound(70)->first == ft_m.upper_bound(70)->first));
        cond = (cond && (m.upper_bound(150)->first == ft_m.upper_bound(150)->first));

        cond = (cond && (c_m.upper_bound(15)->first == c_ft_m.upper_bound(15)->first));
        cond = (cond && (c_m.upper_bound(65)->first == c_ft_m.upper_bound(65)->first));
        cond = (cond && (c_m.upper_bound(63)->first == c_ft_m.upper_bound(63)->first));
        cond = (cond && (c_m.upper_bound(120)->first == c_ft_m.upper_bound(120)->first));
        cond = (cond && (c_m.upper_bound(70)->first == c_ft_m.upper_bound(70)->first));
        cond = (cond && (c_m.upper_bound(150)->first == c_ft_m.upper_bound(150)->first));
        // std::cout << "std: " << m.upper_bound(15)->first << ", ft: " << ft_m.upper_bound(15)->first << "\n";
        // std::cout << "std: " << m.upper_bound(65)->first << ", ft: " << ft_m.upper_bound(65)->first << "\n";
        // std::cout << "std: " << m.upper_bound(63)->first << ", ft: " << ft_m.upper_bound(63)->first << "\n";
        // std::cout << "std: " << m.upper_bound(120)->first << ", ft: " << ft_m.upper_bound(120)->first << "\n";
        // std::cout << "std: " << m.upper_bound(70)->first << ", ft: " << ft_m.upper_bound(70)->first << "\n";
        // std::cout << "std: " << m.upper_bound(150)->first << ", ft: " << ft_m.upper_bound(150)->first << "\n";
        EQUAL(cond);
    }
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " equal_range method "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     bool cond;
    //     /*---------------------------------- time limit test --------------------------------------------*/
    //     {
    //         time_t start, end, diff;
    //         iter_def res;
    //         ft_iter_def ft_res;

    //         std::map<int, std::string> m;
    //         ft::map<int, std::string> ft_m;
    //         for (size_t i = 0; i < 1e6; ++i)
    //         {
    //             m.insert(std::make_pair(i, "value"));
    //             ft_m.insert(ft::make_pair(i, "value"));
    //         }
    //         start = get_time();
    //         res = m.equal_range(1e5);
    //         end = get_time();
    //         diff = end - start;
    //         diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;

    //         ualarm(diff * 1e3, 0);
    //         ft_res = ft_m.equal_range(1e5);
    //         ualarm(0, 0);
    //         cond = (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first);
    //     }
    //     iter_def res;
    //     ft_iter_def ft_res;
    //     const_iter_def c_res;
    //     ft_const_iter_def ft_c_res;
    //     std::map<int, std::string> m;
    //     ft::map<int, std::string> ft_m;
    //     int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
    //     for (size_t i = 0; i < 9; ++i)
    //     {
    //         m.insert(std::make_pair(arr[i], "value"));
    //         ft_m.insert(ft::make_pair(arr[i], "value"));
    //     }
    //     std::map<int, std::string> const c_m(m.begin(), m.end());
    //     ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());

    //     res = m.equal_range(15);
    //     ft_res = ft_m.equal_range(15);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
    //     res = m.equal_range(65);
    //     ft_res = ft_m.equal_range(65);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
    //     res = m.equal_range(63);
    //     ft_res = ft_m.equal_range(63);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
    //     res = m.equal_range(120);
    //     ft_res = ft_m.equal_range(120);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
    //     res = m.equal_range(70);
    //     ft_res = ft_m.equal_range(70);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));
    //     res = m.equal_range(150);
    //     ft_res = ft_m.equal_range(150);
    //     cond = (cond && (ft_res.first->first == res.first->first) && (ft_res.second->first == res.second->first));

    //     c_res = c_m.equal_range(15);
    //     ft_c_res = c_ft_m.equal_range(15);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     c_res = c_m.equal_range(65);
    //     ft_c_res = c_ft_m.equal_range(65);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     c_res = c_m.equal_range(63);
    //     ft_c_res = c_ft_m.equal_range(63);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     c_res = c_m.equal_range(120);
    //     ft_c_res = c_ft_m.equal_range(120);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     c_res = c_m.equal_range(70);
    //     ft_c_res = c_ft_m.equal_range(70);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     c_res = c_m.equal_range(150);
    //     ft_c_res = c_ft_m.equal_range(150);
    //     cond = (cond && (ft_c_res.first->first == c_res.first->first) && (ft_c_res.second->first == c_res.second->first));
    //     EQUAL(cond);
    // }
}


int main() {
    // testModifiers();
    testOperations();
    // system("leaks a.out");
}