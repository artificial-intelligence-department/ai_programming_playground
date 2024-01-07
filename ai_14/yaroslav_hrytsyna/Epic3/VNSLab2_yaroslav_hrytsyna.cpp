#include <iostream>
#include <cmath>
using namespace std;

int n;
double s, a, f;
double t = 0.0001;

double fact (int e){
    f = 1;
    for (int j = 1; j <= e; j++)
        {
            f *= j;
        }
    return f;
}
int main()
{
    cout << "Enter n \n";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a=pow(2,i)*fact(i)/pow(i,i);
        if (a > t)
        {
            s += a;
        }
    }
    cout << s;
    return 0;
}
