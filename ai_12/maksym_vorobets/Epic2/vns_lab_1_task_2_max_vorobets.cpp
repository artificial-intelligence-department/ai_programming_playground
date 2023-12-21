#include <iostream>


int main () {
   int n, m, res;
   std::cout<<"n=";
   std::cin>>n;
   std::cout<<"m=";
   std::cin>>m;
n--;
res=n-m;
   std::cout<<"Result:"<<res<<std::endl;
n++;
m--;
   if (m<n){
   std::cout<<"YES"<<std::endl;
   }
      else
   {
      std::cout<<"NO"<<std::endl;
   }
m++;
n++;
   if (n>m){
      std::cout<<"n>m is TRUE"<<std::endl;
   }
      else   
       {
         std::cout<<"n>m is FALSE"<<std::endl;
       }
       
   return 0; 
}