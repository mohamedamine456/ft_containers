#include <iostream>
#include <vector>
#include "../utils/iterator.hpp"
#include "../vector.hpp"

int main()
{
	// assign & at
	std::cout << "assign & at: " << std::endl;
	{
		ft::vector<int> vec;
		vec.assign(5, 124);
		ft::vector<int>::iterator first = vec.begin();
		ft::vector<int>::iterator last = vec.end();
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
	std::cout << std::endl << "back: " << std::endl;
	{
		ft::vector<int> vec;

		vec.push_back(12);
		while (vec.back() > 0)
		{
			vec.push_back(vec.back() - 1);
		}
		ft::vector<int>::iterator first = vec.begin();
		ft::vector<int>::iterator last = vec.end();
		while (first != last)
		{
			std::cout << *first << " ";
			first++;
		}
		std::cout << std::endl;
	}
	// begin & end
	std::cout << std::endl << "begin & end: " << std::endl;
	{
		ft::vector<int> vec;

		for (int i = 0; i < 15; i++)
		{
			vec.push_back((i + 1) * 100);
		}
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	// size & capacity & max_size
	std::cout << std::endl << "size & capacity & max_size: " << std::endl;
	{
		ft::vector<int> vec;

		vec.push_back(0);
		while (vec.back() < 33)
		{
			vec.push_back(vec.back() + 1);
		}
		std::cout << "size of vec: " << vec.size() << std::endl;
		std::cout << "capacity of vec: " << vec.capacity() << std::endl;
		std::cout << "max_size of vec: " << vec.max_size() << std::endl;
	}
	// clear & empty
	std::cout << std::endl << "clear & empty" << std::endl;
	{
		ft::vector<int> vec;
		vec.assign(10, 13);
		std::cout << "vec is empty: " << (vec.empty() ? "Yes" : "No") << std::endl;
		vec.clear();
		std::cout << "vec is empty: " << (vec.empty() ? "Yes" : "No") << std::endl;
	}
	// erase
	std::cout << std::endl << "erase: " << std::endl;
	{
		ft::vector<int> vec;
		vec.assign(7, 100);

		std::cout << std::endl << "Before erase: " << std::endl;
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			std::cout << *it << " ";
		}
		
		vec.erase(vec.begin(), vec.begin() + 3);
		std::cout << std::endl << "After erase: " << std::endl;
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			std::cout << *it << " ";
		}
	}
	// front 
	std::cout << std::endl << "front: " <<std::endl;
	{
		ft::vector<int> vec;

		vec.push_back(45);
		vec.push_back(14);

		std::cout << "vec.front() was: " << vec.front() << std::endl;

		vec.front() -= vec.back();
		std::cout << "vec.front() now is: " << vec.front() << std::endl;
	}
	// get_allocator
	std::cout << std::endl << "get_allocator: " << std::endl << std::endl;
	{
		ft::vector<int> vec;
		int *pointer;
		pointer = vec.get_allocator().allocate(7);

		for (int i = 0; i < 7; i++)
			vec.get_allocator().construct(pointer + i, i + 1);
		
		std::cout << "The Allocated Array contains: " << std::endl;
		for (int i = 0; i < 7; i++)
			std::cout << pointer[i] << " ";
		std::cout << std::endl;

		for (int i = 0; i < 7; i++)
			vec.get_allocator().destroy(pointer + i);
		vec.get_allocator().deallocate(pointer, 7);
		std::cout << "The Array deallocated" << std::endl;
	}
	// insert
	std::cout << std::endl << "insert: " << std::endl << std::endl;
	{
		ft::vector<int> vec(3, 100);
		ft::vector<int>::iterator it;
		// init vec
		for (ft::vector<int>::iterator tt = vec.begin(); tt != vec.end(); tt++)
			std::cout << *tt << " ";
		std::cout << std::endl;

		//insert one element
		it = vec.begin();
		it = vec.insert(it, 200);
		for (ft::vector<int>::iterator tt = vec.begin(); tt != vec.end(); tt++)
			std::cout << *tt << " ";
		std::cout << std::endl;

		//insert multi
		it = vec.begin();
		vec.insert(it + 2, 2, 300);
		for (ft::vector<int>::iterator tt = vec.begin(); tt != vec.end(); tt++)
			std::cout << *tt << " ";
		std::cout << std::endl;

		//insert using iterators
		it = vec.begin();
		ft::vector<int> sec_vec (2, 400);
		vec.insert(it + 2, sec_vec.begin(), sec_vec.end());
		for (ft::vector<int>::iterator tt = vec.begin(); tt != vec.end(); tt++)
			std::cout << *tt << " ";
		std::cout << std::endl;
	}
	// operator=
	std::cout << std::endl << "operator=: " << std::endl << std::endl;
	{
		ft::vector<int> first (5, 21);
		ft::vector<int> second (3, 45);

		std::cout << "first contains: " << std::endl;
		for (ft::vector<int>::iterator tt = first.begin(); tt != first.end(); tt++)
			std::cout << *tt << " ";
		std::cout << std::endl;

		std::cout << "second contains: " << std::endl;
		for (ft::vector<int>::iterator tt = second.begin(); tt != second.end(); tt++)
			std::cout << *tt << " ";
		std::cout << std::endl;

		second = first;
		first = ft::vector<int> ();

		std::cout << "first contains: " << std::endl;
		for (ft::vector<int>::iterator tt = first.begin(); tt != first.end(); tt++)
			std::cout << *tt << " ";
		std::cout << std::endl;

		std::cout << "second contains: " << std::endl;
		for (ft::vector<int>::iterator tt = second.begin(); tt != second.end(); tt++)
			std::cout << *tt << " ";
		std::cout << std::endl;
	}
	// operator[]
	std::cout << std::endl << "operator[]: " << std::endl << std::endl;
	{
		ft::vector<int> vec(10);
		ft::vector<int>::size_type sz = vec.size();

		for (int i = 0;i < 10; i++)
			vec[i] = (i + 1) * 42;
		for (ft::vector<int>::iterator tt = vec.begin(); tt != vec.end(); tt++)
			std::cout << *tt << " ";
		std::cout << std::endl;

		// reverse using operator[]
		for (size_t i = 0; i < sz / 2; i++)
		{
			int tmp = vec[sz - 1 - i];
			vec[sz - 1 - i] = vec[i];
			vec[i] = tmp;
		}
		for (ft::vector<int>::iterator tt = vec.begin(); tt != vec.end(); tt++)
			std::cout << *tt << " ";
		std::cout << std::endl;
	}
	// pop_back & push_back
	std::cout << std::endl << "pop_back & push_back: " << std::endl << std::endl;
	{
		ft::vector<int> vec;
		int sum = 0;

		vec.push_back(13);
		vec.push_back(42);
		vec.push_back(37);
		vec.push_back(21);

		while (!vec.empty())
		{
			sum += vec.back();
			vec.pop_back();
		}
		std::cout << "Sum of the vector is: " << sum << std::endl;
	}
	// rbegin & rend
	std::cout << std::endl << "rbegin & rend: " << std::endl << std::endl;
	{
		ft::vector<int> vec(5);
		int i = 0;

		ft::vector<int>::reverse_iterator rit = vec.rbegin();
		for (; rit != vec.rend(); rit++)
			*rit = ++i;
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		i = 0;
		rit = vec.rend();
		rit--;
		for (; rit != vec.rbegin(); rit--)
			*rit = ++i;
		*rit = 5;
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	// reserve
	std::cout << std::endl << "reserve: " << std::endl << std::endl;
	{
		ft::vector<int>::size_type sz;
		ft::vector<int> vec;

		sz = vec.capacity();
		for (int i = 0; i < 100; i++)
		{
			vec.push_back((i + 1) * 42);
			if (sz != vec.capacity())
			{
				std::cout << "Capacity changed from: " << sz << " to: " << vec.capacity() << std::endl;
				sz = vec.capacity();
			}
		}

		ft::vector<int> sec;
		sz = sec.capacity();
		std::cout << "Using reserve: " << std::endl;
		sec.reserve(100);
		for (int i = 0; i < 100; i++)
		{
			sec.push_back((i + 1) * 42);
			if (sz != sec.capacity())
			{
				std::cout << "Capacity changed from: " << sz << " to: " << sec.capacity() << std::endl;
				sz = sec.capacity();
			}
		}
	}
	// resize
	std::cout << std::endl << "resize: " << std::endl << std::endl;
	{
		ft::vector<int> vec;

		for (int i = 0; i < 10; i++)
			vec.push_back((i + 1) * 42);
		vec.resize(5);
		vec.resize(8, 300);
		vec.resize(12);
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	// swap
	std::cout << std::endl << "swap: " << std::endl << std::endl;
	{
		ft::vector<int> vec(5, 100);
		ft::vector<int> sec(7, 400);
		std::cout << "Before Swap: " << std::endl;
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		for (ft::vector<int>::iterator it = sec.begin(); it != sec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "After Swap: " << std::endl;
		vec.swap(sec);
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		for (ft::vector<int>::iterator it = sec.begin(); it != sec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		try {
			ft::vector<int> vec(5, 1);
			std::cout << vec.capacity() << std::endl;
			vec.push_back(14);
			std::cout << vec.capacity() << std::endl;
			ft::vector<int> vv(5, 1);
			ft::vector<int>::iterator it = vv.begin();
			ft::vector<int>::iterator tt = vv.end();
			ft::vector<int> voc(it, tt);
			std::cout << voc.capacity() << std::endl;

		} catch(std::exception &ex) {
			std::cout << ex.what();
		}
	}
	return (0);
}
