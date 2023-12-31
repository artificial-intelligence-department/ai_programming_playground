#include <iostream> // Використали бібліотеку iostream, для роботи з виводом.
#include <cmath> // Використали бібліотеку cmath, для вирішення математичних завдань.

using namespace std; // Використали простор імен std;

int main() {
    const double y = 1; // Припускаємо, що y - це константа, яку можна змінити.
    const double hx = 2; // Крок х.
    double z; 

    for (double x = 1; x <= 10; x += hx) { // Цикл, який починається виконується до тих пір, поки x не перевищить 10, збільшуючи x на hx на кожній ітерації.
        if (x > y) { // Умова, яка перевіряє чи x > y, якщо все гуд, виконується код нижче, який обчислює першу частину рівняння системи.
            // Обчислення згідно першої частини системи рівнянь
            z = pow(x, 2) / pow(x - 5, 3); // Рівнняння 1 з умови.
        } else { // Інакше, виконується ця частина коду.
            // Обчислення згідно другої частини системи рівнянь
            z = pow(x - 2, 3) / (y * pow(x - 5, 4)); // Рівняння 2 з умови.
        }
        cout << "x = " << x << ", z = " << z << endl; // Виведення значень х та z, в термінал.
    }

    return 0;
}
