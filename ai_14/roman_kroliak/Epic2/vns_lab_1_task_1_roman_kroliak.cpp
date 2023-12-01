#include <iostream>
#include <math.h>
using namespace std;
int main() {
    float a_f = 1000;
    float b_f = 0.0001;
    float res_f;
    res_f = (pow(a_f+b_f,3)-pow(a_f,3))/(3*a_f*pow(b_f,2)+pow(b_f,3)+3*pow(a_f,2)*b_f);
    cout << "Result (float): " << res_f << endl;
    double a_d = 1000;
    double b_d = 0.0001;
    double res_d;
    res_d = (pow(a_d+b_d,3)-pow(a_d,3))/(3*a_d*pow(b_d,2)+pow(b_d,3)+3*pow(a_d,2)*b_d);
    cout << "Result (double): " << res_d;
    return 0;
}
