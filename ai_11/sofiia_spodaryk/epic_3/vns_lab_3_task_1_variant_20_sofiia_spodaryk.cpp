#include <iostream>
#include <cmath>

using namespace std;

double epsilon = 0.0001;
double e = 2.7182;
double a = 0.1, b = 1;
double k = (b - a) / 10;
double result = 0.0;

int main()
{
  for (double x = a; x <= b; x += k)
  {
    double SN = 0;
    double Y = (pow(x, 2) / 4 + x / 2 + 1) * pow(e, x / 2);

    for (int n = 1; n <= 30; n++)
    {
      result = ((pow(n, 2) + 1) / tgamma(n)) * (pow(x / 2, n));
      SN += result;
    }

    double SE = 0;
    int n1 = 1;
    double resulte = ((pow(n1, 2) + 1) / tgamma(n1)) * (pow(x / 2, n1));

    while (fabs(resulte) >= epsilon)
    {
      SE += resulte;
      n1++;
      resulte = ((pow(n1, 2) + 1) / tgamma(n1)) * (pow(x / 2, n1));
    }

    cout << "X = " << x << " SN = " << SN << " SE = " << SE << " Y = " << Y << endl;
  }
  return 0;
}