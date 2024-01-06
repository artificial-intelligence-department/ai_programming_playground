#include <iostream>
#include <iomanip> // Для використання функції setprecision
using namespace std;

int main() {
    // Введення початкових даних
    double principalAmount, interestRate, income;
    int depositTerm;

    cout << "Обчислення величини доходу по внеску." << endl;
    
    cout << "Величина внеску (грн.) = ";
    cin >> principalAmount;

    cout << "Термін внеску (днів) = ";
    cin >> depositTerm;

    cout << "Процентна ставка (річних в %) = ";
    cin >> interestRate;

    // Обчислення доходу
    income = (principalAmount * interestRate * depositTerm) / (365 * 100);

    // Обчислення суми після закінчення терміну внеску
    double finalAmount = principalAmount + income;

    // Виведення результату з форматуванням до двох знаків після коми
    cout << "Дохід: " << fixed << setprecision(2) << income << " грн." << endl; // setprecision використав для виведення 2 знаків піля коми
    cout << "Сума, після закінчення терміну внеску: " << fixed << setprecision(2) << finalAmount << " грн." << endl;//fixed вказує на використання фіксованого формату для виведення числа з плаваючою комою. Формат фіксованої точності забезпечує постійне відображення заданої кількості знаків після десяткової коми, навіть якщо вони нульові.

    return 0;
}
