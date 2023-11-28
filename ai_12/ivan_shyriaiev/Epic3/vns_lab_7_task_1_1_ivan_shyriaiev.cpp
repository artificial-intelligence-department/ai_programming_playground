#include<iostream>
#include<stdarg.h>
using namespace std;
int sum(int numberOfElements, ...){
    int suma = 0;
    va_list args;
    va_start(args,numberOfElements);
    
        for(int i = 0; i<numberOfElements; i++){
        int value = va_arg(args,int);
        suma+= value;
        }
        
   va_end(args);
return suma;    
}
int main(){
cout<< sum(3,1,2,1)<<" | "<< sum(7,1,1,1,1,1,1,0)<<" | "<<sum(11,1,1,1,4,5,7,2,3,3,3,11);
}


