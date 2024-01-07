#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float a = 1000;
    float b =0.0001;
    
    float c=pow((a-b),3);
    float d1= 3*a*(pow(b,2));
    float d2=3 *(pow(a,2))*b;
    float numerator = c-pow(a,3);
    float denominator =pow(b,3)-d1-d2;
    float result =numerator/denominator;
    cout<<" Result1(for float) "<<result<<endl;

    
    double a1 = 1000;
    double b1 =0.0001;
    
    double c1=pow((a1-b1),3);
    double d11= 3*a1*(pow(b1,2));
    double d22=3 *(pow(a1,2))*b1;
    double numerator1 = c1-pow(a1,3);
    double denominator1 =pow(b1,3)-d11-d22;
    double result1 =numerator1/denominator1;
    cout<<" Result2(for double) "<<result1<<endl;

    
    
    return 0;
}