#include "../include/string/string.hpp"
#include "../include/utility/utility.hpp"

//add const tests
int string()
{
//uncomment at line 108
/*
    std::cout << "Constructor test\n\n"; 
    mstd::string greeting = "Hi";
    mstd::string name = "Michael";

    std::cout << greeting << " " << name; // Hi Michael



    std::cout << "\n\nCopy constructor and Move constructor test:\n\n";

    mstd::string Tom = "Cat Tom";

    mstd::string secondTom = Tom;

    std::cout << secondTom; //Cat Tom

    mstd::string thirdTom = mstd::move(secondTom);

    std::cout << "\n\n" << thirdTom; //Cat Tom

    


    std::cout << "\n\nCopy assigment and Move assigment test:\n\n";



    mstd::string john = "John";

    mstd::string secondJohn = "Bill";
    std::cout << "\n\n" << secondJohn; //Bill
    secondJohn = john;

    std::cout << "\n\n" << secondJohn; //John

    mstd::string futureJohn;

    futureJohn = mstd::move(secondJohn);

    


    std::cout << "\n\nBasic element access\n\n";

    mstd::string string = "Hello World";
//    index:        H e l l o   W o r l d   
//                  0 1 2 3 4 5 6 7 8 9 10

    std::cout << string.at(6) << string.at(7) << string.at(8); //Wor
//    std::cout << string.at(11); //Out of range

    string.at(1) = 'E';
    std::cout << "\n\n" << string; //HEllo World
    
    string = "Hello world";


    std::cout << "\n\n\n" << string[0] << string[1] << string[2] << string[3] << string[4]; //Hello

    
//    std::cout << "\n\n" << string[11]; //Undefined Behavior


    std::cout << "\nFirst letter: " << string.front() << " Last letter: " << string.back(); // First letter: H Last letter: d(because H = 0, d = 10)

    

    std::cout << "\n\nIterators\n\n";

    mstd::string example("Begi"); //Begi
    *example.begin() = 'b';

    std::cout << example; //begi

    *example.end() = 'n';

//    std::cout << "\n\n" << example; //Undefined Behavior


    std::cout << "\n\nCapacity\n\n";
    
    mstd::string ex = "";
    std::cout << ex.empty(); //true (1)


    ex = "Something";
    std::cout << "\n\n" << ex.empty(); //false (0)

    std::cout << "\n\n" << ex.size(); //or ex.length(). output: 9

    std::cout << "\n\n" << ex.capacity(); // elements that you are able to insert before reallocation



    std::cout << "\n\n\n"; //for better output at the end

*/


//it is recommended to comment everything below

/*

    mstd::string stringToBeCleared = "Clear required";
    std::cout << stringToBeCleared << "\n\n";  //Clear required
    stringToBeCleared.clear();
    std::cout << stringToBeCleared << "\n\n"; // no output

    stringToBeCleared.push_back('H');
    stringToBeCleared.push_back('e');
    stringToBeCleared.push_back('l');
    stringToBeCleared.push_back('l');
    stringToBeCleared.push_back('o');
    std::cout << stringToBeCleared; //Hello
    
    while(!stringToBeCleared.empty())
    {
        stringToBeCleared.pop_back();    
    }

    std::cout << "\n\n" << stringToBeCleared; //No output

    

    mstd::string hiWorld = "HelloWorld";

//    index:        H e l l o W o r l d   
//                  0 1 2 3 4 5 6 7 8 9
    std::cout << hiWorld; //HelloWorld
    hiWorld.insert(5, ' ');
    std::cout << "\n\n" << hiWorld;//Hello World (added spacebar)

    hiWorld.erase(5);
    hiWorld.erase(9);//
    std::cout << "\n\n" << hiWorld;//HelloWorl (removed spacebar(index 5) and d(index 9))

    hiWorld.clear(); //cleared

    
    hiWorld.append({'B', 'y', 'e', ' ', 'w', 'o', 'r', 'l', 'd'});

    std::cout << "\n\n" << hiWorld; //Bye world




//   hiWorld = "Bye world"

    std::cout << "\n\n" << hiWorld.substr(hiWorld.find("world"), 5); // world

    std::cout << "\n\n" << hiWorld.substr(hiWorld.find("By"), 2); // By



    std::cout << "\n\n" << hiWorld.substr(hiWorld.find("Hello"), 5); //no output, not found


//also try starts_with, ends_with, contains


    std::cout << "\n\n\n";
*/
    return 0;
}
