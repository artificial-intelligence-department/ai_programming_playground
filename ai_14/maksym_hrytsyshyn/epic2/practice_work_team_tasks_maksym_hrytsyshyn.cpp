#include <iostream>
#include <string>

using namespace std;

int main () {
   string weather;
   cout << "Enter the type of weather:" << '\n' ;
   cin >> weather;

   string sunny;
   string rainy;
   string cloudy;
   string windy;
   string snowy;

   if (weather == "sunny") {
    cout << "You shouldn't take the jacket with" << endl;
   } else if (weather == "rainy" || weather == "windy" || weather == "cloudy" || weather == "snowy" ) {
    cout << "You should take the jacket with" << endl;
   } else {
    cout << "Invalid weather type" << endl;
    return 0;
   }

   if (weather == "sunny") {
    cout << "You can go outside for a walk or playing football etc." << endl;
   } else if (weather == "rainy") {
    cout << "It's time for playing board games with your family or friends" << endl;
   } else if (weather == "windy") {
    cout << "That's a good weather for launching a kite on the field" << endl;
   } else if (weather == "cloudy") {
    cout << "That's a good idea to go in the museum, isn't it?" << endl; 
   } else if (weather == "snowy") {
    cout << "It's time for sledding or ice skating" << endl;
   } 


   switch (weather.at(0)) {
    case 's':
      if (weather.at(1)=='u') 
       cout << "It's a day to take your favourite sneakers" << endl;
       else 
        cout << "The weather calls for winter shoes" << endl;
      break;
    case 'r':
      cout << "It's worth taking rain boots" << endl;
      break;
    case 'c':
      cout << "You can choose any shoes" << endl;
      break;
    case 'w':
      cout << "Choose stronger shoes" << endl;
      break;
   }
    return 0;
   }
