#include <iostream>
#include <cmath>
using namespace std;

#define n 3
#define E 0.0001

int main () {
    float a = 0.1;
    float b = 0.8;
    int k = 10;
    double step = (b-a)/k;
    double x, y, SN, SE, eps;
    SN = SE = 0.0;

    for (x = a; x <= b; x += step) {
    y = (1.0/4)*log((1+x)/(1-x))+(1.0/2)*atan(x);
    SN = SE = 0.0;                              //очищення значеня сум для кожного нового x
         for (int i = 0; i <= n; i++) {
          SN += pow(x, 4*i+1) / (4*i+1);
         }
         
    int j = 0; 
    while (fabs(pow(x, 4*j+1) / (4*j+1)) >= E) {
        SE += pow(x, 4*j+1) / (4*j+1);
        j++;
    }
    
cout << "X = " << x << "\tSN = " << SN << "\tSE = " << SE << "\tY = " << y << endl;
}
    return 0;
}
