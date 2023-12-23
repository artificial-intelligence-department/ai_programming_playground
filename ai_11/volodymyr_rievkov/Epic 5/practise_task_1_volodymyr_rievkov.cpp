#include<iostream>
using namespace std;

const char* file_name = "text.txt";

enum FileResult
{
    Success,
    Failure
};

void set_content(string& content)
{
    cout << "Enter content to write to file: ";
    getline(cin, content);
}

FileResult write_to_file(const char* file_name, const char* content)
{
    FILE* file = fopen(file_name, "w");
    if(file == nullptr)
    {
        return Failure;
        cout << "Error: Content writing is failed" << endl;
    }
    else
    {
        if(fprintf(file, content) < 0)
        {
            cout << "Error: File writing is failed" << endl;
            return Failure;
        }
        if(fclose(file) != 0)
        {
            cout << "Error: File closing is failed" << endl;
            return Failure;
        }
        return Success;
    }
}

void print_file(const char* file_name)
{
    FILE* file = fopen(file_name, "r");
    if(file != nullptr)
    {
        cout << endl << "File content: " << endl << endl;
        char buffer[1024];
        while(fgets(buffer, sizeof(buffer), file))
        {
            cout << buffer;
        }
        cout << endl << endl;
        fclose(file);
    }
    else
    {
        cout << "Error: File  reading is failed" << endl;
    }
}

int main()
{
    string content;
    set_content(content);
    if(write_to_file(file_name, content.c_str()) == Success)
    {
        cout << endl << "Content is successfully written" << endl;
        print_file(file_name);
    }
}