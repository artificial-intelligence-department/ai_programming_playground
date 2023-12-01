#include <iostream>                          
using namespace std;

int main() {
long long H, M, h1, h2, h3, m1, m2, m3;

cin >> H;
cin >>  M;

cin >> h1;
cin >> m1;
                             
cin >> h2;
cin >> m2;

cin >> h3;
cin >> m3;

long long RH = H-(h1+h2+h3);
long long RM = M-(m1+m2+m3);

if (h1 > 0 && m1 > 0 || h2 > 0 && m2 > 0 || h3 > 0 && m3 > 0) {
     cout << "NO";
} else if (RH>0 && RM>0) {
    cout << "YES"; 
    } else {
    cout << "NO"; }
    return 0;
}




