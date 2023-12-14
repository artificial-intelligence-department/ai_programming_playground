#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double h=0.5, x=1;
    while(x<=4){
        double z, y;
        z=abs(x)+pow(x, 3);
        y=z*(sin(pow(2+x, 2))/(2+x));
        cout<<z<<" "<<y<<endl;
        x+=h;
    }
}