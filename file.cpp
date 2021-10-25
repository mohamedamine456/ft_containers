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
    // {
    //     std::vector<int> myvector;
    //     myvector.push_back(78);
    //     myvector.push_back(16);

    //     // now front equals 78, and back 16
    //     myvector.front() -= myvector.back();
    //     std::cout << "myvector.front() is now " << myvector.front() << '\n';
    //     myvector.back() += 15;
    //     std::cout << "myvector.back() is now " << myvector.back() << '\n';
    // }

    // {
    //     ft::vector<int> myvector;
    //     myvector.push_back(78);
    //     myvector.push_back(16);

    //     // now front equals 78, and back 16
    //     myvector.front() -= myvector.back();
    //     std::cout << "myvector.front() is now " << myvector.front() << '\n';
    //     myvector.back() += 15;
    //     std::cout << "myvector.back() is now " << myvector.back() << '\n';
    // }
    // {
    //     std::vector<int> numbers;
    //     numbers.assign(5, 3);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << std::endl;
    //     numbers.assign(6, 7);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << std::endl;
    //     numbers.assign(3, 2);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << std::endl;
    //     std::cout << numbers[4] << std::endl;

    //     std::string extra(12, 'b');
    //     extra[0] = 'c';
    //     extra[11] = 'd';
    //     std::string::iterator itb = extra.begin();
    //     std::string::iterator ite = extra.end();
    //     std::cout << " iterators: " << *itb << " " << *(ite - 1) << std::endl;
    //     numbers.assign(itb, ite);
    //     std::cout << " after assign iterators: " << *itb << " " << *(ite - 1) << std::endl;
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    // {
    //     ft::vector<int> numbers;
    //     numbers.assign(5, 3);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << std::endl;
    //     numbers.assign(6, 7);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << std::endl;
    //     numbers.assign(3, 2);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << std::endl;
    //     std::cout << numbers[4] << std::endl;

    //     std::string extra(12, 'b');
    //     extra[0] = 'c';
    //     extra[11] = 'd';
    //     std::string::iterator itb = extra.begin();
    //     std::string::iterator ite = extra.end();
    //     std::cout << " iterators: " << *itb << " " << *(ite - 1) << std::endl;
    //     numbers.assign(itb, ite);
    //     std::cout << " after assign iterators: " << *itb << " " << *(ite - 1) << std::endl;
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl << "STD::CLEAR:" << std::endl;
    // {
    //     std::vector<std::string> vec;
    //     std::string *str = new std::string("C++");
    //     vec.assign(25, *str);
    //     std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;
    //     delete str;
    //     vec.clear();
    //     std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.capacity(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl << "FT::CLEAR:" << std::endl;
    // {
    //     ft::vector<std::string> vec;
    //     std::string *str = new std::string("C++");
    //     vec.assign(25, *str);
    //     std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;
    //     delete str;
    //     vec.clear();
    //     std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.capacity(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl << "STD::relational operators:" << std::endl;
    // {
    //     std::vector<int> vec;
    //     vec.assign(5,6);
    //     std::vector<int> sec;
    //     sec.assign(5,6);
    //     std::cout << (vec == sec ? "equals" : "different") << std::endl;
    //     sec.assign(5,7);
    //     std::cout << (vec == sec ? "equals" : "different") << std::endl;
    //     sec.assign(5,7);
    //     std::cout << (vec != sec ? "different" : "equals") << std::endl;
    //     sec.assign(5,5);
    //     std::cout << (vec > sec ? "bigger" : "smaller") << std::endl;
    //     sec.assign(5,8);
    //     std::cout << (vec < sec ? "smaller" : "bigger") << std::endl;
    //     sec.assign(5,5);
    //     std::cout << (vec >= sec ? "bigger or equal" : "smaller or eqaul") << std::endl;
    //     sec.assign(5,8);
    //     std::cout << (vec <= sec ? "smaller or equal" : "bigger or eqaul") << std::endl;
    // }
    // std::cout << std::endl << "FT::relational operators:" << std::endl;
    // {
    //     ft::vector<int> vec;
    //     vec.assign(5,6);
    //     ft::vector<int> sec;
    //     sec.assign(5,6);
    //     std::cout << (vec == sec ? "equals" : "different") << std::endl;
    //     sec.assign(5,7);
    //     std::cout << (vec == sec ? "equals" : "different") << std::endl;
    //     sec.assign(5,7);
    //     std::cout << (vec != sec ? "different" : "equals") << std::endl;
    //     sec.assign(5,5);
    //     std::cout << (vec > sec ? "bigger" : "smaller") << std::endl;
    //     sec.assign(5,8);
    //     std::cout << (vec < sec ? "smaller" : "bigger") << std::endl;
    //     sec.assign(5,5);
    //     std::cout << (vec >= sec ? "bigger or equal" : "smaller or eqaul") << std::endl;
    //     sec.assign(5,8);
    //     std::cout << (vec <= sec ? "smaller or equal" : "bigger or eqaul") << std::endl;
    // }

    // std::vector<int> sec;
    // {
    //     std::vector<int> vec(7, 10);
    //     sec = vec;
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;

    //     std::cout << "SEC:: Capacity: " << sec.capacity() << ", Size: " << sec.size() << std::endl;
    //     for (int i = 0; i < sec.size(); i++)
    //         std::cout << sec[i] << " ";
    //     std::cout << std::endl;
    // }
    // std::cout << "SEC:: Capacity: " << sec.capacity() << ", Size: " << sec.size() << std::endl;
    // for (int i = 0; i < sec.size(); i++)
    //     std::cout << sec[i] << " ";
    // std::cout << std::endl;

    // std::cout << std::endl << std::endl;
    // ft::vector<int> tec;
    // {
    //     ft::vector<int> vec(7, 10);
    //     tec = vec;
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;

    //     std::cout << "TEC:: Capacity: " << tec.capacity() << ", Size: " << tec.size() << std::endl;
    //     for (int i = 0; i < tec.size(); i++)
    //         std::cout << tec[i] << " ";
    //     std::cout << std::endl;
    // }
    // std::cout << "TEC:: Capacity: " << tec.capacity() << ", Size: " << tec.size() << std::endl;
    // for (int i = 0; i < tec.size(); i++)
    //     std::cout << tec[i] << " ";
    // std::cout << std::endl;


    // {
    //     std::vector<int>	vec(78, 5);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;
	// 	std::vector<int>::iterator it = vec.begin();
	// 	it = it + 70;
    //     vec[70] = 50;
    //     std::cout << "POSITION: " << *it << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;
	// 	vec.insert(it, 45);
    //     std::cout << "POSITION: " << *it << std::endl;
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;
    // }

	// std::cout << std::endl << std::endl;
	// {
    //     ft::vector<int>	vec(78, 5);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;
	// 	ft::vector<int>::iterator it = vec.begin();
	// 	it = it + 70;
    //     vec[70] = 50;
    //     std::cout << "POSITION: " << *it << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;
	// 	vec.insert(it, 45);
    //     std::cout << "POSITION: " << *it << std::endl;
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << std::endl;
    // }

    {
        std::vector<int>	vec(7, 5);
		std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
        for (int i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " |";
        std::cout << std::endl;
        // vec.push_back(8);
        // std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
        for (int i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " |";
        std::cout << std::endl;
		std::vector<int>::iterator it = vec.begin();
		it++;
		it++;
        vec[2] = 90;
        for (; it != vec.end(); it++)
            std::cout << *it << " |";
        // std::cout << "POSITION: " << *it << std::endl;
		// vec.insert(it, 12, 45);
		// std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
        // for (int i = 0; i < vec.size(); i++)
        //     std::cout << vec[i] << " |";
        std::cout << std::endl;
        // std::cout << "POSITION: " << *it << std::endl;
    //     vec.insert(it, 2, 80);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " \n";
    //     std::cout << std::endl;

    //     vec.insert(it, 100, 85);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " \n";
    //     std::cout << std::endl;

    //     vec.insert(it, 2000, 77);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " \n";
    //     std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
	{
        ft::vector<int>	vec(7, 5);
		std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
        for (int i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " |";
        std::cout << std::endl;
        // vec.push_back(8);
        // std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
        // for (int i = 0; i < vec.size(); i++)
        //     std::cout << vec[i] << " |";
        // std::cout << std::endl;
		ft::vector<int>::iterator it = vec.begin();
		it++;
		it++;
        vec[2] = 90;
        for (; it != vec.end(); it++)
            std::cout << *it << " |";
        // std::cout << "POSITION: " << *it << std::endl;
		// vec.insert(it, 12, 45);
		// std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
        // for (int i = 0; i < vec.size(); i++)
        //     std::cout << vec[i] << " |";
        std::cout << std::endl;
        // std::cout << "POSITION: " << *it << std::endl;
        // vec.insert(it, 2, 80);
		// std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
        // for (int i = 0; i < vec.size(); i++)
        //     std::cout << vec[i] << " \n";
        // std::cout << std::endl;

        // vec.insert(it, 100, 85);
		// std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
        // for (int i = 0; i < vec.size(); i++)
        //     std::cout << vec[i] << " \n";
        // std::cout << std::endl;

        // vec.insert(it, 2000, 77);
		// std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
        // for (int i = 0; i < vec.size(); i++)
        //     std::cout << vec[i] << " \n";
        // std::cout << std::endl;
    }

    // system("leaks a.out");
    return 0;
}