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
            // test 1: test with capacity greater than or equal the size + n (reallocation must'nt happen)
            /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string> v1(1e6, "string2");
                v1.reserve(1e6 + 200);
                v1.insert(v1.begin() + 1e5, 100, "string1");
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string> ft_v1(1e6, "string2");
                ft_v1.reserve(1e6 + 200);
                ft_v1.insert(ft_v1.begin() + 1e5, 100, "string1");
            }
            /*--------------------------------------------------------------------------------------*/
            // test 2: test with capacity lesser than the size + n (reallocation must happen)
            /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string> v1(1e6, "string2");
                v1.insert(v1.begin() + 1e5, 200, "string1");
                // /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string> ft_v1(1e6, "string2");
                ft_v1.insert(ft_v1.begin() + 1e5, 200, "string1");
            }
            /*--------------------------------------------------------------------------------------*/
        }
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        /*
         * bool to store the comparison
         */
        bool cond;

        /*------------------------------- test 1: empty vector ----------------------------------------*/
        // insert at the begin
        {
            std::vector<std::string> v;
            ft::vector<std::string> ft_v;
            v.insert(v.begin(), 100, "hello");
            ft_v.insert(ft_v.begin(), 100, "hello");
            ft_v.begin()->length();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
        }
        // insert at the end
        {
            std::vector<std::string> v;
            ft::vector<std::string> ft_v;

            v.insert(v.end(), "hello");
            ft_v.insert(ft_v.end(), "hello");
            ft_v.begin()->length();

            str.clear();
            ft_str.clear();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
        }
        // // /*---------------------------------------------------------------------------------------------------*/
        // // /*------------------------------- test 2: the vector capacity >= size + n ----------------------------------------*/
        {
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");
            ft::vector<std::string>::iterator valid_it;

            v.reserve(100);
            ft_v.reserve(100);
            valid_it = ft_v.begin();
            v.insert(v.begin() + 15, 70, "hello");
            ft_v.insert(ft_v.begin() + 15, 70, "hello");

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*ft_v.begin())));
        }
        // // /*---------------------------------------------------------------------------------------------------*/
        // // /*------------------------------- test 3: the vector capacity < size + n && n > size ----------------------------------------*/
        // {
        //     std::vector<std::string> v(20, "string");
        //     ft::vector<std::string> ft_v(20, "string");

        //     v.insert(v.begin() + 10, 100, "hello");
        //     ft_v.insert(ft_v.begin() + 10, 100, "hello");

        //     str.clear();
        //     ft_str.clear();
        //     s = v.size();
        //     ft_s = ft_v.size();
        //     c = v.capacity();
        //     ft_c = ft_v.capacity();
        //     for (size_t i = 0; i < v.size(); ++i)
        //         str += v[i];
        //     for (size_t i = 0; i < ft_v.size(); ++i)
        //         ft_str += ft_v[i];
        //     cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        // }
        // // /*---------------------------------------------------------------------------------------------------*/
        // // /*------------------------------- test 4: the vector capacity < size + n && n <= size ----------------------------------------*/
        // {
        //     std::vector<std::string> v(20, "string");
        //     ft::vector<std::string> ft_v(20, "string");

        //     v.insert(v.begin() + 10, 15, "hello");
        //     ft_v.insert(ft_v.begin() + 10, 15, "hello");

        //     str.clear();
        //     ft_str.clear();
        //     s = v.size();
        //     ft_s = ft_v.size();
        //     c = v.capacity();
        //     ft_c = ft_v.capacity();
        //     for (size_t i = 0; i < v.size(); ++i)
        //         str += v[i];
        //     for (size_t i = 0; i < ft_v.size(); ++i)
        //         ft_str += ft_v[i];
        //     cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
        // }
        // /*---------------------------------------------------------------------------------------------------*/
    }

    // system("leaks a.out");
    return 0;
}