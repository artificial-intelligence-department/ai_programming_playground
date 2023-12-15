#include <iostream>
#include <string>

int main() {
    std::string weather;
    std::cout << "Введіть тип погоди: \n";
    std::cin >> weather;

    if (!(weather == "sunny" || weather == "rainy" || weather == "snowy")) {
        std::cout << "Будь ласка, введіть коректну погоду.\n";
        return 1;
    }

    if (weather == "rainy" || weather == "snowy") {
        std::cout << "Вам слід взяти куртку.\n";
    } else if (weather == "sunny") {
        std::cout << "Куртка не потрібна.\n";
    }

    if (weather == "sunny") {
        std::cout << "Можна пограти у футбол з друзями.\n";
    } else if (weather == "snowy") {
        std::cout << "Хороша погода для лиж.\n";
    } else if (weather == "rainy") {
        std::cout << "Можна пограти в більярд вдома.\n";
    }

    char i = weather[0];

    switch (i) {
        case 's':
        if (weather == "sunny"){

            std::cout << "It's okey to go outside without umbrella";
        }
    }

    return 0;
}