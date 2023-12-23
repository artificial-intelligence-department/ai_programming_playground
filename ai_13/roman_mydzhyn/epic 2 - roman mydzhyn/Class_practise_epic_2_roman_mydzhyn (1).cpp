#include <iostream>
#include <string>
using namespace std;
int main () {
  repeat:
  string weather = "rainy, sunny, cloudy, snowy, windy";
  string answear;
cout << "write what a weather is today?(" << weather << "):" << endl;
cin >> answear;
    if (answear == "sunny") {
      cout << "You don't need a jacket." << endl;
    } else if (answear == "rainy") {
      cout << "You should wear a jacket." << endl;
    } else if (answear == "cloudy") {
      cout << "You shouldn't wear jacket." << endl;
    } else if (answear == "snowy") {
      cout << "Wear a jacket." << endl;
    } else if (answear == "windy"){
    cout << "You should wear a jacket" << endl;
   }
   else{
    cout << "Invalid answear" << endl;
    goto repeat;
   }
    
if (answear == "sunny") {
  cout << "You can go for a picnic." << endl;
} else if (answear == "rainy") {
  cout << "Watch a movie or read a book." << endl;
} else if (answear == "cloudy") {
  cout << "You can go for a walk." << endl;
} else if (answear == "snowy") {
  cout << "Go skiing or build a snowman." << endl;
} else if (answear == "windy") {
  cout << "You can fly a kite." << endl;
} 


  switch (answear[0]) {
        case 's':
           if(answear[1] == 'u')
            cout << "Wear sandals or sneakers." << endl;

            else{
            cout << "Wear snow boots." << endl;
            }

            break;
        case 'r':
            cout << "Wear waterproof boots." << endl;
            break;
        case 'c':
            cout << "Wear sneakers." << endl;
            break;
      case 'w':
      cout << "Wear closed shoes." << endl;
          break;
            
   }
    return 0;
}