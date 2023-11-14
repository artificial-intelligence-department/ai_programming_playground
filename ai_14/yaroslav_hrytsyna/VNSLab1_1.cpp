#include <iostream>
#include <cmath>
using namespace std;


long double a;
long double b;
long double R;
long double t;
long double k;
long double n;

int main()
{
    std::cin >> a;
    std::cin >> b;
    t=pow(a+b,3);
    k=pow(a,3)+3*a*a*b;
    n=3*a*b*b+pow(b,3);
    R=(t-k)/n;
    std::cout << R;
}