//
// Created by olehio-p on 10/30/2023.
//
#include <iostream>
#include <string>


constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

int main(int argc, char const *argv[])
{
    std::string weatherCondition;
    std::cout << "Please enter current weather condition: ";
    std::cin >> weatherCondition;
    while(true)
    {
        if(weatherCondition == "sunny" || weatherCondition == "rainy"
           || weatherCondition == "cloudy" || weatherCondition == "snowy"
           || weatherCondition == "windy"){
            break;
        }
        else{
            std::cout << "Please enter the appropriate weather condition: ";
            std::cin >> weatherCondition;
        }
    }

    if(weatherCondition == "snowy" || weatherCondition == "rainy")
    {
        std::cout << "You should put on a jacket" << std::endl;
    }
    else
    {
        std::cout << "You don't need a jacket" << std::endl;
    }

    if(weatherCondition == "sunny")
    {
        std::cout << "Great day for picnic" << std::endl;
    }
    else if(weatherCondition == "rainy")
    {
        std::cout << "Perfect weather to read a book inside the house" << std::endl;
    }
    else if(weatherCondition == "cloudy")
    {
        std::cout << "Shall we visit a museum?" << std::endl;
    }
    else if(weatherCondition == "snowy")
    {
        std::cout << "What about to make a snowman?" << std::endl;
    }
    else
    {
        std::cout << "Launch a kite, if you have one" << std::endl;
    }

    switch (str2int(weatherCondition.c_str())) {
        case str2int("sunny"):
            std::cout << "Put on your favourite trainers" << std::endl;
            break;
        case str2int("rainy"):
            std::cout << "Rainy boots - nice idea!" << std::endl;
            break;
        case str2int("cloudy"):
            std::cout << "You can put on anything you want" << std::endl;
            break;
        case str2int("snowy"):
            std::cout << "Snowy boots will warm your foot" << std::endl;
            break;
        case str2int("windy"):
            std::cout << "Put on something can't be blown off" << std::endl;
            break;
        default:
            std::cout << "Weather condition is invalid";
    }
    return 0;
}
