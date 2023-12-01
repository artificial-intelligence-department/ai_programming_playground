#include <iostream>
using namespace std;

int main(){
    bool ans = true;
    long long h,m;
    cin >> h >> m;
    long long a[3];
    long long b[3];
    for(int i=0;i<3;i++){
        cin >> a[i] >> b[i];
        if(a[i]>0 && b[i]>0) ans = false;
        else{
            h-=a[i];
            m-=b[i];
        }
    }
    if(m<=0||h<=0) ans = false;
    if(ans) cout << "YES";
    else cout << "NO";

}
