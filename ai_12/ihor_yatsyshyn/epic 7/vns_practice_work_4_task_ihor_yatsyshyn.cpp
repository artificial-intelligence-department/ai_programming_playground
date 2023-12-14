#include <iostream>

int main() {
    double input, sum, min, max, arithm;
    int amount;

    std::cout << "Enter the number of inputs: ";
    std::cin >> amount;

    std::cout << "Enter number " << 1 << " : ";
    std::cin >> input;
    sum += input;
    min = max = input;

    int i = 1;
    //Вимога 8 - в коді використаний do while цикл (цикл використовується для ітерації та пошуку мінімального/максимального елемента, їх суми та кількості)
    do{
        std::cout << "Enter number " << i + 1 << " : ";
        std::cin >> input;
        
        sum += input;
        if(input < min) {
            min = input;
        }else if(input > max) {
            max = input;
        }
        i++;
    } while (i < amount);

    std::cout << "Minimal value: " << min << std::endl;
    std::cout << "Maximal value: " << max << std::endl;

    arithm = sum / amount;
    std::cout << "Aruthmetic mean: " << arithm;

    return 0;
}