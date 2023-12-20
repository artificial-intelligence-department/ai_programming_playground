#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    /* Особистий порадник щодо погоди. Користувач вводить поточні погодні умови, 
     а програма видає рекомендації щодо активності на основі погоди */
    string weather;
    cin >> weather; // sunny; rainy; cloudy; snowy; windy;
    if ( weather == "sunny" || weather == "rainy" || weather == "cloudy" || weather == "snowy" || weather == "windy" ) {
        if ( weather == "sunny") {
            cout << "It's a great day for a picnic! \n";
        } else if ( weather == "rainy" ) { 
            cout << "Please, put on a jacket \n";
            cout << "Perfect weather to read a book inside! \n";
        } else if ( weather == "cloudy" ) {
            cout << "Maybe visit a museum? \n";
        } else if ( weather == "snowy" ) { 
            cout << "Please, put on a jacket \n";
            cout << "How about making a snowman? \n";
        } else if ( weather == "windy" ) {
            cout << "Fly a kite if you have one! \n";
        } else {
            cout << "You don't need a jacket \n";
        }
        switch ( weather[1] ) {
         case 'u' :
         cout << "Wear your favorite sneakers! \n";
         break;
         case 'a' :
         cout << "Rain boots are a good idea! \n";
         break;
         case 'l' :
         cout << "Today, any shoe is suitable \n";
         break;
         case 'n' :
         cout << "Snow boots will keep your feet warm! \n";
         break;
         case 'i' :
         cout << "Wear something sturdy! \n";
         break;
    }
        } else {
            cout << "Please, enter a valid condition \n";
        }
}

 