#include <iostream>
#include <numeric>
#include <cstdarg>
using namespace std;

int NSK(int count, ...);

int main()
{
    cout << "The least common multiple for 13, 4, 9 is: " << NSK(3, 13, 4, 9) << endl;
    cout << "The least common multiple for 6, 8, 12, 18, 24 is: " << NSK(5, 6, 8, 12, 18, 24) << endl;
    cout << "The least common multiple for 19, 73, 21, 7, 9, 2 is: " << NSK(6, 19, 73, 21, 7, 9, 2) << endl;
    return 0;
}

int NSK(int count, ...)
{
    va_list args;
    va_start(args, count);
    int nsk = va_arg(args, int);
    for (int i = 1; i < count; i++) 
    {
        int a = va_arg(args, int);
        nsk = nsk * a / gcd(nsk, a);
    }
    va_end(args);
    return nsk;
}