#include <iostream>
#include <string>
using namespace std;

int main()
{
    string weather;
    int switchcase;
    int i = 0;
    cout << "Write what the weather is like (sunny, cloudy, windy, rainy, snowy, foggy): ";
    cin >> weather;
    while (i != 1)
    {
        if (weather == "sunny")
        {
            cout << "Wear a t-shirt. It's a brilliant weather condition to go for a walk! \n";
            switchcase = 1;
            i = 1;
        }
        else if (weather == "cloudy" || weather == "windy")
        {
            cout << "Wear a sweater or hoodie. You should visit a museum or go to the cafe! \n";
            switchcase = 2;
            i = 1;
        }
        else if (weather == "rainy" || weather == "snowy" || weather == "foggy")
        {
            cout << "Wear a jacket. The best idea is to stay at home and watch TV! \n";
            switchcase = 3;
            i = 1;
        }
        else
        {
            cout << "You wrote a wrong condition \n";
            continue;
        }
    }
    switch (switchcase)
    {
    case 1:
        cout << "Wear slippers or sneakers! \n";
        break;

    case 2:
        cout << "Wear sneakers, but choose warmer ones! \n";
        break;

    case 3:
        cout << "Wear boots! \n";
        break;
    }

    return 0;
}
