#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather;

    cout << "Enter the weather (sunny, rainy, cloudy, frosty, windy): ";
    cin >> weather;

    if (weather == "rainy" || weather == "frosty") {
        cout << "You should wear a jacket!" << endl;
    } else {
        cout << "You don't need a jacket today." << endl;
    }

    if (weather == "sunny") {
        cout << "Perfect day for a picnic!!" << endl;
    } else if (weather == "rainy") {
        cout << "Ideal weather to read a book indoors!" << endl;
    } else if (weather == "cloudy") {
        cout << "Maybe visit a museum??" << endl;
    } else if (weather == "frosty") {
        cout << "How about building a snowman?" << endl;
    } else if (weather == "windy") {
        cout << "Fly a kite if you have one!" << endl;
    } else {
        cout << "Enter the correct weather." << endl;
        return 1; 
    }

    cout << "Footwear recommendations: ";
    switch(weather[0]) {
        case 's':
            cout << "Put on your favorite sneakers!";
            break;
        case 'r':
            cout << "Rain boots are a great idea!";
            break;
        case 'c':
            cout << "Any footwear will do.";
            break;
        case 'f':
            cout << "Snow boots will keep your feet warm!";
            break;
        case 'w':
            cout << "Choose something sturdy!";
            break;
        default:
            cout << "We cannot advise on suitable footwear.";
            break;
    }

    return 0;
}
