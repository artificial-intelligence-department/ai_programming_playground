#include <iostream>
#include <string>
using namespace std;

int main()
{
    string weather;
    string a = "sunny";
    string b = "rainy";
    string o = "cloudy";
    string d = "snowy";
    string e = "windy";

    bool y = false;

    cout << "What is the weather today?\n";
    cout << "Choose from this variants: sunny, rainy, cloudy, snowy, windy\n";
    cout << "Type here: ";
    cin >> weather;

    while(y != true)
    {
        if(weather != a && weather != b && weather != o && weather != e && weather != d)
        {
            cout << "This condition is not found. Try again please\n";
            cout << "Choose from this variants: sunny, rainy, cloudy, snowy, windy\n";
            cin >> weather;  
        }
        else
        {
            y = true;
        }
    }
    


    if(weather == b || weather == o || weather == d || weather == e)
    {
        cout << "You'd rather put a jacket on" << endl;
    }
    else
    {
        cout << "You can go without a jacket" << endl; 
    }

    if(weather == a)
    {
        cout << "It's time to go for a walk with your family\n";
        cout << "Hurrry up!" << endl;
    }
    else if(weather == b)
    {
        cout << "What about reading a book or cooking something?" << endl;
    }
    else if(weather == o)
    {
        cout << "A cup of hot chocolate would be great, don't you think?" << endl;
    }
    else if(weather == d)
    {
        cout << "Let's make a snowman!" << endl;
    }
    else
    {
        cout << "Try to relax doing puzzles or singing" << endl;
    }


    switch (weather[0])
    {
    case 's':
        cout << "Put sandales on" << endl;
        break;
    
    case 'r':
        cout << "Put rubber boots on" << endl;
        break;

    case 'c':
        cout << "Put sneakers on" << endl;
        break;
    
    case 'd':
        cout << "Put boots on" << endl;
        break;

    default:
        cout << "Choose something bright to put on ;)" << endl;
        break;
    }

    return 0;
}
