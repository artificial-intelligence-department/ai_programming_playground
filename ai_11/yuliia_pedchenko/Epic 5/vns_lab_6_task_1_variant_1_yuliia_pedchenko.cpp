//Надрукувати найдовше й найкоротше слово в цьому рядку.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    string longestWord, shortestWord, input;
    bool first = true;
    cout << "Введіть рядок англійською, відокремлюючи слова пробілом і поставивши в кінці крапку" << endl;
    getline(cin, input);
    if (input[input.size() - 1] == '.') { // - прибираємо крапку в кінці останнього слова
        input = input.substr(0, input.size() - 1);
    }
    stringstream stream(input);
    while (stream >> input) {
        if (first) {  // - першим значення найдовшого і найкоротшого слова задається перше
                      // слово вводу, щоб було з чим порівнювати
            longestWord = input;
            shortestWord = input;
            first = false;
        }

        if (input.size() > longestWord.size()) {
            longestWord = input;
        }
        if (input.size() < shortestWord.size()) {
            shortestWord = input;
        }
    }
    cout << "The longest word in sentence is: " << longestWord << endl;
    cout << "The shortest word in sentence is: " << shortestWord;

    return 0;
}

