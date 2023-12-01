#include <iostream>
#include <string>

using namespace std;

int main()
{
    string weather;
    cout << "What the weather: ";
    cin >> weather;
    char w = weather[0];
    if (weather == "rainy" || weather == "snowy"){
        cout << "You should wear a jacket today" << endl;
    }
    else if (weather == "sunny" || weather == "cloudy" || weather == "windy"){
        cout << "You don't need a jacket today" << endl;
    }
    else{
      cout << "Invalid input" <<endl;
    }
    
    if (weather == "sunny"){
        cout << "Go to swim" << endl;
    }
    else if (weather == "cloudy"){
        cout << "Stay at home "<< endl;
    }
    else if (weather == "rainy"){
        cout << "Play dota 2" << endl;
    }
    else if (weather == "snowy"){
        cout << "Play snowballs" << endl;
    }
    else if (weather == "windy"){
        cout << "Time to do nothing" << endl;
    }
    
    switch (w){
    case 's':
        if(weather == "sunny"){
            cout<<"sneakers"<<endl;
        }
        else if(weather == "snowy"){
            cout<<"boots"<<endl;
        }
        break;
    case 'r':
        cout<<"rubber boots"<<endl;
        break;
    case 'c':
        cout<<"warm sneakers"<<endl;
        break;
    case 'w':
        cout<<"trainers";
        break;
    }   
    return 0;
}
