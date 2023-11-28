#include<iostream>
using namespace std ;

int main(){
    int i, three = 3, sum = 0;
    int n = 200/3;
    for(i=0; i<=n; i++ ){
        sum=sum +three*i;
    } 
    cout<< sum ;
}
