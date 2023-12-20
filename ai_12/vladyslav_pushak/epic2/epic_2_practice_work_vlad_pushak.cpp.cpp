#include<iostream>
#include<string>

using namespace std;

int main() {
    // Програма порадить, що робити в залежності від погоди

    cout << "Введіть погоду (sunny, rainy, cloudy, snowy, windy): ";
    
    string weather;
    cin >> weather;

    if (weather == "sunny") {
        cout << "Чудовий день для пікніка!\n";
    } else if (weather == "rainy") {
        cout << "Одягніть куртку.\n";
        cout << "Ідеальна погода для читання книги вдома!\n";
    } else if (weather == "cloudy") {
        cout << "Можливо, відвідайте музей.\n";
    } else if (weather == "snowy") {
        cout << "Одягніть куртку.\n";
        cout << "Що скажете на роботу сніговика?\n";
    } else if (weather == "windy") {
        cout << "Полетіть з планером, якщо є такий!\n";
    } else {
        cout << "Будь ласка, введіть правильну погоду.\n";
        return 1; // Повертаємо 1, щоб позначити помилку
    }

    switch (weather[1]) {
        case 'u':
            cout << "Одягніть улюблені кросівки!\n";
            break;
        case 'a':
            cout << "Гумові чоботи - гарна ідея!\n";
            break;
        case 'l':
            cout << "Сьогодні будь-яка взуття підійде.\n";
            break;
        case 'n':
            cout << "Чоботи на сніг зігріють ваші ноги!\n";
            break;
        case 'i':
            cout << "Одягніть щось міцне!\n";
            break;
        default:
            cout << "Невірна погодна умова.\n";
            return 1; // Повертаємо 1, щоб позначити помилку
    }

    return 0;
}
