#include <iostream>
#include <cmath>
using namespace std;

long long limit(){
    bool review = false;
    long long a;
    cin >> a;

    while(review == false){
        if(a < 1 || a > pow(10, 5)) cin >> a;
        else review = true;
    }
    return a;
}

long long LimitOfArray(){
    bool review = false;
    long long a;
    cin >> a;

    while(review == false){ 
        if(a < 0 || a > pow(10, 9)) cin >> a;
        else review = true;
    }
    return a;
}

int main(){
    long long n;
    long long count = 0;
    n = limit();
    long long a[n];
    for(int i = 0; i < n; i++){
        a[i] = LimitOfArray();
        if(a[i] > 0) count += (a[i] - 1);
    }

    cout << count << endl;
    return 0;
}