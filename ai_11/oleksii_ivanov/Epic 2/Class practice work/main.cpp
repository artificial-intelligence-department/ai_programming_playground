#include "epic2.h"
#include "helpers/string_helper.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> weatherNames = { "sunny", "cloudy", "rainy", "snowy", "windy" };
    string weatherStr;

    cout << "Enter weather:";
    cin >> weatherStr;
    weatherStr = ToLowerCase(weatherStr);

    auto it = find(weatherNames.begin(), weatherNames.end(), weatherStr);
    if (it == weatherNames.end()) {
        cout << "Invalid weatherStr type";
        return 1; // error
    }

    Weather weather = (Weather)(it - weatherNames.begin());

    shouldBringJacket(weather);
    suggestedActivity(weather);
    suggestedShoes(weather);

    return 0;
}