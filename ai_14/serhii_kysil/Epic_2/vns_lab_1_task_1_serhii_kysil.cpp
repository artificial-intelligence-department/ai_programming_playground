#include <iostream>  
#include <cmath>
using namespace std;
int main() {
    double a=1000, b=0.0001, z;
    z = (pow(a + b, 3)-pow(a, 3)-3*pow(a, 2)*b)/(3*a*pow(b, 2)+pow(b, 3));
    cout << "Double: "<< z << endl;
    float m=1000, c=0.0001, y;
    y = (pow(m + c, 3)-pow(m, 3)-3*pow(m, 2)*c)/(3*m*pow(c, 2)+pow(c, 3));
    cout << "Float result: "<< y << endl;
    system("pause"); 
    return 0;
}