#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n , m, result1;
    bool check2 = true;
    bool check3 = true;
    cout << "Enter n:";
    cin >> n;

    cout << "Enter m:";
    cin >> m;

    result1 = ++n*++m;
    cout << "++n*++m= " << result1 << endl;

    check2 = m++<n; 
    if (check2 == 0)
        cout << "m++<n=False"<< endl;
    else
        cout << "m++<n=True"<< endl;

    check3 = n++>m;
    if (check3 == 0)
        cout << "n++>m=False"<< endl;
    else
        cout << "n++>m=True"<< endl;

    return 0;
}