#include <iostream>
using namespace std;

int main() {

long long M, H;
cin >> H;
if (H<1) {cout << "NO"; return 0;}
cin >> M;
if (M<1) {cout << "NO"; return 0;}
for (int i=0; i<3; i++) {
    long long h, m;
    cin >> h >> m;
    if (h>=0 && m==0) H-=h;
    else if (m>=0 && h==0) M-=m;
    else {
        cout << "NO";
        return 0;
    }
    if (M<=0 || H<=0) {
    cout << "NO";
    return 0;
    }
}
cout << "YES";
    return 0;
}