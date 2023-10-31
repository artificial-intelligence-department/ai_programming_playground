#include <iostream>                          
using namespace std;
int main() {
long long H, M;
long long hi, mi, h1, h2, h3, m1, m2, m3;
long long RN;
cout << "Enter hit points: ";
cin >> H;
while  (H < 1 || H > 1000000000000LL) {
    cout << "Invalid input for hit points.\n";
    cout << "Enter hit points: ";
    cin >> H;                               
}
cout << "Enter mana: ";
cin >> M;
while  (M < 1 || M > 1000000000000LL) {
    cout << "Invalid input for mana.\n";
    cout << "Enter mana: ";
    cin >> M;                               
}
cout << "Enter the number of hit points you spend for 1 spell: ";
cin >> h1;
while  (h1 < 0 || h1 > 1000000000000LL) {
    cout << "Invalid number of hit points you spend for 1 spell: \n";
    cout << "Enter the number of hit points you spend for 1 spell: ";
    cin >> h1;                               
}
cout << "Enter the number of mana you spend for 1 spell: ";
cin >> m1;
while  (m1 < 0 || m1 > 1000000000000LL) {
    cout << "Invalid number of mana you spend for 1 spell: \n";
    cout << "Enter the number of mana you spend for 1 spell: ";
    cin >> m1;                               
}
cout << "Enter the number of hit points you spend for 2 spell: ";
cin >> h2;
while  (h2 < 0 || h2 > 1000000000000LL) {
    cout << "Invalid number of hit points you spend for 2 spell: \n";
    cout << "Enter the number of hit points you spend for 2 spell: ";
    cin >> h2;                               
}
cout << "Enter the number of mana you spend for 2 spell: ";
cin >> m2;
while  (m2 < 0 || m2 > 1000000000000LL) {
    cout << "Invalid number of mana you spend for 2 spell: \n";
    cout << "Enter the number of mana you spend for 2 spell: ";
    cin >> m2;                               
}
cout << "Enter the number of hit points you spend for 3 spell: ";
cin >> h3;
while  (h3 < 0 || h3 > 1000000000000LL) {
    cout << "Invalid number of hit points you spend for 3 spell: \n";
    cout << "Enter the number of hit points you spend for 3 spell: ";
    cin >> h3;                               
}
cout << "Enter the number of mana you spend for 3 spell: ";
cin >> m3;
while  (m3 < 0 || m3 > 1000000000000LL) {
    cout << "Invalid number of mana you spend for 3 spell: \n";
    cout << "Enter the number of mana you spend for 3 spell: ";
    cin >> m3;                               
}
if (h1 > 0 && m1 > 0) {
     cout << "NO"; 
} else if (h2 > 0 && m2 > 0) {
     cout << "NO";
} else if (h3 > 0 && m3 > 0) {
     cout << "NO";
} else if (H>0 && M>0) {
    cout << "YES"; 
    } else {
    cout << "NO"; }
    return 0;
}




