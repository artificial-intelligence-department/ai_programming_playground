#include <iostream>

int main()
{
    int n, edge;
    std::cin >> n >> edge;

    int maxNum = 0, output = 0;
    for(int i = 0; i < n; i++)
    {
        int teeth;
        std::cin >> teeth;

        if (teeth >= edge)
        {
            maxNum++;
            output = std::max(maxNum, output);
        }
        else
            maxNum = 0;
    }
    
    std::cout << output;
    
    return 0;
}