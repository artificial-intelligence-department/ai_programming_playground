#include <iostream>
#include <string>
using namespace std;

string compressStr(const string& s) {
    string result;
    for (int i = 0; i < s.size(); ) {
        char curCh = s[i];
        int count = 0;
        while (i < s.size() && s[i] == curCh) {
            ++count;
            ++i;
        }
        result += curCh;
        if (count > 1) {
            result += to_string(count);
        }
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << compressStr(s) << endl;
    return 0;
}
