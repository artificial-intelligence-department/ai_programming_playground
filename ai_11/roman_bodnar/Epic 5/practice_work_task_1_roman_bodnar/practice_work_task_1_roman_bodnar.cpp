#include <iostream>
using namespace std;

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult write_to_file(char *name, char *content);
FileOpResult copy_file(char *file_from, char *file_to);

int main()
{
    char name[256], content[256];
    cout << "Enter file name: ";
    fgets(name, 255, stdin);
    cout << "Enter file content: ";
    fgets(content, 255, stdin);

    FileOpResult result1 = write_to_file(name, content);
    if (result1 == FileOpResult::Failure)
    {
        cerr << "Error creating file" << endl;
        return 1;
    }
    cout << "File created successfully" << endl;

    char file_from[256], file_to[256];
    cout << "Enter file to copy from: ";
    fgets(file_from, 255, stdin);
    cout << "Enter file to copy to: ";
    fgets(file_to, 255, stdin);

    FileOpResult result2 = copy_file(file_from, file_to);
    if (result2 == FileOpResult::Failure)
    {
        cerr << "Error copying file" << endl;
        return 1;
    }

    return 0;
}

FileOpResult write_to_file(char *name, char *content)
{
    FILE *f = fopen(name, "w+");
    if (f == NULL)
    {
        return FileOpResult::Failure;
    }
    fputs(content, f);
    fclose(f);
    return FileOpResult::Success;
}

FileOpResult copy_file(char *file_from, char *file_to)
{
    FILE *src = fopen(file_from, "r"),
         *dst = fopen(file_to, "w+");

    if (src == NULL || dst == NULL)
    {
        return FileOpResult::Failure;
    }

    char line[256];
    while (!feof(src))
    {
        fgets(line, 256, src);
        fputs(line, dst);
    }

    fclose(src);
    fclose(dst);

    return FileOpResult::Success;
}
