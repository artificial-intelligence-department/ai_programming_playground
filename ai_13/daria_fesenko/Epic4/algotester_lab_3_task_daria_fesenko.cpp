#include <iostream>
#include <string>
using namespace std;


int main() {
    string S;
    cin >> S;

    int n = S.length();
    for (int i = 0; i < n; ++i) {
        cout << S[i];
       
       
        int count = 1;
        while (i < n - 1 && S[i] == S[i + 1]) {
            ++count;
            ++i;
        }
        if (count > 1) {
            cout << count;
        }
    }

    return 0;
}
