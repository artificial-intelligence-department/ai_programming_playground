// Погоня в колі
#include <iostream>

using namespace std;


int main()
{
    double l, d, a, b, res, resM;

    cin >> l >> d >> a >> b;

    resM = (double) l / ((double) a - (double) b);
    res =  (double) d / ((double) 0.5 * a - (double) b);

    if(res < resM && 0.5 * a > b)
    {
        printf("%.7f", res);
    }
    else
    {
        printf("%.7f", resM);
    }

    return 0;
}
