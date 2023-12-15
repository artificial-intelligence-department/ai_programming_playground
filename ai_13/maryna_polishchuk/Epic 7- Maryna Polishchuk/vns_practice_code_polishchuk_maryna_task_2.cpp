#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a=2, b=3, c=7;
    double y;

    for (double x=0; x<=5; x+=0.31){
        if (x<2){
            y=pow(a, b-x)+c;
        }
        if (x>=2 && x<=4){
            y=pow (b, c-x)+a;
        }
        if (x>4){
            y=pow(c, a-x)+b;
        }
        cout << "y for x=" << x<< ": " << y << endl;
    }
    return 0;
}