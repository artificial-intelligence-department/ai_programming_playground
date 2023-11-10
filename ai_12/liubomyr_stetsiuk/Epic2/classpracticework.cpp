#include <iostream>
#include <string>
using namespace std;

int main() {
    string weather; 

    cout << "Write what the weather is like (sunny, cloudy, windy, rainy, snowy, foggy): ";
    cin >> weather;

    if (weather == "sunny") {
        cout << "Wear a t-shirt. It's a brilliant weather condition to go for a walk! \n";
    } else if (weather == "cloudy" || weather == "windy") {
        cout << "Wear a sweater or hoodie. You should visit a museum or go to the cafe! \n";
    } else if (weather == "rainy" || weather == "snowy" || weather == "foggy") {
        cout << "Wear a jacket. The best idea is to stay at home and watch TV! \n";
    } else {
        cout << "You wrote a wrong condition \n";
    }

    switch (weather[0]) {
        case 's':
            if (weather == "sunny") {
                cout << "Wear slippers or sneakers \n"; 
            break;
            }

        case 'c':
            if (weather == "cloudy" || weather == "windy") {
                cout << "Wear sneakers, but choose warmer ones \n";
            break;
            }

        case 'x':
            if (weather == "snowy" || weather == "foggy") {
                cout << "Wear boots \n"; 
            break;
            }
    }

    return 0; 
}
