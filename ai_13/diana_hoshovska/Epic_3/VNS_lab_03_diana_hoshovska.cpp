#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double SN, Sn, Sn1, SE, y, e = 0.0001, k = 1.0;

    for (float x=0.1; x<=0.8; x+=0.07){
        SN = 0;
        for (int j = 1; j <= 9; j+=4){
            SN+=pow(x, j)/j;
        }

        Sn1 = 0, Sn = 0;
        while (abs(Sn1-Sn)<e){
            SE = 0, k = 1.0;
            Sn=pow(x, k)/k;
            Sn1=pow(x,(4*k+1))/(4*k+1);
            Sn+=Sn1;
            SE+=Sn;
            k++;
        }

        y = 0.25*log((1+x)/(1-x))+0.5*atan(x);
        cout << "X=" << x << "   SN=" << SN << "    SE=" << SE << "     Y=" << y << endl;
    }
    return 0;
}