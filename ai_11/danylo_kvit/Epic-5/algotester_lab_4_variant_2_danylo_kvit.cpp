#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    vector<int> b;
    b.push_back(a[0]);
    for(int i=1;i<n;i++) if(a[i-1]!=a[i]) b.push_back(a[i]);
//    for(int i=0;i<b.size();i++) cout << b[i] << ' ';
    cout << b.size() << '\n';
    for(int i=0;i<b.size();i++) cout << b[(i+k)%b.size()] << ' ';
    return 0;
}