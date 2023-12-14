#include <iostream>

using namespace std;

// Структура, що представляє товар (наприклад, зошит чи олівець)
struct Item {
    string name;    // Назва товару
    double price;   // Ціна товару     //Використана як мінімум одна дійсна змінна
    int quantity;   // Кількість одиниць товару    //цілочисельна змінна
};

// Функція для обчислення вартості покупки
double calculatePurchaseCost(const Item& notebook, const Item& pencil) {
    double totalCost = (notebook.price * notebook.quantity) + (pencil.price * pencil.quantity);
    return totalCost;
}

int main() {
    // Введення інформації про товари
    Item notebook, pencil;

    cout << "Введіть інформацію про зошит:" << endl;
    cout << "Назва: ";
    cin >> notebook.name;
    cout << "Ціна: ";
    cin >> notebook.price;
    cout << "Кількість: ";
    cin >> notebook.quantity;

    cout << "\nВведіть інформацію про олівець:" << endl;           //Використані оператори виведення та введення даних
    cout << "Назва: ";
    cin >> pencil.name;
    cout << "Ціна: ";
    cin >> pencil.price;
    cout << "Кількість: ";
    cin >> pencil.quantity;

    // Обчислення вартості покупки
    double totalCost = calculatePurchaseCost(notebook, pencil);

    // Виведення результатів
    cout << "\nЗагальна вартість покупки: " << totalCost << " грн." << endl;

    return 0;
}
