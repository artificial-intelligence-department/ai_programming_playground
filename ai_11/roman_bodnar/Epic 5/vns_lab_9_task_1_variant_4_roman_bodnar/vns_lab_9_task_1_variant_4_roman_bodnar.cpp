#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int max_line_length = 256,
          ignore_lines = 4;

int main()
{
    FILE *f1 = fopen("f1.txt", "r+"),
         *f2 = fopen("f2.txt", "w+");

    if (f1 == NULL || f2 == NULL) {
        cout << "Error opening files" << endl;
        return 1;
    }

    char line[max_line_length];

    for (int i = 0; i < ignore_lines && !feof(f1); i++) {
        fgets(line, max_line_length, f1);
    }

    while (!feof(f1)) {
        fgets(line, max_line_length, f1);
        fputs(line, f2);
    }

    fclose(f1);
    fclose(f2);

    f2 = fopen("f2.txt", "r+");
    if (f2 == NULL) {
        cout << "Error opening file" << endl;
        return 1;
    }

    while (!feof(f2)) fgets(line, max_line_length, f2);

    // finds last space and returns pointer to it
    char* last_word = strrchr(line, ' ') + 1;
    cout << last_word << endl << strlen(last_word) << endl;

    fclose(f2);

    return 0;
}