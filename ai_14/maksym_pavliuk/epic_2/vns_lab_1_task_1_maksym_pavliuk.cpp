#include<iostream>
#include<math.h>

using namespace std;

int main(){
    float a1,b1,c1,d1,result1;

    a1 = 1000;
    b1 = 0.0001;

    c1 = pow((a1+b1), 2);
    d1 = a1*a1 - 2*a1*b1;

    result1 = (c1 - d1) / b1*b1;
    /////////////////////////////
    double a2,b2,c2,d2,result2;

    a2 = 1000;
    b2 = 0.0001;

    c2 = pow((a2+b2), 2);
    d2 = a2*a2 - 2*a2*b2;

    result2 = (c2 - d2) / b2*b2;

    cout << "Result using float is: " << result1 << endl;
    cout << "Result using double is: " << result2 << endl;

    return 0;
}