#include <stdio.h>
#include <string.h>


int count_words(char* str, char* separators) {
    int count = 0;

    char* token = strtok(str, separators);
    while (token != NULL) {
        count++;
        token = strtok(NULL, separators);
    }

    return count;
}

int main() {
    char* seps = " ,.";

    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    int count = count_words(str, seps);
    printf("Number of words: %d\n", count);

    return 0;
}
