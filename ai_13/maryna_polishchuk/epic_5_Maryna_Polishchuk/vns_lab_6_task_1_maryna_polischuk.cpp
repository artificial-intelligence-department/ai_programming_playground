#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[255];
    cin.getline(s, sizeof(s)); // cin.getline(s, sizeof(s)); отримує рядок введення включаючи пробіли та зберігає його в масив s.
    string str;

    // strtok - функція для розбиття на слова на основі роздільника (в нашому випадку пробіл)
    char *word = strtok(s, " ");
    int wordCount = 0;

    while (word != NULL) {
        wordCount++;
        //якщо false, то додаємо до рядка стр слово і пробіл щоб розділити ті слова 
        if (wordCount % 2 == 1) {
            str += word;
            str += " ";
        }
        
        // переміщення вказівника на першу букву наступного слова
        word = strtok(NULL, " ");
    }

    cout << "Resulting sentence after removing even words: " << str << endl;
    return 0;
}