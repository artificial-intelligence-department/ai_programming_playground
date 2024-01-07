#include <iostream>
#include <string>
using namespace std;
int main() {
    char s[255];
    gets(s);
    bool out = true;
    string word;
    int size = 0;
    for (char i : s) size++;
    for (char i : s) {
        word.push_back(i);
        switch (i) {
            case 'a':case 'e':case 'i':case 'o':case 'u':
                out = false;
                break;
            case ' ':
                if (out) cout << word;
                word = "";
                out = true;
                break;
            default:
                if (i == s[size-1] && out) {
                    cout << word;
                    out = false;
                }
                break;
        }
    }
    return 0;
}
