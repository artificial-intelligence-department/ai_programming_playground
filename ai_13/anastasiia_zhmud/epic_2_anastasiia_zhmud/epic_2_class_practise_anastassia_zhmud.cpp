#include<iostream>
#include<string>
using namespace std;
int main(){
    string sunny="sunny";
    string rainy="rainy";
    string cloudy="cloudy";
    string snowy="snowy";
    string windy="windy";
    string weather;
    cout<<"Enter weather tipe:\n";
    cin >> weather;
    if(weather==rainy || weather == snowy || weather == windy){
        cout<<"It's better to wear a jacket\n\n";
    } else{
        cout<<"It`s warm outside, you don`t need a jacket\n\n";
    }
    if(weather==sunny || weather == cloudy){
        cout<<"You can go for a walk\n\n";
    } else{
        cout<<"You can visit your friends\n\n";
    } 
    switch (weather[0])
        {
        case 'r': 
        cout <<"It is better to choose waterproof shoes";
        break;
        case 'w' || 'c':
        cout<<"It is better to choose sneakers or some warmer";
        break;
        case 's':
        if(weather[1]=='n'){
            cout<<"It is better to choose warm shoes";
        } else{
            cout<<"It is better to choose something like convers or loafers";
        }
    }
}