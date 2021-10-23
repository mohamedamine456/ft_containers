#include "vector.hpp"
#include <vector>

int main() {
    ft::iterator<ft::input_iterator_tag, int> It;
    ft::iterator<ft::input_iterator_tag, int> It0;
    ft::iterator<ft::bidirectional_iterator_tag, int> It1;
    ft::iterator<ft::bidirectional_iterator_tag, int> It10;
    ft::iterator<ft::random_access_iterator_tag, int> It2;
    ft::iterator<ft::random_access_iterator_tag, int> It20;
    ft::advance(It, 5);
    ft::advance(It1, 5);
    ft::advance(It2, 5);

    ft::distance(It, It0);
    ft::distance(It1, It10);
    ft::distance(It2, It20);
    // int p[4] = {1, 2, 3, 4};
    // ft::iterator<ft::random_access_iterator_tag, int> ii (p);
    // std::cout << *ii << std::endl;
    
    {
        ft::vector<int> vec(5, 100);
        ft::vector<int>::iterator itt = vec.begin();
        std::cout << *itt << std::endl;
        ft::vector<int>::iterator rtt = vec.end();
        vec[4] = 45;
        rtt--;
        std::cout << *rtt << std::endl;
        rtt--;
        std::cout << *rtt << std::endl;
        ft::vector<int> v;
        std::cout << (v.empty() ? "true" : "false") << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        std::vector<int> vecc(5, 100);
        std::vector<int>::iterator ittc = vecc.begin();
        std::cout << *ittc << std::endl;
        std::vector<int>::iterator rttc = vecc.end();
        vecc[4] = 45;
        rttc--;
        std::cout << *rttc << std::endl;
        rttc--;
        std::cout << *rttc << std::endl;
        ft::vector<int> vc;
        std::cout << (vc.empty() ? "true" : "false")  << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        std::vector<int> myvector;
        std::cout << "capacity: " << myvector.capacity() << std::endl;
        // set some initial content:
        for (int i=1;i<17;i++)
            myvector.push_back(i);
        std::cout << "capacity: " << myvector.capacity() << std::endl;
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        myvector.resize(5);
        std::cout << std::endl << "capacity: " << myvector.capacity() << std::endl;
        std::cout << std::endl;
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << std::endl << myvector[8] << std::endl;
        myvector.resize(8,100);
        std::cout << "capacity: " << myvector.capacity() << std::endl;
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << std::endl << myvector[8] << std::endl;
        myvector.resize(33);
        std::cout << "capacity: " << myvector.capacity() << std::endl;
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    std::cout << std::endl << std::endl;
    {
        ft::vector<int> myvector;
        std::cout << "capacity: " << myvector.capacity() << std::endl;
        // set some initial content:
        for (int i=1;i<17;i++)
            myvector.push_back(i);
        std::cout << "capacity: " << myvector.capacity() << std::endl;
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        myvector.resize(5);
        std::cout << std::endl << "capacity: " << myvector.capacity() << std::endl;
        std::cout << std::endl;
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << std::endl << myvector[8] << std::endl;
        myvector.resize(8,100);
        std::cout << "capacity: " << myvector.capacity() << std::endl;
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << std::endl << myvector[8] << std::endl;
        myvector.resize(33);
        std::cout << "capacity: " << myvector.capacity() << std::endl;
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    return 0;
}