#include <cstdio>
#include <iostream>
#include <string>

int main() {
    std::string weather;
input:
    std::cout << "Choose the weather from suggested (sunny; rainy; cloudy; snowy; windy): ";
    std::cin >> weather;

    if (weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy"){
        goto input;
    }

    if(weather == "rainy" || weather == "snowy"){
        std::cout << "You should better take a jacket \n";
    }else{
        std::cout << "It's warm enough, leave your jacker at home! \n";
    }

    if(weather == "rainy"){
        std::cout << "You can spend your evening watching a film) \n";
    }else if(weather == "sunny"){
        std::cout << "Take your bike and go for a ride \n";
    }else if(weather == "cloudy"){
        std::cout << "Don't forget to meet your friends \n";
    }else if(weather == "snowy"){
        std::cout << "Nice time to play snow balls! \n";
    }else if(weather == "windy"){
        std::cout << "You'd rather stay home and thy to cook some new dishes \n";
    }

    switch (weather[0]) {
        case 's':
            if(weather == "sunny"){
                std::cout << "Wear your snikers or sandales \n";
            }else{
                std::cout << "Wear your warm boots \n";
            }
            break;
        case 'r': 
            std::cout << "Wear your rainy boots \n";
            break;
        case 'c':
            std::cout << "Wear anything you want)) \n";
            break;
        case 'w':
            std::cout << "Wear some sturdy shoes \n";
            break;
    }

    return 0;
}