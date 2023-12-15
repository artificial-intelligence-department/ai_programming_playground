#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    char S[256];

    puts( "Enter a text ending with a dot:" );
    gets(S); 

    int len = strlen(S);
    for (int i = 0; i < len; ++i) {
        if (S[i] == '.') {
            S[i] = '\0'; 
            break;
        }
    }

    sort(S, S + strlen(S), [](char a, char b) {
        return tolower(a) < tolower(b);
    });

    puts(S); 
    return 0;
}
