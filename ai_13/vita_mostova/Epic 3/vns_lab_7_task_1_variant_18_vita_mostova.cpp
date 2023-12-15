#include <iostream>
#include<cstdarg>
using namespace std;
int nsd(int num1,int num2){
    
while(num1>0 && num2>0) 
if (num1 < num2) num2 = num2%num1;
else num1 =num1% num2;
return num1 + num2;}
int nok(int num,...){
    va_list args;
    va_start(args,num);
    int result=1;
    for(int i=0;i<num;i++){
        int element=va_arg(args,int);
         result *=element/nsd(result,element);
    }
    va_end(args);
    return result;
}

int main(){

cout<<"NOK(2,5,3) = "<<nok(3,2,5,3)<<endl;
cout<<"NOK(3,4,7,14,28) = "<<nok(5,3,4,7,14,28)<<endl;
cout<<"NOK(2,3,6,7,34,5) = "<<nok(6,2,3,6,7,34,5)<<endl;



    return 0;
}