#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int n = 10;
    double S=0, x, i, fact2n;

    for (int i = 1; i <= n; i++)
    {
        fact2n=1;
        x=0.1*i;
        for (int j = 1; j <= i*2; j++)
        {
           fact2n*=j; 
        }
        S+= pow(x, 2*i) / fact2n;
    }
    cout << "a) S =" << S+1 << endl;

    cout << "b) S =" << round((S+1)*10000)/10000 << endl;

    return 0;
}

