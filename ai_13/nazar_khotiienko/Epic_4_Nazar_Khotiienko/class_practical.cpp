#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &str, int Start, int End) // Рекурсивна функція для перевірки паліндрома в рядку
{

    if (Start >= End) // якщо початковий індекс більший або рівний кінцевому, то це паліндром
        return true;

    if (str[Start] == str[End]) // Якщо символ на початковому індексі дорівнює символу на кінцевому індексі,викликаємо рекурсивно для наступної пари індексів
    {
        return isPalindrome(str, Start + 1, End - 1);
    }
    else
    {
        return false; // Якщо хоча б одна пара символів не співпадає, це не паліндром
    }
}

bool isPalindrome(int a) // Функція для перевірки, чи є число паліндромом
{
    string q = to_string(a); // Конвертуємо ціле число в рядок

    int b = q.size(); // довжина рядка

    return isPalindrome(q, 0, b - 1);
}

int main()
{
    string word;
    cout << "Введіть слово:";
    cin >> word;

    if (isPalindrome(word, 0, word.size() - 1))
        cout << "Слово " << word << " є паліндромом" << endl;
    else
        cout << "Слово " << word << " не є паліндромом" << endl;

    int number;
    cout << "Введіть число:";
    cin >> number;

    if (isPalindrome(number))
        cout << "Число " << number << " є паліндромом" << endl;
    else
        cout << "Число " << number << " не є паліндромом" << endl;

    return 0;
}
