#include "../include/array/array.hpp"
#include <iostream>
#include "../include/string/string.hpp"


//add const tests

int array()
{
    mstd::array<int, 7> arr = {3, 2, 5, 1, 2, 7, 6};


    for(auto it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";//3 2 5 1 2 7 6
    }

//    arr.at(67); //Out of range

    arr.at(6) = 10;
    std::cout << "\n\n";
    for(auto it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";//3 2 5 1 2 7 10
    }

//    std::cout << arr[15]; //UB
    std::cout << "\n\n" << arr[4] << " "; //2
    arr[4] = 14;
    std::cout << arr[4]; //14

    mstd::array<mstd::string, 0> pip;
    std::cout << "\n\n" << pip.empty() << " " << arr.empty(); //true(1)  false(0)

    return 0;
}