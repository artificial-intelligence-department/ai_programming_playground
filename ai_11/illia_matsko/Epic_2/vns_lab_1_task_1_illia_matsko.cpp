#include <iostream>
using namespace std;

int main()
{
    double a_d = 1000, b_d = 0.0001;
    float a_f = 1000, b_f = 0.0001;

    float c_f = a_f+b_f;
    float d_f = pow(c_f, 3);
    float e_f = pow(a_f, 3) + 3 * pow(a_f,2) * b_f;
    float f_f = 3 * a_f * pow(b_f, 2) + pow(b_f, 3);

    double c_d = a_d+b_d;
    double d_d = pow(c_d, 3);
    double e_d = pow(a_d, 3) + 3 * pow(a_d,2) * b_d;
    double f_d = 3 * a_d * pow(b_d, 2) + pow(b_d, 3);

    cout << "With double: " <<  (d_d-e_d)/f_d << endl;
    cout << "With float: " <<  (d_f-e_f)/f_f;
}