#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a;
    float b;

    cout << "input a and b: ";
    cin >> a >> b;

    int pow_a_2 = pow(a, 2);
    int pow_a_3 = pow(a, 3);
    int pow_a_4 = pow(a, 4);

    float pow_b_2 = pow(b, 2);
    float pow_b_3 = pow(b, 3);
    float pow_b_4 = pow(b, 4);

    float c = a - b;
    float d = pow_a_4 - 4 * pow_a_3 * b;
    float e = 6 * pow_a_2 * pow_b_2 - 4 * a * pow_b_3 + pow_b_4;

    float result = (c - d) / e;

    cout << result;
}
