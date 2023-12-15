#include <iostream>
#include <string>
using namespace std;

int main()
{
    string weather;

    cout << "What wheather is it today?\n";

    cin >> weather;

    if (weather == "sunny" || weather == "cloudy")
    {
        cout << "You don't have to wear Jacket.";
    }
    else
    {
        cout << "You have to wear Jacket.";
    }

    cout << "\nYou can ";

    if (weather == "sunny")
    {
        cout << "play tenis";
    }
    else if (weather == "rainy")
    {
        cout << "jump in a puddle";
    }
    else if (weather == "cloudy")
    {
        cout << "walk through city";
    }
    else if (weather == "snowy")
    {
        cout << "build a snowman";
    }
    else if (weather == "windy")
    {
        cout << "launch a kite";
    }
    else
    {
        cout << "do nothing";
    }

    cout << ".\n";

    cout << "You have to wear ";

    switch (weather[0])
    {
    case 's':
        if (weather[1] == 'u')
        {
            cout << "crocks";
        }
        else if (weather[1] == 'n')
        {
            cout << "winter boots";
        }
        break;
    case 'r':
        cout << "rubber boots";
        break;
    case 'c':
        cout << "shoes";
        break;
    case 'w':
        cout << "sport shoes";
        break;
    default:
        cout << "naked feet";
        break;
    }

    cout << ".\n";

    return 0;
}
