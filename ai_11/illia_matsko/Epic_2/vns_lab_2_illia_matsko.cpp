#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;

    cout << "n+++m: " << n+++m << endl;
    cout << "m--<n: " << ((m--<n)==1 ? "true" : "false") << endl;
    cout << "n++>m: " << ((n++>m)==1 ? "true" : "false") << endl;

    return 0;
}