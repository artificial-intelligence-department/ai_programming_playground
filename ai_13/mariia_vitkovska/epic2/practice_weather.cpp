#include <iostream>
#include <stdio.h>
 
using namespace std;
 int main() {
    string weather;
    cout << "What the weather is today?" << endl;
    cin >> weather;

    if (weather == "sunny") {
        cout << "You don't need a jacket going outside" << endl;
    }
    else if (weather == "windy"|| weather == "rainy"|| weather == " cloudy"|| weather =="snowy") {
        cout << "You should wear a jacket going outside" << endl;
    }
   


    if (weather == "sunny") {
        cout << "Let's go for a walk" << endl;
    } 
    else if (weather == "snowy") {
        cout << "Let's play snowballs" << endl;
    }
    else if ( weather == "rainy" ) {
        cout << "Let's go outside and jump in puddles " << endl;
    }
    else if (weather == "windy") {
        cout << "Let's go to the cafe" << endl;
    }
    else if (weather == "cloudy" ) {
        cout << "Let's take some pictures outside" << endl;
    }
    
    
    
    switch (weather[0]) {
        case 's' :
            if (weather=="sunny") {
                cout << "Put on something light" << endl;
            }
            else {
                cout << "Wear winter boots" << endl;
            }
        break;

        case 'r' :
            if (weather == "rainy") {
                cout << "Put on rubber boots" << endl;
            }
        break;
        
        case 'w' :
            if (weather == "windy")  {
                cout << "Wear your favourite pair of sneakers" << endl;
            }
        break;
        
        case 'c' :
            if (weather == "cloudy") {
                cout << "Put on any type of shoes" << endl;
            }
        break;
    }

    return 0;
 }