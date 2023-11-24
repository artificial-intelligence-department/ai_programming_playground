#include <iostream>
#include <string>
using namespace std;

int main () {

    string weather;
    int weathercode;

    cout << "Введіть поточні погодні умови (sunny, rainy, cloudy, Snowy, windy): " << endl;
    cin >> weather;

    if (weather == "sunny" ) {
        cout << "Чудовий день для пікніка!"<< endl;
        weathercode = 1;
    }
    else if (weather == "rainy" ) {
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
        cout << "Потрібно взяти куртку."<< endl;
        weathercode = 2;
    }
    else if (weather == "cloudy" ) {
        cout << "Може, відвідати музей?"<< endl;
        weathercode = 3;
    }
    else if (weather == "snowy") {
        cout << "Як щодо того, щоб зліпити сніговика?"<< endl;
        cout << "Потрібно взяти куртку."<< endl;
        weathercode = 4;
    }
    else if (weather == "windy") {
        cout << "Запустіть повітряного змія, якщо він у вас є!"<< endl;
        weathercode = 5;
    }




    switch(weathercode) {
        case 1:
        cout << "Взуй улюблені кросівки!"<< endl; 
        break;
        

        case 2:
        cout << "Дощові чоботи - гарна ідея!"<< endl;
        break;
        

        case 3:
        cout << "Сьогодні підходить будь-яке взуття."<< endl;
        break;

        case 4:
        cout << "Снігові черевики зігріють ваші ноги!"<< endl;
        break;
        

        case 5:
        cout << "Одягніть щось міцне!"<< endl;
        break;
        
    } 

return 0;
}