#include <iostream>
#include <cmath>
#include <string>
#include <cstdarg>
using namespace std;
void oct(int count, ...)
{
    va_list args;
    va_start(args, count);
    std::string r;
    for (int i = 0; i < count; ++i)
    {
        int x=va_arg(args, int);
        std::cout << "dec=" <<x << " ";
        while (x>0)
        {
            r = std::to_string(x%8) + r;
            x = (x-x%8)/8;
            //std::cout << x << " tyff  " << r << " jgv      ";
        }
    std::cout << "oct=" << r << " " << endl;
    r="";
    }
    va_end(args);
}
int main()
{
    oct(3, 45, 56, 81);
    oct(5, 876, 67, 132, 72, 39);
    oct(8, 3, 19, 16, 64, 543, 54, 24, 14);
    return 0;
}
