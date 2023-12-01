#include <iostream>
#include <cmath>
using namespace std;
//варіант 22

int main()
{
    double sum = 0;

    double value;

    for(int n = 2; n <= 15; n++)
    {
        value = double(pow(n, log10(n))) / double(pow(log10(n), n));
        sum += value;
    }

    cout << "The sum of first 15 terms is " << sum << endl;
    return 0;
}
