#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void sortLetters(char* str) {

    int length = strlen(str);
    for (int i = 0; i < length; ++i) 
    {
        if (isspace(str[i])) 
        {
            memmove(&str[i], &str[i + 1], length - i);
            /* memmove ця функція видаляє пробіл
            зсуваючи всі наступні символи на одну позицію назад */
            length--;
            i--;
        }
    }
    sort(str, str + length);

    cout << str << endl;
}

int main() {
    const int maxLength = 255;
    char input[maxLength];

    cout << "Введіть рядок: ";
    fgets(input, maxLength, stdin);

    sortLetters(input);

    return 0;
}



