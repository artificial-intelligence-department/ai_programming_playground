

#include<iostream>
#include<string>

int main() {

    std::string weather;
    std::cout << "Please enter weather: ";
    std::cin >> weather;

    
    for (int i = 0; i < weather.size(); i++)
    {
        weather[i] = tolower(weather[i]);
    }

    if (weather == "rainy" || weather == "cloudy" || weather == "snowy" || weather == "windy")
        std::cout << "| Put on a jacket!" << std::endl;
    else
        std::cout << "| You don't have to put on a jacket" << std::endl;

    if (weather == "rainy")
        std::cout << "| Watch film or serial" << std::endl;
    else if (weather == "sunny")
        std::cout << "| Go to walk" << std::endl;
    else if (weather == "windy")
        std::cout << "| Sit home" << std::endl;
    else if (weather == "clody")
        std::cout << "| Go to the cinema" << std::endl;
    else if (weather == "snowy")
        std::cout << "| Go to play snowballs" << std::endl;


    switch (weather.at(0)) {
    case 's':
        if (weather.at(1) == 'u')//додаткова перев≥рка на сон€чну погоду
            std::cout << "| You can put on sandels" << std::endl;
        else
            std::cout << "| You can put on boots" << std::endl;
        break;
    case 'w':
        std::cout << "| You can put on boots" << std::endl;
        break;
    case 'r':
        std::cout << "| You can put on trainers" << std::endl;
        break;
    case 'c':
        std::cout << "| You can put on shoes" << std::endl;
        break;
    default:
        std::cout << "| Invalid wether: error:(((" << std::endl;
        break;
    }
    return 0;

}