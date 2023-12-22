#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 255

int main() {
    FILE *file1, *file2;
    char buffer[MAXLENGTH];
    char minWord[MAXLENGTH];
    int minLine = -1;
    int curLine = 0;
    
    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        printf("File file1.txt does not exist. Creating new...\n");
        file1 = fopen("file1.txt", "w");
        if (file1 == NULL) {
            perror("Failed to create file file1:");
            return 1;
        }
        fprintf(file1, "Sunny day.\n");
        fprintf(file1, "Green tree.\n");
        fprintf(file1, "Happy cat.\n");
        fprintf(file1, "Tasty coffee.\n");
        fclose(file1);


        printf("File file1.txt successfully created.\n");

        return 0;
    }

    while (fgets(buffer, MAXLENGTH, file1) != NULL) {
        curLine++;
        char *word = strtok(buffer, " \t\n");
        if (word != NULL && (strlen(word) < strlen(minWord) || minLine == -1)) {
            strcpy(minWord, word);
            minLine = curLine;
        }
    }

    rewind(file1);

    file2 = fopen("file2.txt", "w");
    if (file2 == NULL) {
        perror("Failed to open file file2");
        fclose(file1);
        return 1;
    }

    curLine = 0;
    while (fgets(buffer, MAXLENGTH, file1) != NULL) {
        curLine++;
        if (curLine != minLine) {
            fputs(buffer, file2);
        }
    }

    printf("Row with the shortest word: %d\n", minLine);

    fclose(file1);
    fclose(file2);

    return 0;
}
