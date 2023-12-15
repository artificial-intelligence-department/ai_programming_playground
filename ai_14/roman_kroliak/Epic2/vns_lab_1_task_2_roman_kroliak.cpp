#include <iostream>
using namespace std;
int main(){
    int n;
    int m;
    cout << "Enter n:";
    cin >> n;
    cout << "Enter m:";
    cin >> m;
    int res1;
    string res2;
    string res3;
    res1 = ++n * m;
    (++n < m) ? res2 = "true" : res2 = "false";
    (--m > m) ? res3 = "true" : res3 = "false";
    cout << "Result 1: " << res1 << endl;
    cout << "Result 2: " << res2 << endl;
    cout << "Result 3: " << res3;
    return 0;
}