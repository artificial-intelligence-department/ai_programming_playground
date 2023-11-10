#include <iostream>
#include <string>

using namespace std;
int main(){
    string weather;
    cout<<"Enter a weather: ";
    cin>>weather;
    switch (weather[0]){
        case('s'):
            if(weather=="sunny")
                cout<<"Don't take a jacket with u;\nWear sneakers;\nGo for a walk;";
            else if(weather=="snowy")
                cout<<"Take a jacket with u;\nWear boots\nPlay football;";
        break;
        case('r'):;
            cout<<"Take a jacket with u;\nWear boots;\nPlay cards with ur fr;";
        break;
        case('c'):
            cout<<"Don't take a jacket with u;\nWear sneakers;\nPlay h&s;";
        break;
        case('w'):
            cout<<"Take a jacket with u;\nWear boots;\nPlay volleyball;";
        break;
        default:
            cout<<"Enter an appropriate weather;\n";
        break;
    }
}