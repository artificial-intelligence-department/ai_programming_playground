// Надрукувати всі слова, що співпадають з першим
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line, first;

    cout << "enter the line: " << endl;

    getline(cin, line);

    
    istringstream iss(line);    // Використовуємо, щоб розбити строку на слова
    
    iss >> first; // Контейнер для зберігання першого слова
    cout << "words, similar to the first one " << endl;
    string word;
    bool isMatch = false;    // Використовуємо для порівняння слів
    while (iss >> word) {
        if (word == first) {
            cout << word << endl;
            isMatch = true;
        }
    }

    if (!isMatch) {     // Умова відсутності збігів
        cout << "no matches" << endl;
    }

    return 0;
}
