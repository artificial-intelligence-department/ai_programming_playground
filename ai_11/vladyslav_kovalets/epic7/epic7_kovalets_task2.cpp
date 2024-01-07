#include <iostream>
#include <cmath>

int main() 
{
    //4. в коді використана як мінімум одна цілочисельна константа
    int const a = 2;
    // 1. в коді використана як мінімум одна цілочисельна змінна
    int b = 3, c = 7;
    double y, x = 0, h = 0.31;

    // 5. в коді використані умовні оператори та розгалуження
    // 9. в коді використаний while цикл
    while (x <= 5) 
    {
        if (x < 2) 
        {
            y = std::pow(a, b - x) + c; 
            std::cout << "y = " << y << std::endl;
        } 
        else if (x >= 2 && x <= 4) 
        {
            y = std::pow(b, c - x) + a;
            std::cout << "y = " << y << std::endl;
        } 
        else 
        {
            y = std::pow(c, a - x) + b;
            std::cout << "y = " << y << std::endl;
        }
        x += h;
    }

    //6. в коді використаний одновимірний масив 
    int array[1] = {1};
    for (int i = 0; i < 100; ++i) 
    {
         int random = std::rand() % 50;
        if(random == array[0] )
        std::cout << " :<) "  << " ";
    }
}
