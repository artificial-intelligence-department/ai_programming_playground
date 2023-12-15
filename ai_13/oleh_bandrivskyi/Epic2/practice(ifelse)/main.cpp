#include <iostream>
#include <string>

using namespace std;

int main(){
    string weather;
    cout << "Enter the weather:" << endl;
    cin >> weather;
    if(weather == "sunny" || weather == "cloudy"){
        cout << "wear T-shirt" << endl;
    }if(weather == "rainy" || weather=="snowy"){
        cout << "wear jacket" << endl;
    }if(weather == "windy"){
        cout << "wear hudi" << endl;
    }

    if(weather == "sunny" || weather == "cloudy"){
        cout << "go for a walk" << endl;
    }else if(weather == "rainy" || weather=="snowy"){
        cout << "play table games" << endl;
    }else if(weather == "windy"){
        cout << "stay at home" << endl;
    }else{
        cout << "Weather in progress.." << endl;
    }

    switch(weather[0])
    {
    case 'c':
    case 'C':
        cout << "Wear sneakers";
        break;
    case 's':
    case 'S':
        cout << "Wear flip-flops";
        break;
    case 'r':
    case 'R':
        cout << "Wear boots";
        break;
    case 'n':
    case 'N':
        cout << "Wear boots";
        break;
    case 'w':
    case 'W':
        cout << "Wear sneakers";
        break;
    }

    return 0;
}