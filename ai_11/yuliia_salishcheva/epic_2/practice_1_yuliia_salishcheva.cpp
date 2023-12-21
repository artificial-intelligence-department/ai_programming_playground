#include<iostream>
#include<string>
using namespace std;

int main(){
    string weather;
    cout<<"Please enter weather: ";
    cin>>weather;
    if (weather=="rainy"||weather=="cloudy"||weather=="snowy"||weather=="windy"){
        cout<<"Put on a jacket"<<endl;
    }
    else{
        cout<<"You don't have to put on a jacket"<<endl;
    }

    if(weather=="rainy"){
        cout<<"watch film"<<endl;
    }
    else if(weather=="clody"){
        cout<<"Go to the cinema"<<endl;
    }
    else if(weather=="snowy"){
        cout<<"Go to play snowballs"<<endl;
    }
    else if(weather=="windy"){
        cout<<"sit home"<<endl;
    }
    else if(weather=="sunny"){
        cout<<"Go to walk"<<endl;
    }

     
    switch(weather.at(0)){
        case 's':
            if(weather.at(1)=='u')
                cout<<"you can put on sandels"<<endl;
            else
                cout<<"you can put on boots"<<endl;
            break;
        case 'r':
            cout<<"you can put on trainers"<<endl;
            break;
        case 'c':
            cout<<"you can put on shoes"<<endl;
            break;
        case 'w':
            cout<<"you can put on windy shoes"<<endl;
            break;
        default :
            cout<<"invalid wether"<<endl;

    }


    return 0;

}