#include <iostream>
#include <string>
using namespace std;
int main() {
    string S;
    getline(cin, S);
    string Scompressed = "";
    int count=1;

    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == S[i + 1]) {
            count++;
        } else {
            Scompressed += S[i] + (count > 1 ? to_string(count) : "");
            count = 1;
        }
    }

    cout << Scompressed << endl;

    return 0;
}


