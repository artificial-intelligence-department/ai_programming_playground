#include <iostream>
#include <cmath>
using namespace std;

double tailorFormulaBySteps(double x, int n);
double tailorFormulaByAccuracy(double x, double e, int n);

int main()
{
    const int n = 15;
    const double e = 0.0001;

    for (int i = 10; i <= 20; i++)
    {
        double x = i / 10.0;
        double tailor = tailorFormulaBySteps(x, n);
        double accuracy = tailorFormulaByAccuracy(x, e, 2);
        cout << "|\tX = " << x << "\t\t|\tSN = " << tailor << "\t|\tSN = " << accuracy << "\t|\tY = " << exp(x) << "\t|\n";
    }

    return 0;
}

double factorial(int n)
{
    if (n == 1)
        return 1;
    else
    {
        return factorial(n - 1) * n;
    }
}

double tailorFormulaBySteps(double x, int n)
{
    if (n == 1)
        return 1 + x;

    double expression = pow(x, n) / factorial(n);

    return tailorFormulaBySteps(x, n - 1) + expression;
}

double tailorFormulaByAccuracy(double x, double e, int n)
{
    double expression = pow(x, n) / factorial(n);

    if (e > abs(expression))
    {
        return 1.0 + x + expression;
    }

    return tailorFormulaByAccuracy(x, e, n + 1) + expression;
}