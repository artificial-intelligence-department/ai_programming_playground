#include <iostream>

using namespace std;

int main() {
 long n;
 cin>>n;
 int m=0;
 while(n>0){
     while ((n - 500) >= 0) {
         n-=500;
         m++;
     }
     while((n-200)>=0){
         n-=200;
         m++;
     }
     while((n-100)>=0){
         n-=100;
         m++;
     }
     while((n-50)>=0){
         n-=50;
         m++;
     }
     while((n-20)>=0){
         n-=20;
         m++;
     }
     while((n-10)>=0){
         n-=10;
         m++;
     }
     while((n-5)>=0){
         n-=5;
         m++;
     }
     while((n-2)>=0){
         n-=2;
         m++;
     }
     while((n-1)>=0){
         n-=1;
         m++;
     }
     cout<<m;
 }

}


