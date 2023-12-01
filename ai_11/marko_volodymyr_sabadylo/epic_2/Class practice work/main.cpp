#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum Weather {SUNNY,WINDY,SNOWY,CLOUDY,RAINE};

int main() {
    string weather;
    vector<string> strs{"sunny", "windy", "snowy", "cloudy", "raine"};
    cin >> weather;

    Weather weather1 = Weather(find(strs.begin(), strs.end(), weather) - strs.begin());

    switch (weather1) {
        case SUNNY:
            cout << "T-shirt";
            break;
        case WINDY:
        case SNOWY:
            cout << "hoodie";
            break;
        case CLOUDY:
        case RAINE:
            cout << "jacket";
            break;
    }
    return 0;
}