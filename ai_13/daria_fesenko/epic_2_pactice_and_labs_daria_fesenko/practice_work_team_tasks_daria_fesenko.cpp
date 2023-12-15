#include <cstdio>
#include <cmath>
#include <iostream> 
#include <string>
using namespace std;

int main () {
    string weather;
    cout << "Please enter the current weather (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

    if (weather == "sunny" ) {
        cout << "You should wear a cap today." << endl;
    } else if (weather == "cloudy") {
        cout << "It may rain today, dont forget your umbrella." << endl;
    } else if (weather == "windy") {
        cout << "Today its better to refrain from walking outside." << endl;
    }  else if  (weather == "snowy") {
       cout << "Lets go skiing." << endl;
     }  else if (weather == "rainy") {
        cout << "You should wear a jacket today." << endl;
 }

    switch (weather.at(0)) 
    {
    case 's':
    if (weather.at(1)=='u')
    cout << "Lets go to the swimming pool" << endl;
    else 
      cout << "Wait for better weather" << endl;
        break;
    
    case 'c':
    cout << "It looks like it will rain soon" << endl;
     break;

     case 'r':
     cout << "Lets take a walk in the rain!" << endl;
     break;

     case 'w':
     cout << "We should stay home today" << endl;
     break;
    
    default:
            cout << "Invalid weather condition input." << endl;

        break;
    }
return 0;

}
