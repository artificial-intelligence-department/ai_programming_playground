#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

    vector<string> weather = {"sunny", "rainy", "snowy", "cloudy", "windy"};

    cout << "Type in what the weather is like:" << endl;
list:

    for (string word : weather)
    {
        cout << word << endl;
    }

    string typein;

    cin >> typein;

    if (typein == "sunny")
    {

        cout << "You shouldn't put on any jacket" << endl;
        cout << "you can organize a picnic in the park" << endl;
        cout << "don't forget to apply sunscreen before going out" << endl;
        return 0;
    }
    else if (typein == "rainy")
    {
        cout << "you better take an umbrella or raincoat" << endl;
        cout << "don't forget to put on a jacket" << endl;
        cout << "Hot tea or coffee during the rain is a good option." << endl;
        return 0;
    }
    else if (typein == "snowy")
    {
        cout << "you can play snowballs with your friends" << endl;
        cout << "try hot chocolate" << endl;
        cout << "take goretex shoes" << endl;
        return 0;
    }
    else if (typein == "cloudy")
    {
        cout << "listen to some calm music" << endl;
        cout << "get ready to possible weather changes" << endl;
        cout << "you may put on sweater" << endl;
        return 0;
    }
    else if (typein == "windy")
    {
        cout << "wear warm scarves and hats" << endl;
        cout << "don't forget to put on a jacket" << endl;
        cout << "Beware of gusts of wind" << endl;
        return 0;
    }
    else
    {

        cout << "Write a weather from the list! \n";
        goto list;
    }
}