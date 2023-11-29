#include <iostream>
#include <cmath>
using namespace std;

void func(double x, int n, double epsilon)
{
    double resultN = 0;
    for(int i=1; i<=n; i++)
    {
        resultN += pow(-1, i) * pow(2*x, 2*i) / tgamma(2*i + 1);
    }


    double dodanok = (-1) * pow(2*x, 2) / 2;
    double resultE = dodanok;
    int counter = n-1;
    while(abs(dodanok) > epsilon)
    {
        dodanok = pow(-1, n-counter) * pow(2*x, 2*(n-counter)) / tgamma(2*(n-counter) + 1);
        resultE += dodanok;
        counter--;
    }

    double y = 2*(pow(cos(x), 2) - 1);

    cout << "X = " << x << "     " << "SN = " <<  resultN << "    " << "SE = " << resultE << "    " << "Y = " << y << endl;
}

int main()
{
    double x = 0.1, epsilon = 0.0001;
    int n = 15;

    while(x<=1)
    {
        func(x, n, epsilon);
        x+=(1-0.1)/10;
    }
}