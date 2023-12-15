#include <iostream>
#include <cmath>

using namespace std;

double epsilon = 0.0001; // глобальна змінна, точність обчислень

// Функція для обчислення факторіалу
int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

// Функція для обчислення суми ряду Берруса
double sum_bebrus(int n) {
  // Обчислюємо n-й елемент ряду Берруса
  double n_element = (pow(2, n) * factorial(n)) / pow(n, n);

  // Перевіряємо, чи досягнута необхідна точність
  if (n_element < epsilon)
    return n_element;

  // Рекурсивно викликаємо функцію для обчислення наступного елементу та додаємо до поточного
  return n_element + sum_bebrus(n + 1);
}

int main() {
  // Обчислення суми ряду Берруса
  double sum = sum_bebrus(1);

  // Вивід результату
  cout << "Вивід результату: " << sum << endl;

  return 0;
}
