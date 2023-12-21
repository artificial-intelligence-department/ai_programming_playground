#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Please, enter weather conditions: ";
    string weather;
    cin >> weather;

    //1
    if (weather == "sunny" || weather == "cloudy" || weather == "windy") {
        cout << "You do not have to wear your jacket today." << endl;
    }
    else if (weather == "snowy" || weather == "rainy") {
        cout << "You should wear your jacket today." << endl;
    }
    else {
        cout << "Invalid weather!";
        return 0;
    }

    //2
    if (weather == "cloudy") {
        cout << "You can play football today!" << endl;
    }
    else if (weather == "snowy" || weather == "rainy") {
        cout << "You can play chess today!" << endl;
    }
    else if (weather == "sunny") {
        cout << "You can sunbathe today!" << endl;
    }
    else {
        cout << "you can go for a walk today!" << endl;
    }

    //3
    switch (weather[0])
    {
    case 'w':
        cout << "You can wear sneakers today."; break;
    case 'r':
        cout << "You can wear rubber boots today."; break;
    case 'c':
        cout << "You can wear shoes today."; break;    
    case 's':
        if (weather[1] == 'n'){
            cout << "You can wear boots today."; break;
        }
        else if (weather[1] == 'u'){
            cout << "You can wear sandals today."; break;
        }
    default:
        break;
    }
    return 0;
}