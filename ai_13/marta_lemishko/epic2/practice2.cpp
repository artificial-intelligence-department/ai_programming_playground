include <iostream>
#include <string>

int main() {
    std::string weather;
    std::cout << "Введіть поточні погодні умови: ";
    std::cin >> weather;

    // Перевірка погодних умов та надання рекомендацій
    if (weather == "sunny") {
        std::cout << "Варто використати сонцезахисний крем!" << std::endl;
    } else if (weather == "cloudy") {
        std::cout << "Можливо, варто взяти парасолю." << std::endl;
    } else if (weather == "rainy") {
        std::cout << "Краще залишитися вдома та подивитися фільм." << std::endl;
    } else if (weather == "snowy") {
        std::cout << "обов'язково потрібно взяти рукавиці та шарф" << std::endl;
    } else if (weather == "windy") {
        std::cout << "Варто одягнутися тепло." << std::endl;
}
    return 0;
}
