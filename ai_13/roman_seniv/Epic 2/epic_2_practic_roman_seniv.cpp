#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather;
    cout << "write type of weather:\n";
    cin >> weather;

    if (weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy") {
        cout << "error";
        return 0;
    }

    if (weather == "snowy" || weather == "windy" || weather == "rainy") {
        cout << "Stay at home\n";
    } else if (weather == "cloudy" || weather == "sunny") {
        cout << "Go play football";
    }

    switch (weather[0]) {
    case 's':
        if (weather == "sunny") {
            cout << "Wear your favorite sneakers!\n";
        } else {
            cout << "Snow boots will keep your feet warm!\n";
        }
        break;
    case 'r':
        cout << "Rain boots are a good idea!\n";
        break;
    case 'c':
        cout << "Today, any shoe is suitable\n";
        break;
    case 'w':
        cout << "Put on something strong!\n";
        break;
    default:
        cout << "Unknown weather type\n";
    }

    return 0;
}
