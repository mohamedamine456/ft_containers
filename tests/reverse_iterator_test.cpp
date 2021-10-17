#include <iostream>
#include "../iterator.hpp"
#include <vector>

int main () {
  {
    std::vector<int> myvector;
    for (int i=0; i<10; i++)
      myvector.push_back(i);

    typedef std::vector<int>::iterator iter_type;
    iter_type from (myvector.begin());
    iter_type until (myvector.end());
    ft::reverse_iterator<iter_type> rev_until (from);
    ft::reverse_iterator<iter_type> rev_from (until);

    std::cout << "myvector:";
    while (rev_from != rev_until)
      std::cout << ' ' << *rev_from++;
    std::cout << '\n';
  }
  {
    typedef std::vector<int>::reverse_iterator iter_type;

    std::vector<int> myvector;
    for (int i=0; i < 10; i++)
      myvector.push_back(i);

    ft::reverse_iterator<iter_type> rev_iterator = myvector.rend() - 3;

    std::cout << "ft::myvector.rend() - 3 points to: " << *rev_iterator << '\n';
  }
  return 0;
}