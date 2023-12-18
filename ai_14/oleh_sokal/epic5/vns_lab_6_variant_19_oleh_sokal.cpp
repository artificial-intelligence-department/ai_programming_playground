#include <stdio.h>
#include <string.h>
#include <ctype.h>


void identificatorOrNot(char str[]) {
    char *token;


    token = strtok(str, " ");
    while (token != NULL) {
        int isValid = 1;
        for (int i = 0; i < strlen(token); ++i) {
            if (!isalnum(token[i]) && token[i] != '_') {
                isValid = 0;  
                break;
            }
        }
        if (isValid && (isdigit(token[0]) || token[0] == '-')) {
            isValid = 0;  
        }
        if (isValid) {
            printf("Токен '%s' є допустимим ідентифікатором\n", token);
        }
        token = strtok(NULL, " ");
    }
}


int main() {
    char str[] = "valid _valid_ invalid-s valid123 _Valid 1invalid ";
    identificatorOrNot(str);


    return 0;
}
