#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int*r = new int[n];
    for(int i=0;i<n;i++) cin >> r[i];
    sort(r,r+n);
    if(n==1){
        cout << 0;
        return 0;
    }
    if(n==2){
        cout << 0;
        return 0;
    }
    if(n==3){
        cout << min(r[1]-r[0], r[2]-r[1]);
        return 0;
    }
    cout << min(r[n-2]-r[0], r[n-1]-r[1]);
    return 0;
}