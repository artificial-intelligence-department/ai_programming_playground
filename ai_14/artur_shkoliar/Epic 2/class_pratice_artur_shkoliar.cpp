#include<iostream>
#include <cstdio>
#include <cmath>
#include<string>

using namespace std;

int main() {
    string weather;

    cout << "Please enter the current weather (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;


    
    if (weather == "snowy" || weather == "rainy") 
    {
        cout << "You should wear a jacket today." << endl;
    } 
    else 
    {
        cout << "You don't need a jacket today." << endl;;
    }


    if (weather == "sunny") 
    {
        cout << "It's a great day for a picnic!" << endl;
    } 
    else if (weather == "rainy") 
    {
        cout << "Perfect weather to read a book inside!" << endl;
    } 
    
    else if (weather == "cloudy") 
    {
        cout << "Maybe visit a museum?" << endl;
    } 

    else if (weather == "snowy") 
    {
        cout << "How about building a snowman?" << endl;
    } 
    
    else if (weather == "windy") 
    {
        cout << "Fly a kite if you have one!" << endl;
    }


    
    switch (weather[0]) 
    { 
        case 's': 
            if(weather == "sunny") 
            {
                cout << "Wear your favorite sneakers!" << endl;
            } 
            else
            {
                cout << "Snow boots will keep your feet warm!" << endl;
            }
            break;
        case 'r':
            cout << "Rain boots are a good idea!" << endl;;
            break;
        case 'c':
            cout << "Any footwear is fine today." << endl;
            break;
        case 'w':
            cout << "Wear something sturdy!" << endl;
            break;
        default:
            cout << "Invalid weather condition input." << endl;
            break;
    }


    return 0;
}