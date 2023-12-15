#include <iostream>
#include <cstdarg>
using namespace std;

int sum(int a, ...)
{
    va_list arg;
    va_start(arg, a);
    int result = 0;
    for (int i = 0; i < a; ++i)
    {
        if (i % 2 == 0)
        {
            result += va_arg(arg, int) * va_arg(arg, int);
        } 
        else
        {
            result -= va_arg(arg, int) * va_arg(arg, int);
        }
    }
    va_end(arg);
    return result;
}

int main()
{
    int res5 = sum(2, 1, 2, 3, 4, 5);
    int res10 = sum(5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int res12 = sum(6, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);

    cout << res5 << endl;
    cout << res10 << endl;
    cout << res12 << endl;
    return 0;
}