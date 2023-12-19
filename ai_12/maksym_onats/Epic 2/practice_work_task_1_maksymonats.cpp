#include <iostream>
using namespace std;

int main() {

    string weather_condition;
    cout << "Enter weather conditions (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather_condition;

    if (weather_condition == "rainy" || weather_condition == "snowy") {
        cout << "Bring a jacket to stay dry!" << '\n';
    } else {
        cout << "You don't need a jacket, you can go outside." << '\n';
    }

    if (weather_condition == "sunny") {
        cout << "A great day for a picnic!" << '\n';
    } else if (weather_condition == "rainy") {
        cout << "Perfect weather to read a book inside!" << '\n';
    } else if (weather_condition == "cloudy") {
        cout << "Maybe visit a museum?" << '\n';
    } else if (weather_condition == "snowy") {
        cout << "How about making a snowman?" << '\n';
    } else if (weather_condition == "windy") {
        cout << "Fly a kite if you have one!" << '\n';
    } else {
        cout << "Please enter a valid weather condition." << '\n';
        return 1;
    }

    char weather_c = weather_condition[0];

    switch (weather_c) {
        case 's':
            if (weather_condition == "snowy") {
                cout << "Snow boots will keep your feet warm!" << '\n';
            } else {
                cout << "Wear your favorite sneakers!" << '\n';
            }
            break;
        case 'r':
            cout << "Rain boots are a good idea!" << '\n';
            break;
        case 'c':
            cout << "Today, any shoe is suitable." << '\n';
            break;
        case 'w':
            cout << "Wear something sturdy!" << '\n';
            break;
        default:
            cout << "Please enter a valid weather condition." << '\n';
    }

    return 0;
}