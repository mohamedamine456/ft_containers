#include <iostream>
#include "../vector.hpp"
#include "../stack.hpp"

int main()
{
    // empty & push & pop & top & size
    std::cout << "empty & push & pop & top: " << std::endl << std::endl;
    {
        ft::stack<int , ft::vector<int> > stk;

        int sum = 0;
        for (int i = 0; i < 14; i++)
            stk.push((i + 1) * 37);
        ft::stack<int, ft::vector<int> >::size_type sz = stk.size();
        std::cout << "size of the stack is: " << sz << std::endl;
        while (!stk.empty())
        {
            sum += stk.top();
            std::cout << stk.top() << " ";
            stk.pop();
        }
        std::cout << std::endl;
        std::cout << "stack is empty: " << (stk.empty() ? "Yes" : "No") << std::endl;
        std::cout << "sum of the stack: " << sum << std::endl;
    }
    {
        ft::stack<int , ft::vector<int> > stk;
        for (int i = 0; i < 14; i++)
            stk.push((i + 1) * 37);
        ft::stack<int , ft::vector<int> > sec = stk;

        std::cout << (stk == sec ? "Equal" : "Different") << std::endl;
    }
}