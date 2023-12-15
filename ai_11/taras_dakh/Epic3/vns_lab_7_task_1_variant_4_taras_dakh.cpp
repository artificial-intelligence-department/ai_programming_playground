#include <iostream>
#include <cstdarg>
using namespace std;

int sum(int count, ...){
    va_list args;
    va_start(args,count);
    int sum=0;
    int i=0;
    for(i=0;i<count;i+=2)
    {
        int a = va_arg(args,int);
        int b = va_arg(args,int);
        sum+=a*b;
    }
    va_end(args);
    return sum;
}

int main(){
    int sum1=sum(8,1,2,3,4,5,6,7,8);
    int sum2=sum(10,1,2,3,4,5,6,7,8,9,10);
    int sum3=sum(12,1,2,3,4,5,6,7,8,9,10,11,12);

    cout<<"Сума 1= "<<sum1<<endl;
    cout<<"Сума 2= "<<sum2<<endl;
    cout<<"Сума 3= "<<sum3<<endl;

    return 0;

}
