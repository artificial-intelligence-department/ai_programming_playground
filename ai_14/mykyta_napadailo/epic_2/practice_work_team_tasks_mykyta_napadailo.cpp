#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "What weather is like today? ";
    string weather;
    cin >> weather;
   
    if (weather!="sunny" && weather!="rainy" && weather!="cloudy" && weather!="snowy" && weather!="windy") {
        cout << "Invalid weather input. Choose a valid one(sunny, rainy, cloudy, snowy, windy)." << endl;
        return 1;
    }
    if (weather=="snowy" || weather=="rainy") {
        cout << "Don't forget to take your jacket!" << endl;
    }
    else {
        cout << "There is no need for a jacket!" << endl;
    }

    if (weather=="sunny") {
        cout << "Looks like a great day for a picnic!" << endl;
    }
    else if (weather=="rainy") {
        cout << "Perfect weather for reading inside!" << endl;
    }
    else if (weather=="cloudy") {
        cout << "What about going to a museum?" << endl;
    }
    else if (weather=="windy") {
        cout << "Launch a kite if you've got one!" << endl;
    }
    else if (weather=="snowy") {
        cout << "Let's make a snowman!" << endl;
    }

switch (weather[0]) {
    case 's':
        if (weather[1]=='u') {
            cout << "It's time for your favourite sneakers!" << endl;
        }
        else {
            cout << "You would be comfy in warm boots!" << endl;
        }
        break;
    case 'r':
        cout << "Rain boots are a great idea!" << endl;
        break;
    case 'c':
        cout << "You can choose whatever shoes you want today!" << endl;
        break;
    case 'w':
        cout << "Wear something sturdy today!" << endl;
        break;
}

    return 0;
}