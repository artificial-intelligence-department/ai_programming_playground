#include <iostream>
#include <cmath>
using namespace std;

int fact(int i){
    int res;
    if (i == 1){
        return 1;
    }
    res = i * fact(i - 1);
    return res;
}

int main(){
    double sum = 0, epsi = 0.0001, ai = 1; 
    int i = 1;
    while (ai > epsi){
        sum += ai;
        i++;
        ai = ai * (pow(i, i))/fact(i);   
    }
    cout << sum;
    return 0;
}