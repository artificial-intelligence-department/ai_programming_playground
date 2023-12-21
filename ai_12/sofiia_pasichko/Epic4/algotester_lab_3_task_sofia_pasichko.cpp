#include <iostream>
#include <string>
using namespace std;

string compressedS(string s) {
int n=1;
string result;

for (int i = 0; i<s.length(); i++) {
    while (s[i]==s[i+1]) {
        n++;
        i++;
    }

    if (n == 1) {
        result = result + s[i];
    } else {
        result = result + s[i] + to_string(n);
    }
    n = 1;
}
return result;
}

int main() {
    string s;
    cin >> s;
    cout << compressedS(s);
    return 0;
}

