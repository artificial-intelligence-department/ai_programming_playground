#include <iostream>

using namespace std;

double sum = 0;
double a = 0.5;
double epsilon = 0.0001;
int n = 1;
double reccurent;

int main()
{
    while(a >= epsilon)
    {
        sum += a;
        reccurent = ((2.0*n)+1.0)/((4.0*n)-2.0);
        a *= reccurent;
        n++;
    }

    cout << sum << endl;

    return 0;
}
