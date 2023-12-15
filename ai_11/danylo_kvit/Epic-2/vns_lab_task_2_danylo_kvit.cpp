#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    cout << (n++)-(m) << '\n';
    cout << ((m--)>n) << '\n';
    cout << ((n--)>m);
    return 0;
}