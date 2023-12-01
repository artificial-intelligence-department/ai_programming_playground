#include <iostream>
#include <string>

using namespace std;
int main(){
    string weather;

    cout<<"What weather?"<<endl;
    cin>>weather;

    cout<<"Should i wear a coat?"<<endl;
        if(weather=="sunny"){
        cout<<"You don't need a coat"<<endl;}

        else 
        cout<<"You should wear a coat"<<endl;

    cout<<"Which type of activity?"<<endl;
        if(weather=="sunny"){
        cout<<"Play football"<<endl;}

        else if(weather=="rainy"){
        cout<<"Take an umbrella "<<endl;}

        else if(weather=="cloudy"){
        cout<<"Go to a cafe"<<endl;}

        else if(weather=="snowy"){
        cout<<"Play snowballs"<<endl;}

        else if(weather=="windy"){
        cout<<"Stay at home"<<endl;}

    cout<<"Which footwear?"<<endl;
        switch (weather[0]){

        case 's':
        if (weather=="sunny"){
        cout<<"Light trainers"<<endl;}
        else if(weather=="snowy"){
        cout<<"Warm boots"<<endl;}
        break;

        case 'r':
        cout<<"Rain shoes"<<endl;
        break;

        case 'c':
        cout<<"Trainers"<<endl;
        break;

        case 'w':
        cout<<"Trainers"<<endl;
        break;
        }
    return 0;
    }



        
    
    
