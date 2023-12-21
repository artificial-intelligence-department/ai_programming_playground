#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


void stringCheck(char *s) {
    char str[256] = "";
    char *strPtr = str;

    for (char *i = s; *i != '\0'; i++) {
        if (*i == ' ' || *i == '.') {
            bool isAlpha = false, isDigit = false;
            for (char *j = str; *j != '\0'; j++) {
                if (isdigit(*j)) {
                    isDigit = true;
                } else if(isalpha(*j)){
                    isAlpha = true;
                        }
                    }
            if (isDigit == true && isAlpha == true){
                printf("%s ", str);
            }
            str[0] = '\0';
            strPtr = str;
        } else {
            *strPtr = *i;
            *(strPtr + 1) = '\0';
            strPtr++;
        }
    }

    bool isAlpha = false, isDigit = false;
    for (char *j = str; *j != '\0'; j++) {
        if (isdigit(*j)) {
            isDigit = true;
        } else if(isalpha(*j)){
            isAlpha = true;
        }
    }
    if (isDigit == true && isAlpha == true){

        printf("%s ", str);
    }

}

int main() {
    char s[256];
    gets(s);
    stringCheck(s);

    return 0;
}
