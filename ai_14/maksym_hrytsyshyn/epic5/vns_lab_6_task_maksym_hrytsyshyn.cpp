#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

const int amount = 255;
int main() {
    char str[amount];
    cout << "Enter a string: ";
    cin.getline(str, amount, '.');

    string line;
    for (int i = 0; i < str[i] != '\0'; i++){
        if (isalpha(str[i])){
           line += tolower(str[i]);
        }  
    }
    
    sort(line.begin(), line.end());

    cout << "Updated string: " << line << endl;
}