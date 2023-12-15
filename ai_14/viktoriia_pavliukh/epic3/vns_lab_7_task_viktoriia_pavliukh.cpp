#include <iostream>
#include <cstdarg>
using namespace std;

float mult(float a, ...){
    va_list va;
    va_start(va, a);
    float m=1;
    for(int i=0; i<a; i++){
        float x = va_arg(va, double );
        m*=x;
    }
    va_end(va);
    return m;
}
int main() {
    float m1 = mult(3,1.01,2.1,3.6);
    cout<<m1<<endl;

    float m2 = mult(7,1.01,2.1,3.6,4.1,2.5,1.1,3.004);
    cout<<m2<<endl;

    float m3 = mult(11,1.01,2.1,3.6,4.09,5.12,4.54,7.36,4.1,2.2,1.2,1.1);
    cout<<m3<<endl;
    return 0;

}


