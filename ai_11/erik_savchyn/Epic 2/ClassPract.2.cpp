#include <iostream>
#include <string>
using namespace std;

int main(){
    string weather;
    cout << "What the weather (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;
    char w = weather[0];

    if (weather == "rainy" || weather == "snowy"){
        cout << "Wear the jacket!" << endl;
    }
    else if (weather == "sunny" || weather == "cloudy" || weather == "windy"){
        cout << "Dont wear the jacket!" << endl;
    }
    else{
        cout << "Weather condition invalid!" << endl;
    }

    if (weather == "sunny"){
        cout << "Let's play football or valleyball!" << endl;
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

    return 0;
}