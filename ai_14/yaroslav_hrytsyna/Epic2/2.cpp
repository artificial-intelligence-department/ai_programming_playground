#include <iostream>
#include <string>

using namespace std;

enum Act {

};

std::string weather;
std::string activity;
const std::string x1 = "sports";
const std::string x2 = "bathing";
const std::string x3 = "formal occasions";

int main()
{
    std::cout << "Weather?" << endl;
    std::cin >> weather;
    std::cout << "Activity?" << endl;
    std::cin >> activity;
    if (weather=="sunny" or weather=="cloudy")
    {
     std::cout << "Куртку не брати" << endl; 
    }
    else if (weather=="snowy" or weather=="rainy" or weather=="windy")
    {
        std::cout << "Куртку треба" << endl;
    }
    else
    {
        std::cout << "Wrong" << endl;
    }
    switch (activity[0])
    {
    case 's':
        std::cout << "Wear sneakers" << endl;
        break;
    case 'b':
        std::cout << "Wear nothing" << endl;
        break;
    case 'f':
        std::cout << "Wear shirt" << endl;
        break;
    
    default:
        std::cout << "wRONG" << endl;
        break;
    }
}
