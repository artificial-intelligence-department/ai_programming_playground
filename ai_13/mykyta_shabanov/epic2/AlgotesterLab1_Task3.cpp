// Algotester Lab 1 - Task 3

#include <iostream>

int main()
{
    long long cube[5];
    for (int i = 0; i < 5; i++)
    {
        std::cin >> cube[i];
        if(cube[i] <= 0)
        {
            std::cout << "ERROR";
            return 0;
        } else
        if(cube[i] > cube[i-1])
        {
            std::cout << "LOSS";
            return 0;
        }
    }

    std::cout << "WIN";
    return 0;
}