#include <iostream>
using namespace std;
int main() {
cout << boolalpha;

int n, m;
cout << "Enter n and m: ";
cin >> n >> m;

    cout << "++n*++m: " << ++n*++m << endl;
	cout << "m++<n: "	<< (m++<n) << endl;
	cout << "n++>m: "	<< (n++>m) << endl;
return 0;
}

