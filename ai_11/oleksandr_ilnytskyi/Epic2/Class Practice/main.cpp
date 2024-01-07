#include <iostream>
#include <string>

using namespace std;

bool isValid(const string Weather) {
    if (Weather == "cloudy" || Weather == "rainy" || Weather == "snowy" || Weather == "windy" || Weather == "sunny") {
        return true;
    }
    else {
        return false;
    }
}

string wearJacket(const string Weather) {
    if (Weather == "cloudy" || Weather == "rainy" || Weather == "snowy" || Weather == "windy") {
        return "Wear Jacket";
    }
    else if (Weather == "sunny") {
        return "Wear T-Shirt";
    }
}

string chooseFootwear(const string Weather) {
    switch (Weather[1]) {
        case 'l':
            return "hiking boots";
        case 'a':
            return "sneakers";
        case 'n':
            return "boots";
        case 'i':
            return "runners";
        case 'u':
            return "sandals";
    }
}

string chooseActivity(const string Weather) {
    if (Weather == "cloudy") {
        return "go hiking";
    }
    else if (Weather == "rainy") {
        return "go playing table tennis with your friends";
    }
    else if (Weather == "snowy") {
        return "go make a snowman with your friends";
    }
    else if (Weather == "windy") {
        return "go launch kite in park";
    }
    else if (Weather == "sunny") {
        return "go to beach and swim or play volleyball";
    }
}

int main() {
    string weather;

    cout << "Enter your weather: ";
    cin >> weather;

    if (isValid(weather)) {
        cout << wearJacket(weather) + ", put on " + chooseFootwear(weather) + " and " + chooseActivity(weather) << endl;
    }
    else {
        cout << "Invalid input" << endl;
    }

}
