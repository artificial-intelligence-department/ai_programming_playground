#include <iostream>
#include <string> 
using namespace std;

int main() {
    string weather;

    cout << "What is the weather today?";
    cin >> weather;


    if (weather == "rainy"|| weather == "snowy")
    {
        cout << "You need take a jacket" << endl;
    }
    else
    {
        cout << "You dont need take a jacket" << endl;
    }
   

    if (weather == "sunny")
    {
        cout << "A great day for a picnic!" << endl;
    }
    else if (weather == "rainy") {
        cout << "Perfect weather to read a book inside!" << endl;
    }
    else if (weather == "cloudy") {
        cout << "Maybe visit a museum?" << endl;
    }
    else if (weather == "snowy") {
        cout << "How about making a snowman?" << endl;
    }
    else if (weather == "windy") {
        cout << "Fly a kite if you have one!" << endl;
    }
    else {
        cout << "Enter the correct weather!" << endl;
    }



    switch (weather[0])
    {
    case 's':
        if (weather[1] == 'u')
        {
            cout << "Put on your favorite sneakers!" << endl;
        }
        else {
            cout << "Snow boots will keep your feet warm!" << endl;
        } break;
    case 'r':
        cout << "Rain boots are a good idea!" << endl;
        break;
    case 'c':
        cout << "Any shoe is fine today." << endl;
        break;
    case 'w':
        cout << "Put on something strong!" << endl; 
        break;
    default:
        cout << "wrong wheather" << endl; 
        break;
    }

}


