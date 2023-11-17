#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string weather;
    string sunny ("sunny"), snowy ("snowy"), rainy ("rainy"), windy("windy"), cloudy("cloudy");
    cout << "Enter weather (example sunny, snowy, windy....) ";
    cin >> weather;
    char a;
    if (weather != sunny && weather  != cloudy && weather != snowy && weather != rainy && weather != windy)
    {
        cout << "weather is undefiend";
    }

    else
    {
        if (weather == sunny || weather  == cloudy)
        {
            cout << "don't take the jacket\n ";
        }
            else
            {
                cout << "you must take the jacket\n";
            }
        if (weather == sunny)
        {
            cout << "you can play football\n ";
            a = 's';
        }
            else if (weather == snowy || weather == rainy || weather == windy )
            {
                cout << "better stay at home\n";
            }
            else 
            {
                cout << "You can take a walk\n";
                a = 'c';
            }
        if (weather == snowy) 
            a = {'s'};
        else if (weather == rainy)
            a = {'r'};
        else if (weather == windy)
            a = {'w'};

        
        switch (a)
        {
            case 'r':
            cout << "take boots";
            break;

            case 'w':
            cout << "take sneakers";
            break;

            case 's':
            if (weather == sunny)
            cout << "take sandals";
            else 
            cout << "take winter boots";
            break;

            default:
            cout << "take shoes";
            break;
        }


    }

    return 0;
}