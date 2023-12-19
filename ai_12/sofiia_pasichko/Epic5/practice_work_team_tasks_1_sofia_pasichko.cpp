#include <stdio.h>
#include <string.h>

enum FileOpResult { Success, Failure };
FileOpResult write_to_file(char *name, char *content) {
    FILE *file = fopen(name, "w");

    if (file == NULL) {
        return Failure;
    }

    fprintf(file, "%s", content);
    fclose(file);

    return Success;
}

int main() {
    char name[] = "MyNewFile.txt";
    char content[100];

    fgets(content, sizeof(content), stdin);
    FileOpResult result = write_to_file(name, content);

    if (result == Success) {
        printf("Success\n");
    } else if (result == Failure) {
        printf("Error\n");
    } 
    return 0;
}