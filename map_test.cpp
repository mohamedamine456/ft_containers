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
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond(false);
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;

            start = get_time();
            for (size_t i = 0; i < 1e6; i++)
                m1.insert(std::make_pair(i, "string2"));
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            for (size_t i = 0; i < 1e6; i++)
                ft_m1.insert(ft::make_pair(i, "string2"));

            ualarm(0, 0);
            /*----------------------------------------------------*/
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m_range;
            ft::map<int, std::string> ft_m_range;

            start = get_time();
            m_range.insert(m1.begin(), m1.end());
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m_range.insert(ft_m1.begin(), ft_m1.end());
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }

        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;

            start = get_time();
            m1.insert(std::make_pair(1e9, "string2"));
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.insert(ft::make_pair(1e9, "string2"));
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }

        std::map<char, int> m;
        ft::map<char, int> ft_m;

        cond = m.size() == ft_m.size() && m.empty() == ft_m.empty();

        // first insert function version (single parameter):
        m.insert(std::pair<char, int>('a', 100));
        m.insert(std::pair<char, int>('z', 200));

        ft_m.insert(ft::pair<char, int>('a', 100));
        ft_m.insert(ft::pair<char, int>('z', 200));

        cond = cond && (m.size() == ft_m.size() && m.empty() == ft_m.empty());

        std::pair<std::map<char, int>::iterator, bool> ret;
        ft::pair<ft::map<char, int>::iterator, bool> ft_ret;

        ret = m.insert(std::pair<char, int>('z', 500));
        ft_ret = ft_m.insert(ft::pair<char, int>('z', 500));

        cond = cond && ret.second == ft_ret.second;

        // second insert function version (with hint position):
        std::map<char, int>::iterator it = m.begin();
        ft::map<char, int>::iterator ft_it = ft_m.begin();
        m.insert(it, std::pair<char, int>('b', 300));
        m.insert(it, std::pair<char, int>('c', 400));

        ft_m.insert(ft_it, ft::pair<char, int>('b', 300));
        ft_m.insert(ft_it, ft::pair<char, int>('c', 400));

        cond = cond && (m.size() == ft_m.size() && m.empty() == ft_m.empty());

        // third insert function version (range insertion):
        std::map<char, int> anothermap;
        ft::map<char, int> ft_anothermap;
        anothermap.insert(m.begin(), m.find('c'));
        ft_anothermap.insert(ft_m.begin(), ft_m.find('c'));
        cond = cond && (anothermap.size() == ft_anothermap.size() && anothermap.empty() == ft_anothermap.empty());

        cond = cond && comparemaps(ft_m.begin(), ft_m.end(), m.begin(), m.end()) && comparemaps(ft_anothermap.begin(), ft_anothermap.end(), anothermap.begin(), anothermap.end());
        EQUAL(cond);
    }

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " erase method "
              << "] --------------------]\t\t\033[0m";

    {
        bool cond(false);
        // erasing all the elements in the map;
        {
            // time_t start, end, diff;
            // /*------------------ std::maps ---------------------*/
            // std::map<int, std::string> m1;
            // ft::map<int, std::string> ft_m1;
            // for (size_t i = 0; i < 1e6; i++)
            // {
            //     m1.insert(std::make_pair(i, "string2"));
            //     ft_m1.insert(ft::make_pair(i, "string2"));
            // }

            // start = get_time();
            // m1.erase(m1.begin(), m1.end());
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*-----------------------------------------------------*/
            // /*------------------ ft::maps ---------------------*/
            // ualarm(diff * 1e3, 0);
            // ft_m1.erase(ft_m1.begin(), ft_m1.end());
            // ualarm(0, 0);
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

    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " swap method "
              << "] --------------------]\t\t\033[0m";

    {
        {
            time_t start, end, diff;

            /* ------------------ a > b ------------------ */
            std::map<int, std::string> m1, m2;
            ft::map<int, std::string> ft_m1, ft_m2;
            for (size_t i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, "string2"));
            }

            start = get_time();
            m1.swap(m2);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.swap(ft_m2);
            ualarm(0, 0);
            /*----------------------------------------------------*/

            /* ------------------ a and b are not empty ------------------ */
            for (size_t i = 0; i < 1e4; i++)
            {
                m2.insert(std::make_pair(i, "string2"));
                ft_m2.insert(ft::make_pair(i, "string2"));
            }

            start = get_time();
            m1.swap(m2);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.swap(ft_m2);
            ualarm(0, 0);
            /*----------------------------------------------------*/

            /* ------------------ a == b ------------------ */
            m1 = m2 = std::map<int, std::string>();
            ft_m1 = ft_m2 = ft::map<int, std::string>();
            start = get_time();
            m2.swap(m1);
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m2.swap(ft_m1);
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        bool cond = false;
        std::map<char, int> foo, bar;
        ft::map<char, int> ft_foo, ft_bar;

        foo['x'] = 100;
        foo['y'] = 200;

        ft_foo['x'] = 100;
        ft_foo['y'] = 200;

        cond = foo.size() == ft_foo.size() && bar.size() == ft_bar.size();

        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;

        ft_bar['a'] = 11;
        ft_bar['b'] = 22;
        ft_bar['c'] = 33;

        cond = cond && foo.size() == ft_foo.size() && bar.size() == ft_bar.size() && comparemaps(foo.begin(), foo.end(), ft_foo.begin(), ft_foo.end()) && comparemaps(bar.begin(), bar.end(), ft_bar.begin(), ft_bar.end());

        foo.swap(bar);
        ft_foo.swap(ft_bar);

        cond = cond && foo.size() == ft_foo.size() && bar.size() == ft_bar.size() && comparemaps(foo.begin(), foo.end(), ft_foo.begin(), ft_foo.end()) && comparemaps(bar.begin(), bar.end(), ft_bar.begin(), ft_bar.end());

        std::map<std::string, std::string, std::greater<std::string> > m1, m2;
        ft::map<std::string, std::string, std::greater<std::string> > ft_m1, ft_m2;

        m1["γ"] = "gamma";
        m1["β"] = "beta";
        m1["α"] = "alpha";
        m1["γ"] = "gamma";

        m2["ε"] = "eplsilon";
        m2["δ"] = "delta";
        m2["ε"] = "epsilon";

        ft_m1["γ"] = "gamma";
        ft_m1["β"] = "beta";
        ft_m1["α"] = "alpha";
        ft_m1["γ"] = "gamma";

        ft_m2["ε"] = "eplsilon";
        ft_m2["δ"] = "delta";
        ft_m2["ε"] = "epsilon";

        const std::pair<std::string, std::string> &ref = *(m1.begin());
        // const std::map<std::string, std::string, std::greater<std::string> >::iterator iter = std::next(m1.begin());
        const ft::pair<std::string, std::string> &ft_ref = *(ft_m1.begin());
        // const ft::map<std::string, std::string, std::greater<std::string> >::iterator ft_iter = std::next(ft_m1.begin());

        // std::cout << "──────── before swap ────────\n"
        //           << "m1: " << m1 << "m2: " << m2 << "ref: " << ref
        //           << "\niter: " << *iter << '\n';

        cond = cond && ref.first == ft_ref.first && ref.second == ft_ref.second && m1.size() == ft_m1.size() && m2.size() && ft_m2.size();

        m1.swap(m2);
        ft_m1.swap(ft_m2);

        // _---------------_ << ──────── after swap ──────── >> _---------------_

        cond = cond && ref.first == ft_ref.first && ref.second == ft_ref.second && m1.size() == ft_m1.size() && m2.size() && ft_m2.size();

        EQUAL(cond);
    }
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " clear method "
    //           << "] --------------------]\t\t\033[0m";

    // {
    //     {
    //         time_t start, end, diff;
    //         /*------------------ std::maps ---------------------*/
    //         std::map<int, std::string> m1;
    //         ft::map<int, std::string> ft_m1;
    //         for (size_t i = 0; i < 1e6; i++)
    //         {
    //             m1.insert(std::make_pair(i, "string2"));
    //             ft_m1.insert(ft::make_pair(i, "string2"));
    //         }

    //         start = get_time();
    //         m1.clear();
    //         end = get_time();
    //         diff = end - start;
    //         diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
    //         /*-----------------------------------------------------*/
    //         /*------------------ ft::maps ---------------------*/
    //         ualarm(diff * 1e3, 0);
    //         ft_m1.clear();
    //         ualarm(0, 0);
    //         /*----------------------------------------------------*/
    //     }
    //     bool cond(false);
    //     std::map<char, int> m;
    //     ft::map<char, int> ft_m;

    //     m['x'] = 100;
    //     m['y'] = 200;
    //     m['z'] = 300;

    //     ft_m['x'] = 100;
    //     ft_m['y'] = 200;
    //     ft_m['z'] = 300;

    //     cond = m.size() == ft_m.size();

    //     m.clear();
    //     ft_m.clear();

    //     cond = cond && m.empty() == ft_m.empty() && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

    //     m['a'] = 1101;
    //     m['b'] = 2202;
    //     ft_m['a'] = 1101;
    //     ft_m['b'] = 2202;

    //     cond = cond && m.size() == ft_m.size() && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

    //     m = std::map<char, int>();
    //     ft_m = ft::map<char, int>();

    //     m.clear();
    //     ft_m.clear();

    //     cond = cond && m.size() == ft_m.size() && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

    //     EQUAL(cond);
    // }
}


int main() {
    testModifiers();
    system("leaks a.out");
}