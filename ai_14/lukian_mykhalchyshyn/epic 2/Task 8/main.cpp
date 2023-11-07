#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::string weather;
    std::cout << "Enter type of weather \n";
    std::cin >> weather;

    if (weather != "sunny" && "rainy" && "snowy")
    {
        std::cout << "Вкажіть правильну погоду\n";
    }
    std::cin >> weather;

    if (weather == "rainy" || weather == "snowy")
    {
        std::cout << "Вам слід взяти куртку\n";
    }
    else if (weather == "sunny")
    {
        std::cout << "Куртка не потрібна\n";
    }

    if (weather == "sunny")
    {
        std::cout << "Можна зіграти в футбол з друзями\n";
    }
    else if (weather == "snowy")
    {
        std::cout << "Хороша погода для їзди на лижах\n";
    }
    else if (weather == "rainy")
    {
        std::cout << "Зіграти в більярд вдома\n";
    }

    char i = weather[0];
    switch (i)

    {
    case 's':
        if (weather == "sunny")
        {
            std::cout << "Взуй улюблені кросівки!\n";
            break;
        }
        else if (weather == "snowy")
        {
            std::cout << "Снігові черевики зігріють ваші ноги!\n";
        }
        break;

    case 'r':
        std::cout << "Дощові чоботи - гарна ідея!\n";
        break;

    case 'c':
        std::cout << "Сьогодні підходить будь-яке взуття!\n";
        break;

    case 'w':
        std::cout << "Одягніть щось міцне!\n";
        break;
    }

    return 0;
}