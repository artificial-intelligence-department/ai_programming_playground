#include <iostream>
using namespace std;

int main()
{
    string weather, activity, shoes, jacket;
    int weathernum;

    for (int i = 0; i != 1;)
    {
        cout << "What's the weather like today? (Possible answers are limited to 'sunny', 'rainy', 'cloudy', 'snowy', and 'windy')" << endl;
        cin >> weather;
        if (weather == "sunny")
        {
            activity = "It's a wonderful day for a picnic!";
            weathernum = 1;
            i = 1;
        }
        else if (weather == "rainy")
        {
            activity = "It's an opportunity to read a book or watch a movie at home.";
            jacket = "If you have to be somewhere else, put on your jacket before going out.";
            weathernum = 2;
            i = 1;
        }
        else if (weather == "cloudy")
        {
            activity = "Consider going to the cinema or another place of such kind today.";
            weathernum = 3;
            i = 1;
        }
        else if (weather == "snowy")
        {
            activity = "When was the last time you made a snowman? How about making one today?";
            jacket = "Don't forget to put on your winter jacket before going out though.";
            weathernum = 4;
            i = 1;
        }
        else if (weather == "windy")
        {
            activity = "Do you remember flying a kite as a kid? Why don't you bring your childhood memories back today?";
            weathernum = 5;
            i = 1;
        }
        else
        {
            cout << "That's not an appropriate answer. Please try again." << endl;
        }
    }

    switch (weathernum)
    {
    case 1:
        shoes = "Put on your favorite sneakers or sandals before going out today!";
        break;
    case 2:
        shoes = "Rain boots are a wonderful idea for today's weather!";
        break;
    case 3:
        shoes = "You can wear any shoes you want!";
        break;
    case 4:
        shoes = "Warm winter boots are a must for today's weather.";
        break;
    case 5:
        shoes = "Wear the shoes that are warm enough for you to endure this kind of weather.";
        break;
    }

    if (weathernum == 2 || weathernum == 4)
    {
        cout << activity << endl
             << jacket << endl
             << shoes;
    }
    else
    {
        cout << activity << endl
             << shoes;
    }

    return 0;
}