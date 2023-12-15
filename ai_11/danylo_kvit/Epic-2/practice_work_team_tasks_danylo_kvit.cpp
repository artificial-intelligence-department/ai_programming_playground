#include <iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    int k = 0;

    if(s=="rainy"||s=="snowy") cout << "Краще візьми куртку.\n";
    else cout << "Куртку брати не потрібно.\n";

    if(s=="sunny") {cout << "Чудовий день для пікніка!\n"; k=0;}
    else if(s=="rainy") {cout << "Ідеальна погода, щоб читати книгу всередині!\n"; k=1;}
    else if(s=="cloudy") {cout << "Може, відвідати музей?\n"; k=2;}
    else if(s=="snowy") {cout << "Як щодо того, щоб зліпити сніговика?\n"; k=3;}
    else if(s=="windy") {cout << "Запустіть повітряного змія, якщо він у вас є!\n"; k=4;}

    switch(k) {
        case 0:
            cout << "Взуй улюблені кросівки!";
            break;
        case 1:
            cout << "Дощові чоботи - гарна ідея!";
            break;
        case 2:
            cout << "Сьогодні підходить будь-яке взуття.";
            break;
        case 3:
            cout << "Снігові черевики зігріють ваші ноги!";
            break;
        case 4:
            cout << "Одягніть щось міцне!";
            break;
    }
    return 0;
}

