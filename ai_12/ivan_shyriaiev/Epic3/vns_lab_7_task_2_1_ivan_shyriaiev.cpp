#include<iostream>
#include<complex>
using namespace std;
int addition(int a, int b){
    return a + b ;
}
complex<int> addition(complex<int>a, complex<int>b){
    return a + b;
}
int main(){
    cout<< addition(10,5)<<"\n";
complex<int> firstnumber(1,-2);
complex<int> secondnumber(2,4);
cout<<addition(firstnumber,secondnumber);
return 0;
}