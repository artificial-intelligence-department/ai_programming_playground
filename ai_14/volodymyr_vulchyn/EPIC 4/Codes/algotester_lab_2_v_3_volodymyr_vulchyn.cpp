#include <iostream>
using namespace std;

int main() {
  int inscribeInteger;
  int newInteger;
  cin >> inscribeInteger; // Зчитуємо у користувача змінну inscribeInteger.

  int arr[inscribeInteger]; // Масив, який вміщає в собі inscribeInteger-елементів.
  // Цикл, який повторюється inscribeInteger-разів. 
  for (newInteger = 0; newInteger < inscribeInteger; newInteger++) { 
    cin >> arr[newInteger]; // Зберігаємо числа введені користувачем в новий масив arr[newInteger].
  }
  int leftDrone = 1, rightDrone = inscribeInteger; // Вказуємо позицію лівого та правого дрона відповідно.
  // Нескінченний цикл, який виконується поки не зустрінеться оператор break.
  while (1) { 
    if (leftDrone > rightDrone) { // Перевіряємо чи перетув лівий дрон правого, рухаючись по масиву
      cout << leftDrone << " " << rightDrone; // Виводимо поточні позиції обох дронів.
      cout << "\nMiss";
      break; // Виходимо з циклу, якщо задовільняє умова.
    } else if (leftDrone == rightDrone) { // Перевіряємо чи обидва дрона розташовані на одній позиції.
      cout << leftDrone << " " << rightDrone; // Виводимо поточні позиції обох дронів.
      cout << " \nCollision";
      break; // Виходимо з циклу, якщо задовільняє умова.
    } else if (leftDrone == rightDrone - 1) { // Перевіряємо чи лівий дрон на одну позиції позаду ніж правий дрон.
      cout << leftDrone << " " << rightDrone; // Виводимо поточні позиції обох дронів.
      cout << " \nStopped";
      break; // Виходимо з циклу, якщо задовільняє умова.
    }
    // Отримуємо значення елемента arr[leftDrone - 1]
    // Додаємо отримане значення до поточної позиції лівого дрона.
    // Призначаємо нову позицію лівому дрону.
    leftDrone += arr[leftDrone - 1]; 
    // Отримуємо значення елемента arr[rightDrone - 1].
    // Віднімаємоо отримане значення до поточної позиції правого дрона.
    // Призначаємо нову позицію лівому дрону.
    rightDrone -= arr[rightDrone - 1];
  }
  return 0;
}
