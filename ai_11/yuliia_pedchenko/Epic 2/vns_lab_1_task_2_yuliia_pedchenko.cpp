#include <iostream>
#include <cmath>
using namespace std;

int main() {

int m, n;
cin >> m;
cout << "\n";
cin >> n;

cout << boolalpha;

cout << "--m-++n - " << (--m-++n) << "\n";
cout << "m*n<n++ - " << (m*n<n++) << "\n";
cout << "n-->m++ - " << (n--> m++) << "\n";

return 0;

}