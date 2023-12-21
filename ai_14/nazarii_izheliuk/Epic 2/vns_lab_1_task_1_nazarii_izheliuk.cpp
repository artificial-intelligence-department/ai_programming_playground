#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


int main() {
    double a, b, answer, c, x, u;


    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    c = pow(a+b, 3);
    x = (pow(a, 3)+3 * a * a *b);
    u = (3 * a * b * b + pow(b, 3));
    
    answer = (c - x) / (u);
    cout << "Answer: " << fixed << setprecision(2) << answer << endl;

    return 0;
}