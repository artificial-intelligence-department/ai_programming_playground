#include <iostream>
#include <cstring>
#include <cctype>
#include <string>


const int MAX_LENGTH = 255;


using namespace std;


bool isIdentifier(const char* word) {
    if (!isalpha(word[0]) && word[0] != '_') {
        return false;
    }


    for (int i = 1; i < strlen(word); ++i) {
        if (!isalnum(word[i]) && word[i] != '_') {
            return false;
        }
    }


    return true;
}


void delete_non_identifiers(char* str) {
    char* token = strtok(str, " ");
    string result;


    while (token != nullptr) {
        if (isIdentifier(token)) {
            result += token;
            result += ' '; 
        }


        token = strtok(nullptr, " ");
    }


    
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }


    
    strcpy(str, result.c_str());
}


int main() {
    char str[MAX_LENGTH];


    cout << "Enter a string (up to 255 characters): ";
    cin.getline(str, MAX_LENGTH);


    delete_non_identifiers(str);


    cout << "Output string only with identifiers: " << str;


    return 0;
}
