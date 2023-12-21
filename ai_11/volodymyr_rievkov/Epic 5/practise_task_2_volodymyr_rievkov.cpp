#include<iostream>
#include<string.h>
using namespace std;

const char* file_from_name = "file_from.txt";
const char* file_to_name = "file_to.txt";

enum FileResult
{
    Success,
    Failure
};

FileResult copy_file(const char* file_from_name, const char* file_to_name)
{
    FILE* file_from = fopen(file_from_name, "r");
    FILE* file_to = fopen(file_to_name, "w");
    if(file_from == nullptr && file_to == nullptr)
    {
        cout << "Error: Files opening is failed" << endl;
        return Failure;
    }
    if(file_from == nullptr)
    {
        cout << "Error: " << file_from_name << " opening is failed" << endl;
        return Failure;
    }
    if(file_to == nullptr)
    {
        cout << "Error: " << file_to_name << " opening is failed" << endl;
        return Failure;
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), file_from))
    {
        if(fprintf(file_to, buffer) < 0)
        {
            cout << "Error: File copying is failed" << endl;
            return Failure;
        }
    }
    int close_f1 = fclose(file_from);
    int close_f2 = fclose(file_to);
    if(close_f1 != 0 && close_f2 != 0)
        {
            cout << "Error: Files closing is failed" << endl;
            return Failure;
        }
    if(close_f1 != 0)
        {
            cout << "Error: " << file_from_name << "closing is failed" << endl;
            return Failure;
        }
    if(close_f2 != 0)
        {
            cout << "Error: " << file_to_name << "closing is failed" << endl;
            return Failure;
        }
    return Success;
}

void print_file(const char* file_name)
{
    FILE* file = fopen(file_name, "r");
    if(file != nullptr)
    {
        cout << "File content: " << endl << endl;
        char buffer[1024];
        while(fgets(buffer, sizeof(buffer), file))
        {
            cout << buffer;
        }
        cout << endl;
        fclose(file);
    }
    else
    {
        cout << "Error: File  reading is failed" << endl;
    }
}

int main()
{
    if(copy_file(file_from_name, file_to_name) == Success)
    {
        cout << endl << "From ";
        print_file(file_from_name);
        cout << endl << "To ";
        print_file(file_from_name);
    }
}