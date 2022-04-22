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

void print_map_int(ft::map<int,int>::iterator ft_it, std::map<int,int>::iterator std_it, ft::map<int,int> ft_map, std::map<int,int>  std_map, clock_t time_ft, clock_t time_std)
{
    ft_it = ft_map.begin();
    std_it = std_map.begin();
    while (true)
    {
        if (ft_it == ft_map.end() && std_it == std_map.end())
            break ;
        if (ft_it != ft_map.end())
        {
            if (ft_it->first == std_it->first)
                std::cout <<MAGENTA<< "ft_map: " <<RESET<< ft_it->first <<" -> "<< ft_it->second << " | ";
            else
                std::cout <<MAGENTA<< "ft_map: " <<RED<< ft_it->first <<" -> "<< ft_it->second <<RESET<< " | ";
            ft_it++;
        }
        else
            std::cout <<MAGENTA<< "ft_map: " <<RED<< "NULL" <<RESET;
        if (std_it != std_map.end())
        {
            std::cout <<MAGENTA<< "std_map: " <<RESET<< std_it->first <<" -> "<< std_it->second << std::endl;
            std_it++;
        }
        else
            std::cout <<MAGENTA<< "std_map: " << RED << "NULL" << RESET << std::endl;
    }
    if (ft_map.size() == std_map.size())
        std::cout <<BLUE<< "ft_map size: " <<RESET<< ft_map.size() << " | ";
    else
        std::cout <<BLUE<< "ft_map size: " <<RED<< ft_map.size() <<RESET<< " | ";
    std::cout <<BLUE<< "std_map size: " <<RESET<< std_map.size() << std::endl;

    if (time_ft / time_std >= 20)
        std::cout << RED<<"YOUR TIME IS SO BAD" <<RESET<< std::endl;
    else if (time_ft > time_std)
    {
        std::cout <<BLUE<< "ft_map time: " <<RED<< time_ft <<RESET<< " | ";
        std::cout <<BLUE<< "std_map time: " <<RESET<< time_std << std::endl;
    }
    else if (time_ft < time_std)
    {
        std::cout <<BLUE<< "ft_map time: " <<RESET<< time_ft << " | ";
        std::cout <<BLUE<< "std_map time: " <<RED<< time_std <<RESET<< std::endl;
    }
    else
    {
        std::cout <<BLUE<< "ft_map time: " <<RESET<< time_ft << " | ";
        std::cout <<BLUE<< "std_map time: " <<RESET<< time_std << std::endl;
    }
}

int main()
{
    std::cout << GREEN << "*\n*\n*\n*\n**********TEST MAP**********\n*\n*\n*\n*" << RESET << std::endl;
    ft::map<int,int> ft_map1;
    std::map<int, int> std_map1;
    ft::map<int,int>::iterator ft_it;
    std::map<int, int>::iterator std_it;
    clock_t             time_ft;
    clock_t             time_std;
    for (int i = 0; i != 10; i += 2)
        ft_map1.insert(ft::pair<int, int>(i, 50 - i));
    for (int i = 0; i != 10; i += 2)
        std_map1.insert(std::pair<int, int>(i, 50 - i));
    std::cout << GREEN << "///TEST CONSTRUCTOR///" << RESET << std::endl;
    if (true)
    {
        time_ft = clock();
        ft::map<int,int> ft_map2;
        time_ft = clock() - time_ft;
        time_std = clock();
        std::map<int,int> std_map2;
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map2, std_map2, time_ft, time_std);
        time_ft = clock();
        ft::map<int,int> ft_map3(ft_map1.begin(), ft_map1.end());
        time_ft = clock() - time_ft;
        time_std = clock();
        std::map<int,int> std_map3(std_map1.begin(), std_map1.end());
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map3, std_map3, time_ft, time_std);
        time_ft = clock();
        ft::map<int,int> ft_map4(ft_map3);
        time_ft = clock() - time_ft;
        time_std = clock();
        std::map<int,int> std_map4(std_map3);
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map4, std_map4, time_ft, time_std);
    }
    std::cout << GREEN << "///TEST INSERT///" << RESET << std::endl;
    if (true)
    {
        ft::map<int,int> ft_map2;
        std::map<int,int> std_map2;
        for (int i = 1; i != 11; i += 2)
            ft_map2.insert(ft::pair<int, int>(i, 50 - i));
        for (int i = 1; i != 11; i += 2)
            std_map2.insert(std::pair<int, int>(i, 50 - i));
        time_ft = clock();
        ft_map1.insert(ft::pair<int, int> (3, 450));
        time_ft = clock() - time_ft;
        time_std = clock();
        std_map1.insert(std::pair<int, int> (3, 450));
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map1, std_map1, time_ft, time_std);
        time_ft = clock();
        ft_map1.insert(ft_map1.end()-- , ft::pair<int, int> (13, 543));
        time_ft = clock() - time_ft;
        time_std = clock();
        std_map1.insert(std_map1.end()-- , std::pair<int, int> (13, 543));
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map1, std_map1, time_ft, time_std);
        time_ft = clock();
        ft_map1.insert(ft_map2.begin(), ft_map2.end());
        time_ft = clock() - time_ft;
        time_std = clock();
        std_map1.insert(std_map2.begin(), std_map2.end());
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map1, std_map1, time_ft, time_std);
    }
    std::cout << GREEN << "///TEST ERASE///" << RESET << std::endl;
    if (true)
    {
        time_ft = clock();
        ft_map1.erase(++(++(++(ft_map1.begin()))));
        time_ft = clock() - time_ft;
        time_std = clock();
        std_map1.erase(++(++(++(std_map1.begin()))));
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map1, std_map1, time_ft, time_std);
        time_ft = clock();
        ft_map1.erase(5);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_map1.erase(5);
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map1, std_map1, time_ft, time_std);
        time_ft = clock();
        ft_map1.erase(++(++(++(ft_map1.begin()))), --ft_map1.end());
        time_ft = clock() - time_ft;
        time_std = clock();
        std_map1.erase(++(++(++(std_map1.begin()))), --std_map1.end());
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map1, std_map1, time_ft, time_std);
    }
    std::cout << GREEN << "///TEST SWAP & CLEAR///" << RESET << std::endl;
    if (true)
    {
        ft::map<int,int> ft_map2;
        std::map<int,int> std_map2;
        for (int i = 1; i != 11; i += 2)
            ft_map2.insert(ft::pair<int, int>(i, 50 - i));
        for (int i = 1; i != 11; i += 2)
            std_map2.insert(std::pair<int, int>(i, 50 - i));
        time_ft = clock();
        ft_map1.swap(ft_map2);
        time_ft = clock() - time_ft;
        time_std = clock();
        std_map1.swap(std_map2);
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map1, std_map1, time_ft, time_std);
        time_ft = clock();
        ft_map2.clear();
        time_ft = clock() - time_ft;
        time_std = clock();
        std_map2.clear();
        time_std = clock() - time_std;
        print_map_int(ft_it, std_it, ft_map2, std_map2, time_ft, time_std);   
    }
    std::cout <<GREEN<< "//TEST OPERATOR///" <<RESET<< std::endl;
    if (true)
    {
        ft::map<int,int> ft_map2;
        std::map<int,int> std_map2;
        for (int i = 1; i != 11; i += 2)
            ft_map2.insert(ft::pair<int, int>(i, 50 - i));
        for (int i = 1; i != 11; i += 2)
            std_map2.insert(std::pair<int, int>(i, 50 - i));
        
        std::cout <<BLUE<< "ft_map []: " <<RESET<< ft_map1[1] << " | ";
        std::cout <<BLUE<< "std_map []: " <<RESET<< std_map1[1] << std::endl;
        std::cout <<BLUE<< "ft_map ==: " <<RESET<< (ft_map1 == ft_map2) << " | ";
        std::cout <<BLUE<< "std_map ==: " <<RESET<< (std_map1 == std_map2) << std::endl;
        std::cout <<BLUE<< "ft_map !=: " <<RESET<< (ft_map1 != ft_map2) << " | ";
        std::cout <<BLUE<< "std_map !=: " <<RESET<< (std_map1 != std_map2) << std::endl;
        std::cout <<BLUE<< "ft_map > " <<RESET<< (ft_map1 > ft_map2) << " | ";
        std::cout <<BLUE<< "std_map >: " <<RESET<< (std_map1 > std_map2) << std::endl;
        std::cout <<BLUE<< "ft_map >: " <<RESET<< (ft_map2 > ft_map1) << " | ";
        std::cout <<BLUE<< "std_map >: " <<RESET<< (std_map2 > std_map1) << std::endl;
        std::cout <<BLUE<< "ft_map < " <<RESET<< (ft_map1 < ft_map2) << " | ";
        std::cout <<BLUE<< "std_map <: " <<RESET<< (std_map1 < std_map2) << std::endl;
        std::cout <<BLUE<< "ft_map <: "<<RESET << (ft_map2 < ft_map1) << " | ";
        std::cout <<BLUE<< "std_map <: " <<RESET<< (std_map2 < std_map1) << std::endl;
        std::cout <<BLUE<< "ft_map >= " <<RESET<< (ft_map1 >= ft_map2) << " | ";
        std::cout <<BLUE<< "std_map >=: " <<RESET<< (std_map1 >= std_map2) << std::endl;
        std::cout <<BLUE<< "ft_map >=: " <<RESET<< (ft_map2 >= ft_map1) << " | ";
        std::cout <<BLUE<< "std_map >=: " <<RESET<< (std_map2 >= std_map1) << std::endl;
    }
}