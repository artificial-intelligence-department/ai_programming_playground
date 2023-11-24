#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather;
    cout << "What is the weather (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

    // 1
    if (weather == "rainy" || weather == "snowy") {
        cout << "You should bring a jacket." << endl;
    } else {
        cout << "Jacket is not needed." << endl;
    }

    // 2
    if (weather == "sunny") {
        cout << "Go to the sea." << endl;
    } else if (weather == "cloudy") {
        cout << "Go to the restaurant." << endl;
    } else if (weather == "rainy") {
        cout << "Watch Dota 2 new video." << endl;
    } else if (weather == "snowy") {
        cout << "Go skiing." << endl;
    } else if (weather == "windy") {
        cout << "Go play CS:GO tournament." << endl;
    }

    // 3
    char w = weather[0];
    switch (w) {
        case 's':
            if (weather == "sunny") {
                cout << "Flip-flops will be a nice choice." << endl;
            } else if (weather == "snowy") {
                cout << "Warm boots are the best option." << endl;
            }
            break;
        case 'r':
            cout << "New Balance Gore-Tex sneakers are nice." << endl;
            break;
        case 'c':
            cout << "Any of your favorite shoes." << endl;
            break;
        case 'w':
            cout << "Any Nike Air Max." << endl;
            break;
    }

    return 0;
}
