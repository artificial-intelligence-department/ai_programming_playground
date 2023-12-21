#include <iostream>

using namespace std;
int main() {

int m, n, s;
cout << "Введи своє значення m та n\n";
cin >> m >> n;
s = m + --n;
cout << "m + --n = " << s << endl;
cout << "m++ < ++n: " << (m++ < ++n) << endl;
cout << "n-- < --m: " << (n-- < --m) << endl;

    return 0;
}
