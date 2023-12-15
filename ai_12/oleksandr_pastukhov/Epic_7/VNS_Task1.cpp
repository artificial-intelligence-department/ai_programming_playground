#include<iostream>
#include<cmath>

int main(){
    using namespace std;

    int m = 2;
    int c =1;
    float x = 1.2;
    float b = 0.7;

    double q = sqrt(m* tan(x)+abs(c*sin(x)));
    cout << "q = " << q << endl;

    double e = m*cos(b*x+sin(x))+pow(c,3);
    cout << "e = " << e << endl;

    return 0;
}