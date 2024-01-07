#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main(){
    char s[256];
    printf("Введіть рядок: ");
    gets(s);  // читаємо рядок
    const char *delimiters = " .";  // пробіли та крапка як роздільники
    char *word = strtok(s, delimiters);  // розбиваємо рядок на слова
    while (word != NULL){
        int digit_count = 0;
        for (int i = 0; i < strlen(word); i++){
            if (isdigit(word[i])){
                digit_count++;  // підрахунок цифр у слові
            }
        }
        if (digit_count == 1){  // якщо у слові рівно одна цифра
            cout << word << endl;  // виводимо слово
        }
        word = strtok(NULL, delimiters);  // переходимо до наступного слова
    }
    return 0;
}
