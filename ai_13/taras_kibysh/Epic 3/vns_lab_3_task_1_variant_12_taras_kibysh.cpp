#include <iostream>
#include <cmath>
#include <cstdio>
int main(){
    using namespace std;
    float A = 0.1, B = 0.8;
    float k = 10;
    float step = (B-A)/k;
    float e = 0.0001;
    for(float x = A ; x <= B; x+=step){
    float sn = 0, se = 0;
    for(int n = 1; n<=35;n++){
        sn += (pow(x,n)*cos(n*M_PI/3))/n;
    }

    float check = 1;
    int j = 1;
    while(check > e){
    se += (pow(x,j)*cos(j*M_PI/3))/j;
    check = (pow(x,j)*cos(j*M_PI/3))/j;
    j++;
    }
    float y = 0.5*log(1-2*x*cos(M_PI/3)+ pow(x,2));


    // cout << "X=" << x << "    " << "SN = " << sn << "   " << "SE=" << se << "   " << "Y =" << y << endl;
    printf("x = %.2f    sn = %.7f  se = %.6f  y = %.7f \n", x, sn, se, y);


    


    }

    return 0;
}