#include <iostream>
    
using namespace std;

int m;
int n;

int main()
{
    cin >> m;
    cin >> n;

    cout << n++*m << endl;

    bool a = n++<m;
    cout << a << endl;
    
    int c = m--;

    bool b = c > m;
    cout << b << endl;

    return 0;
}
