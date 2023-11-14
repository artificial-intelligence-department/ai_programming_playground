#include<iostream>
#include<math.h>

using namespace std;

int main(){
    float a,b,c,d,result;

    a = 1000;
    b = 0.0001;

    c = pow((a+b), 2);
    d = a*a - 2*a*b;

    result = (c - d) / b*b;


    double a2,b2,c2,d2,result2;

    a2 = 1000;
    b2 = 0.0001;

    c2 = pow((a2+b2), 2);
    d2 = a2*a2 - 2*a2*b2;

    result2 = (c2 - d2) / b2*b2;

    cout << "Float: " << result << endl;
    cout << "Double: " << result2 << endl;

    return 0;
}
