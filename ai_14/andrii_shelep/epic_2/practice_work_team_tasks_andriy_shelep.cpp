#include <iostream>
#include <string>

using namespace std;

enum WeatherTypes {sunny, rainy, cloudy, snowy, windy};

int main(){
    string weather;
    int weatherType;

    cout << "enter the type of weather (sunny, rainy, cloudy, snowy, windy):" << endl;
    cin >> weather;
//перевіряємо чи користувач ввів правильний тип погоди    
    bool weather_acceptable = false;

    while(weather_acceptable==false){
        if(weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "snowy" || weather == "windy"){
            weather_acceptable = true;
        }
// якщо ні - просимо, що він ще раз ввів його
        else{
            cout << "введіть правильне значення: ";
            cin >> weather;
        }
    }
// в залежності від погоди, програма радить чи надягати куртку    
    if (weather == "rainy" || weather == "snowy"){
        cout << "Одягніть куртку!" << endl;
    } else{
        cout << "Куртка непотрібна!" << endl;
    }
// в залежності від погоди, програма радить якусь активність
    if (weather == "sunny"){
        weatherType = WeatherTypes::sunny;
        cout << "Чудовий день для пікніка!" << endl;
    } else if (weather == "rainy"){
        weatherType = WeatherTypes::rainy;
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    } else if (weather == "cloudy"){
        weatherType = WeatherTypes::cloudy;
        cout << "Може, відвідати музей?" << endl;
    } else if(weather == "snowy"){
        weatherType = WeatherTypes::snowy;
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    } else if (weather == "windy"){
        weatherType = WeatherTypes::windy;
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    }
// в залежності від погоди, програма радить кросівки
    switch (weatherType)
    {
        case WeatherTypes::sunny:
            cout << "Взуй улюблені кросівки!";
        break;

        case WeatherTypes::rainy:
            cout << "Дощові чоботи - гарна ідея!";
        break;

        case WeatherTypes::cloudy:
            cout << "Сьогодні підходить будь-яке взуття.";
        break;

        case WeatherTypes::snowy:
            cout << "Снігові черевики зігріють ваші ноги!";
        break;

        case WeatherTypes::windy:
            cout << "Взуйте щось міцне!";
        break;
    }
}