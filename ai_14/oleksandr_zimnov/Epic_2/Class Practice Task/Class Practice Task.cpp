#include <iostream>
#include <string>
using namespace std;

int main() {
    string weather = " ";
    string recommendation, footwear;
    bool jacket = false;
    do {
        if (weather == " ") {
            cout << "What is your weather? (1 for sunny, 2 for rainy, 3 for cloudy, 4 for snowy, 5 for windy)\n";
            cin >> weather;
        } else {
            cout << "Please enter a correct weather (1 for sunny, 2 for rainy, 3 for cloudy, 4 for snowy, 5 for windy)\n";
            cin >> weather;
        }
    } while (weather != "1" && weather != "2" && weather != "3" && weather != "4" && weather != "5");
    int weatherCode = stoi(weather); 
    switch (weatherCode) {
        case 1:
            recommendation = "A great day for a picnic!";
            footwear = "Wear your favorite sneakers!";
            break;
        case 2:
            recommendation = "Perfect weather to read a book inside!";
            footwear = "Rain boots are a good idea!";
            jacket = true;
            break;
        case 3:
            recommendation = "Can you visit the museum?";
            footwear = "Today, any shoe is suitable";
            break;
        case 4:
            recommendation = "How about making a snowman?";
            footwear = "Snow boots will keep your feet warm!";
            jacket = true;
            break;
        case 5:
            recommendation = "Fly a kite if you have one!";
            footwear = "Wear something sturdy!";
            break;
        default:
            break;
    }
    cout << recommendation << endl;
    if (jacket) {
        cout << "Please wear a jacket" << endl;
    }
    cout << footwear << endl;

    return 0;
}
