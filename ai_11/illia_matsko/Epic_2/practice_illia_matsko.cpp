#include <iostream>
#include <string>
using namespace std;

int main()
{
    string weather;
    cin >> weather;

    int weather_num = -1;

    if(weather == "Cloudy") weather_num = 2;
    if(weather == "Windy") weather_num = 4;

    if(weather == "Cloudy" || weather == "Windy") cout << "Wear coat" << endl;

    if(weather == "Sunny")
    {
        weather_num = 0;
        cout << "Wear T-Shirt" << endl;
    } else if(weather == "Rainy")
    {
        weather_num = 1;
        cout << "Take an umbrella" << endl;
    } else if(weather == "Snowy")
    {
        weather_num = 3;
        cout << "Wear gloves" << endl;
    }

    switch(weather_num)
    {
        case 0:
            if(weather == "Sunny") cout << "Wear sandals" << endl;
            break;
        case 1:
            cout << "Wear rubber boots" << endl;
            break;
        case 2:
            cout << "Wear trainers" << endl;
            break;
        case 3:
            if(weather == "Snowy") cout << "Wear warm boots" << endl;
            break;
        case 4:
            cout << "Wear boots" << endl;
            break;
        default:
            cout << "Error: Unknown weather!";
    }

    if(weather == "Sunny") cout << "Play football";
    else if(weather == "Snowy") cout << "Make snowman";
    else if(weather == "Rainy") cout << "Jump in puddles";
    else if(weather == "Cloudy" || weather == "Windy") cout << "Sit at home and drink tea";
}