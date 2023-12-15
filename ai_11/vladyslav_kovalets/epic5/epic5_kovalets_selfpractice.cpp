#include <iostream>
#include <string>

int my_max(int a, int b) 
{
    return (a > b) ? a : b;
}

int main() 
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int signal_strength = 15;

    for (int i = 0; i < n; ++i) 
    {
        char block = s[i];

        if (block == 'k')
        {
            signal_strength = my_max(signal_strength - 1, 0);
        } 
        else if (block == 'p') 
        {
            signal_strength = (signal_strength >= 1) ? 15 : 0;
        } 
        else if (block == 'z') 
        {
            signal_strength = (signal_strength >= 1) ? 0 : 15;
        }
    }

    std::cout << signal_strength << std::endl;

    return 0;
}
