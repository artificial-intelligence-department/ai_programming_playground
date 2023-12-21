//епік 2 практична (погода)

#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    int weather;
    cout << "Enter the current weather conditions (1-sunny, 2-rainy, 3-cloudy, 4-snowy, 5-windy): " << endl;
    cin >> weather;

    if (weather == 2 || weather == 4) // snowy
    {
        cout << "you need to wear a jacket" << endl;
    }
    else
    {
        cout << "no need to wear a jacket" << endl;
    }

    if (weather == 1)
    {
        cout << "A great day for a picnic!" << endl;
    }
    else if (weather == 2)
    {
        cout << "Perfect weather to read a book inside!" << endl;
    }
    else if (weather == 3)
    {
        cout << "Maybe visit the museum?" << endl;
    }
    else if (weather == 4)
    {
        cout << "How about making a snowman?" << endl;
    }
    else if (weather == 5)
    {
        cout << "Fly the kite if you have one!" << endl;
    }

    else
    {
        cout << "you entered an invalid condition!" << endl
             << "please try again" << endl;
        return 0;
    }

    switch (weather)
    {
    case 1:
        cout << "Put on your favorite sneakers!" << endl;

        break;
    case 2:
        cout << "Rain boots are a good idea!" << endl;
        break;
    case 3:
        cout << "Any shoe is fine today." << endl;
        break;
    case 4:
        cout << "Snow boots will keep your feet warm!" << endl;
        break;
    case 5:
        cout << "Put on something strong!" << endl;
        break;
    }

    return 0;
}