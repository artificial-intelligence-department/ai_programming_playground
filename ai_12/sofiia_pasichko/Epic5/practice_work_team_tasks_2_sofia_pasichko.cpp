#include <stdio.h>
#include <string.h>

enum FileOpResult { Success, Failure };
FileOpResult copy_file(char *file_from, char *file_to) {

FILE *file1 = fopen(file_from, "r");
FILE *file2 = fopen(file_to, "w");

if (file_from == NULL || file_to == NULL) {
    return Failure;
}
int process;

while ((process = fgetc(file1)) != EOF) {
    fputc(process, file2);
}

fclose(file1);
fclose(file2);
return Success;
}
int main() {
char file_from[] = "file_from.txt";
char file_to[] = "file_to.txt";

FileOpResult result = copy_file(file_from, file_to);
if (result == Success) {
    printf("Success\n");
} else if (result == Failure) {
    printf("Error\n");
}
return 0;
}