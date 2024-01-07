#include <iostream>
#include <cstring>
using namespace std;

int Aword(const char* inputString) {
    int count = 0;

    //strtok розділення рядка на слова
    char* token = strtok(const_cast<char*>(inputString), " ");
    while (token != nullptr) {

        if (token[0] == 'a' or token[0] == 'A') {
            count++;
        }
        token = strtok(nullptr, " ");

    }

    return count;
}

int main() {
    const int maxLength = 255;
    char inputString[maxLength];

    cout << "Enter your text: ";
    gets(inputString);

    int result = Aword(inputString);

    cout << result  << " words begin with letter \"a\" \n";

    return 0;
}