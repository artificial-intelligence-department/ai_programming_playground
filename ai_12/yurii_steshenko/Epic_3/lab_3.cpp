#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n)
{
    return n ? n * factorial(n - 1) : 1;
}

double calc_term(double x, double i)
{
    return pow(-1, i) * ((2 * pow(i, 2) + 1) / (factorial(2 * i)) * pow(x, 2 * i));
}

int main()
{
    double a = 0.1;
    double b = 1;

    double step = (b - a) / 10;

    int n = 10;
    double epsilon = 0.0001;

    for (double x = a; x <= b + epsilon; x += step)
    {
        double Sn = 0, Se = 0;

        int i = 0;
        double term;

        while (fabs(term) >= epsilon || i == 0)
        {
            term = calc_term(x, i);
            Se += term;
            i++;
        }
        i = 0;
        while (i <= n)
        {
            term = calc_term(x, i);
            Sn += term;
            i++;
        }

        double y = (1 - pow(x, 2) / 2) * cos(x) - (x / 2) * sin(x);

        printf("X = %.2f\tSN = %.6f\tSE = %.6f\tY = %.6f\n", x, Sn, Se, y);
    }

    return 0;
}
