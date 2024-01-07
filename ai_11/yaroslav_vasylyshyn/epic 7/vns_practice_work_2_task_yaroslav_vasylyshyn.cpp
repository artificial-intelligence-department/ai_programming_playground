#include <iostream>
#include <cmath>

using namespace std;

int main(){
    //variant 15 (a > - 0.5)
    double a = 1.2 ,z = 0;
    for(double x=1; x<=4; x +=0.5){
        if(x-1.5 < 0)
            cout<<"Error"<<'\n';
        else{
            z = (sqrt(x - 1.5) + pow(x, a))/(pow((x-2), (1/3)));
            a += 0.2;
            cout<<"x = "<<x<<'\t'<<"a = "<<a<<'\t'<<"z = "<<z<<'\n';
        }
    }
    return 0;
}