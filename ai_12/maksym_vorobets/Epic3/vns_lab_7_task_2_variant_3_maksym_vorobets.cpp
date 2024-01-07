#include <iostream>
#include <complex>
using namespace std;

   double comp(double x1, double x2, double y1, double y2);
   int comp(int a, int b);
int main(){
    comp(1.0, 6.0, 2.0, 4.0);
    comp(23, 5);
 return 0;
}
    double comp(double x1, double x2, double y1, double y2){
    complex< double > z1(x1, x2); //1+6i//
    complex< double > z2(y1, y2);//2+4i//
    cout<<z1*z2<<endl;
    return 0;
}
    int comp(int a, int b){
    int s;
    s=a*b;
    cout<<s<<endl;
    return s;
}