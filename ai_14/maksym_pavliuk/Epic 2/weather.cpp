#include<iostream>

using namespace std;

int main(){
    string WeatherCondition;
    int WeatherConditionInt;
    cout << "\nPossible inputs: snowy, rainy, sunny, windy, cloudy ";
    
    while(WeatherCondition != "cloudy" && WeatherCondition != "rainy" && WeatherCondition != "snowy" && 
    WeatherCondition != "windy" && WeatherCondition != "sunny"){
        cout << "\nPlease input the weather conditions: ";
        cin >> WeatherCondition;
    }

    if(WeatherCondition == "rainy" || WeatherCondition == "snowy"){
        cout << "\nYou should put on a jacket! It's " << WeatherCondition << " outside\n";
    } else {
        cout << "\nYou will be aight without a jacket. It's " << WeatherCondition << " outside\n";
    }

    if( WeatherCondition == "rainy" ){  
        cout << "\nIdeal weather to stay inside and read some books! ";
        WeatherConditionInt = 1;
    }else if( WeatherCondition == "snowy" ){
        cout << "\nHow about making a snowman? ";
        WeatherConditionInt = 2;
    }else if( WeatherCondition == "sunny" ){
        cout << "\nA great day for a picnic! ";
        WeatherConditionInt = 3;
    }else if( WeatherCondition == "windy" ){
        cout << "\nYou could fly a kite if you had one rn! ";
        WeatherConditionInt = 4;
    }else{
        cout << "\nWanna go to a museum?";
        WeatherConditionInt = 5;
    }

    switch(WeatherConditionInt){
        case 1:
            cout << "\nYou should wear rain boots" << endl;
            break;
        case 2:
            cout << "\nYou should wear snow boots" << endl;
            break;
        case 3:
            cout << "\nYou should wear your favorite sneakers!" << endl;
            break;
        case 4:
            cout << "\nYou should wear something stronger for the boots" << endl;
            break;
        case 5:
            cout << "\nYou could wear anything you want!" << endl;
            break;
    }

    cout << endl;

    return 0;
}