#include <iostream>
#include <cstring>

using namespace std;

void MyFunc(char str[]) {
    char* temp;
    char* nextToken = NULL;
    char delimiters[] = " ";
    temp = strtok_s(str, delimiters, &nextToken);
    char* firstWord = temp;

    while (temp != NULL) {
        if (strcmp(temp, firstWord) == 0) {
            cout << firstWord << " ";
        }
        temp = strtok_s(NULL, delimiters, &nextToken);
    }
}

int main() {
    char s[256] = "This program work well, because This program was updated";
    MyFunc(s);
    return 0;
}