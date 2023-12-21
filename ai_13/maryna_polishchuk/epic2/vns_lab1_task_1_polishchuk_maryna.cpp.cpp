
//must be -1
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double a, b, top, bottom, res;
    a = 1000;
    b = 0.0001;
    top = pow((a-b), 3) - (pow(a, 3)- 3 * pow(a, 2)* b);
    bottom = pow (b, 3) - (3 * a * pow (b, 2));
    res = top / bottom;

    cout << res << endl;
    return 0;
}