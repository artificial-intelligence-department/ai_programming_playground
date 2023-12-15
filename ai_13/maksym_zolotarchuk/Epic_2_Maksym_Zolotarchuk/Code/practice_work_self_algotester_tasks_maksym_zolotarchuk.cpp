#include <iostream>
#include <cmath>
using namespace std;

int main() {
int rm,sm,pm; // r - камінь, s - ножиці, p - папір
cin >> rm >> sm >> pm;
int rz,sz,pz;
cin >> rz >> sz >> pz;

int n = min(rm, sz) + min(pm,rz) + min(sm,pz);
cout << n;

return 0;
}
