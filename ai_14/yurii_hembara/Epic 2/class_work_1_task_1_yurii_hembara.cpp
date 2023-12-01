#include <iostream>
#include <string>

int main() {
    // Запитуємо користувача ввести поточні погодні умови
    std::string weatherCondition;
    std::cout << "Введіть поточні погодні умови (sunny, rainy, cloudy, snowy, windy): ";
    std::cin >> weatherCondition;

    // Перевіряємо, чи введено вірні умови, інакше просимо користувача ввести дійсну умову
    if (weatherCondition != "sunny" && weatherCondition != "rainy" && weatherCondition != "cloudy" && weatherCondition != "snowy" && weatherCondition != "windy") {
        std::cout << "Будь ласка, введіть дійсну умову." << std::endl;
    } else {
        // Рішення чи потрібно брати куртку
        if (weatherCondition == "rainy" || weatherCondition == "snowy") {
            std::cout << "Вам потрібно взяти куртку!" << std::endl;
        } else {
            std::cout << "Куртка не потрібна." << std::endl;
        }

        // Рекомендація щодо активності
        if (weatherCondition == "sunny") {
            std::cout << "Чудовий день для пікніка!" << std::endl;
        } else if (weatherCondition == "rainy") {
            std::cout << "Ідеальна погода, щоб читати книгу всередині!" << std::endl;
        } else if (weatherCondition == "cloudy") {
            std::cout << "Може, відвідати музей?" << std::endl;
        } else if (weatherCondition == "snowy") {
            std::cout << "Як щодо того, щоб зліпити сніговика?" << std::endl;
        } else if (weatherCondition == "windy") {
            std::cout << "Запустіть повітряного змія, якщо він у вас є!" << std::endl;
        }

        // Рекомендації щодо взуття
        switch (weatherCondition[0]) {
            case 's':
                std::cout << "Взуй улюблені кросівки!" << std::endl;
                break;
            case 'r':
                std::cout << "Дощові чоботи - гарна ідея!" << std::endl;
                break;
            case 'c':
                std::cout << "Сьогодні підходить будь-яке взуття." << std::endl;
                break;
            case 'sn':
                std::cout << "Снігові черевики зігріють ваші ноги!" << std::endl;
                break;
            case 'w':
                std::cout << "Одягніть щось міцне!" << std::endl;
                break;
            default:
                break;
        }
    }

    return 0;
}
