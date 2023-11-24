#include <iostream>
#include "epic2.h"

using namespace std;

void shouldBringJacket(const Weather& weather) {
    if (weather == Weather::SUNNY || weather == Weather::CLOUDY)
        cout << "You can go out without a jacket";
    else cout << "You should bring a jacket";

    cout << endl;
}

void suggestedActivity(const Weather& weather) {
    if (weather == Weather::SUNNY)
        cout << "You may go to the park or bring some friends for picnic";
    else if (weather == Weather::CLOUDY)
        cout << "You may visit some cafes downtown or find a festival nearby";
    else if (weather == Weather::RAINY ||
             weather == Weather::SNOWY)
        cout << "You may go to the mall, theater or a cinema, "
                "or visit your friends";
    else // if windy
        cout << "You may bring up a kite to play with it outdoors";

    cout << endl;
}

void suggestedShoes(Weather weather) {
    switch (weather) {
        case Weather::SUNNY:
            cout << "If you go out, put on sneakers";
            break;
        case Weather::CLOUDY:
            cout << "If you go out, put on any shoes you like";
            break;
        case Weather::RAINY:
            cout << "If you go out, put on water-repellent shoes";
            break;
        case Weather::SNOWY:
            cout << "If you go out, put on boots";
            break;
        case Weather::WINDY:
            cout << "If you go out, put on leather shoes";
            break;
        default:
            break;
    }

    cout << endl;
}
