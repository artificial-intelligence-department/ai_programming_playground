#include <iostream>
using namespace std;
int main(){
    string weather;
    cout << "Enter weather (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;
    if (weather == "sunny") cout << "Чудовий день для пікніка!\n";
    else if (weather == "rainy") cout << "Ідеальна погода, щоб читати книгу всередині!\n";
    else if (weather == "cloudy") cout << "Може, відвідати музей?\n";
    else if (weather == "snowy") cout << "Як щодо того, щоб зліпити сніговика?\n";
    else if (weather == "windy") cout << "Запустіть повітряного змія, якщо він у вас є!\n";
    else cout << "Input error\n";
    switch (weather[1])
    {
    case 'u':
        cout << "Взуй улюблені кросівки!";
        break;
    case 'n':
        cout << "Снігові черевики зігріють ваші ноги!";
        break;
    case 'a':
        cout << "Дощові чоботи - гарна ідея!";
        break;
    case 'l':
        cout << "Сьогодні підходить будь-яке взуття.";
        break;
    case 'i':
        cout << "Одягніть щось міцне!";
        break;
    default:
        cout << "Input error";
        break;
    }
    return 0;
}