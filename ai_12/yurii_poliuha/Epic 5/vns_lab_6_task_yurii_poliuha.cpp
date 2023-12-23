#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int N = 255;
    char sentence[N];
    cin.getline(sentence, N);

    string str;
    char divider[] = " ";
    int CountOfWords = 0;
    char *words = strtok(sentence, divider);

    while(words != nullptr) {
        CountOfWords++;
        if(CountOfWords % 2 == 1) str = str + words + " ";
        words = strtok(nullptr, " ");
    }
    cout << str << endl;

    return 0;
}