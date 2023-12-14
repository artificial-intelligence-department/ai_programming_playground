#include <iostream>

int main() 
{
    // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    long double volt, Ohm, Amperage;

    // 21. в коді використано оператори виведення та введення даних
    std::cout << "Voltage (volt) > ";
    std::cin >> volt;

    std::cout << "Resistance (Ohm) > ";
    std::cin >> Ohm;

    //5. в коді використані умовні оператори та розгалуження
    if (Ohm != 0) 
    {
        Amperage = volt / Ohm;
        std::cout << "Amperage: " << Amperage;
    } 
    else 
    {
        std::cout << "Error: Division by zero!";
    }

    
    int i = 0;
    //8. в коді використаний do while цикл
    do 
    {
        std::cout << "\nIteration: " << i;
        i++;
    } 
    while (i < 3);
    }