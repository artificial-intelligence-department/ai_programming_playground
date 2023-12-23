#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char s[256];
    gets(s);

    int length = strlen(s);
    for (int i = 0; i < length / 2; ++i) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }

    puts(s);

    return 0;
}