#include <iostream>
using namespace std;
int main() {
    long long h1, h2, h3, h4;
    long long del1, del2, del3, del4;
    string result = "YES";
    cin >> h1 >> h2 >> h3 >> h4;
    cin >> del1 >> del2 >> del3 >> del4;
    if (del1 > h1 || del2 > h2 || del3 > h3 || del4 > h4) {
        result = "ERROR";
        cout << result;
        return 0;
    }
    if (h1 < 0 || h2 < 0 || h3 < 0 || h4 < 0) {
        result = "NO";
        cout << result;
        return 0;
    }
    h1 -= del1;
    if (h1 == 0 || h2 / h1 >= 2 || h3 / h1 >= 2 || h4 / h1 >= 2) {
        result = "NO";
    }
    h2 -= del2;
    if (h2 == 0 || h1 / h2 >= 2 || h3 / h2 >= 2 || h4 / h2 >= 2) {
        result = "NO";
    }
    h3 -= del3;
    if (h3 == 0 || h1 / h3 >= 2 || h2 / h3 >= 2 || h4 / h3 >= 2) {
        result = "NO";
    }
    h4 -= del4;
    if (h4 == 0 || h1 / h4 >= 2 || h3 / h4 >= 2 || h2 / h4 >= 2) {
        result = "NO";
    }
    cout << result;
    return 0;
}

