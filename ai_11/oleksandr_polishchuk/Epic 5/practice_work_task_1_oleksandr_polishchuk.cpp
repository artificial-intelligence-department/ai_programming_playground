#include <iostream>
#include <string>

using namespace std;

#define maxName 64
#define maxContent 512

enum FileOpResult { Success, Opening_failure, Closing_failure };

FileOpResult write_to_file(const char* name, const char* content) {
    FILE* f;
    f = fopen(name, "w");

    if (f == nullptr) {
        return Opening_failure;
    }

    if (content != nullptr) {
        fputs(content, f);
    }

    if (fclose(f) != 0) {
        return Closing_failure;
    }

    return Success;
}

int main() {
    string content, name;

    cout << "Введіть назву файлу з розширенням : ";
    getline(cin, name);
    cout << "Введіть рядок: ";
    getline(cin, content);

    FileOpResult result = write_to_file(name.c_str(), content.c_str());

    if (result == Success) 
    {
        cout << "Success";
    } 
    else if (result == Opening_failure) 
    {
        cerr << "Opening_failure";
    } 
    else if (result == Closing_failure)
    {
        cerr << "Closing_failure";
    }

    return 0;
}
