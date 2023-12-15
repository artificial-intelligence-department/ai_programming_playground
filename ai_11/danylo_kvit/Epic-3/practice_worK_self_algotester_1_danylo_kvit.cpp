#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(a[n/2]-a[i])+abs(b[n/2]-b[i])+abs(c[n/2]-c[i]);
    }
    cout<<ans<<"\n";

}
