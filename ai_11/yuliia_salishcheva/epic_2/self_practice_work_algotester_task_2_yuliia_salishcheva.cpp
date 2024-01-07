//Self-practice Class work version2
#include <iostream>
#include <string>

int main()
{
    std::string weather;
    bool jacket;
    bool shoes;
    bool actives;
   
    std::cout << "Enter wheather | sunny, windy, cloudy, rain, snowy : ";
    std::cin >> weather;

    std::cout << "You take a jacket? [True[1] / False[0]: ";
    std::cin >> jacket;

    std::cout << "You take a shoes? [True[1] / False[0]: ";
    std::cin >> shoes;

    std::cout << "Activity? [True[1] / False[0]: ";
    std::cin >> actives;

    
    switch (weather.at(0))
    {
    case 's':
        if (weather.at(1) == 'u')
        {
            if (jacket)
                std::cout << "Jacket: Light jacket" << std::endl;
            if (shoes)
                std::cout << "Shoes: Sandals" << std::endl;
            if (actives)
                std::cout << "Actives: A walk in the park)" << std::endl;
        }
        else
        {
            if (jacket)
                std::cout << "Jacket: down jacket" << std::endl;
            if (shoes)
                std::cout << "Shoes: winter's boots" << std::endl;
            if (actives)
                std::cout << "Actives: Go sledding)" << std::endl;
        }
        break;

    case 'c':
        if (jacket)
            std::cout << "Jacket: Warm jacket" << std::endl;
        if (shoes)
            std::cout << "Shoes: Boots" << std::endl;
        if (actives)
            std::cout << "Actives: A walk in the park)" << std::endl;
        break;

    case 'r':
        if (jacket)
            std::cout << "Jacket: Raincoat" << std::endl;
        if (shoes)
            std::cout << "Shoes: Rubber Boots" << std::endl;
        if (actives)
            std::cout << "Actives: A walk in the cinema)" << std::endl;
        break;
    case 'w':
        if (jacket)
            std::cout << "Jacket: Warm jacket" << std::endl;
        if (shoes)
            std::cout << "Shoes: Boots" << std::endl;
        if (actives)
            std::cout << "Actives: A walk in the museum)" << std::endl;
        break;
    default:
        std::cout << "Error!" << std::endl;
        return -1;
        break;
    }

}
