#include <iostream>
#include <cstring>

using namespace std;

bool correctWord(const char * word, int size);

int main(){
    char line[256];

    cout << "Enter a string:" << endl;
    cin.getline(line, sizeof(line));

    char * word;
    word = strtok(line, " ");

    while(word != NULL){
        if (correctWord(word, strlen(word))){
            cout << word << " ";
        }
        word = strtok(NULL, " ");
    }

    return 0;
}

bool correctWord(const char * word, int size){
    for(int i = 0; i < size; i++){
        if(!(isdigit(word[i]) || isalpha(word[i])))
            return false;
    }
    return true;
}