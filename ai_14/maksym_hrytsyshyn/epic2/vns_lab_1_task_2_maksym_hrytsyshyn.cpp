#include <iostream>

using namespace std;

int main () {
    float m;
    float n;

    cout << "Enter the value of m: " << endl;
    cin >> m;
    cout << "Enter the value of n: " << endl;
    cin >> n;

    float result = m-++n;
    cout << "1) The result of the operation: " << result << endl;

    if (++m>--n) {
        cout << "2) True" << endl;
    } else {
        cout << "2) False" << endl;
    }

    if (--n<m++) {
        cout << "3) True" << endl;
    } else {
        cout << "3) False" << endl;
    }
    
    return 0;
}