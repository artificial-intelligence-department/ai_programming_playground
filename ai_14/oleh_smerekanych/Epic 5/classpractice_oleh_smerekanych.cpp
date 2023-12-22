#include <stdio.h>
#include <stdlib.h>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(char *name, char *content) {
    if (name == NULL || content == NULL) {
        return Failure;
    }

    FILE *file = fopen(name, "w");

    if (file == NULL) {
        return Failure;
    }

    fprintf(file, "%s", content);

    if (fclose(file) == EOF) {
        return Failure;
    }

    return Success;
}

int main() {
    char fileName[50];
    char content[100];

    printf("Enter the file name: ");
    scanf("%s", fileName);

    printf("Enter the content: ");
    scanf("%s", content);

    FileOpResult result = write_to_file(fileName, content);

    if (result == Success) {
        printf("File created and content written successfully.\n");
    } else {
        printf("Failed to create file or write content.\n");
    }

    return 0;
}
