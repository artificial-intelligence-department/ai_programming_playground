#include <iostream>
#include <cmath>

using namespace std;
int main() {
float x=0.2, n1, n, SN, epsylon=0.0001, an, an1, SE, Y;
while (x<1) {
    SN=0;
    n1=1;
    an=(x-1)/(x+1);
    while (n1<=10) {
        an=an*((2*n1+1)/(2*n1+3))*pow(((x-1)/(x+1)),2);
        SN=SN+an;
        n1++;
    }
    SE=0;
    n=1;
    an1=(x-1)/(x+1);
    while (abs(an1)>=epsylon) {
        an1=an1*((2*n+1)/(2*n+3))*pow(((x-1)/(x+1)),2);
        SE=SE+an1;
        n++;
    }
    Y=0.5*log(x);
    cout << "x=" << x << " " << "SN=" << SN << " " << "SE=" << SE << " " << "Y=" << Y << endl;
    x=x+0.08;
}
return 0;
}

