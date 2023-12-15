#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double y, eps=0.0001, se, sn, fr;
    int na = 1;
    // x= (0.8-0.1)/10=0.07
    for(double x=0.1; x<=0.81; x+=0.07){
        fr=0.0;
        na=1;
        se=0.0;
        sn=0.0;

        y=x*atan(x)-log(sqrt(1+pow(x,2)));

        do{
            fr=pow(x,2*na)/2*na*(2*na-1);
            se+=fr;
            na++;
          }while(fabs(fr)>eps);
          fr=0.0;
          
          for(int n=1; n<=10; n++){
            fr=pow(x,2*n)/2*n*(2*n-1);
            sn+= fr;
          }
    cout<<"X= "<<x<<" SN="<<sn<<" SE="<<se<<" Y="<<y<<endl;
    }
    return 0;
}