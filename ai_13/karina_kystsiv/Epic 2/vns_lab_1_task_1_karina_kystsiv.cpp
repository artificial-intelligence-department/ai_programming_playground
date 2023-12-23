#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    float a = 100.0f;
    float b = 0.001f;

    float res1 = pow(a+b, 4); // (a+b)^4

    float res2 = pow(a, 4); // a^4
    float res3 = 4 * pow(a, 3) * b; // 4*(a^3)*b
    float res4 = 6 * pow(a, 2) * pow(b, 2); // 6*(a^2)*(b^2)
    
    float numerator = res1 - (res2 + res3 + res4); // чисельник
    float denominator = 4 * a * pow(b, 3) + pow(b, 4); // знаменник
    
    float result = numerator / denominator;
    cout  << result << endl;


    double a_d = 100.0;
    double b_d = 0.001;

    double res_1 = pow(a_d+b_d, 4);

    double res_2 = pow(a_d, 4);
    double res_3 = 4 * pow(a_d, 3) * b_d;
    double res_4 = 6 * pow(a_d, 2) * pow(b_d, 2);
    
    double result_d = res_1 - (res_2 + res_3 + res_4) / 4 * a_d * pow(b_d, 3) + pow(b_d, 4) ;
    cout  << result_d << endl;


    return 0;
}
