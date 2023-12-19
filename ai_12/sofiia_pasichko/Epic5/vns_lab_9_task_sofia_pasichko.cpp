#include <stdio.h>
#include <string.h>
#include <cctype>

enum FileOpResult { Success, Failure };
FileOpResult processing(char *file_from, char *file_to, char start_char, int n1, int n2) {

FILE *file1 = fopen(file_from, "r");
FILE *file2 = fopen(file_to, "w");

if (file_from == NULL || file_to == NULL) {
    return Failure;
}
char line[100];
int current_line=0;

while (fgets(line, 100, file1) != NULL) {
current_line++;
if (line[0] == start_char && current_line>n1 && current_line<n2) {
    fputs(line, file2);
}
}
fclose(file1);
fclose(file2);
return Success;
}

int consonants(char* file_to) {
FILE* file2 = fopen(file_to, "r");

if (file2 == NULL) {
    return -1;
}

char line[100];
int current_line = 0;
int maxConsonantCount = 0;
int rowWithMaxConsonants = 0;

while (fgets(line, sizeof(line), file2) != NULL) {
    int consonantCount = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (isalpha(line[i]) && !strchr("AEIOUaeiou", line[i])) {
            consonantCount++;
        }
    }

    if (consonantCount > maxConsonantCount) {
        maxConsonantCount = consonantCount;
        rowWithMaxConsonants = current_line;
    }
    current_line++;
}
    fclose(file2);
    return maxConsonantCount;
}



int main() {
char file_from[] = "file_from.txt";
char file_to[] = "file_to.txt";
char start_char='A';

FileOpResult result = processing(file_from, file_to, start_char, 2, 4);
if (result == Success) {
    printf("Success\n");
} else if (result == Failure) {
    printf("Error\n");
}
int countedConsonants=consonants(file_to);
printf("%d", countedConsonants);
return 0;
}