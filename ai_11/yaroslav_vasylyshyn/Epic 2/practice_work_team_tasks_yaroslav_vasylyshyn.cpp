#include <iostream>
#include <string>

using namespace std;
int main(){
    string weather;
    cout<<"Enter a weather: "
    cin>>weather;
    if (weather=="rainy"||weather=="snowy"||weather=="windy"){
        cout<<"Take a jacket with u;"<<endl;
    }else{
        cout<<"Don't take a jacket with u;"<<endl;
    }

    if(weather=="sunny"){
        cout<<"Go for a walk;"<<endl;
    }else if(weather=="rainy"){ 
        cout<<"Play cs;"<<endl;
    }else if(weather=="cloudy"){ 
        cout<<"Play dota;"<<endl;
    }else if(weather=="snowy"){ 
        cout<<"Play snowballs;"<<endl;
    }else if(weather=="windy"){ 
        cout<<"Play wot;"<<endl;
    }

    char sw = weather[0];
    switch(sw)
    {
        case('s'):
        if(weather=="sunny"){
        cout<<"Wear sneakers;";
        }else if(weather=="snowy"){
        cout<<"Wear boots;";
        }
        break;
        case('r'):
        cout<<"Wear boots";
        break;
        case('c'):
        cout<<"Wear sneakers";
        break;
        case('w'):
        cout<<"Wear boots";
        break;
        default:
        cout<<"Enter an appropriate weather";
        break;
    }
    
    return 0;
}