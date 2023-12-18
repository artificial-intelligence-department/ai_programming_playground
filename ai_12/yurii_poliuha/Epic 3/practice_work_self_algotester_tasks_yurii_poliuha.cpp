#include <iostream>
#include <cmath>
using namespace std;

long long limit(long long a){
    bool review = false;
    while(review == false){
        if(a >= 1 && a <= pow(10, 9)) review = true;
        else cin >> a;
    }
    return a;
}

long long limit_teeth(long long a){
    bool review = false;
    while(review == false){
        if(a >= 1 && a <= pow(10, 5)) review = true;
        else cin >> a;
    }
    return a;
}

int main(){
    long long n, k;
    int count = 0;
    int Max = 0;

    cin >> n >> k;
    n = limit_teeth(n);
    k = limit(k);
    long long a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = limit(a[i]);
    }

    for(int i = 0; i < n; i++){
        if(a[i] >= k) count++;
        else count = 0;
        Max = max(Max, count);
    }
    cout << Max;

    return 0;
}