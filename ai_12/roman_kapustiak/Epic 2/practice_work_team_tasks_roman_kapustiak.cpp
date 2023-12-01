#include <iostream>

using namespace std;

bool searchElement(string target, string array[], int length);

int main()
{    
    string possibleWeatherConditions[] = {"sunny", "rainy", "cloudy", "snowy", "windy"};

    string currentWeather;

    do
    {
    cout << "What's the weather like now? (use \"sunny\", \"rainy\", \"cloudy\", \"snowy\", \"windy\")\n";
    cin >> currentWeather;
    }
    while(!(searchElement(currentWeather, possibleWeatherConditions, 5)));

    if(currentWeather == "snowy" || currentWeather == "rainy")
    {
        cout << "You should take a jacket!\n";
    }
    else
    {
        cout << "No need to take a jacket!\n";
    }

    if(currentWeather == "sunny")
    {
        cout << "A great day for a picnic!\n";
    }
    else if((currentWeather == "rainy"))
    {
        cout << "Perfect weather to read a book inside!\n";
    }
    else if((currentWeather == "cloudy"))
    {
        cout << "Maybe visit a museum?\n";
    }
    else if((currentWeather == "snowy"))
    {
        cout << "How about making a snowman?\n";
    }
    else
    {
        cout << "Fly a kite if you have one!\n";
    }


    switch (currentWeather[0])
    {
    case 's':
        if(currentWeather == "sunny")
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

bool searchElement(string target, string array[], int length)
{
    for (int i = 0; i < length; i++){
        if(array[i] == target){
            return true;
        }
    }

    return false;
}
