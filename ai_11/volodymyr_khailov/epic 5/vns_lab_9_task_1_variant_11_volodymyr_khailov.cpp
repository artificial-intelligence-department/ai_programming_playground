#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 255

int main() {
    FILE *F1, *F2;
    char buf[MAXLINE];
    char shortestWord[MAXLINE];
    int shortestLine = -1;
    int currentLine = 0;
    
    // Відкрити файл F1 для читання
    F1 = fopen("F1.txt", "r");
    if (F1 == NULL) {
        // Якщо файл не існує, створити новий
        printf("File F1.txt not exist. Creating new...\n");
        F1 = fopen("F1.txt", "w");
        if (F1 == NULL) {
            perror("Failed to create file F1:");
            return 1;
        }
        // Записати приклад данних в файл F1
        fprintf(F1, "longest word.\n");
        fprintf(F1, "short line.\n");
        fprintf(F1, "Bob is here.\n");
        fprintf(F1, "well well well.\n");
        fprintf(F1, "I love Canada.\n");
        fclose(F1);

        printf("File F1.txt successfully created.\n");

        // Вихід, оскільки файл щойно був створений, і даних в ньому немає
        return 0;
    }

    // Знайти рядок із найкоротшим словом
    while (fgets(buf, MAXLINE, F1) != NULL) {
        currentLine++;
        char *word = strtok(buf, " \t\n");
        if (word != NULL && (strlen(word) < strlen(shortestWord) || shortestLine == -1)) {
            strcpy(shortestWord, word);
            shortestLine = currentLine;
        }
    }

    // Повторно встановити позицію читання в F1 в початок файлу
    rewind(F1);

    // Відкрити файл F2 для запису
    F2 = fopen("F2.txt", "w");
    if (F2 == NULL) {
        perror("Failed to open file F2");
        fclose(F1);
        return 1;
    }

    // Скопіювати рядки з F1 в F2, пропустивши рядок із найкоротшим словом
    currentLine = 0;
    while (fgets(buf, MAXLINE, F1) != NULL) {
        currentLine++;
        if (currentLine != shortestLine) {
            fputs(buf, F2);
        }
    }

    // Вивести номер рядка із найкоротшим словом
    printf("Row with the shortest word: %d\n", shortestLine);

    // Закрити файли
    fclose(F1);
    fclose(F2);

    return 0;
}
