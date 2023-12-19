#include <iostream>
#include <string>
using namespace std;

// Функція для перевірки, чи є слово паліндромом
bool isPalindrome(const string& word, int start, int end);

int main(){
    string word, n;
    cout << "Enter a number or word to check if it's a palindrome: ";
    cin >> word;

    // Викликаємо функцію isPalindrome() для перевірки, чи є введене слово паліндромом
    if (isPalindrome(word, 0, word.length()-1)){
        cout << "It's a palindrome"; // Якщо є паліндромом, виводимо відповідне повідомлення
    }
    else{
        cout << "It's not a palindrome"; // Якщо не є паліндромом, виводимо відповідне повідомлення
    }
    return 0;
}

// Рекурсивна функція для перевірки паліндрому
bool isPalindrome(const string& word, int start, int end){
    if (start >= end){
        return true; // Базовий випадок: якщо start більше або дорівнює end, повертаємо true
    }

    if (word[start] == word[end]){
        return isPalindrome(word, start + 1, end - 1); // Рекурсивний виклик для наступних символів
    }
    return false; // Якщо поточні символи не співпадають, повертаємо false
}
