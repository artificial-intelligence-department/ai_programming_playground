#include <iostream>
using namespace std;
int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    int max_h = max(x-1,n-x)+max(y-1,m-y);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << max_h-(abs(x-1-i)+abs(y-1-j)) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
