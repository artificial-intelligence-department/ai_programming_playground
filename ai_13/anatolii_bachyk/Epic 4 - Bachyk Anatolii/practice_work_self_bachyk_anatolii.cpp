#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minDeletions(string s1, string s2, int i, int j) {
    // якщо один з рядків порожній, повертаємо довжину іншого рядка
    if (i == s1.size()) return s2.size() - j;
    if (j == s2.size()) return s1.size() - i;

    
    if (s1[i] == s2[j]) return minDeletions(s1, s2, i + 1, j + 1); // Якщо символи співпадають, переходимо до наступного символу в обох рядках

    
    return min(minDeletions(s1, s2, i + 1, j), minDeletions(s1, s2, i, j + 1)) + 1;// Якщо символи не співпадають, видаляємо символ з s1 або s2 і рекурсивно викликаємо функцію
}

int main() {
    string s1 = "pinguin";
    string s2 = "madagascar";

    cout << "Мінімальна кількість символів, які потрібно видалити: " << minDeletions(s1, s2, 0, 0) << endl;

    return 0;
}