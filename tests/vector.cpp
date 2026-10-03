#include "../include/vector.hpp"
#include "../include/string.hpp"
#include <iostream>




int main()
{
    mstd::vector<mstd::string> vec = {"cucumber", "apple", "pear"};
    std::cout << vec.size() << " " << vec.capacity() << "\n";
    vec.push_back("bean"); 
    vec.push_back("jelly");
    vec.push_back("sausage");
    std::cout << vec.size() << " " << vec.capacity() << "\n"; //pass size increase
    vec.push_back("burger");
    std::cout << vec.size() << " " << vec.capacity() << "\n"; //pass capacity increase 

    mstd::vector<int> zero;
    std::cout << zero.capacity() << " " << zero.size() << "\n";
    zero.push_back(1);
    std::cout << zero.capacity() << " " << zero.size() << "\n";
    zero.push_back(2);
    std::cout << zero.capacity() << " " << zero.size() << "\n";//pass vector with nothing
    std::cout << "\n\n\n";
    zero.insert(zero.begin() + 1, 20);
    std::cout << zero.capacity() << " " << zero.size() << "\n";
    for(int x : zero)
    {
        std::cout << x << " "; //passed insert and capacity increase when insert
    }
    std::cout << "\n\n\n";



    mstd::vector<mstd::string> zeroins;
    zeroins.insert(zeroins.begin(), "First"); //passed insert at no value

    
    for(size_t i = 0; i < 4; i++)
    {
        zeroins.insert(zeroins.begin() + i, "4inserts");//pass
    }

    for(mstd::string x : zeroins)
    {
        std::cout << x << " ";
    }


    std::cout << "\n\n\n\n";







    std::cout << "\n\n\n\n\n";
    return 0;
}

                                                                                                                              