#include <stdio.h>
#include <string.h>

int main() {
    char s[256], pr[256];
    gets_s(s, 255);
    int letters[52] = {0};
    int abc=0;
    while (s[abc] != '.') {
        for (int j = 0; j < 26; j++) {
            if (s[abc] == (char)(j+65)) {letters[j]++;}
            if (s[abc] == (char)(j+97)) {letters[j+26]++;}
        }
        abc++;
    }
    int counter = 0;
    for (int i = 0; i<26; i++) {
        while (letters[i] !=0) {
            pr[counter]=(char)(i+65);
            --letters[i];
            ++counter;
        }
        while (letters[i+26]!=0) {
            pr[counter]=(char)(i+97);
            --letters[i+26];
            ++counter;
        }
    }
    pr[counter] = '.';
    pr[counter+1] = '\0';
    puts(pr);
    return 0;
}