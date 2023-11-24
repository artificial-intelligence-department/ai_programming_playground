#include <iostream>
#include <string>

using namespace std;

int main()
{
    string weather;
    cout << "What the weather (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;
    char w = weather[0];
    if (weather == "rainy" || weather == "snowy")
    {
        cout << "Wear the jacket!" << endl;
    }
    else
    {
        cout << "Dont wear the jacket!" << endl;
    }

    if (weather == "sunny")
    {
        cout << "Go for a walk" << endl;
    }
    else if (weather == "cloudy")
    {
        cout << "Time to wear jaket" << endl;
    }
    else if (weather == "rainy")
    {
        cout << "Time to watch film" << endl;
    }
    else if (weather == "snowy")
    {
        cout << "Play snowballs!" << endl;
    }
    else if (weather == "windy")
    {
        cout << "Go for a shopping" << endl;
    }

    switch (w)
    {
    case 's':
        if (weather == "sunny")
        {
            cout << "You shouldn't wear boots!" << endl;
        }
        else if (weather == "snowy")
        {
            cout << "You should wear boots!" << endl;
        }
        break;
    case 'r':
        cout << "You should wear rubber bands!" << endl;
        break;
    case 'c':
        cout << "You should wear dad boots!" << endl;
        break;
    case 'w':
        cout << "You should wear lapatasionchik!";
        break;
    }
    return 0;
}