#include <iostream>

using namespace std;

int main() {

    string current_weather;

    cout << "Enter weather: ";
    cin >> current_weather;

    if (current_weather == "rainy" || current_weather == "snowy") {
        cout << "візьми куртку";
    }

    else {
        cout << "курточки не треба";
    }

    char i = current_weather[0];

    switch (i) {
        case 's':
            if (current_weather[1]=='n'){
                cout << "Як щодо того, щоб зліпити сніговика?\n";
                cout << "Снігові черевики зігріють ваші ноги!\n";
            }
            else if (current_weather[1]=='u') {
                cout << "Чудовий день для пікніка!\n";
                cout << "Взуй улюблені кросівки!\n";
            }
        case 'r':
            cout << "Ідеальна погода, щоб читати книгу всередині!\n";
            cout << "Дощові чоботи - гарна ідея!\n";
        case 'c':
            cout << "Може, відвідати музей?\n";  
            cout << "Сьогодні підходить будь-яке взуття.\n";
        case 'w':
            cout << "Запустіть повітряного змія, якщо він у вас є!\n"; 
            cout << "Одягніть щось міцне!\n"; 
        default:
            return 0;
    }






 
    return 0;
}