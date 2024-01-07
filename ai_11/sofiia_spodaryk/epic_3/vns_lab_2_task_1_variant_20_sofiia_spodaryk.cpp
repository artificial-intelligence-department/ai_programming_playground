#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double epsilon = 0.0001;
    const double e = 2.7182;
    double sum = 0;
    int n = 0;
    double an;

 do {
     an = pow(e, n) * pow(100, -pow(n, 2));
        sum += an;
        n++;
 } while (abs(an) >= epsilon); 
    cout << "Сума ряду дорівнює " << sum << endl;
    return 0;
}
