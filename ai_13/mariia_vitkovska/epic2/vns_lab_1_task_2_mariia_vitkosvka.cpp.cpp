#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n, m, result1;
    cout << "enter n:" << endl;
    cin >> n;
    cout << "enter m:" << endl;
    cin >> m;
    
    result1 = ++n*++m;

    cout << "++n*++m = " << result1 << endl;
    
    if (n++ > m) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    if (m++ < n) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0; 
}