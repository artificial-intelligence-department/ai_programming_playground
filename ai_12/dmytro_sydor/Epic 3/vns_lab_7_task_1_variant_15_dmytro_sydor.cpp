#include <iostream>
#include <sstream>

using namespace std;

void eithSyst(int k, ...)
{
    va_list args;
    va_start(args, k);

    for (int i = 0; i < k; i++)
    {
        int octNum = va_arg(args, int);
        int decNum = 0;
        int base = 1;

        while (octNum > 0)
        {
            int lastDigit = octNum % 10;
            octNum = octNum / 10;
            decNum += lastDigit * base;
            base *= 8;
        }

        cout << decNum << " ";
    }

    va_end(args);
}

int main()
{
    eithSyst(3, 10, 20, 30);
    cout << endl;
    eithSyst(6, 244, 820, 999, 123, 473, 7453);
    cout << endl;
    eithSyst(7, 344, 440, 654, 324, 66, 4543, 1543, 59874);
    cout << endl;
}