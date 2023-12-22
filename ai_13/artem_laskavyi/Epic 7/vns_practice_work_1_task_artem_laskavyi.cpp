#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double e = exp(1.0);

    double a = 3.2;
    double b = 17.5;
    double x = -4.8;

    double Y = pow(b, 3) * pow(tan(x), 2) - a/(pow(sin(x/a), 2));
    double Z = a * pow(e, -sqrt(3)) * cos(b*x/a);

    cout << "Y = " << Y << endl;
    cout << "Z = " << Z << endl;
    
return 0;
}