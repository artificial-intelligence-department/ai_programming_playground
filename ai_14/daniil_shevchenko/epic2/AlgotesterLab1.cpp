#include <iostream>
#include <cmath>

int main()
{
    long long a[5];
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter the # " << i + 1 << " element: ";
        std::cin >> a[i];
    }
    bool limits = false;
    for (int i = 0; i < 5; i++)
    {
        if (a[i] >= pow(10, 12) || a[i] <= -pow(10, 12))
        {
            break;
        }
        if (i == 4)
        {
            limits = true;
        }

    }
    if (limits)
    {
        if (a[0] <= 0 || a[1] <= 0 || a[2] <= 0 || a[3] <= 0 || a[4] <= 0)
        {
            std::cout << "Error";
        }
    
        else 
        {

            if (a[0] >= a[1] && a[1] >= a[2] && a[2] >= a[3] && a[3] >= a[4])
            {
                std::cout << "Win";
            }
            else
            {
                std::cout << "Loss";
            }
        }
    }
    else
    {
        std::cout << "Not in limits";
    }
}