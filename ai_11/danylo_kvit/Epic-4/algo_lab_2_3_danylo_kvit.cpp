#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int x = 0;
    int y = n-1;
    while(true){
        if(y == x+1){
            cout << x+1 << ' ' << y+1 << '\n';
            cout << "Stopped";
            return 0;
        }else if(x>y){
            cout << x+1 << ' ' << y+1 << '\n';
            cout << "Miss";
            return 0;
        }else if(y == x){
            cout << x+1 << ' ' << y+1 << '\n';
            cout << "Collision";
            return 0;
        }
        x+=a[x];
        y-=a[y];
    }
}
