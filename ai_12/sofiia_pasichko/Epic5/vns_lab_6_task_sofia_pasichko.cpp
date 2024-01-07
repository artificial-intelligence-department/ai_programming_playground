#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>

void sortDigitsInWord(char word[]) {
int a = strlen(word);
for (int i = 0; i < a - 1; i++) {
    for (int j = 0; j < a - i - 1; j++) {
        if (isdigit(word[j]) && isdigit(word[j + 1]) && word[j] < word[j + 1]) {
            char b = word[j];
            word[j] = word[j + 1];
            word[j + 1] = b;
        }
    }
}
} // Бульбашкове сортування

void sortWordsInString(char str[]) {
    char *result = strdup(str); 
    char *token;
    token = strtok(result, " ");

    while (token != NULL) {
        sortDigitsInWord(token);
        printf("%s ", token);  
        token = strtok(NULL, " ");
    }
    free(result); 
}
int main() {
    char s[256];
    gets_s(s, 256);
    sortWordsInString(s);
    printf("\n");

    return 0;
}