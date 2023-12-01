#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather;
    cout << "Введіть погодні умови (sunny, rainy, cloudy, frosty, windy): ";
    cin >> weather;

    if (weather == "sunny") {
        cout << "Чудовий день для пікніка!\n";
    } else if (weather == "rainy") {
        cout << "Ідеальна погода, щоб читати книгу всередині!\n";
    } else if (weather == "cloudy") {
        cout << "Може, відвідати музей?\n";
    } else if (weather == "frosty") {
        cout << "Як щодо того, щоб зліпити сніговика?\n";
    } else if (weather == "windy") {
        cout << "Запустіть повітряного змія, якщо він у вас є!\n";
    } else {
        cout << "Неправильно введені погодні умови. Будь ласка, введіть правильну умову.\n";
    }
    switch (weather[0]) {
        case 's':
            cout << "Взуй улюблені кросівки!" << endl;
            break;
        case 'r':
            cout << "Дощові чоботи - гарна ідея!" << endl;
            break;
        case 'c':
            cout << "Сьогодні підходить будь-яке взуття." << endl;
            break;
        case 'f':
            cout << "Снігові черевики зігріють ваші ноги!" << endl;
            break;
        case 'w':
            cout << "Одягніть щось міцне!" << endl;
            break;
        default:
            break;
    }
    
    return 0;
}