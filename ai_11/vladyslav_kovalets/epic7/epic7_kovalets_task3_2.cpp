#include <iostream>

int main() 
{
    // 1. в коді використана як мінімум одна цілочисельна змінна
    int km;
    double result;
    const double verst = 1066.8;

    std::cout << "Enter the km: ";
    std::cin >> km;

    //17. в коді використано математичні операції та математичні функції

    result = km*1000 / verst;

    std::cout << "This is a " << result << " verst." <<std::endl;

    //7. в коді використаний двовимірний масив 
    int matrix[km][km];
    //10. в коді використаний for цикл 
    for (int i = 0; i < km; ++i) 
    {
        for (int j = 0; j < km; ++j) 
        {
           int random = std::rand() % 101;
           if(random == 1)
           {
                std::cout << "I❤️y  ";
           }  
        }
        
    }
}
