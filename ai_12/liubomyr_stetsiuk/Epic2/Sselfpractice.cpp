#include <iostream>
using namespace std;

int main() {
  int numbers[5];

  cout << "Введіть 5 цілих чисел: ";
  for (int i = 0; i < 5; i++) {
    int num;
    cin >> num;
    numbers[i] = num;
  }

  int pos = -1, posCount = 0;
  for (int i = 0; i < 5; i++) {
    int num = numbers[i];
    if (num > 0) {
      posCount++;
      if (posCount == 2 && pos == -1) {
        pos = i;
      }
    }
  }

  int min = numeric_limits<int>::max();
  int minPos = -1;
  for (int i = 0; i < 5; i++) {
    if (numbers[i] < min) {
      min = numbers[i];
      minPos = i++;
    }
  }
  
  int prod = 1;
  for (int i = 0; i < 5; i++) {
    if (numbers[i] % 2 == 0 && numbers[i] != 0) {
      prod *= numbers[i];
    }
  }

  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += numbers[i];
  }
  pos++;
  minPos++;
  cout << "Позиція другого позитивного числа: " << pos << endl;
  cout << "Мінімальне значення в масиві: " << min << endl;
  cout << "Позиція мінімального значення: " << minPos << endl;
  cout << "Добуток всіх парних чисел (крім 0): " << prod << endl;
  cout << "Сума перших п'яти елементів: " << sum << endl;

  return 0;
}
