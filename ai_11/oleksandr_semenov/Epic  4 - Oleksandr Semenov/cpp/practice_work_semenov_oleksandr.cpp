#include <iostream>
#include <string>

using namespace std;

// Рекурсивна функція для перевірки, чи рядок є паліндромом
bool isPalindrome(const string& str, size_t start, size_t end) {//const string& str-Це рядок, який ми перевіряємо на паліндром;size_t start-Це індекс початку підрядка, який ми розглядаємо на поточному рекурсивному кроці.;
                                                                //size_t end - Це індекс кінця підрядка, який ми розглядаємо на поточному рекурсивному кроці.
    
    if (start >= end) {                                                                  // Базовий випадок: якщо рядок має менше або рівно одного символу, то він паліндром
        return true;
    }

    // Рекурсивний виклик для порівняння символів на початку та в кінці рядка
    return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);// && порівнюємо старт і кінець якщо рівні тоді 'true';str: Це вхідний рядок, який перевіряється на паліндром;start + 1 ми додаєм  1 до поточного значення start, ми переходимо до наступного символу у рядку.
                                                                             
}

 bool isPalindrome(int num) {                                                                  // Перевантажена функція для перевірки, чи ціле число є паліндромом
    string numStr = to_string(num);                                                            // Перетворення цілого числа на рядок

     return isPalindrome(numStr, 0, numStr.length() - 1);                                      // Виклик рядкової версії функції для перевірки, чи це паліндром
}

int main() {
    
    string word = "apple";                                                                        // Перевірка рядка на паліндром
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "\"" << word << "\" є паліндромом." << endl;
    } else {
        cout << "\"" << word << "\" не є паліндромом." << endl;
    }

   
    int number = 12321;                                                                      // Перевірка цілого числа на паліндром 
    if (isPalindrome(number)) {
        cout << number << " є паліндромом." << endl;
    } else {
        cout << number << " не є паліндромом." << endl;
    }

    return 0;
}
