#include "vector.hpp"
#include <vector>
#include <iostream>
#include <time.h>

#define RED   "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

void print_vector_int(ft::vector<int>::iterator ft_it, std::vector<int>::iterator std_it, ft::vector<int> ft_vector, std::vector<int>  std_vector, clock_t time_ft, clock_t time_std)
{
    ft_it = ft_vector.begin();
    std_it = std_vector.begin();
    while (true)
    {
        if (ft_it == ft_vector.end() && std_it == std_vector.end())
            break ;
        if (ft_it != ft_vector.end())
        {
            if ((*ft_it) == (*std_it))
                std::cout <<MAGENTA<< "ft_vector: " <<RESET<< (*ft_it) << " | ";
            else
                std::cout <<MAGENTA<< "ft_vector: " <<RED<< (*ft_it) <<RESET<< " | ";
            ft_it++;
        }
        else
            std::cout <<MAGENTA<< "ft_vector: " <<RED<< "NULL" <<RESET;
        if (std_it != std_vector.end())
        {
            std::cout <<MAGENTA<< "std_vector: " <<RESET<< (*std_it) << std::endl;
            std_it++;
        }
        else
            std::cout <<MAGENTA<< "std_vector: " << RED << "NULL" << RESET << std::endl;
    }
    if (ft_vector.size() == std_vector.size())
        std::cout <<BLUE<< "ft_vector size: " <<RESET<< ft_vector.size() << " | ";
    else
        std::cout <<BLUE<< "ft_vector size: " <<RED<< ft_vector.size() <<RESET<< " | ";
    std::cout <<BLUE<< "std_vector size: " <<RESET<< std_vector.size() << std::endl;
    if (ft_vector.capacity() == std_vector.capacity())
        std::cout <<BLUE<< "ft_vector capacity: " <<RESET<< ft_vector.capacity() << " | ";
    else
        std::cout <<BLUE<< "ft_vector capacity: " <<RED<< ft_vector.capacity() <<RESET<< " | ";
    std::cout <<BLUE<< "std_vector capacity: " <<RESET<< std_vector.capacity() << std::endl;
    
    if (time_ft / time_std >= 20)
        std::cout << RED<<"YOUR TIME IS SO BAD" <<RESET<< std::endl;
    else if (time_ft > time_std)
    {
        std::cout <<BLUE<< "ft_vector time: " <<RED<< time_ft <<RESET<< " | ";
        std::cout <<BLUE<< "std_vector time: " <<RESET<< time_std << std::endl;
    }
    else if (time_ft < time_std)
    {
        std::cout <<BLUE<< "ft_vector time: " <<RESET<< time_ft << " | ";
        std::cout <<BLUE<< "std_vector time: " <<RED<< time_std <<RESET<< std::endl;
    }
    else
    {
        std::cout <<BLUE<< "ft_vector time: " <<RESET<< time_ft << " | ";
        std::cout <<BLUE<< "std_vector time: " <<RESET<< time_std << std::endl;
    }
}

int main()
{
    clock_t             time_ft;
    clock_t             time_std;
   

    ft::vector<int>                 ft_vector1;
    std::vector<int>                std_vector1;
    ft::vector<int>::iterator       ft_it;
    std::vector<int>::iterator      std_it;
    
    std::cout << GREEN << "*\n*\n*\n*\n**********TEST VECTOR**********\n*\n*\n*\n*" << RESET << std::endl;
    for (int i = 0; i != 5; i++)
        ft_vector1.push_back(i);
    for (int i = 0; i != 5; i++)
        std_vector1.push_back(i);
    std::cout << GREEN << "///TEST CONSTRUCTOR///" << RESET << std::endl;
    if (true)
    {
        clock_t             time_ft2;
        clock_t             time_std2;
        clock_t             time_ft3;
        clock_t             time_std3;
        clock_t             time_ft4;
        clock_t             time_std4;
        time_ft2 = clock();
        ft::vector<int>     ft_vector2(5, 5);
        time_ft2 = clock() - time_ft2;
        time_ft3 = clock();
        ft::vector<int>     ft_vector3(ft_vector1.begin(), ft_vector1.end());
        time_ft3 = clock() - time_ft3;
        time_ft4 = clock();
        ft::vector<int>     ft_vector4(ft_vector1);
        time_ft4 = clock() - time_ft4;
        time_std2 = clock();
        std::vector<int>     std_vector2(5, 5);
        time_std2 = clock() - time_std2;
        time_std3 = clock();
        std::vector<int>     std_vector3(std_vector1.begin(), std_vector1.end());
        time_std3 = clock() - time_std3;
        time_std4 = clock();
        std::vector<int>     std_vector4(std_vector1);
        time_std4 = clock() - time_std4;
        print_vector_int(ft_it, std_it, ft_vector2, std_vector2, time_ft2, time_std2);
        print_vector_int(ft_it, std_it, ft_vector3, std_vector3, time_ft3, time_std3);
        print_vector_int(ft_it, std_it, ft_vector4, std_vector4, time_ft4, time_std4);
    }
    std::cout << GREEN << "///TEST RESIZE///" << RESET << std::endl;
    if (true)
    {
        time_ft = clock();
        ft_vector1.resize(8, 5);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.resize(8, 5);
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
        time_ft = clock();
        ft_vector1.resize(3);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.resize(3);
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
    }
    for (int i = 0; i != 5; i++)
        ft_vector1.push_back(i);
    for (int i = 0; i != 5; i++)
        std_vector1.push_back(i);
    std::cout << GREEN <<"///TEST ERASE///" << RESET << std::endl;
    if (true)
    {
        time_ft = clock();
        ft_vector1.erase(ft_vector1.begin() + 1);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.erase(std_vector1.begin() + 1);
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
        time_ft = clock();
        ft_vector1.erase(ft_vector1.begin() + 1, ft_vector1.end() - 3);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.erase(std_vector1.begin() + 1, std_vector1.end() - 3);
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
    }
    std::cout <<GREEN<< "///TEST INSERT///" <<RESET<< std::endl;
    if (true)
    {
        ft::vector<int>     ft_vector2(5, 5);
        std::vector<int>     std_vector2(5, 5);
        time_ft = clock();
        ft_vector1.insert(ft_vector1.begin() + 1, 500);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.insert(std_vector1.begin() + 1, 500);
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
        time_ft = clock();
        ft_vector1.insert(ft_vector1.begin() + 3, 2, 400);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.insert(std_vector1.begin() + 3, 2,  400);
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
        time_ft = clock();
        ft_vector1.insert(ft_vector1.begin(), 2, 300);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.insert(std_vector1.begin(), 2,  300);
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
        time_ft = clock();
        ft_vector1.insert(ft_vector1.end() - 2 ,ft_vector2.begin(), ft_vector2.end() - 2);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.insert(std_vector1.end() - 2 ,std_vector2.begin(), std_vector2.end() - 2);
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
    }
    std::cout <<GREEN<< "///TEST CLEAR///" <<RESET<< std::endl;
    if (true)
    {
        time_ft = clock();
        ft_vector1.clear();
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.clear();
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
        std::cout << "ft_vector empty: " << ft_vector1.empty() << " | ";
        std::cout << "std_vector empty: " << std_vector1.empty() << std::endl;
    }
    std::cout <<GREEN<< "//TEST ASSIGN///" <<RESET<< std::endl;
    if (true)
    {
        ft::vector<int>     ft_vector2(5, 5);
        std::vector<int>     std_vector2(5, 5);
        time_ft = clock();
        ft_vector1.assign(ft_vector2.begin() + 1, ft_vector2.end());
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.assign(std_vector2.begin() + 1, std_vector2.end());
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
        time_ft = clock();
        ft_vector1.assign(4, 3);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.assign(4, 3);
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
    }
    std::cout <<GREEN<< "//TEST POP_BACK///" <<RESET<< std::endl;
    if(true)
    {
        time_ft = clock();
        ft_vector1.pop_back();
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.pop_back();
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
    }
    std::cout <<GREEN<< "//TEST SWAP///" <<RESET<< std::endl;
    if (true)
    {
        ft::vector<int>     ft_vector2(5, 100);
        std::vector<int>     std_vector2(5, 100);
        time_ft = clock();
        ft_vector1.swap(ft_vector2);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_vector1.swap(std_vector2);
        time_std = clock() - time_std;
        print_vector_int(ft_it, std_it, ft_vector1, std_vector1, time_ft, time_std);
    }
    std::cout <<GREEN<< "//TEST OPERATOR///" <<RESET<< std::endl;
    if (true)
    {
        ft::vector<int>     ft_vector2(5, 200);
        std::vector<int>     std_vector2(5, 200);
        
        std::cout <<BLUE<< "ft_vector []: " <<RESET<< ft_vector1[1] << " | ";
        std::cout <<BLUE<< "std_vector []: " <<RESET<< std_vector1[1] << std::endl;
        std::cout <<BLUE<< "ft_vector at: " <<RESET<< ft_vector1.at(1) << " | ";
        std::cout <<BLUE<< "std_vector at: " <<RESET<< std_vector1.at(1) << std::endl;
        std::cout <<BLUE<< "ft_vector front: " <<RESET<< ft_vector1.front() << " | ";
        std::cout <<BLUE<< "std_vector front: " <<RESET<< std_vector1.front() << std::endl;
        std::cout <<BLUE<< "ft_vector back: " <<RESET<< ft_vector1.back() << " | ";
        std::cout <<BLUE<< "std_vector back: " <<RESET<< std_vector1.back() << std::endl;
        std::cout <<BLUE<< "ft_vector ==: " <<RESET<< (ft_vector1 == ft_vector2) << " | ";
        std::cout <<BLUE<< "std_vector ==: " <<RESET<< (std_vector1 == std_vector2) << std::endl;
        std::cout <<BLUE<< "ft_vector !=: " <<RESET<< (ft_vector1 != ft_vector2) << " | ";
        std::cout <<BLUE<< "std_vector !=: " <<RESET<< (std_vector1 != std_vector2) << std::endl;
        std::cout <<BLUE<< "ft_vector > " <<RESET<< (ft_vector1 > ft_vector2) << " | ";
        std::cout <<BLUE<< "std_vector >: " <<RESET<< (std_vector1 > std_vector2) << std::endl;
        std::cout <<BLUE<< "ft_vector >: " <<RESET<< (ft_vector2 > ft_vector1) << " | ";
        std::cout <<BLUE<< "std_vector >: " <<RESET<< (std_vector2 > std_vector1) << std::endl;
        std::cout <<BLUE<< "ft_vector < " <<RESET<< (ft_vector1 < ft_vector2) << " | ";
        std::cout <<BLUE<< "std_vector <: " <<RESET<< (std_vector1 < std_vector2) << std::endl;
        std::cout <<BLUE<< "ft_vector <: "<<RESET << (ft_vector2 < ft_vector1) << " | ";
        std::cout <<BLUE<< "std_vector <: " <<RESET<< (std_vector2 < std_vector1) << std::endl;
        std::cout <<BLUE<< "ft_vector >= " <<RESET<< (ft_vector1 >= ft_vector2) << " | ";
        std::cout <<BLUE<< "std_vector >=: " <<RESET<< (std_vector1 >= std_vector2) << std::endl;
        std::cout <<BLUE<< "ft_vector >=: " <<RESET<< (ft_vector2 >= ft_vector1) << " | ";
        std::cout <<BLUE<< "std_vector >=: " <<RESET<< (std_vector2 >= std_vector1) << std::endl;

    }
}