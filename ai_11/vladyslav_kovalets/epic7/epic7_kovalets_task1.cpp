#include <iostream>
#include <cmath>

// 14. в коді використано структури 
struct Point 
{
    int x, y;
};

int main() 
{
    // 1. в коді використана як мінімум одна цілочисельна змінна
    int x = 2, y = 2; 

    // 2. в коді використана як мінімум одна дійсна змінна
    // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    double a = (sqrt(std::abs(x - 1)) - sqrt(y)) / (1 + std::pow(x, 2) / 2 + std::pow(y, 2) / 4);
    std::cout << "A = " << a << std::endl;

    double b = 1 / (tan(exp(x)));
    std::cout << "B = " << b;

    // Додавання структури
    Point point;
    point.x = 5;
    point.y = 7;

    std::cout << "\nPoint: (" << point.x << ", " << point.y << ")";
}
