#include <iostream>
#include <cmath>
using namespace std;

int main() {

int m, n;
cin >> m;
cout << "\n";
cin >> n;

cout << boolalpha;
cout << "++n*++m - " << (++n*++m) <<endl;
cout << "m++<n - " << (m++<n) << endl;
cout << "n++>m - " << (n++>m) << endl;

return 0;

}