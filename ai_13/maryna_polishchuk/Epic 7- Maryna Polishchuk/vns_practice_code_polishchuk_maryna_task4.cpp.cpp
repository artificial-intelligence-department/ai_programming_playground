#include <iostream>
using namespace std;

// Рекурсивна функція для обчислення суми перших n цілих позитивних чисел
int sum_of_first_n_positive_integers(int n) {
  if (n == 0) {
    return 0;
  }
  return n + sum_of_first_n_positive_integers(n - 1);
}

int main() {
  // запит на введення кількості чисел
  int n;
  cout << "Enter number of nums: ";
  cin >> n;

  // Виклик рекурсивної функції
  int sum = sum_of_first_n_positive_integers(n);

  // Виведення результату
  cout << "Sum of first " << n << " integer nums: " << sum << endl;

  return 0;
}
