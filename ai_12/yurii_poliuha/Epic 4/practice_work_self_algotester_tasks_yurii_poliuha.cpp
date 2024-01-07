#include <iostream>
#include <cmath>
using namespace std;

long long limit(){
    bool review = false;
    long long a;
    cin >> a;

    while(review == false){
        if(a < 1 || a > pow(10, 12)) cin >> a;
        else review = true;
    }
    return a;
}

long long LimitOfMagic(){
    bool review = false;
    long long a;
    cin >> a;

    while(review == false){
        if(a < 0 || a > pow(10, 12)) cin >> a;
        else review = true;
    }
    return a;
}

int main(){
    long long h, m, h1, h2, h3, m1, m2, m3;

    h = limit();
    m = limit();
    h1 = LimitOfMagic();
    m1 = LimitOfMagic();
    h2 = LimitOfMagic();
    m2 = LimitOfMagic();
    h3 = LimitOfMagic();
    m3 = LimitOfMagic();

    if((h1 > 0 && m1 > 0) || (h2 > 0 && m2 > 0) || (h3 > 0 && m3 > 0)){
        cout << "NO" << endl;
        return 0;
    }

    long long sum_hi = h1 + h2 + h3;
    long long sum_mi = m1 + m2 + m3;
    
    h -= sum_hi;
    m -= sum_mi;

    if(h > 0 && m > 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
} 