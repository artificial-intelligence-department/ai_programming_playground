#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a = 100;
    float b = 0.001;

    

    float c=pow(a+b,4);
    float d=pow(a,4);
    float e=4*pow(a,3)*b;
    float f=6*pow(a,2)*pow(b,2);
    float g=4*a*pow(b,3);
    float h=pow(b,4);
    float result = (c-d-e)/(f+g+h);


    cout << "Result of float: " << result << endl;


    int a_d = 100;
    double b_d = 0.001;

    
    double c_d=pow(a_d+b_d,4);
    double d_d=pow(a_d,4);
    double e_d=4*pow(a_d,3)*b_d;
    double f_d=6*pow(a_d,2)*pow(b_d,2);
    double g_d=4*a_d*pow(b_d,3);
    double h_d=pow(b_d,4);
    double result_d = (c_d-d_d-e_d) / (f_d+g_d+h_d);


    cout << "Result of double: " << result_d << endl;


}