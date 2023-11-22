#include <iostream>
#include <cmath>

using namespace std;

int main() {
int n, m;

cout << "enter m" << endl;
cin >> m;
cout << "enter n" << endl;
cin >> n;

cout << "++n*++m = " << ++n*++m << endl;

if (m++<n) {
    cout << "m++<n = true" << endl;
}
else cout << "m++<n = false" << endl;

if (n++>m) {
    cout << "n++>m = true" << endl;
}
else cout << "n++>m = false" << endl;
    return 0;
}