#include <iostream>
using namespace std;
int main()
{
    int n, m;

    cin >> n;
    cin >> m;

    cout << " \n The value of the expression n---m = " << (n- --m)<<endl;
    cin >> n;
    cin >> m;
    
    cout << " \n  m--<n = " << (m--<n) <<endl<<m << endl;
    cin >> n;
    cin >> m;

    cout << " \n  n++>m = " << (n++>m) << endl << n << endl;
}


