#include <iostream>
#include <string>
using namespace std;

int main () {

    string weather;
    int weathercode;

    cout << "Enter the weather (sunny, rainy, clody, snowy, windy)" << endl;
    cin >> weather;

    if (weather == "sunny" ) {
        cout << "Go for a picnic"<< endl;
        weathercode = 1;
    }
    else if (weather == "rainy" ) {
        cout << "Perfect weather to read a book inside!" << endl;
        cout << "Take an anorak"<< endl;
        weathercode = 2;
    }
    else if (weather == "cloudy" ) {
        cout << "Maybe visit a museum?"<< endl;
        weathercode = 3;
    }
    else if (weather == "snowy") {
        cout << "How about making a snowman?"<< endl;
        cout << "Take an anorak"<< endl;
        weathercode = 4;
    }
    else if (weather == "windy") {
        cout << "Fly a kite if you have one!"<< endl;
        weathercode = 5;
    }




    switch(weathercode) {
        case 1:
        cout << "Take your favourite shoes"<< endl; 
        break;

        case 2:
        cout << "Rain boots are a good idea!"<< endl;
        break;

        case 3:
        cout << "Today, any shoe is suitable."<< endl;
        break;

        case 4:
        cout << "Snow boots will keep your feet warm!"<< endl;
        break;

        case 5:
        cout << "Wear something sturdy!"<< endl;
        break;
    }
return 0;
}