// Підключення необхідних бібліотек
#include <iostream>
#include <cmath>

// Основна функція програми
int main(){
    // Оголошення змінних для обчислень та констант
    double u, f;
    const float a = 0.5;
    const float b = 2.9;
    const float x = 0.3;

    // Обчислення чисельника для виразу U
    double numerator = pow(a, 3) + exp(-x) * cos(b * x); 

    // Обчислення знаменника для виразу U
    double denominator = b * x - exp(-x) * sin(b * x) + 1;

    // Обчислення виразу U та виведення результату
    u = numerator / denominator;
    std::cout << "U = " << u << std::endl;

    // Обчислення виразу F
    f = exp(2 * x) * log(a + x) - pow(b, 3 * x) * log(abs(x - b));

    // Виведення результату обчислення виразу F
    std::cout << "F = " << f << std::endl;

    // Повертається 0, що вказує на успішне завершення програми
    return 0;
}
