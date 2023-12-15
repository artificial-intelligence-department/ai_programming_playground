#include <iostream>
#include <cstdarg>
using namespace std;
int min(int k, ... ){
    va_list p;
    va_start(p , k);

    auto min = va_arg(p,int);
    
    for(int i = 1; i < k; i++){
        int current = va_arg(p, int);
        if(current < min)
            min = current;
    }
    va_end(p);

    return min;
}
double min(double k, ... ){
    va_list p;
    va_start(p , k);

    double min = k;
    
    for(int i = 0 ; i < k ; i++){
        double current = va_arg(p, double);
        if (current < min)
            min = current;
    }
    va_end(p);

    return min;
}

int main(){

    cout << min(5 , 15 , 176 , 249, 136 ,157) << endl;
    cout << min(10.0 ,0.5, 2.7, 2.8, 0.6,0.01,0.1,0.015,0.0014,1.4,4.5)<< endl;
    cout << min(12 , 235, 345, 634, 243, 235, 456, 654, 657, 543, 234,345,134);

    return 0;
}