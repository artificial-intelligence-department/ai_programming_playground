#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char s[256];
    gets(s);

    string curWord;
    int numsFrequency = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != ' ') {
            if (isdigit(s[i])){
                numsFrequency += 1;
                curWord += s[i];
            }
            else {
                curWord += s[i];
            }
        }
        else {
            if (numsFrequency == 1) {
                cout << curWord << endl;
            }
            curWord = "";
            numsFrequency = 0;
        }
    }

    return 0;
}
