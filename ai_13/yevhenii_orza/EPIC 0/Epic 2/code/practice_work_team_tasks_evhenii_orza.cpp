#include <iostream>
#include <string>
using namespace std;
int main(){
    string typeOfWeather;
    cout << "Enter what weather outside: ";

    cin >> typeOfWeather;
    cout << endl;
    cout << "Your weather is: " << typeOfWeather << endl;

    if (typeOfWeather == "Sunny" || typeOfWeather == "sunny"){
        cout << "You don`t need jacket" << endl;
    } else{
        cout << "You realy need something warmer than skinny"<< endl;
    }
    if (typeOfWeather == "Sunny" || typeOfWeather == "sunny" || typeOfWeather == "Cloudy" || typeOfWeather == "cloudy") {
        cout << "You can go for a wolk, play football, basketball and ect. Feel free in choise" << endl;
    }else if(typeOfWeather == "snowy" || typeOfWeather == "Snowy"){
        cout << "Oh! you can play snowball, make a SnowMan, or sit home and drink hot chockolate" << endl;
    }else {
        cout << "You should stay home, dont good weather to go outside" << endl;
    }
    switch (typeOfWeather[0])
    {
     case 'S':
     case 's':
        if (typeOfWeather == "Snowy"){
            cout << "take realy warm boots" << endl;
        }else{
        cout << "You need to wear flip-flops or same things:)" << endl;}
        break;
     case 'C': 
     case 'c':
     case 'W':
     case 'w': 
     case 'R': 
     case 'r':
        cout << "Wear warm boots" << endl;
        break;  
     default:
     cout << "Error : go bearfood" << endl;
        break;
    }
    return 0;
}