#include <iostream>
#include <cmath>

// Це обчислення тангенса від x
double mtgx(double x) {
    return tan(x);
}

// А вот тут обчислення косинуса від x
double csinx(double x) {
    return cos(x);
}

// Це база, основна функція для обчислення виразу з заданими формулами
double linearAlgorithm(double x, double m, double c, double b) {
    // Розрахунок фі за формулою
    double phi = sqrt(mtgx(x) + fabs(csinx(x)));

    // Розрахунок ксі за формулою
    double xi = m * cos(b * x + sin(x)) + pow(c, 3);

    // Повернення суми фі та ксі
    return phi + xi;
}

int main() {
    // Це константи і я додав їх значення
    double m = 2.0;
    double c = 1.0;
    double x = 1.2;
    double b = 0.7;

    // Виклик основної функції та виведення результату
    double result = linearAlgorithm(x, m, c, b);
    std::cout << "Результат: " << result << std::endl;

    // Ну і завершення
    return 0;
}
