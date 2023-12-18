#include <iostream>    //потоковий ввід-вивід
#include <sstream>  //Для роботи зі стрічками як потоками.(istringstream - клас цієї бібліотеки)  
#include <string>       //Для роботи зі стрічками. //для getline
#include <vector>
using namespace std;

bool palindrom(const string &word) {
    string t = word;          // Створення копії вхідного рядка word, оскільки нам потрібно здійснити перевірку паліндрома, і ми не хочемо змінювати оригінальний рядок.

    int start = 0;                      //перший символ рядка
    int end = t.length() - 1;     //останній символ рядка.

    while (start <= end) {
        if (t[start] != t[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void printPalindromes(const string &input) {
    istringstream iss(input);                                // дозволяє об'єднувати функціонал для роботи з рядками 
                                                             //та потоками. Цей клас дає можливість використовувати
                                                             // рядки як об'єкти потоку вводу/виводу, тобто здійснювати
                                                             // операції вводу та виводу на рядок так само, як це 
                                                             //робиться зі стандартними потоками вводу/виводу, такими 
                                                             //як cin та cout.

                                                             //це для розбиття введеного рядка на слова.
                                                             //iss є об'єктом класу istringstream, який дозволяє читати 
                                                             //дані з рядка input так, як це робиться з потоками вводу 
                                                             //(cin). Цей об'єкт створюється для розбиття рядка на окремі 
                                                             //слова за допомогою операції введення >>.
    string word;                 //змінна для зберігання кожного окремого слова
    vector<string> palindromes;  //вектор рядків, куди будуть зберігатися слова-паліндроми під час перевірки.

    while (iss >> word) {      //Цикл while використовується для пошуку паліндромів у кожному слові рядка input.
              //Умова iss >> word читає наступне слово з iss (тобто з рядка input) і зберігає 
              //його у змінну word.
            //Якщо iss вичерпує всі слова, цикл завершується.
        if (palindrom(word)) {
            palindromes.push_back(word); //Якщо word є паліндромом, воно додається до вектора palindromes
        }
    }

    if (palindromes.empty()) {  //перевіряє, чи є вектор порожнім. Метод empty() повертає true, якщо вектор не містить жодного елемента (тобто, він порожній), та false у протилежному випадку.
        cout << "There are no palindromes in the string.";
    } else {
        cout << "Palindromes in the string: ";
        for (const string &palindrome : palindromes) {  //Під час кожної ітерації циклу for, змінна palindrome приймає значення наступного слова-паліндрому з вектора palindromes
            cout << palindrome << " ";
        }
    }
}

int main() {
    
    const int length = 256;   
    char input[length];  

    cout << "Enter a string (no more than 255 characters; all words in lowercase) with a point at the end: ";
    cin.getline(input, length);     //зчитування рядка стандартного вводу у масив(рядок) input довжиною length
                             //користувач введе рядок а потім зчитає цей рядок у масив input за допомогою cin.getline()

    printPalindromes(input);

    return 0;
}
