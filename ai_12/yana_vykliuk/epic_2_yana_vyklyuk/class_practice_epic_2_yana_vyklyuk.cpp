#include <iostream>
#include <string>

using namespace std;

string weather;
int s;

int main()
{

    bool weatherWasIdentified = false;
    
    while(!weatherWasIdentified)
    {
        cout << "Введіть поточні погодні умови:" << endl;
        cin >> weather;
        if(weather=="sunny" || weather=="rainy" || weather=="cloudy" || weather=="snowy" || weather=="windy")
        {
            weatherWasIdentified=true;
        }
        else
        {
            cout << "Введіть дійсну умову" << endl;
        }
    }
    
    if (weather=="snowy" || weather=="rainy")
    {
        cout << "Вдягайте куртку" << endl;
    }
    else
    {
        cout << "Куртки не потрібно" << endl;
    }

    if (weather=="sunny")
    {
        cout << "Чудовий день для пікніка!" << endl;
        s = 1;
    }
    else if (weather=="rainy")
    {
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
        s = 2;
    }
    else if (weather=="cloudy")
    {
        cout << "Може, відвідати музей" << endl;
        s = 3;
    }
    else if (weather=="snowy")
    {
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
        s = 4;
    }
    else 
    {
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    }
    
    switch(s)
    {
        case 1:
        cout << "Взуй улюблені кросівки!" << endl;
        break;

        case 2 :
        cout << "Дощові чоботи - гарна ідея!" << endl;
        break;

        case 3 :
        cout << "Сьогодні підходить будь-яке взуття." << endl;
        break;

        case 4 :
        cout << "Снігові черевики зігріють ваші ноги!" << endl;
        break;

        default:
        cout << "Одягніть щось міцне!" << endl;
        break;
    }

    return 0;
}
