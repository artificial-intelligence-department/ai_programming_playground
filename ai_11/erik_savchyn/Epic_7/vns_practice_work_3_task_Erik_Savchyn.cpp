#include <iostream> // 21. Включено оператори введення та виведення даних
#include <cmath>    // 17. Включено математичні операції та функції
using namespace std;

int main() {
    double input; // 2, 3. Використано дійсну змінну з подвійною точністю
    cout << "Введіть дробове число: "; // 21. Використано оператор виведення даних
    cin >> input; // 21. Використано оператор введення даних

    int hryvnias = static_cast<int>(input); // Приведення типу до цілого числа
    int kopecks = round((input - hryvnias) * 100); // Округлення копійок

    cout << input << " грн. - це " << hryvnias << " грн. " << kopecks << " коп." << endl; // 21. Використано оператор виведення даних

    // Додано нову частину для розрахунку кількості деталей
    int partsPerHour; // Кількість деталей за годину
    const int hoursPerShift = 8, shiftsPerDay = 2, workDaysPerMonth = 30, extraHoursPerDay = 4; // Константи для розрахунків
    const int maintenancePerShift = 1; // Константа для профілактики
    cout << "Введіть кількість деталей виготовлених за годину: ";
    cin >> partsPerHour; // 21. Використано оператор введення даних

    int partsPerShift = partsPerHour * (hoursPerShift - maintenancePerShift); // 17. Обчислення кількості за зміну
    int partsPerDay = partsPerShift * shiftsPerDay; // 17. Обчислення кількості за день
    int partsPerMonth = (partsPerDay + partsPerHour * extraHoursPerDay) * workDaysPerMonth; // 17. Обчислення кількості за місяць

    // Виведення результатів
    cout << "За годину: " << partsPerHour << "\n";
    cout << "За 8-годинну зміну: " << partsPerShift << "\n";
    cout << "За робочий день при двозмінній роботі: " << partsPerDay << "\n";
    cout << "За місяць: " << partsPerMonth << " з урахуванням 4 додаткових годин щодня і 1 години на профілактику в кожній зміні" << endl;

    return 0;
}
