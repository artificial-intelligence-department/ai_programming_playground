#include <stdio.h>
#include <string.h>
#include <ctype.h>

void formattedString(char str[]) {
    char result[256] = "";
    char *token = strtok(str, " ");

    while (token != NULL) {
        int il = 0, id = 0;

        for (int i = 0; token[i] != '\0'; i++) {
            if (isalpha(token[i])) {
                il = 1;
            } else if (isdigit(token[i])) {
                id = 1;
            }
        }

        if (il && id) {
            strcat(result, token);
            strcat(result, " ");
        }

        token = strtok(NULL, " ");
    }

    strcpy(str, result);
}

int main() {
    char s[256];
    printf("Enter a string: ");
    gets(s);

    printf("Original String: %s\n", s);

    formattedString(s);

    printf("Processed String: %s\n", s);

    return 0;
}
