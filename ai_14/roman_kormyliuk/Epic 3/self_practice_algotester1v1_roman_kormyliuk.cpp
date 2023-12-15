#include <iostream>

using namespace std;

int main() {
long long HP, MP, h, m;
cin >> HP >> MP;
bool victory = true;
for (long long i = 0; i < 3; i++) {
    cin >> h >> m;
    if ( h > 0 && m > 0) {
        victory = false;
        }
        HP -= h, MP -= m;
}
if ( HP <= 0 || MP <= 0 || victory == false){
    cout << "NO" << endl;
    return 0;
}
cout << "YES" << endl;
return 0;
}