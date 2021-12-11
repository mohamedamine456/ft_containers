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

void testrbeginrend() {
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rbegin and rend methods "
              << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
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
            m1.rbegin();
            m1.rend();
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.rbegin();
            ft_m1.rend();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::maps ---------------------*/
        std::map<int, std::string> m1;
        ft::map<int, std::string> ft_m1;

        for (size_t i = 0; i < 10; i++)
        {
            m1.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair(i, "string2"));
        }

        std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
        ft::map<int, std::string> const ft_m2(ft_m1.rbegin(), ft_m1.rend());

        /*-----------------------------------------------------*/
        /*------------------ ft::maps ---------------------*/
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) // fill res from m1
            res += it->second;
        for (std::map<int, std::string>::const_reverse_iterator rit = m2.rbegin(); rit != m2.rend(); ++rit) // fill c_res from const m1
            c_res += rit->second;

        for (ft::map<int, std::string>::reverse_iterator it = ft_m1.rbegin(); it != ft_m1.rend(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;
        for (ft::map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin(); rit != ft_m2.rend(); ++rit) // fill c_ft_res from const ft_m1
            c_ft_res += rit->second;
        int arr[] = {12, 82, 37, 64, 15};
        ft::map<int, int> end_test;
        for(size_t i = 0; i < 5; ++i)
            end_test.insert(ft::make_pair(arr[i], i));
        ft::map<int, int>::reverse_iterator rit = end_test.rend();
        rit--;
        EQUAL(res == ft_res && c_res == c_ft_res && rit->first == 12);
    }
}

int main() {
    testrbeginrend();
    // system("leaks a.out");
}