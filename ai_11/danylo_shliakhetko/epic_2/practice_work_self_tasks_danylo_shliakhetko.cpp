#include <iostream>
#include <string>
using namespace std;

const string CSUNNY = "sunny";
const string CRAINY = "rainy";
const string CCLOUDY = "cloudy";
const string CSNOWY = "snowy";
const string CWINDY = "windy";

enum Weather
{
    NAW,
    SUNNY,
    RAINY,
    CLOUDY,
    SNOWY,
    WINDY
};

Weather stirngToWeather(string weather)
{
    if (weather == CSUNNY)
    {
        return SUNNY;
    }
    if (weather == CRAINY)
    {
        return RAINY;
    }
    if (weather == CCLOUDY)
    {
        return CLOUDY;
    }
    if (weather == CSNOWY)
    {
        return SNOWY;
    }
    if (weather == CWINDY)
    {
        return WINDY;
    }
    return NAW;
}

bool checkJacketWearByWeather(Weather weather)
{
    bool answer = true;

    if (weather == SUNNY || weather == CLOUDY)
    {
        return false;
    }

    return answer;
}

string getActivityByWeather(Weather weather)
{
    if (weather == SUNNY)
    {
        return "play tenis";
    }
    else if (weather == RAINY)
    {
        return "jump in a puddle";
    }
    else if (weather == CLOUDY)
    {
        return "walk through city";
    }
    else if (weather == SNOWY)
    {
        return "build a snowman";
    }
    else if (weather == WINDY)
    {
        return "launch a kite";
    }
    else
    {
        return "false action";
    }
}

string getFootwearByWeather(Weather weather)
{
    string answer;

    switch (weather)
    {
    case SUNNY:
        answer = "crocks";
        break;
    case RAINY:
        answer = "rubber boots";
        break;
    case CLOUDY:
        answer = "shoes";
        break;
    case SNOWY:
        answer = "winter boots";
        break;
    case WINDY:
        answer = "sport shoes";
        break;
    default:
        answer = "naked feet";
        break;
    }

    return answer;
}

int main()
{
    string input;

    cout << "What wheather is it today?\n";

    cin >> input;

    Weather weather = stirngToWeather(input);

    cout << (checkJacketWearByWeather(weather) ? "You have to wear Jacket" : "You don't have to wear Jacket");

    cout << "\nYou can " << getActivityByWeather(weather) << ".\n";

    cout << "You have to wear " << getFootwearByWeather(weather) << ".\n";

    return 0;
}
