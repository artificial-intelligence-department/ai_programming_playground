#include <stdio.h>
#include <string.h>

int main () {
    char sentence[30];
    int words;

    printf ("Введіть речення ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int s =0; s < strlen(sentence); s++ ){
        if (sentence [s] != ' ' && (sentence[s+1] == ' ' || sentence[s+1] == '\0')) {
               words++;
        }
    }

printf ("Кількість слів в рядку %d", words);
return 0;
    
}