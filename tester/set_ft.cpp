#include <iostream>
#include "../set.hpp"

int main()
{
    // begin & end
    std::cout << "begin & end: " << std::endl << std::endl;
    {
        ft::set<int> st;
        for (int i = 0; i < 7; i ++) {
            st.insert((i + 1) * 13);
        }
        // st.insert(13);
        for (ft::set<int>::iterator it = st.begin(); it != st.end(); it++)
            std::cout << "data: " << *it << std::endl;
        std::cout << "max_size: " << st.max_size() << "\n";
        std::cout << std::endl;
    }
    // clear
    std::cout << std::endl << "clear: " << std::endl << std::endl;
    {
        ft::set<int> st;
        for (int i = 0; i < 7; i ++) {
            st.insert((i + 1) * 13);
        }
        for (ft::set<int>::iterator it = st.begin(); it != st.end(); it++)
            std::cout << "data: " << *it << std::endl;
        std::cout << std::endl;
        st.clear();
        for (ft::set<int>::iterator it = st.begin(); it != st.end(); it++)
            std::cout << "data: " << *it << std::endl;
        std::cout << std::endl;
    }
    // count
    std::cout << std::endl << "count: " << std::endl << std::endl;
    {
        ft::set<int> st;

        // set some initial values:
        for (int i=1; i<5; ++i) st.insert(i*3);    // set: 3 6 9 12

        for (int i=0; i<10; ++i)
        {
            std::cout << i;
            if (st.count(i) != 0)
                std::cout << " is an element of st.\n";
            else
                std::cout << " is not an element of st.\n";
        }
    }
    // empty
    std::cout << std::endl << "empty" << std::endl << std::endl;
    {
        ft::set<int> st;

        st.insert(20);
        st.insert(30);
        st.insert(10);

        std::cout << "st contains:";
        while (!st.empty())
        {
            std::cout << ' ' << *st.begin();
            st.erase(st.begin());
        }
        std::cout << '\n';
    }
    // equal_range
    std::cout << std::endl << "equal_range" << std::endl << std::endl;
    {
        ft::set<int> st;

        for (int i=1; i<=5; i++) st.insert(i*10);   // st: 10 20 30 40 50

        ft::pair<ft::set<int>::const_iterator,ft::set<int>::const_iterator> ret;
        ret = st.equal_range(30);

        std::cout << "the lower bound points to: " << *ret.first << '\n';
        std::cout << "the upper bound points to: " << *ret.second << '\n';
    }
    // erase & find
    std::cout << std::endl << "erase & find: " << std::endl << std::endl;
    {
        ft::set<int> st;
        ft::set<int>::iterator it;

        // insert some values:
        for (int i=1; i<10; i++) st.insert(i*10);  // 10 20 30 40 50 60 70 80 90

        it = st.begin();
        ++it;                                         // "it" points now to 20

        st.erase (it);

        st.erase (40);

        it = st.find (60);
        st.erase (it, st.end());

        std::cout << "st contains:";
        for (it = st.begin(); it != st.end(); ++it)
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
    // get_allocator 
    std::cout << std::endl << "get_allocator: " << std::endl << std::endl;
    {
        ft::set<int> st;
        int * p;
        unsigned int i;

        // allocate an array of 5 elements using st's allocator:
        p = st.get_allocator().allocate(5);

        // assign some values to array
        for (i = 0; i < 5; i++)
            p[i] = (i+1) * 10;

        std::cout << "The allocated array contains:";
        for (i = 0; i < 5; i++)
            std::cout << ' ' << p[i];
        std::cout << '\n';

        st.get_allocator().deallocate(p,5);
    }
    // insert 
    std::cout << std::endl << "insert: " << std::endl << std::endl;
    {
        ft::set<int> st;
        ft::set<int>::iterator it;
        ft::pair<ft::set<int>::iterator,bool> ret;

        // set some initial values:
        for (int i = 1; i <= 5; ++i)
            st.insert(i * 10);    // set: 10 20 30 40 50

        ret = st.insert(20);               // no new element inserted

        if (ret.second == false) it=ret.first;  // "it" now points to element 20

        st.insert (it, 25);                 // max efficiency inserting
        st.insert (it, 24);                 // max efficiency inserting
        st.insert (it, 26);                 // no max efficiency inserting

        int myints[]= {5,10,15};              // 10 already in set, not inserted
        st.insert(myints, myints + 3);

        std::cout << "st contains:";
        for (it = st.begin(); it != st.end(); ++it)
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
    // key_comp
    std::cout << std::endl << "key_comp" << std::endl << std::endl;
    {
        ft::set<int> st;
        int highest;

        ft::set<int>::key_compare mycomp = st.key_comp();

        for (int i = 0; i <= 5; i++)
            st.insert(i);

        std::cout << "st contains:";

        highest =* st.rbegin();
        ft::set<int>::iterator it = st.begin();
        do {
            std::cout << ' ' << *it;
        } while ( mycomp(*(++it), highest) );

        std::cout << '\n';
    }
    // lower_bound & upper_bound
    std::cout << std::endl << "lower_bound & upper_bound: " << std::endl << std::endl;
    {
        ft::set<int> st;
        ft::set<int>::iterator itlow,itup;

        for (int i = 1; i < 10; i++)
            st.insert(i*10); // 10 20 30 40 50 60 70 80 90

        itlow = st.lower_bound (30);                //       ^
        itup = st.upper_bound (60);                 //                   ^

        st.erase(itlow, itup);                     // 10 20 70 80 90

        std::cout << "st contains:";
        for (ft::set<int>::iterator it = st.begin(); it != st.end(); ++it)
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
    // max_size
    std::cout << std::endl << "max_size: " << std::endl << std::endl;
    {
        int i;
        ft::set<int> st;

        if (st.max_size()>1000)
        {
            for (i=0; i<1000; i++) st.insert(i);
            std::cout << "The set contains 1000 elements.\n";
        }
        else std::cout << "The set could not hold 1000 elements.\n";

        return 0;
    }
    // operator=
    std::cout << std::endl << "operator=: " << std::endl << std::endl;
    {
        int myints[]={ 12,82,37,64,15 };
        ft::set<int> first (myints, myints+5);   // set with 5 ints
        ft::set<int> second;                    // empty set

        second = first;                          // now second contains the 5 ints
        first = ft::set<int>();                 // and first is empty

        std::cout << "Size of first: " << int (first.size()) << '\n';
        std::cout << "Size of second: " << int (second.size()) << '\n';
    }
    // rbegin && rend
    std::cout << std::endl << "rbegin && rend: " << std::endl << std::endl;
    {
        int myints[] = { 21, 64, 17, 78, 49 };
        ft::set<int> st (myints,myints+5);

        ft::set<int>::reverse_iterator rit;

        std::cout << "st contains:";
        for (rit = st.rbegin(); rit != st.rend(); ++rit)
        std::cout << ' ' << *rit;

        std::cout << '\n';
    }
    // size
    std::cout << std::endl << "size: " << std::endl << std::endl;
    {
        ft::set<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<10; ++i) myints.insert(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.insert (100);
        std::cout << "2. size: " << myints.size() << '\n';

        myints.erase(5);
        std::cout << "3. size: " << myints.size() << '\n';
    }
    // swap
    std::cout << std::endl << "swap: " << std::endl << std::endl;
    {
        int myints[]={ 12, 75, 10, 32, 20, 25 };
        ft::set<int> first (myints,myints+3);     // 10,12,75
        ft::set<int> second (myints+3,myints+6);  // 20,25,32

        first.swap(second);

        std::cout << "first contains:";
        for (ft::set<int>::iterator it = first.begin(); it != first.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "second contains:";
        for (ft::set<int>::iterator it = second.begin(); it != second.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    // value_comp
    std::cout << std::endl << "value_comp: " << std::endl << std::endl;
    {
        ft::set<int> st;

        ft::set<int>::value_compare mycomp = st.value_comp();

        for (int i = 0; i <= 5; i++)
            st.insert(i);

        std::cout << "st contains:";

        int highest =* st.rbegin();
        ft::set<int>::iterator it = st.begin();
        do {
            std::cout << ' ' << *it;
        } while ( mycomp(*(++it),highest) );

        std::cout << '\n';
    }
}