#include <iostream>
#include <string>
using namespace std;
void WhetherToWearAJacket(string weather){
    if (weather == "rainy" || weather == "snowy"){
        cout << "Wear the jacket!" << endl;
    }
    else if (weather == "sunny" || weather == "cloudy" || weather == "windy"){
        cout << "Dont wear the jacket!" << endl;
    }
    else{
        cout << "Weather condition invalid!" << endl;
    }
}
void WhatToDo(string weather){
    if (weather == "sunny"){
        cout << "Let's play footbal or valleyball!" << endl;
    }
    else if (weather == "cloudy"){
        cout << "Time to play frisbee!" << endl;
    }
    else if (weather == "rainy"){
        cout << "Time to read a book!" << endl;
    }
    else if (weather == "snowy"){
        cout << "Play snowballs!" << endl;
    }
    else if (weather == "windy"){
        cout << "You can play tennis in the hall!" << endl;
    }
} 
void WhatShoes(string weather, char w){
    switch (w){
    case 's':
        if(weather == "sunny"){
            cout<<"You should wear fliplops!"<<endl;
        }
        else if(weather == "snowy"){
            cout<<"You should wear boots!"<<endl;
        }
        break;
    case 'r':
        cout<<"You should wear wellingtons!"<<endl;
        break;
    case 'c':
        cout<<"You should wear shoes!"<<endl;
        break;
    case 'w':
        cout<<"You should wear trainers!";
        break;
    }   
}
int main(){
    string weather;
    cout << "What the weather (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;
    char w = weather[0];
    WhetherToWearAJacket (weather);
    WhatToDo (weather);
    WhatShoes (weather, w);
    return 0;
}
