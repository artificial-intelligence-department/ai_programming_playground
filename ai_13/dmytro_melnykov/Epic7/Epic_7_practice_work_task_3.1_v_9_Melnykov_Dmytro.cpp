#include <iostream>

using namespace std;

int main() {
    //Ініціалізація поч. даних
    double FirstR, secondR;
    
    // ввожу значення 1 опору
    cout << "перший опір(Ом) > ";
    cin >> FirstR;

    // ввожу значення 2 опору
    cout << "другий опір(Ом) > ";
    cin >> secondR;

    // Обчислення опору
    double allR = FirstR + secondR;

    //результат
    cout << "Опір ланцюга: " << allR << " Ом" << endl;

    return 0;
}
