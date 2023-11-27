#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<long> legs(4);
    std::vector<long> cuts(4);

    for (int i = 0; i < 4; i++)
    {
        std::cin >> legs[i];
    }

    for (int i = 0; i < 4; i++)
    {
        std::cin >> cuts[i];
        if (cuts[i] > legs[i])
        {
            std::cout << "ERROR\n";
            return 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        legs[i] -= cuts[i]; 

        long hmax = *std::max_element(legs.begin(), legs.end());
        long hmin = *std::min_element(legs.begin(), legs.end());
        
        if (hmax >= 2 * hmin)
        {
            std::cout << "NO";
            return 0;
        }
        
    }

    std::cout << "YES";
    return 0;
}

