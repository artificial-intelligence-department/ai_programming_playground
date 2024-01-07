#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double a {0.7};
    double b {0.05};
    double x {0.5};
    double R {};
    double S {};

    R=((pow(x,3)*(x+1))/pow(b,2))-sin(pow(x*(x+a),2));
    S=sqrt((x*b)/a)+cos(pow((x+b),6));
    cout << R << endl;
    cout << S;
    return 0;
}