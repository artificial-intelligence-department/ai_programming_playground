#include <iostream>
#include <vector>
#include <stdarg.h>
using namespace std;

double dividing (double a, double b){
    double result;
    if(b == 0){
        return 0;
    }else{
    result = a/b;
    }
    cout << result;
    return result;
}
int dividing (int a, int b){
    double result;
    if(b == 0){
        return 0;
    }else{
    result = a/b;
    }
    cout << result;
    return result;
}

int main(){
    
    dividing(10, 2);
    cout<< endl;
    dividing(21.2, 2.5);
    
    return 0;
}
