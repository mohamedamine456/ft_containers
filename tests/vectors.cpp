#include <iostream>
#include <vector>

int main()
{
	// assign & at
	std::cout << "assign & at" << std::endl;
	{
		std::vector<int> vec;
		vec.assign(5, 124);
		std::vector<int>::iterator first = vec.begin();
		std::vector<int>::iterator last = vec.end();
		while (first != last)
		{
			std::cout << *first << " ";
			first++;
		}
		std::cout << std::endl;

		vec.at(0) = 500;
		vec.at(2) = 300;
		vec.at(4) = 100;
		first = vec.begin();
		last = vec.end();
		while (first != last)
		{
			std::cout << *first << " ";
			first++;
		}
		std::cout << std::endl;
	}
	// back
	std::cout << std::endl << "back" << std::endl;
	{
		std::vector<int> vec;

		vec.push_back(12);
		while (vec.back() > 0)
		{
			vec.push_back(vec.back() - 1);
		}
		std::vector<int>::iterator first = vec.begin();
		std::vector<int>::iterator last = vec.end();
		while (first != last)
		{
			std::cout << *first << " ";
			first++;
		}
		std::cout << std::endl;
	}
	// begin & end
	std::cout << std::endl << "begin & end" << std::endl;
	{
		std::vector<int> vec;

		for (int i = 0; i < 15; i++)
		{
			vec.push_back((i + 1) * 100);
		}
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	//size & capacity & max_size
	std::cout << std::endl << "size & capacity & max_size" << std::endl;
	{
		std::vector<int> vec;

		vec.push_back(0);
		while (vec.back() < 33)
		{
			vec.push_back(vec.back() + 1);
		}
		std::cout << "size of vec: " << vec.size() << std::endl;
		std::cout << "capacity of vec: " << vec.capacity() << std::endl;
		std::cout << "max_size of vec: " << vec.max_size() << std::endl;
	}
	
	{

	}
	return (0);
}
