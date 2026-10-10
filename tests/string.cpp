
#include "../include/string.hpp"
#include <iostream>



int main()
{
    mstd::string str = "Hello world";
    std::cout << str;
    str.clear();
    std::cout << str;
    str.append({'e', 'l', 'l','a', 'o', 'w','o','r','l'});
    std::cout << "\n\n" << str;
    str.insert(5, ' ');
    str.insert(10, 'd');
    std::cout << "\n" << str.capacity() << " " << str.size();
    str.insert(0, 'H');
    str.erase(4);
    str.push_back('l');
    str.pop_back();
    str.push_back('!');
    std::cout << "\n\n" << str;



    std::cout << "\n\n\n";


    std::cout << str.find(" world") << "\n\n";
    std::cout << str.find(" worldd") << "\n\n";
    std::cout << str.find("Hello") << "\n\n";
    std::cout << str.find(" Hello") << "\n\n";
    std::cout << "\n\n\n\n" << str.contains("Hel lo") << "\n\n";

    std::cout << "\n\n\n\n\n\n" << str.starts_with('H') << str.ends_with('!') << "\n\n";
    std::cout << "\n" << str.starts_with('e') << str.ends_with('d');

    std::cout << "\n\n" << str.substr(str.find("world!"), 6);

    std::cout << "\n\n";
    return 0;
}
                                                                                                                              