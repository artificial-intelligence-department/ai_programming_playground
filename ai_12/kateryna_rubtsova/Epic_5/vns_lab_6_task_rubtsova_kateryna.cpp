#include <iostream>
#include <cctype>
#include <cstring> 

using namespace std;

int main() {
    const int maxSize = 255;
    char inputString[maxSize];
    cout<<"Введіть ряд: ";

    cin.getline(inputString, maxSize); 

    char letters[maxSize]; 
    char digits[maxSize]; 

    for (int i = 0; inputString[i] != '\0'; ++i) {
        if (isalpha(inputString[i])) {
            strncat(letters, &inputString[i], 1);
        } else if (isdigit(inputString[i])) {
            strncat(digits, &inputString[i], 1);
        }
    }

    cout << letters << digits;
    
    return 0;
}