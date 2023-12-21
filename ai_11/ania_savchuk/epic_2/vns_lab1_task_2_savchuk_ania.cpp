#include <iostream>
using namespace std;
 
int main() {
    int m, n;
    cout << "Enter n and m: ";
    cin >> m >> n;
    cout << boolalpha;
    cout << "m+--n: " << m+--n << endl;
    cout << "m++<++n: " << (m++<++n) << endl;
    cout << "n--<--m: " << (n--<--m) << endl;
 
    return 0; 
}