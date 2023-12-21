#include <iostream>
#include <string>


using namespace std;


enum WeatherTypes {sunny, rainy, cloudy, snowy, windy};


int main(){
    string weather;
    int weatherType;
    LabelMenu:
    cout << "Enter the weather conditions  " << endl;
    cin >> weather;
   
    if (weather == "windy" || weather == "rainy" || weather == "snowy"){
        cout << "одягніть куртку" << endl;
    } else if(weather == "sunny" || weather == "cloudy" )
        cout << "не одягайте куртку" << endl;
    else{
        cout << "You entered unappropriate data  ";
        goto LabelMenu;
    }
        if (weather == "sunny"){
        weatherType = WeatherTypes::sunny;
        cout << "Nice day for a picnic!" << endl;
    } else if (weather == "rainy"){
        weatherType = WeatherTypes::rainy;
        cout << "An ideal for reading a book" << endl;
    } else if (weather == "cloudy"){
        weatherType = WeatherTypes::cloudy;
        cout << "Maybe, visit the museum?" << endl;
    } else if(weather == "snowy"){
        weatherType = WeatherTypes::snowy;
        cout << "What about making snowman?" << endl;
    } else if (weather == "windy"){
        weatherType = WeatherTypes::windy;
        cout << "What about flying a kite?" << endl;
    }


    switch (weatherType)
    {
        case sunny:
            cout << "Wear your favourite shoes";
        break;


        case rainy:
            cout << "Rainy boots is an ideal shoes";
        break;


        case cloudy:
            cout << "You can wear any shoes";
        break;


        case snowy:
            cout << "waterproof shoe";
        break;


        case windy:
            cout << "Wear something strong";
        break;
    }
    return 0;
    }


