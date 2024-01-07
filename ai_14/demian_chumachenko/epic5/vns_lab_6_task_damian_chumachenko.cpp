#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main() {
    char str[256];
    char *word = nullptr;
    int max = 0;
    map<string, int> wordCounts;

    cin.getline(str, 256, '.');

    char *token = strtok(str, " ");

    while (token != nullptr) {
        
        wordCounts[token]++;

        if (wordCounts[token] > max) {
            max = wordCounts[token];
            word = token;
        }

        token = strtok(nullptr, " ");
    }

    cout <<  word;
   
    return 0;
}
