#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
    char str[256];
    cout << "Enter string: ";
    gets(str);

    char *word = strtok(str, " ");

    char *minWord = word, *maxWord = word;

    while(word != NULL) {
        if(strlen(word) < strlen(minWord)) {
            minWord = word;
        }
        if(strlen(word) > strlen(maxWord)) {
            maxWord = word;
        }
        word = strtok(NULL, " ");
    }

    cout << "Shortest word: " << minWord << endl;
    cout << "Longest word: " << maxWord << endl;

    return 0;
}
