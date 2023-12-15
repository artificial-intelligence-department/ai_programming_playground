#include <iostream>
#include <string>

using namespace std;

int main(){
    string array[5] = {"snowy" , "rainy" , "windy" , "cloudy" , "sunny"};
    string weather;
    cout << "Enter a type of weather: " << endl;
    cin >> weather;

    if (weather == "snowy" ||  weather == "rainy")
        cout << "Потрібна куртка" << endl;
    else
        cout << "Куртка не потрібна" << endl;

    if (weather == "rainy")
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;

    if (weather == "sunny")
    {
        cout << "Чудовий день для пікніка!" << endl;
    }

    else if (weather == "cloudy")
        cout << "Може, відвідати музей?" << endl;

    else if (weather == "windy")
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;

    else if (weather == "snowy")
    {
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    }



    switch(char n = weather[0])
    {
        case 'r':
            cout << "Дощові чоботи - гарна ідея!" << endl;
            break;
        case 's':{
            if (weather == "sunny")
                cout << "Взуй улюблені кросівки!" << endl;
            else
                cout << "Снігові черевики зігріють ваші ноги!" << endl;
            break;
        }
        case 'c':
            cout << "Сьогодні підходить будь-яке взуття." << endl;
            break;
        case 'w':
            cout << "Одягніть щось міцне!" << endl;
            break;

    }



    return 0;



}