#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather;
    cout << "Enter weather : ";
    getline (cin, weather);
    string question;


    if (weather=="sunny"||weather=="rainy"||weather=="cloudy"||weather=="snowy"||weather=="windy") {

        if (weather=="sunny" || weather=="cloudy") {
            cout << "jacket is not required\n";
        }
        else {
            cout << "you should wear a jacket\n";
        }

        if (weather=="sunny") {
            cout << "Take a walk\n";
        }

        else if (weather=="cloudy") {
            cout << "Make yourself a cup of tea\n";
        }

        else if (weather=="windy") {
            cout << "Make a hot chocolate\n";
        }

        else if (weather=="rainy") {
            cout << "Watch a film\n";
        }

        else if (weather=="snowy") {
            cout << "Make a snowman\n";
        }
        

        
        switch (weather[0]) {

            case 's' :
            if (weather[1]='n') {
                cout << "wear boots\n";
            } 
            else {
                cout << "wear sneakers\n";
            }
            break;

            case 'r' :
            cout << "wear boots\n";
            break;

            case 'w' :
            cout << "wear loffers\n";
            break;
                
            case 'c' :
            cout << "wear loffers\n";
            break;

        }
        
    }

    else {
        cout << "invalid input\n";
    }
}