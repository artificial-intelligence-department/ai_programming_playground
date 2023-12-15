#include <iostream>

using namespace std;

int main(){
    double n,m;
    cin >> n >> m;
    cout << m+--n << endl;
    cout << (m++<++n) << endl;
    cout << (n--<--m);
    
    return 0;
}