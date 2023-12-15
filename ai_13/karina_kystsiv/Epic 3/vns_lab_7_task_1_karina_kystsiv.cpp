#include <iostream>
#include <cstdarg>

using namespace std;

int nod(int a,int b){
  while(a && b) if (a < b) b %= a; else a %= b;
    return a + b;
}
int nok(int count,...){
    va_list list;
    va_start(list,count);
    int nsk=1;
    for(int i=0;i<count;i++){
        int parameter=va_arg(list,int);
         nsk =(nsk*parameter)/nod(nsk,parameter);
    }
    va_end(list);
    return nsk;
}

int main(){

cout<<"NOK(5, 134, 526) = "<<nok(3,5,134,526)<<endl;
cout<<"NOK(1, 2, 3, 4, 5) = "<<nok(5,1,2,3,4,5)<<endl;
cout<<"NOK(6, 7, 0, 9, 2, 3) = "<<nok(6,6,7,0,9,2,3)<<endl;



    return 0;
}
