#include <iostream>
#include <string>

int main() {
    std::cout << "Введіть погодні умови (sunny, rainy, cloudy, snowy, windy): ";
    std::string weather;
    std::cin >> weather;

    if (weather == "snowy" || weather == "rainy") {
        std::cout << "Вам потрібно взяти куртку!\n";
    } else {
        std::cout << "Куртка не обов'язкова.\n";
    }

    if (weather == "sunny") {
        std::cout << "Чудовий день для пікніка!\n";
    } else if (weather == "rainy") {
        std::cout << "Ідеальна погода, щоб читати книгу всередині!\n";
    } else if (weather == "cloudy") {
        std::cout << "Може, відвідати музей?\n";
    } else if (weather == "snowy") {
        std::cout << "Як щодо того, щоб зліпити сніговика?\n";
    } else if (weather == "windy") {
        std::cout << "Запустіть повітряного змія, якщо він у вас є!\n";
    } else {
        std::cout << "Будь ласка, введіть дійсну умову погоди.\n";
    }

    switch (weather[0]) {
        case 's':
            std::cout << "Взуй улюблені кросівки!\n";
            break;
        case 'r':
            std::cout << "Дощові чоботи - гарна ідея!\n";
            break;
        case 'c':
            std::cout << "Сьогодні підходить будь-яке взуття.\n";
            break;
        case 'w':
            std::cout << "Снігові черевики зігріють ваші ноги!\n";
            break;
        case 'n':
            std::cout << "Одягніть щось міцне!\n";
            break;
        default:
            std::cout << "Не можливо надати рекомендацію щодо взуття.\n";
    }

    return 0;
}
