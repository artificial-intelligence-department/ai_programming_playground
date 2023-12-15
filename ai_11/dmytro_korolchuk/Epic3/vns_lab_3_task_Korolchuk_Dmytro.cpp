#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float e = 0.0001;
    float an;
    float step = (M_PI-M_PI/5)/10;
    for(float p = M_PI/5; p<M_PI; p+=step){
        float SE = 0, SN = 0; // значення суми для заданого значення n, для заданої точності
        float Y; // поточне значення функції
        Y = 0.25*(p*p-(M_PI*M_PI/3));
        for (int n = 1; n <= 20; n++){ 
            SN += pow(-1,n)*cos(n*p)/(n*n); //сума SN
        }
        int m = 1;
        an = pow(-1,m)*cos(m*p)/(m*m);//перший член суми SE
        while (abs(an) > e){ 
            an = pow(-1,m)*cos(m*p)/(m*m); //сума SE
            SE += an;
            m++;
        }
        cout<<p<<" "<<SN<<" "<<SE<<" "<<Y<<endl;
    }
}