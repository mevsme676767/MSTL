#include "../include/utility/utility.hpp"
#include "../include/vector/vector.hpp"
#include <iostream>

int vector()
{
//uncomment at line 112
/*
    std::cout << "Constructor test:\n\n"; 
    
    mstd::vector<int> vec = {1, 3 ,2 ,5};
    for(int x : vec)
    {
        std::cout << x << " "; // 1 3 2 5
    }

    std::cout << "\n\n";



    std::cout << "\n\nCopy constructor and Move constructor test:\n\n";
    

    mstd::vector<int> vec2 = {1, 2, 3, 4};
    
    mstd::vector<int> newvec2 = vec2;

    for(int x : newvec2)
    {
        std::cout << x; //1234
    }

    std::cout << "\n\n\n";

    mstd::vector<int> newvec3 = mstd::move(newvec2);

    for(int x : newvec2)
    {
        std::cout << x;//no output since moved
    }
    std::cout << "\n\n";


    for(int x : newvec3)
    {
        std::cout << x;//1234
    }

    std::cout << "\n\nCopy assigment and Move assigment test:\n\n";
    
    mstd::vector<int> he = {4, 3, 2 , 1};

    mstd::vector<int> hes = {3, 2, 4, 4};
    hes = he;

    for(int x : hes)
    {
        std::cout << x; //4321
    }

    std::cout << "\n\n";
    

    mstd::vector<int> hes2 = {22, 11, 98};

    hes2 = mstd::move(he);
    
    for(int x : he)
    {
        std::cout << x; //no output
    }

    for(int x : hes2)
    {
        std::cout << x; //4321
    }
    
    

    std::cout << "\n\nElement access and iterators\n\n";

    mstd::vector v = {8, 6, 5, 2, 3};

    std::cout << v[2] << "\n\n"; //5
//    std::cout << "\n\n" << v.at(5); //out of range


    for(int x : v)
    {
        std::cout << x;//86523
    }
    v[1] = 12;
    v.at(4) = 2;
    std::cout << "\n\n";
    for(int x : v)
    {
        std::cout << x;//812522
    }

    std::cout << "\n\n";

    for(auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it;
    }
    //works

    std::cout << "\n\n";
    std::cout << v.front() << " " << v.back();//8 2(because v[0] = 8, v[4] = 2) 

*/

//It is recommended to comment everything below
    std::cout << "\n\nModifiers test\n\n";

    mstd::vector<int> ve = {2, 3, 1, 5, 4};
    ve.clear();

    for(int x : ve)
    {
        std::cout << x; // no output
    }

    ve.push_back(10);
    ve.push_back(12);
    ve.push_back(10);
    ve.push_back(10);
    ve.push_back(1022);
    ve.push_back(110);
    ve.push_back(140);
    ve.push_back(33);

    for(int x : ve)
    {
        std::cout << x << " ";
    }

    std::cout << "\n\n";
    ve.pop_back();
    ve.pop_back();
    ve.pop_back();

    for(int x : ve)
    {
        std::cout << x << " ";//last 3 elements should not appear
    }

    std::cout << "\n\n\n\n";

    ve.insert(ve.begin() + 3, 15);

    for(int x : ve)
    {
        std::cout << x << " ";
    }

    ve.push_back(10);
    ve.push_back(10);
    ve.push_back(10);
    ve.push_back(10);

    std::cout << "\n\n" << ve.size() << " " << ve.capacity() << "\n\n";


    ve.insert(ve.begin() + 5, 555);

    for(int x : ve)
    {
        std::cout << x << " ";
    }

    
    std::cout << "\n\n";
}