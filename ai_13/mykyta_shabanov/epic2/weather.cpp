#include <iostream>
#include <string>


int main() {
    std::string weather;
    std::cout << "What is the weather today? \n";
    std::cin >> weather;


    if (weather == "cloudy" || weather == "rainy" || weather == "windy" || weather == "snowy") {
        std::cout << "\nYou need a coat(";
        if (weather == "snowy") {
            std::cout << " and put on your hat, it's really cold outside.";
        } else if (weather == "rainy") {
            std::cout << " and take an umbrella with you.";
        }
    } else if (weather == "sunny") {
        std::cout << "It's hot outside. You don't need a coat)";
    } else {
        std::cout << "It looks like there is no such option as " << weather << ". You can choose these options: rainy, cloudy, windy, sunny, or snowy. Try again!\n";
        return 0;
    }


    if (weather == "cloudy" || weather == "windy" || weather == "snowy") {
        std::cout << "\nBetter stay at home and watch your favorite TV series!";
        if (weather == "snowy") {
            std::cout << " Or you can play in the snow)";
        } else if (weather == "windy") {
            std::cout << " Or you can fly a kite";
        } else if (weather == "cloudy") {
            std::cout << " Or you can visit a museum";
        }
    } else if (weather == "sunny") {
        std::cout << "\nGo outside and have fun!";
    } else if (weather == "rainy") {
        std::cout << "\nIt's a perfect time to read a book!";
    }


    switch (weather[0]) {
        case 'r':
            std::cout << "\nIf you do go outside, don't forget to put on rubber boots.";
            break;
        case 'c':
        case 'w':
            std::cout << "\nIf you do go outside, don't forget to put on casual shoes.";
            break;
        case 's':
            if (weather == "snowy") {
                std::cout << "\nIf you do go outside, don't forget to put on boots.";
            } else if (weather == "sunny") {
                std::cout << "\nDon't forget to put on flip-flops.";
            }
            break;
    }


    return 0;
}
