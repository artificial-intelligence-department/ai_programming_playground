#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const int length_yard = 110; // Вимога 4.	в коді використана як мінімум одна цілочисельна константа
const char vowels[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

float YardsToMeters (int yard);
int countVowels(string str, int index, int counter);
char* findIntersectionL(string surname, float length, double letter_length);
char* findIntersectionR(string surname, float length, double letter_length);

struct Length // Вимога 19.	в коді використано свою структуру даних
{
    float m; // Вимога 2.	в коді використана як мінімум одна дійсна змінна
    float yards;
};

int main()
{
    string surname;
    Length field;
    field.yards = length_yard;

    cout << "Enter surname: ";
    cin >> surname; // Вимога 18.	в коді використано оператори виведення та введення даних

    field.m  = YardsToMeters(length_yard);

    double letter_length = 0.8 * countVowels(surname, 0, 0);
    double surname_length = letter_length * surname.length(); // Вимога 3.	в коді використана як мінімум одна дійсний з подвійною точністю змінна

    cout << "surname_length = " << surname_length << endl;
    cout << "field.m = " << field.m << endl;
    
    cout << "1)" << endl;
    char* resultLeft = findIntersectionL(surname, field.m, letter_length);
    cout << resultLeft << endl;
    cout << "2)" << endl;
    char* resultRight = findIntersectionR(surname, field.m, letter_length);
    cout << resultRight << endl;


    return 0;
}
float YardsToMeters(int yard)
{
    return yard * 3 * 12 * 2.54 / 100; // Вимога 15.	в коді використано математичні операції та математичні функції
}
int countVowels(string str, int index, int counter) // Вимога 14.	в коді використано параметри та аргументи функції	
{
    if(index == str.length())
    {
        return counter;
    }

    for(const auto vowel : vowels) // Вимога 10.	в коді використаний for цикл 
    {
        if(vowel == str[index])
        {
            counter++;
            break; // Вимога 11. в коді використано оператори break і continue
        }
        else // Вимога 5.	в коді використані умовні оператори та розгалуження
        {
            continue; // Вимога 11.	в коді використано оператори break і continue
        }
    }

    return countVowels(str, index + 1, counter); // Вимога 13.	в коді використано рекурсивну функцію 
}
char* findIntersectionL(string surname, float length, double letter_length)
{
    int counter = 0;
    double middle = (length - 3) / 2;
    int index = int(middle / letter_length);
    double temp = letter_length * round(middle / letter_length);
    
    while (temp < middle + 3) // Вимога 9.	в коді використаний while цикл
    {
        temp += letter_length;
        counter++;
    }
    if(counter == 0)
    {
        return NULL;
    }

    char* result = new char[counter + 1]; // Вимога 6.	в коді використаний одновимірний масив.  Вимога 20.	в коді використано вказівники
    int i = 0; // Вимога 1.	в коді використана як мінімум одна цілочисельна змінна
    do // Вимога 8.	в коді використаний do while цикл
    {
        index = (index + 1) % surname.length();
        result[i] = surname[index];
        i++;
    } while (i < counter); 
    result[i] = '\0';

    return result;
}
char* findIntersectionR(string surname, float length, double letter_length)
{
    int counter = 0;
    double middle = (length - 3) / 2;
    int index = int(middle / letter_length);
    double temp = letter_length * round(middle / letter_length);
    
    while (temp < middle + 3) // Вимога 9.	в коді використаний while цикл
    {
        temp += letter_length;
        counter++;
    }
    if(counter == 0)
    {
        return NULL;
    }

    char* result = new char[counter + 1]; // Вимога 6.	в коді використаний одновимірний масив.  Вимога 20.	в коді використано вказівники
    int i = 0; // Вимога 1.	в коді використана як мінімум одна цілочисельна змінна
    do // Вимога 8.	в коді використаний do while цикл
    {
        index = (index + 1) % surname.length();
        result[i] = surname[surname.length() - 1 - index];
        i++;
    } while (i < counter); 
    result[i] = '\0';

    return result;
}
