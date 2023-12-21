#include <iostream>
#include <cstring>
using namespace std;

enum FileOpResult {
    INDETERMINATE = 0,
    SUCCESS,
    FAILURE,
    FILE_NOT_FOUND,
};

FileOpResult write_to_file(const char *name, const char *content);
FileOpResult copy(const char *src_path, const char *dest_path);

int main() {
    int choice = 0;

    do {
        cout << "1. Write to file\n"
                "2. Copy file\n"
                "3. Exit\n"
                "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                char name[256];
                string content;

                cout << "Enter file name: ";
                cin >> name;

                cout << "Enter content: ";
                cin.ignore(INT_MAX, '\n');
                getline(cin, content);

                if (write_to_file(name, content.c_str()) == SUCCESS) {
                    cout << "Successfully written to file" << endl;
                } else {
                    cout << "Failed to write to file" << endl;
                }

                break;
            }
            case 2: {
                char src_path[256];
                char dest_path[256];

                cout << "Enter source file path: ";
                cin >> src_path;

                cout << "Enter destination file path: ";
                cin >> dest_path;

                if (copy(src_path, dest_path) == SUCCESS) {
                    cout << "Successfully copied file" << endl;
                } else {
                    cout << "Failed to copy file" << endl;
                }

                break;
            }
            case 3: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    } while (choice != 3);

    return 0;
}

FileOpResult write_to_file(const char *name, const char *content) {
    FILE* file = fopen(name, "w+");

    if (file == nullptr) {
        return FILE_NOT_FOUND;
    }

    size_t len = strlen(content);
    fwrite(content, sizeof(char), len, file);

    return fclose(file) == 0 ? SUCCESS : FAILURE;
}

FileOpResult copy(const char *src_path, const char *dest_path) {
    FILE *src_file = fopen(src_path, "r");
    FILE *dest_file = fopen(dest_path, "w+");

    if (src_file == nullptr || dest_file == nullptr) {
        return FILE_NOT_FOUND;
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0)
        fwrite(buffer, sizeof(char), bytes_read, dest_file);

    return fclose(src_file) == 0 && fclose(dest_file) == 0
           ? SUCCESS
           : FAILURE;
}