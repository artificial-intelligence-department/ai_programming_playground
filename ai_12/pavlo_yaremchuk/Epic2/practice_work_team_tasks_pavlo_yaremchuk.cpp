#include <iostream>
#include <string>
using namespace std;

int main()
{
    string weather;
    cout << "What is the weather today? (sunny, rainy, cloudy, snowy, windy)" << endl;
    cin >> weather;
    if (weather == "sunny")
    {
        cout << "Don't wear a jacket" << endl;
    }
    else 
    {
        cout << "Wear a jacket" << endl;
    }
    if (weather == "sunny")
    {
        cout << "It's a nice day for a picnic!" << endl;
    }
    else if (weather == "rainy")
    {
        cout << "Perfect weather to read a book inside!" << endl;
    }
    else if (weather == "cloudy")
    {
        cout << "Maybe, visit a myseum?" << endl;
    }
    else if (weather == "snowy")
    {
        cout << "How about making a snowman?" << endl;
    }
    else if (weather == "windy")
    {
        cout << "Fly a kite if you have one!" << endl;
    }
    else 
    {
        cout << "Enter a valid condition" << endl;
    }

    switch (weather[0])
    {
        case 'r':
        cout << "Rain boots are a good idea!" << endl;
        break;
        case 'c':
        cout << "Today, any shoe is suitable." << endl;
        break;
        case 'w':
        cout << "Wear something sturdy!" << endl;
        break;
    } 
     if (weather == "sunny")
    {
        cout << "Wear your favorite sneakers" << endl;
    }
    if (weather == "snowy")
    {
        cout << "Snow boots will keep your feet warm!" << endl;
    }
    return 0;
}