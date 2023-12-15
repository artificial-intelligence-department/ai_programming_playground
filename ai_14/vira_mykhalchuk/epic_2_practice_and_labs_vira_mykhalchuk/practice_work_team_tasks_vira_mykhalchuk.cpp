#include <iostream>
using namespace std;

int main() {
    string weather;
    cout << "What is the weather? (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

    if (weather == "sunny") {
        cout << "Today is a great day for a picnic. Don’t forget to use sunscreen.";
    }
    else if (weather == "rainy") {
        cout << "It’s the best weather to read a book inside. If you go outside don’t forget your umbrella.";
    }
    else if (weather == "cloudy") {
        cout << "You can visit a museum today. Wear your favorite sneakers.";
    }
    else if (weather == "snowy") {
        cout << "You can make a snowman with friends. Wear the warmest shoes.";
    }
    else if (weather == "windy") {
        cout << "You can play with a kite today. Wear a vibrant windbreaker.";
    }
    else {
        cout << "ERROR";
    }

    return 0;
}
