#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int fact(int f)
{
    if (f == 1)
    {
        return 1;
    }
    return f * fact(f - 1);
    // Функція обчислення факторіалу;
}
int main()
{
    double a = 0.0, r, epsilon = 0.0001;

    for (int i = 1; a >= epsilon; i++)
    {
        a = (pow(fact(i), 2)) / pow(2, pow(i, 2));

        r += a;
    }

    cout << "\n Result is: " << r << endl;
    return 0;
}