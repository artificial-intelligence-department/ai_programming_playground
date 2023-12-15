#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;

int fact(int n){
 if(n==0||n==1){return 1;}
    return n*fact(n-1);
}
int main(){
    double x, s, a=0.1, b=1.0, SN, SE, Y, E=0.0001;
    cout << fixed << setprecision(5);
    int n=10, k=10;
        for(double i=a;i<=b;i+=(b-a)/k){
        x=i;
        cout <<"X="<< x << "    ";
        SN=x;
    for(int i=0; i<=n; i++){
        SN+=pow((-1),i)*pow(x,2*i+1)/fact(2*i+1);
    }
     cout <<"SN="<< SN << "    ";
        s=x;  
        int m=1; 
   while (E<=abs(s)){
    s=pow((-1),m)*pow(x,2*m+1)/fact(2*m+1);
    SE+=s;
    m++;
   }            
   cout <<"SE="<< SE << "    ";
   Y=sin(x);
   cout <<"Y="<< Y << "    "<<endl;
}  
    return 0;  
}
