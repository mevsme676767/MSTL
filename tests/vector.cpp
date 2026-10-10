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

    std::cout << "\n\n\n\n" << zeroins.capacity() << "\n\n";
    
    zeroins.reserve(20);
    std::cout << zeroins.capacity() << " " << zeroins.size();

    for(size_t i = 0; i < 15; ++i)
    {
        zeroins.push_back("h");
    }
    std::cout << "\n\n" << zeroins.capacity() << " " << zeroins.size();
    zeroins.push_back("L");

    std::cout << "\n\n" << zeroins.capacity() << " " << zeroins.size();
    



    std::cout << "\n\n\n\n";


    for(mstd::string x : zeroins)
    {
        std::cout << x << " ";
    }

    zeroins.resize(10);
    std::cout << "\n\n";

    for(mstd::string x : zeroins)
    {
        std::cout << x << " ";
    }
    std::cout << "\n" << zeroins.size() << "\n\n";


    zeroins.resize(10, "h");

    
    for(mstd::string x : zeroins)
    {
        std::cout << x << " ";
    }
    std::cout << "\n" << zeroins.size();


    mstd::vector<int> on = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    on.resize(20, 0);
    std::cout << "\n\n\n\n" << on.size() << "\n";
    on.resize(30, 0);
    std::cout << "\n" << on.size() << "\n";


    std::cout << "\n\n";
    for(int x : on)
    {
        std::cout << x << " ";
    }

    std::cout << "\n\n";
    mstd::vector<int> count = {1, 2, 3, 4, 7, 8, 5, 6};
    count.erase(count.begin() + 4);
    count.erase(count.begin() + 4);

    for(int x : count)
    {
        std::cout << x << " ";
    }

    std::cout << "\n\n";
    mstd::vector<int> count1 = {1, 2, 3, 4, 7, 8, 5, 6};
    count1.erase(count1.begin() + 4);
    count1.erase(count1.begin() + 4);

    for(int x : count1)
    {
        std::cout << x << " ";
    }

    std::cout << "\n\n";
    count1.erase(count1.begin() + 5);
    count1.erase(count1.begin());
    for(int x : count1)
    {
        std::cout << x << " ";
    }


    std::cout << "\n\n\n\n\n";
    return 0;
}
                                                                                                                              