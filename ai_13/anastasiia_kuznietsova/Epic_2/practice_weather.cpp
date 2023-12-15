#include <iostream>
#include <string>
using namespace std;

int main()
{
string weather_conditions;
cout<<"Введіть поточні погодні умови\n";
cin>>weather_conditions;
if (weather_conditions == "windy" || weather_conditions == "snowy")
    {
    cout<<"Варто вдягнути куртку\n";
    }
else 
    {
    cout<<"Сьогодні куртка не потрібна\n";
    }
if (weather_conditions == "sunny")
{
    cout<<"Чудовий день для пікніка!\n";
}
else if (weather_conditions == "rainy")
{
    cout<<"Ідеальна погода, щоб читати книгу всередині!\n";
}
else if (weather_conditions == "cloudy")
{
    cout<<"Може, відвідати музей?\n";
}
else if (weather_conditions == "snowy")
{
    cout<<"Як щодо того, щоб зліпити сніговика?\n";
}
else if (weather_conditions == "windy")
{
    cout<<"Запустіть повітряного змія, якщо він y вас є!\n";
}
else
{
 cout<<"Будь ласка, введіть дійсну умову";
}
switch (weather_conditions[0])
{
    case 's':
        if (weather_conditions[1] == 'u') 
        cout<<"Взуй улюблені кросівки!";
        else if (weather_conditions[1] == 'n')
        cout<<"Снігові черевики зігріють ваші ноги!";
        break;
    case 'r':
        cout<<"Дощові чоботи - гарна ідея!";
        break;
    case 'c':
        cout<<"Сьогодні підходить будь-яке взуття.";
        break;
    case 'w':
        cout<<"Одягніть щось міцне!";
        break;
    default:
        cout<<"Будь ласка, введіть дійсну умову";
}
return 0;
}