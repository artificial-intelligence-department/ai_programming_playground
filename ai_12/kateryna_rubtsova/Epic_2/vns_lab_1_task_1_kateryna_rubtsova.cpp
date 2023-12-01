
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
    float a, b; //a = 100, b = 0.0001;
    float  c, v, d, k, g, w, answer;
    
    cout << " a = ";
    cin >> a;
    cout << " b = ";
    cin >> b;
    c = pow(a - b, 4);
    v = pow(a, 4)- 4*pow(a, 3)*b + 6*pow(a, 2)*pow(b, 2);
    k = pow(b, 4);
    g = -4*a*pow(b, 3);
    d = c - v;
    w = k + g;
    answer = d/w;
    cout << answer;

    return 0;
}