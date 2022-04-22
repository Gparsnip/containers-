#include "vector.hpp"
#include <vector>
#include <iostream>
#include <time.h>
#include <stack>
#include "stack.hpp"
#include "map.hpp"
#include <map>

#define RED   "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int main()
{
    clock_t             time_ft;
    clock_t             time_std;
    std::cout << GREEN << "*\n*\n*\n*\n**********TEST STACK**********\n*\n*\n*\n*" << RESET << std::endl;
    std::cout << GREEN << "///TEST CONSTRUCTOR///" << RESET << std::endl;
    if (true)
    {
        time_ft = clock();
        ft::stack<std::string> ft_stack;
        time_ft = clock() - time_ft;
        time_std = clock();
        std::stack<std::string> std_stack;
        time_std = clock() - time_std;
        std::cout <<BLUE<< "ft_stack empty: " <<RESET<< ft_stack.empty() << " | ";
        std::cout <<BLUE<< "std_stack empty: " <<RESET<< ft_stack.empty() << std::endl;
        if (time_ft / time_std >= 20)
            std::cout << RED<<"YOUR TIME IS SO BAD" <<RESET<< std::endl;
        else if (time_ft > time_std)
        {
            std::cout <<BLUE<< "ft_stack time: " <<RED<< time_ft <<RESET<< " | ";
            std::cout <<BLUE<< "std_stack time: " <<RESET<< time_std << std::endl;
        }
        else if (time_ft < time_std)
        {
            std::cout <<BLUE<< "ft_stack time: " <<RESET<< time_ft << " | ";
            std::cout <<BLUE<< "std_stack time: " <<RED<< time_std <<RESET<< std::endl;
        }
        else
        {
            std::cout <<BLUE<< "ft_stack time: " <<RESET<< time_ft << " | ";
            std::cout <<BLUE<< "std_stack time: " <<RESET<< time_std << std::endl;
        }
    }
    std::cout << GREEN << "///TEST PUSH POP SIZE TOP///" << RESET << std::endl;
    {
        ft::stack<std::string> ft_stack;
        std::stack<std::string> std_stack;
        time_ft = clock();
        for (int i = 0; i != 5; i++)
            ft_stack.push("top");
        time_ft = clock() - time_ft;
        time_std = clock();
        for (int i = 0; i != 5; i++)
            std_stack.push("top");
        time_std = clock() - time_std;
        std::cout <<BLUE<< "ft_stack top: " <<RESET<< ft_stack.top() <<RESET<< " | ";
        std::cout <<BLUE<< "std_stack top: " <<RESET<< ft_stack.top() << std::endl;
        std::cout <<BLUE<< "ft_stack size: " <<RESET<< ft_stack.size() <<RESET<< " | ";
        std::cout <<BLUE<< "std_stack size: " <<RESET<< ft_stack.size() << std::endl;
        if (time_ft / time_std >= 20)
            std::cout << RED<<"YOUR TIME IS SO BAD" <<RESET<< std::endl;
        else if (time_ft > time_std)
        {
            std::cout <<BLUE<< "ft_stack time: " <<RED<< time_ft <<RESET<< " | ";
            std::cout <<BLUE<< "std_stack time: " <<RESET<< time_std << std::endl;
        }
        else if (time_ft < time_std)
        {
            std::cout <<BLUE<< "ft_stack time: " <<RESET<< time_ft << " | ";
            std::cout <<BLUE<< "std_stack time: " <<RED<< time_std <<RESET<< std::endl;
        }
        else
        {
            std::cout <<BLUE<< "ft_stack time: " <<RESET<< time_ft << " | ";
            std::cout <<BLUE<< "std_stack time: " <<RESET<< time_std << std::endl;
        }
        time_ft = clock();
        ft_stack.pop();
        time_ft = clock() - time_ft;
        time_std = clock();
        std_stack.pop();
        time_std = clock() - time_std;
        std::cout <<BLUE<< "ft_stack top: " <<RESET<< ft_stack.top() <<RESET<< " | ";
        std::cout <<BLUE<< "std_stack top: " <<RESET<< ft_stack.top() << std::endl;
        std::cout <<BLUE<< "ft_stack size: " <<RESET<< ft_stack.size() <<RESET<< " | ";
        std::cout <<BLUE<< "std_stack size: " <<RESET<< ft_stack.size() << std::endl;
        if (time_ft / time_std >= 20)
            std::cout << RED<<"YOUR TIME IS SO BAD" <<RESET<< std::endl;
        else if (time_ft > time_std)
        {
            std::cout <<BLUE<< "ft_stack time: " <<RED<< time_ft <<RESET<< " | ";
            std::cout <<BLUE<< "std_stack time: " <<RESET<< time_std << std::endl;
        }
        else if (time_ft < time_std)
        {
            std::cout <<BLUE<< "ft_stack time: " <<RESET<< time_ft << " | ";
            std::cout <<BLUE<< "std_stack time: " <<RED<< time_std <<RESET<< std::endl;
        }
        else
        {
            std::cout <<BLUE<< "ft_stack time: " <<RESET<< time_ft << " | ";
            std::cout <<BLUE<< "std_stack time: " <<RESET<< time_std << std::endl;
        }
    }
    std::cout << GREEN << "///TEST OPERATOR///" << RESET << std::endl;
    if (true)
    {
        ft::stack<std::string> ft_stack1;
        std::stack<std::string> std_stack1;
        ft::stack<std::string> ft_stack2;
        std::stack<std::string> std_stack2;
        for (int i = 0; i != 5; i++)
            ft_stack1.push("top");
        for (int i = 0; i != 5; i++)
            std_stack1.push("top");
        for (int i = 0; i != 4; i++)
            ft_stack1.push("lot");
        for (int i = 0; i != 4; i++)
            std_stack1.push("lot");
        std::cout <<BLUE<< "ft_stack ==: " <<RESET<< (ft_stack1 == ft_stack2) << " | ";
        std::cout <<BLUE<< "std_stack ==: " <<RESET<< (std_stack1 == std_stack2) << std::endl;
        std::cout <<BLUE<< "ft_stack !=: " <<RESET<< (ft_stack1 != ft_stack2) << " | ";
        std::cout <<BLUE<< "std_stack !=: " <<RESET<< (std_stack1 != std_stack2) << std::endl;
        std::cout <<BLUE<< "ft_stack > " <<RESET<< (ft_stack1 > ft_stack2) << " | ";
        std::cout <<BLUE<< "std_stack >: " <<RESET<< (std_stack1 > std_stack2) << std::endl;
        std::cout <<BLUE<< "ft_stack >: " <<RESET<< (ft_stack2 > ft_stack1) << " | ";
        std::cout <<BLUE<< "std_stack >: " <<RESET<< (std_stack2 > std_stack1) << std::endl;
        std::cout <<BLUE<< "ft_stack < " <<RESET<< (ft_stack1 < ft_stack2) << " | ";
        std::cout <<BLUE<< "std_stack <: " <<RESET<< (std_stack1 < std_stack2) << std::endl;
        std::cout <<BLUE<< "ft_stack <: "<<RESET << (ft_stack2 < ft_stack1) << " | ";
        std::cout <<BLUE<< "std_stack <: " <<RESET<< (std_stack2 < std_stack1) << std::endl;
        std::cout <<BLUE<< "ft_stack >= " <<RESET<< (ft_stack1 >= ft_stack2) << " | ";
        std::cout <<BLUE<< "std_stack >=: " <<RESET<< (std_stack1 >= std_stack2) << std::endl;
        std::cout <<BLUE<< "ft_stack >=: " <<RESET<< (ft_stack2 >= ft_stack1) << " | ";
        std::cout <<BLUE<< "std_stack >=: " <<RESET<< (std_stack2 >= std_stack1) << std::endl;
    }

}