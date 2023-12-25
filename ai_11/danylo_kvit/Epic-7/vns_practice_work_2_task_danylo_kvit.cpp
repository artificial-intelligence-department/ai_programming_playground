#include <iostream>
using namespace std;
int main(){
    for(double x = -2.5;x<=2;x+=0.5){
         double z = abs(x)+x*x;
         double y = z*(sin(2+x)*sin(2+x))/(2+x);
         cout << y << '\n';
    }
}