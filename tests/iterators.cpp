#include <iostream>
#include <iterator>
#include <vector>
#include <deque>

int main () {
    // advance
    std::cout << std::endl << "advance: " << std::endl << std::endl;
    {
        std::vector<int> vec;
        int arr [] = { 101, 202, 303, 404, 505, 606, 707 };
        vec.insert(vec.begin(), arr, arr + 7);
        std::vector<int>::iterator it = vec.begin();
        std::cout << "Iterator it on: " << *it << std::endl;
        std::advance(it, 5);
        std::cout << "Iterator it after advance on: " << *it << std::endl;
    }
    // back_inserter
    std::cout << std::endl << "back_inserter: " << std::endl << std::endl;
    {
        std::vector<int> vec, sec_vec;
        int arr [] = { 101, 202, 303, 404, 505, 606, 707 };
        int arr2 [] = { 1, 2, 3, 4, 5, 6, 7 };
        vec.insert(vec.begin(), arr, arr + 7);
        sec_vec.insert(sec_vec.begin(), arr2, arr2  + 7);

        std::copy(sec_vec.begin(), sec_vec.end(), back_inserter(vec));
        std::cout << "vec contains:";
        for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << ' ' << *it;
    }
    // distance
    std::cout << std::endl << "distance: " << std::endl << std::endl;
    {
        std::vector<int> vec, sec_vec;
        int arr [] = { 101, 202, 303, 404, 505, 606, 707 };
        vec.insert(vec.begin(), arr, arr + 7);

        std::cout << "The distance is: " << std::distance(vec.begin(), vec.end()) << std::endl;
    }
    // front_inserter
    std::cout << std::endl << "front_inserter: " << std::endl << std::endl;
    {
        std::deque<int> dq, sec_dq;
        int arr [] = { 101, 202, 303, 404, 505, 606, 707 };
        int arr2 [] = { 1, 2, 3, 4, 5, 6, 7 };
        dq.insert(dq.begin(), arr, arr + 7);
        sec_dq.insert(sec_dq.begin(), arr2, arr2  + 7);

        std::copy(sec_dq.begin(), sec_dq.end(), std::front_inserter(dq));
        std::cout << "vec contains:";
        for(std::deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
            std::cout << ' ' << *it;
    }
    // inserter
    std::cout << std::endl << "inserter: " << std::endl << std::endl;
    {

    }
    return (0);
}