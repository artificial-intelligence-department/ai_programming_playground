#include <iostream>
using namespace std;

int limit(int a){
    bool review = false;
    while(review == false){
        if(a > 1000 || a < 0) cin>>a;
        else review = true;
    }
    return a;
}

int main(){
    int lv, ky, kh, d;
    cin>>lv;
    lv = limit(lv);
    cin>>ky;
    ky = limit(ky);
    cin>>kh;
    kh = limit(kh);
    cin>>d;
    d = limit(d);
    int sum = lv + ky + kh + d;
    cout<<sum<<endl;
    return 0;
}