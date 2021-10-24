#include "vector.hpp"
#include <vector>

int main() {
    // ft::iterator<ft::input_iterator_tag, int> It;
    // ft::iterator<ft::input_iterator_tag, int> It0;
    // ft::iterator<ft::bidirectional_iterator_tag, int> It1;
    // ft::iterator<ft::bidirectional_iterator_tag, int> It10;
    // ft::iterator<ft::random_access_iterator_tag, int> It2;
    // ft::iterator<ft::random_access_iterator_tag, int> It20;
    // ft::advance(It, 5);
    // ft::advance(It1, 5);
    // ft::advance(It20, 5);

    // ft::distance(It, It0);
    // ft::distance(It1, It10);
    // ft::distance(It20, It2);
    // int p[4] = {1, 2, 3, 4};
    // ft::iterator<ft::random_access_iterator_tag, int> ii (p);

    // {
    //     ft::vector<int> vec(5, 100);
    //     ft::vector<int>::iterator itt = vec.begin();
    //     std::cout << *itt << std::endl;
    //     ft::vector<int>::iterator rtt = vec.end();
    //     vec[4] = 45;
    //     rtt--;
    //     std::cout << *rtt << std::endl;
    //     rtt--;
    //     std::cout << *rtt << std::endl;
    //     ft::vector<int> v;
    //     std::cout << (v.empty() ? "true" : "false") << std::endl;
    // }
    // std::cout << std::endl << std::endl;
    // {
    //     std::vector<int> vecc(5, 100);
    //     std::vector<int>::iterator ittc = vecc.begin();
    //     std::cout << *ittc << std::endl;
    //     std::vector<int>::iterator rttc = vecc.end();
    //     vecc[4] = 45;
    //     rttc--;
    //     std::cout << *rttc << std::endl;
    //     rttc--;
    //     std::cout << *rttc << std::endl;
    //     ft::vector<int> vc;
    //     std::cout << (vc.empty() ? "true" : "false")  << std::endl;
    // }
    // std::cout << std::endl << std::endl;
    // {
    //     std::vector<int> myvector;
    //     std::cout << "capacity: " << myvector.capacity() << std::endl;
    //     // set some initial content:
    //     for (int i=1;i<10;i++)
    //         myvector.push_back(i);
    //     std::cout << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << "myvector contains:";
    //     for (int i=0;i<myvector.size();i++)
    //         std::cout << ' ' << myvector[i];
    //     myvector.resize(5);
    //     std::cout << std::endl << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << std::endl;
    //     std::cout << "myvector contains:";
    //     for (int i=0;i<myvector.size();i++)
    //         std::cout << ' ' << myvector[i];
    //     std::cout << std::endl << myvector[8] << std::endl;
    //     myvector.resize(8,100);
    //     std::cout << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << "myvector contains:";
    //     for (int i=0;i<myvector.size();i++)
    //         std::cout << ' ' << myvector[i];
    //     std::cout << std::endl << myvector[8] << std::endl;
    //     myvector.resize(12);
    //     std::cout << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << "myvector contains:";
    //     for (int i=0;i<myvector.size();i++)
    //         std::cout << ' ' << myvector[i];
    //     std::cout << '\n';
    //     std::vector<int> vv;
    //     vv.reserve(33);
    //     std::cout << "capacity: " << vv.capacity() << std::endl;
    //     myvector.clear();
    //     std::cout << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << std::endl << myvector[4] << std::endl;
    // }
    // std::cout << std::endl << "FT::" << std::endl;
    // {
    //     ft::vector<int> myvector;
    //     std::cout << "capacity: " << myvector.capacity() << std::endl;
    //     // set some initial content:
    //     for (int i=1;i<10;i++)
    //         myvector.push_back(i);
    //     std::cout << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << "myvector contains:";
    //     for (int i=0;i<myvector.size();i++)
    //         std::cout << ' ' << myvector[i];
        // ft::vector<int>::iterator it = myvector.begin();
        // ft::vector<int>::iterator eit = myvector.end();
        // std::cout << std::endl << ft::distance(it, eit) << std::endl;
        // for (ft::vector<int>::iterator rit = myvector.begin(); rit != myvector.end(); rit++)
        //     std::cout << *rit << " ";
    //     myvector.resize(5);
    //     std::cout << std::endl << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << std::endl;
    //     std::cout << "myvector contains:";
    //     for (int i=0;i<myvector.size();i++)
    //         std::cout << ' ' << myvector[i];
    //     std::cout << std::endl << myvector[8] << std::endl;
    //     myvector.resize(8,100);
    //     std::cout << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << "myvector contains:";
    //     for (int i=0;i<myvector.size();i++)
    //         std::cout << ' ' << myvector[i];
    //     std::cout << std::endl << myvector[8] << std::endl;
    //     myvector.resize(12);
    //     std::cout << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << "myvector contains:";
    //     for (int i=0;i<myvector.size();i++)
    //         std::cout << ' ' << myvector[i];
    //     std::cout << '\n';
    //     ft::vector<int> vv;
    //     vv.reserve(33);
    //     std::cout << "capacity: " << vv.capacity() << std::endl;
    // }
    {
        std::vector<int> myvector;
        myvector.push_back(78);
        myvector.push_back(16);

        // now front equals 78, and back 16
        myvector.front() -= myvector.back();
        std::cout << "myvector.front() is now " << myvector.front() << '\n';
        myvector.back() += 15;
        std::cout << "myvector.back() is now " << myvector.back() << '\n';
    }

    {
        ft::vector<int> myvector;
        myvector.push_back(78);
        myvector.push_back(16);

        // now front equals 78, and back 16
        myvector.front() -= myvector.back();
        std::cout << "myvector.front() is now " << myvector.front() << '\n';
        myvector.back() += 15;
        std::cout << "myvector.back() is now " << myvector.back() << '\n';
    }
    {
        std::vector<int> numbers;
        numbers.assign(5, 3);
        std::cout << numbers.capacity() << std::endl;
        for (int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
        numbers.assign(6, 7);
        std::cout << numbers.capacity() << std::endl;
        for (int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
        numbers.assign(3, 2);
        std::cout << numbers.capacity() << std::endl;
        for (int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
        std::cout << numbers[4] << std::endl;

        std::string extra(12, 'b');
        numbers.assign(extra.begin(), extra.end());
        std::cout << numbers.capacity() << std::endl;
        for (int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        ft::vector<int> numbers;
        numbers.assign(5, 3);
        std::cout << numbers.capacity() << std::endl;
        for (int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
        numbers.assign(6, 7);
        std::cout << numbers.capacity() << std::endl;
        for (int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
        numbers.assign(3, 2);
        std::cout << numbers.capacity() << std::endl;
        for (int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
        std::cout << numbers[4] << std::endl;

        std::string extra(12, 'b');
        numbers.assign(extra.begin(), extra.end());
        std::cout << numbers.capacity() << std::endl;
        for (int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
    }
    return 0;
}