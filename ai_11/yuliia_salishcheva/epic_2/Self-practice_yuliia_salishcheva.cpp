
#include <iostream>
int main()
{
    long int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    long int counter = 0;
    while (a > 0 || b > 0)
    {
        a -= c;
        b -= d;
        counter++;
    }
    std::cout << counter;
    
}

