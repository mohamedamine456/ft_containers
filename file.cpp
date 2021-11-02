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
    //     std::cout << "|" << std::endl;
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
    //     myvector.resize(5);
    //     std::cout << std::endl << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << "|" << std::endl;
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
    //     myvector.clear();
    //     std::cout << "capacity: " << myvector.capacity() << std::endl;
    //     std::cout << std::endl << myvector[4] << std::endl;
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
    //     std::cout << "|" << std::endl;
    //     numbers.assign(6, 7);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << "|" << std::endl;
    //     numbers.assign(3, 2);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << "|" << std::endl;
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
    //     std::cout << "|" << std::endl;
    // }
    // std::cout << "|" << std::endl;
    // {
    //     ft::vector<int> numbers;
    //     numbers.assign(5, 3);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << "|" << std::endl;
    //     numbers.assign(6, 7);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << "|" << std::endl;
    //     numbers.assign(3, 2);
    //     std::cout << numbers.capacity() << std::endl;
    //     for (int i = 0; i < numbers.size(); i++)
    //         std::cout << numbers[i] << " ";
    //     std::cout << "|" << std::endl;
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
    //     std::cout << "|" << std::endl;
    // }
    // std::cout << std::endl << "STD::CLEAR:" << std::endl;
    // {
    //     std::vector<std::string> vec;
    //     std::string *str = new std::string("C++");
    //     vec.assign(25, *str);
    //     std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     delete str;
    //     vec.clear();
    //     std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.capacity(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }
    // std::cout << std::endl << "FT::CLEAR:" << std::endl;
    // {
    //     ft::vector<std::string> vec;
    //     std::string *str = new std::string("C++");
    //     vec.assign(25, *str);
    //     std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     delete str;
    //     vec.clear();
    //     std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.capacity(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
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
    //     std::cout << "|" << std::endl;

    //     std::cout << "SEC:: Capacity: " << sec.capacity() << ", Size: " << sec.size() << std::endl;
    //     for (int i = 0; i < sec.size(); i++)
    //         std::cout << sec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }
    // std::cout << "SEC:: Capacity: " << sec.capacity() << ", Size: " << sec.size() << std::endl;
    // for (int i = 0; i < sec.size(); i++)
    //     std::cout << sec[i] << " ";
    // std::cout << "|" << std::endl;

    // std::cout << std::endl << std::endl;
    // ft::vector<int> tec;
    // {
    //     ft::vector<int> vec(7, 10);
    //     tec = vec;
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;

    //     std::cout << "TEC:: Capacity: " << tec.capacity() << ", Size: " << tec.size() << std::endl;
    //     for (int i = 0; i < tec.size(); i++)
    //         std::cout << tec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }
    // std::cout << "TEC:: Capacity: " << tec.capacity() << ", Size: " << tec.size() << std::endl;
    // for (int i = 0; i < tec.size(); i++)
    //     std::cout << tec[i] << " ";
    // std::cout << "|" << std::endl;


    // {
    //     std::vector<int>	vec(78, 5);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
	// 	std::vector<int>::iterator it = vec.begin();
	// 	it = it + 70;
    //     vec[70] = 50;
    //     std::cout << "POSITION: " << *it << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
	// 	vec.insert(it, 45);
    //     // vec.insert(it, 25);
    //     std::cout << "POSITION: " << *it << std::endl;
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }

	// std::cout << std::endl << std::endl;
	// {
    //     ft::vector<int>	vec(78, 5);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
	// 	ft::vector<int>::iterator it = vec.begin();
	// 	it = it + 70;
    //     vec[70] = 50;
    //     std::cout << "POSITION: " << *it << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
	// 	vec.insert(it, 45);
    //     // vec.insert(it, 25);
    //     std::cout << "POSITION: " << *it << std::endl;
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }

    // {
    //     std::vector<int>	vec(7, 5);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
    //     vec.push_back(8);
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
	// 	std::vector<int>::iterator it = vec.begin();
	// 	it++;
	// 	it++;
    //     vec[2] = 90;
    //     std::cout << "POSITION: " << *it << std::endl;
	// 	vec.insert(it, 5, 45);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
    //     std::cout << "POSITION: " << *it << std::endl;
    //     it--;
    //     std::cout << "POSITION: " << *it << std::endl;
    //     it--;
    //     std::cout << "POSITION: " << *it << std::endl;
    //     it = vec.begin();
	// 	it++;
	// 	it++;
    //     vec[2] = 90;
    //     vec.insert(it, 2, 80);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
    //     it = vec.begin();
	// 	it++;
	// 	it++;
    //     vec[2] = 90;
    //     vec.insert(it, 100, 85);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
    //     it = vec.begin();
	// 	it++;
	// 	it++;
    //     vec[2] = 90;
    //     vec.insert(it, 2000, 77);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
    // }
    // std::cout << std::endl << std::endl;
	// {
    //     ft::vector<int>	vec(7, 5);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
    //     vec.push_back(8);
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
	// 	ft::vector<int>::iterator it = vec.begin();
	// 	it++;
	// 	it++;
    //     vec[2] = 90;
    //     std::cout << "POSITION: " << *it << std::endl;
	// 	vec.insert(it, 5, 45);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
    //     std::cout << "POSITION: " << *it << std::endl;
    //     it--;
    //     std::cout << "POSITION: " << *it << std::endl;
    //     it--;
    //     std::cout << "POSITION: " << *it << std::endl;
    //     it = vec.begin();
	// 	it++;
	// 	it++;
    //     vec[2] = 90;
    //     vec.insert(it, 2, 80);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
    //     it = vec.begin();
	// 	it++;
	// 	it++;
    //     vec[2] = 90;
    //     vec.insert(it, 100, 85);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
    //     it = vec.begin();
	// 	it++;
	// 	it++;
    //     vec[2] = 90;
    //     vec.insert(it, 2000, 77);
	// 	std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " |";
    //     std::cout << "|" << std::endl;
    // }
    // {
    //     std::vector<int> vec;
    //     vec.assign(5, 11);
    //     int p[8] = {4, 5 , 2 , 7 , 9 , 44 , 66 , 65};
    //     std::vector<int>::iterator it = vec.begin();
    //     it = it + 2;
    //     vec.insert(it, p, p + 7);
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     it = vec.begin();
    //     it = it + 5;
    //     vec.insert(it, p + 2, p + 8);
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }
    // std::cout << "\n\n";
    // {
    //     ft::vector<int> vec;
    //     vec.assign(5, 11);
    //     int p[8] = {4, 5 , 2 , 7 , 9 , 44 , 66 , 65};
    //     ft::vector<int>::iterator it = vec.begin();
    //     it = it + 2;
    //     vec.insert(it, p, p + 7);
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     it = vec.begin();
    //     it = it + 5;
    //     vec.insert(it, p + 2, p + 8);
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }
    // {
    //     std::vector<std::string> vec;
    //     vec.assign(5, "Hello");
    //     std::string p[8] = {"AA", "DD" , "TT", "II", "OO" , "RR" , "QQ" , "SS"};
    //     std::vector<std::string>::iterator it = vec.begin();
    //     it = it + 2;
    //     vec.insert(it, p, p + 7);
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << ", ITERATORS: " << *it << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     vec.push_back("C++");
    //     it = vec.begin();
    //     it = it + 5;
    //     vec.insert(it, p + 2, p + 8);
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << ", ITERATORS: " << *it << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }
    // std::cout << "\n\n";
    // {
    //     ft::vector<std::string> vec;
    //     vec.assign(5, "Hello");
    //     std::string p[8] = {"AA", "DD" , "TT", "II", "OO" , "RR" , "QQ" , "SS"};
    //     ft::vector<std::string>::iterator it = vec.begin();
    //     it = it + 2;
    //     vec.insert(it, p, p + 7);
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << ", ITERATORS: " << *it << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     vec.push_back("C++");
    //     it = vec.begin();
    //     it = it + 5;
    //     vec.insert(it, p + 2, p + 8);
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << ", ITERATORS: " << *it << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }
    // {
    //     std::vector<std::string> vec;
    //     std::string p[11] = {"AA", "DD" , "TT", "II", "OO" , "RR" , "QQ" , "SS", "PP", "LL", "UU"};
    //     for (int i = 0; i < 11; i++)
    //         vec.push_back(p[i]);
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     std::vector<std::string>::iterator it = vec.begin();
    //     it += 1;
    //     vec.erase(it);
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     it = vec.begin();
    //     it = it + 2;
    //     std::vector<std::string>::iterator itl = vec.end();
    //     itl -= 2;
    //     vec.erase(it, itl);
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    // }
    // std::cout << "\n\n";
    // {
    //     ft::vector<std::string> vec;
    //     std::string p[11] = {"AA", "DD" , "TT", "II", "OO" , "RR" , "QQ" , "SS", "PP", "LL", "UU"};
    //     for (int i = 0; i < 11; i++)
    //         vec.push_back(p[i]);
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     ft::vector<std::string>::iterator it = vec.begin();
    //     it += 1;
    //     vec.erase(it);
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     it = vec.begin();
    //     it = it + 2;
    //     ft::vector<std::string>::iterator itl = vec.end();
    //     itl -= 2;
    //     vec.erase(it, itl);
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    // }
    // {
    //     std::cout << "STD: \n";
    //     std::vector<std::string> vec;
    //     std::vector<std::string> sec;
    //     std::string p[11] = {"AA", "DD" , "TT", "II", "OO" , "RR" , "QQ" , "SS", "PP", "LL", "UU"};
    //     for (int i = 0; i < 11; i++)
    //         vec.push_back(p[i]);
    //     std::string d[5] = {"MM", "CC", "YY", "JJ", "FF"};
    //     for (int i = 0; i < 5; i++)
    //         sec.push_back(d[i]);
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "SEC:: Capacity: " << sec.capacity() << ", Size: " << sec.size() << std::endl;
    //     for (int i = 0; i < sec.size(); i++)
    //         std::cout << sec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     vec.swap(sec);
    //     std::cout << "AFTER SWAP: \n";
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "SEC:: Capacity: " << sec.capacity() << ", Size: " << sec.size() << std::endl;
    //     for (int i = 0; i < sec.size(); i++)
    //         std::cout << sec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::vector<std::string>::iterator it = vec.begin();
    //     it = it + 2;
    //     vec.insert(it, p, p + 7);
    //     it = sec.begin();
    //     it = it + 2;
    //     sec.insert(it, d, d + 3);
    //     std::cout << "AFTER insert: \n";
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "SEC:: Capacity: " << sec.capacity() << ", Size: " << sec.size() << std::endl;
    //     for (int i = 0; i < sec.size(); i++)
    //         std::cout << sec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }
    // std::cout << "\n\n\n";
    // {
    //     std::cout << "FT: \n";
    //     ft::vector<std::string> vec;
    //     ft::vector<std::string> sec;
    //     std::string p[11] = {"AA", "DD" , "TT", "II", "OO" , "RR" , "QQ" , "SS", "PP", "LL", "UU"};
    //     for (int i = 0; i < 11; i++)
    //         vec.push_back(p[i]);
    //     std::string d[5] = {"MM", "CC", "YY", "JJ", "FF"};
    //     for (int i = 0; i < 5; i++)
    //         sec.push_back(d[i]);
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "SEC:: Capacity: " << sec.capacity() << ", Size: " << sec.size() << std::endl;
    //     for (int i = 0; i < sec.size(); i++)
    //         std::cout << sec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     vec.swap(sec);
    //     std::cout << "AFTER SWAP: \n";
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "SEC:: Capacity: " << sec.capacity() << ", Size: " << sec.size() << std::endl;
    //     for (int i = 0; i < sec.size(); i++)
    //         std::cout << sec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     ft::vector<std::string>::iterator it = vec.begin();
    //     it = it + 2;
    //     vec.insert(it, p, p + 7);
    //     it = sec.begin();
    //     it = it + 2;
    //     sec.insert(it, d, d + 3);
    //     std::cout << "AFTER insert: \n";
    //     std::cout << "VEC:: Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    //     for (int i = 0; i < vec.size(); i++)
    //         std::cout << vec[i] << " ";
    //     std::cout << "|" << std::endl;
    //     std::cout << "SEC:: Capacity: " << sec.capacity() << ", Size: " << sec.size() << std::endl;
    //     for (int i = 0; i < sec.size(); i++)
    //         std::cout << sec[i] << " ";
    //     std::cout << "|" << std::endl;
    // }
    // {
    //     ft::vector<int> v(3, 4);
    //     ft::vector<int>::iterator it, it1;
    //     it = v.begin();
    //     it1 = v.begin() + 1;
    //     /*----------------------------------*/
    //     /*------------ ft::vector ---------*/
    //     ft::vector<int> my_v(3, 4);
    //     ft::vector<int>::iterator my_it, my_it1, tmp;
    //     my_it = my_v.begin();
    //     my_it1 = my_v.begin() + 1;
    //     my_it += 1;
    //     my_it -= 1;
    //     ++my_it;
    //     --my_it;
    //     tmp = my_it++;
    //     std::cout << "FT: " <<  &(*my_it) << ", " << &(*tmp) << ", " <<  &(*my_it) << ", " << &(*my_it1) << "\n";
    // }
    // {
    //     std::vector<int> v(3, 4);
    //     std::vector<int>::iterator it, it1;
    //     it = v.begin();
    //     it1 = v.begin() + 1;
    //     /*----------------------------------*/
    //     /*------------ ft::vector ---------*/
    //     std::vector<int> my_v(3, 4);
    //     std::vector<int>::iterator my_it, my_it1, tmp;
    //     my_it = my_v.begin();
    //     my_it1 = my_v.begin() + 1;
    //     my_it += 1;
    //     my_it -= 1;
    //     ++my_it;
    //     --my_it;
    //     tmp = my_it++;
    //     std::cout << "STD: " <<  &(*my_it) << ", " << &(*tmp) << ", " <<  &(*my_it) << ", " << &(*my_it1) << "\n";
    // }
    
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string> v1(10, "string2");
            v1.reserve(1e6);
            std::cout << v1.capacity() << v1[0] << " " << v1[9] << "\n";
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string> ft_v1(10, "string2");
            ft_v1.reserve(1e6);
            std::cout << ft_v1.capacity() << ft_v1[0] << " " << ft_v1[9] << "\n";
        }
        /*
         * Strings to store the results
         */
        // std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
        // std::string sit1, ft_sit1; // strings to store the result by iterators
        // /*
        //  * Var to store the size and the capacity
        //  */
        // size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
        // size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        // /*
        //  * iterators to check the iterator validity
        //  *  it : iterator, eit : iterator to the end
        //  */
        // std::vector<std::string>::iterator valid_it, valid_eit;
        // ft::vector<std::string>::iterator ft_valid_it, ft_valid_eit;
        // // bool to check if the function throw or not
        // bool exec_throwed = false;
        // /*------------------ std::vectors ---------------------*/
        // std::vector<std::string> v1(10, "string2");
        // std::vector<char> v2;
        // /*------------------ std::vectors ---------------------*/
        // ft::vector<std::string> ft_v1(10, "string2");
        // ft::vector<char> ft_v2;
        // try
        // {
        //     ft_v1.reserve(ft_v1.max_size() + 1);
        // }
        // catch (std::exception const &e)
        // {
        //     (void)e;
        //     exec_throwed = true;
        // }
        // v1.reserve(100);
        // ft_v1.reserve(100);

        // z1 = v1.size();
        // ft_z1 = ft_v1.size();
        // c1 = v1.capacity();
        // ft_c1 = ft_v1.capacity();

        // for (size_t i = 0; i < v1.size(); ++i)
        //     s1 += v1[i];

        // ft_valid_it = ft_v1.begin();
        // for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
        //     ft_s1 += *ft_valid_it;

        // valid_it = v1.begin();
        // valid_eit = v1.end();
        // ft_valid_it = ft_v1.begin();
        // ft_valid_eit = ft_v1.end();
        // v1.reserve(50);
        // ft_v1.reserve(50);

        // z2 = v1.size();
        // ft_z2 = ft_v1.size();
        // c2 = v1.capacity();
        // ft_c2 = ft_v1.capacity();

        // for (size_t i = 0; i < v1.size(); ++i)
        //     s2 += v1[i];

        // for (; valid_it != valid_eit; ++valid_it)
        //     sit1 += *valid_it;

        // for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
        //     ft_s2 += *it;

        // for (; ft_valid_it != ft_valid_eit; ++ft_valid_it)
        //     ft_sit1 += *ft_valid_it;

        // v2.reserve(200);
        // ft_v2.reserve(200);
        // z3 = v2.size();
        // ft_z3 = ft_v2.size();
        // c3 = v2.capacity();
        // ft_c3 = ft_v2.capacity();

        // for (size_t i = 0; i < v2.size(); ++i)
        //     s3 += v2[i];

        // for (ft::vector<char>::iterator it = ft_v2.begin(); it != ft_v2.end(); ++it)
        //     ft_s3 += *it;
    }

    // system("leaks a.out");
    return 0;
}