#include <iostream>
#include <string>
using namespace std;

int vowelsCount(string surname) // Вимога 12: використав перевантаження функції для рядків та символів
{
    string vowels = "AOEUIYaoueuiy";
    int count = 0;
    for (char ch : surname) { //Вимога 10: використано цикл for
        if (vowels.find(ch) != string::npos) { //Вимога 5: використано if
            count++;
        }
    }
    return count;
}

int vowelsCount(char c)
{
    string vowels = "AOEUIYaoueuiy";
    if (vowels.find(c) != string::npos) return 1;
    else return 0;
}

int main()
{
    const int group = 14; // Вимога 14: використав цілочисельної константи для збереження незмінного числа
    double field_length = (group * 10 - 10) * 0.9144; // ВИмога 3: використана змінна з подвійною точністю
    string surname = "Napadailo";
    double letter_width = vowelsCount(surname) * 0.8;
    float min_length = surname.length() * letter_width;
    double central_chars_count = field_length * 3 / letter_width;
    
    int left_start = 0; //Вимога 1: використана цілочисельна змінна
    int left_index = (left_start + surname.length() - (int)(min_length / 2)) % surname.length();
    string left_centralchars = surname.substr(left_index, central_chars_count);

    /*int right_start = surname.length() - 1;
    int right_end = right_start - (int)(field_length / letter_width); // Кінцевий індекс
    int right_index = right_end - (int)(central_chars_count) + 1; // Початковий індекс
    string right_centralchars = surname.substr(right_index, central_chars_count);
    */ 
    cout << "Minimum length of banner is " << min_length << " meters" << endl;
    cout << "Letters in the middle 3 meters from left side: " << left_centralchars;
    // Вивести символи з правого краю не виходить оскільки за моєю формулою індекси виходять за межі розміру surname
}