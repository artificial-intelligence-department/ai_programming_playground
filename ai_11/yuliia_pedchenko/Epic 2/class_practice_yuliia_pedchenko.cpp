#include <iostream>
#include <string>

using namespace std;

int main()
{
    Start:
    string weather;
    cin >> weather;

    if (weather == "sunny" || weather == "cloudy")
    {
        cout << "You don't need to wear your jacket"
             << "\n";
    }
    else if (weather == "windy" || weather == "snowy" || weather == "rainy")
    {
        cout << "You need to wear your jacket"
             << "\n";
    }
    else
    {
        cout << "unknown weather"
             << "\n";
        goto Start;     
    }

    if (weather == "sunny")
    {
        cout << "play volleyball";
    }
    else if (weather == "cloudy")
    {
        cout << "read a book";
    }
    else if (weather == "windy")
    {
        cout << "go windsurfing";
    }
    else if (weather == "rainy")
    {
        cout << "watch how the rain falls, listen to music";
    }
    else if (weather == "snowy")
    {
        cout << "make the snowman";
    }
    else
    {}
    cout << endl;
    

   

    switch (weather[0])
    {
    case 's':

    //перша буква відповіді

        if (weather[1] == 'u') cout << "Beautiful weather to wear sneakers";
        else cout << "Time to wear warm bootforts";
        break;

    case 'c':

        cout << "You can choose any shoes, but don't forget about temperature";
        break;

    case 'w':

        cout << "You should wear boots";
        break;

    case 'r':

        cout << "Wear something water-proof";
        break;

    default:
        break;
    }
    return 0;
}
