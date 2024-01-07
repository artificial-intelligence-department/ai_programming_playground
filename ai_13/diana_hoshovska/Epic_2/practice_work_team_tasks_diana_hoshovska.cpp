#include <iostream>
#include <string>

int main()
{
    std::string weather;

    std::cout << "Enter the weather today (sunny/rainy/cloudy/snowy/windy): ";
    std::cin >> weather;

    std::cout << "Today's weather: " << weather;
    if(weather == "sunny" || weather == "cloudy" || weather == "windy"){
        std::cout << "\nYou don't have to take a coat.";
    }
    else if (weather == "rainy" || weather == "snowy"){
        std::cout << "\nYou should take a coat.";
    }
    else{
        std::cout << "\nNot a weather or try to change the language";
    }

    if(weather == "sunny"){
        std::cout << "\nIt's a great time for a stroll! Take your friends and go for a walk with them (or play football, volleyball etc).";
    }
    else if(weather == "snowy"){
        std::cout << "\nWhat about going on skiing?";
    }
    else if(weather == "rainy"){
        std::cout << "\nIt's an ideal weather to tidy up at home :)";
    }
    else if(weather == "cloudy"){
        std::cout << "\nMaybe you should try to film a video.";
    }
    else if(weather == "windy"){
        std::cout << "\nTry out some new things! Have you already tried hand gliding?";
    }

    switch (char weather_char = weather [1]) {
        case 'u':
            std::cout << "\nTake your best shoes!";
            break;
        case 'a':
            std::cout << "\nShoes for rain would be the best idea!";
            break;
        case 'n':
            std::cout << "\nWinter shoes will keep your legs warm!";
            break;
        case 'i':
            std::cout << "\nTake something endurable.";
            break;
        case 'l':
            std::cout << "\nToday any shoes can be used.";
            break;
        default:
            std::cout << "\nNot a weather";
            break;
    }

    return 0;
}