#include <iostream>
#include <cmath>

using namespace std;

// 14. в коді використано структури 
struct triangleSettings
{
    double pidstava;
    double height;
    double area;
};

//16. в коді використано параметри та аргументи функції
void areaOfTriangle(triangleSettings &triangle) 
{
    triangle.area = 0.5 * triangle.pidstava * triangle.height;
}

// Функція для виведення результатів виготовлення шайб
void workResults(int KOL) 
{
    int zminaKols = KOL * 7;
    int dailyKols = zminaKols * 2;
    int monthlyKols = dailyKols * 26;

    cout << "За 8-годинну зміну виготовиться: " << zminaKols << " шайб" << endl;
    cout << "За робочий день(двозмінна робота): " << dailyKols << " шайб" << endl;
    cout << "За 30-денний місяць з 4-ма вихідними(двозмінна робота): " << monthlyKols << " шайб" << endl;
}

int main() 
{
    triangleSettings triangle;
    
    cout << "Підстава (см): ";
    cin >> triangle.pidstava;

    cout << "Висота (см): ";
    cin >> triangle.height;

    // Виклик функції для обчислення площі трикутника
    areaOfTriangle(triangle);

    cout << "S трикутника = " << triangle.area << " кв.см." << endl;

    int KOL;
    cout << "Кількість шайб, що виготовляється за 1 годину: ";
    cin >> KOL;

    // Виклик функції для виведення результатів виготовлення шайб
    workResults(KOL);

    return 0;
}
