#include <iostream>
using namespace std;
int main()
{

    // Вимога 4 цілочисельна константа
    const int maxmass = 1000;
    const int minmass = 100;
    int step = 100;
    double price = 17.5;

    for (int mass = minmass; mass <= maxmass; mass += step)
    {

        price = ((mass * 17.5) / 1000);

        cout << price << endl;
    }
}