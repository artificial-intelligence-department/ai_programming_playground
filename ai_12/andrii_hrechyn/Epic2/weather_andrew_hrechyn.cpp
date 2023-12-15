#include <iostream>
using namespace std;

int main()
{    
    string allWeatherConditions[] = {"sunny", "rainy", "cloudy", "snowy", "windy"};

    string Weatheratmoment;

    cout << "What's the weather like today? (sunny, rainy, cloudy, snowy, windy)\n";
    cin >> Weatheratmoment;

    if(Weatheratmoment == "snowy" || Weatheratmoment == "rainy")
    {
        cout << "You should take a jacket!\n";
    }
    else
    {
        cout << "No need to take a jacket!\n";
    }

    if(Weatheratmoment == "sunny")
    {
        cout << "A great day for a picnic!\n";
    }
    if((Weatheratmoment == "rainy"))
    {
        cout << "Perfect weather to read a book inside!\n";
    }
    if((Weatheratmoment == "cloudy"))
    {
        cout << "Maybe visit a museum?\n";
    }
    if((Weatheratmoment == "snowy"))
    {
        cout << "How about making a snowman?\n";
    }
    else
    {
        cout << "Fly a kite if you have one!\n";
    }


    switch (Weatheratmoment[0])
    {
    case 's':
        if(Weatheratmoment == "sunny")
        {
            cout << "Wear your favorite sneakers!\n";
        }
        else{
            cout << "Snow boots will keep your feet warm!\n";
        }
        break;
    case 'r':
        cout << "Rain boots are a good idea!\n";
        break;
    case 'c':
        cout << "Today, any shoe is suitable.\n";
        break;
    case 'w':
        cout << "Wear something sturdy!\n";
        break;
    }

    return 0;
}

