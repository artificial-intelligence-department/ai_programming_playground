#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather;

    cout << "Введіть погоду ( sunny, rainy, cloudy, frosty, windy): ";
    cin >> weather;

    if (weather == "rainy" || weather == "frosty") {
        cout << "Вам слід одягнути куртку!" << endl;
    } else {
        cout << "Сьогодні вам куртка не потрібна" << endl;
    }

    if (weather == "sunny") {
        cout << "Чудовий день для пікніка!!" << endl;
    } else if (weather == "rainy") {
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    } else if (weather == "cloudy") {
        cout << "Може, відвідати музей??" << endl;
    } else if (weather == "frosty") {
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    } else if (weather == "windy") {
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    } else {
        cout << "Введіть правильну погоду." << endl;
        return 1; 
    }


    cout << "Рекомендації щодо взуття: ";
    switch(weather[0]) {
        case 's':
            cout << "Взуй улюблені кросівки!";
            break;
        case 'r':
            cout << "Дощові чоботи - гарна ідея!";
            break;
        case 'c':
            cout << "Будь-яке взуття підійде.";
            break;
        case 'f':
            cout << "Снігові черевики зігріють ваші ноги!";
            break;
        case 'w':
            cout << "Оберіть щось міцне!";
            break;
        default:
            cout << "Не можемо порадити, яке взуття підходить.";
            break;
    }

    return 0;
}
