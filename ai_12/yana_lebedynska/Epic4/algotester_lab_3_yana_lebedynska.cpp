#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    long n = S.size();
    string compressedS;

    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (i < n - 1 && S[i] == S[i + 1]) 
        {
            count++;
            i++;
        }
        compressedS += S[i];
        if (count > 1) 
        {
            compressedS += to_string(count);
        }
    }

    cout << compressedS << endl;

    return 0;
}
