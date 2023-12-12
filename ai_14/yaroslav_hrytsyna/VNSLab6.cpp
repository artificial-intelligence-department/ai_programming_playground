#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    char line[256];
    std::string sw;

    cout << "Enter a line of text: ";
    fgets(line, sizeof(line), stdin);

    char* word = strtok(line, " ");

    while(word != NULL)
    {
        string sw = word;
        std::sort(sw.begin(), sw.end());
        cout << sw << " ";
        word = strtok(NULL, " ");
    }


    return 0;
}