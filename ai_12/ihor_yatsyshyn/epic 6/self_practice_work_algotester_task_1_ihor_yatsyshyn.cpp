#include <iostream>
#include <string>

int main() 
{
    std::string text;
    int res = 0;

    std::cin >> text;
    for(int i = 0; i < text.length(); i++) 
    {
        if(text[i] != text[i - 1])
        {
            res++;
        }
    }

    std::cout << res;

    return 0;
}