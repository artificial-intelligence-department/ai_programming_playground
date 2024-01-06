#include <iostream> // Використовую директиву include, щоб використати cout та cin із  заголовкового файлу <iostream>
#include <cmath>// Використовую директиву include, для використання pow та числа PI із  заголовкового файлу <cmath>
using namespace std;//Використовую простір імен std

// Оголошення функції
double CalculateVolume(double R, double h);

int main() {
    double R, H; //оголошення змінних типу double
    
    // Вивід повідомлення та зчитування даних в користувача
    cout << "Enter the radius and the height of the cylinder: " << endl;
    cin >> R >> H;

    // Перевірка умови перед викликом функції
    if (R > 5.5 && H > 7) {
        cout << "Volume: " << CalculateVolume(R, H) << endl;
    } else {
        cout << "Incorrect input :(" << endl;
    }

    return 0;
}

// Визначення функції, яка визначає об'єм цидіндра
double CalculateVolume(double R, double h) {
    // Перевірка  введених даних
    if (R > 5.5 && h > 7) {
        double V = M_PI * pow(R, 2) * h;// Оголошення й ініціалізація змінної типу double, за якою обчислюється об'єм
        return V;
    } else {
        cout << "Incorrect input :(" << endl;
        return 0; 
    }
}
