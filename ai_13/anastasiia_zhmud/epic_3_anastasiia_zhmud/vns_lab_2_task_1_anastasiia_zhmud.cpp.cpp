#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double rez, a1=1, factorial=0, forpow;
    for(int i=1; i<=10; i++){
        if(i==1){
            factorial=1;
        }
        else{
            factorial=factorial*i;
        }
        rez+=a1;
        a1=(factorial/pow(i+1,(pow(i+1, 0.5)-1)));
    }
    cout<<rez;
}