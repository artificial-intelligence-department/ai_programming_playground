#include <iostream>

using namespace std;
int main()
{
    int m;
    int n;
    cout << "m = ";  
    cin >> m;
    cout << "n = ";
    cin >> n;
    int a = n++ * m;
    bool b = n++ < m;
    bool c = (m--) > m;
    cout << boolalpha;
    cout << a << endl;
    cout << b << endl;
    cout << c;
}