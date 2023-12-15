#include <iostream>
#include <string>
using namespace std;

int main() {
    string weather;
    string a = "sunny"; 
    string b = "rainy"; 
    string c = "cloudy"; 
    string d = "snowy"; 
    string e = "windy"; 
    
    while (weather != a && weather != b && weather != c && weather != d && weather != e) {
    cout << "What is the weather today?Choose from this variants : sunny , rainy , cloudy , snowy , windy.Write here:\n";
    cin >> weather;}

    if(weather == b || weather == c || weather == d || weather == e){
      cout <<"You should take a jacket";  
    }
    else{
        cout << "It is not necessary to take a jacket";
    }

    if (weather == a){
        cout << "It is time to go playing football\n";
        cout << "Hurry up!";
    }
    else if(weather == b){
        cout << "You can spend time with family at home";
    }
    else if(weather == c){
        cout << "You should go for a walk";
    }
    else if(weather == d){
        cout << "You can go skiing";
    }
    else if(weather == e){
        cout << "You can fly a kite";
    }

    switch (weather[8])
    {
    case 'q':
    cout<<"Put on sandals";
        break;
    case 'w':
    cout<<"Put on rain boots";
        break;
    case 'r':
    cout<<"Put on sneakers";
        break;
    case 't':
    cout<<"Put on boots";
        break;
    case 'y':
    cout<<"Put on flats";
        break;
    }
    return 0;
}

   