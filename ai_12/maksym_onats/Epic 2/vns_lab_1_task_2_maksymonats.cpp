#include <iostream>
#include <cmath>

using namespace std;

int main() {
int n, m;
    cout << "Enter value n:" << '\n';
    cin>>n;

    cout << "Enter value m:" << '\n';
    cin >> m;

        cout << "1):" << ( m + --n ) << '\n';
        cout << "2):" << ( m++ < ++n )<< '\n';
        cout << "3):" << ( n-- < --m ) << '\n';
    
    
    return 0;

}