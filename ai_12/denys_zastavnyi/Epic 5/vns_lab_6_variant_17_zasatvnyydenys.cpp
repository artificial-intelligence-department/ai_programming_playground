#include <iostream>
#include <cstring>
#include <algorithm>


int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    using namespace std;

    char input[256];
    char *words[256];  
    char *token;

    cout << "Enter a string: \n";
    cin.getline(input, sizeof(input));

    int wordCount = 0;
    token = strtok(input, " ");
    while (token != NULL) {
        words[wordCount] = new char[strlen(token) + 1];
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }

   
    qsort(words, wordCount, sizeof(char *), compareStrings);

    cout << "Sorted words: ";
    for (int i = 0; i < wordCount; i++) {
        if (isalpha(words[i][0])) {  
            cout << words[i] << " ";
        }
        delete[] words[i];
    }

    return 0;
}
