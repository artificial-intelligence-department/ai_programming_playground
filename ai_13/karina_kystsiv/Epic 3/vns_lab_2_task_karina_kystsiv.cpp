#include <iostream>
#include <cmath>
using namespace std;
int factorial(int fn){
    if (fn<=1){                                
        return 1;
    }
    else{
        return fn*factorial(fn-1);
    }
   }
int main(){
    int n=1;
    float an=pow(n,3)/factorial(3*n -3);
    float totalsum =0;
    do{ 
        totalsum += an;
        an*=pow((n+1),3)/(3*(pow(n,4))*(3*n-2)*(3*n-1));
        n++;
    }while(an>=0.0001);
  cout<<totalsum;          
return 0;
    }