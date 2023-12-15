#include<iostream>
using namespace std;

int main(){
    bool WeatherIdentify = false;
    int option;
    string weather;
    string sun = "sunny", wind = "windy", snow = "snowy", cloud = "cloudy", rain = "rainy";
    cout<<"Choose one of the options \n-sunny \n-rainy \n-cloudy \n-snowy \n-windy"<<endl;
    cin>>weather;

    //Перевірка на істиність вибору погоди
    
    while(WeatherIdentify == false){
        if(weather == sun || weather == wind || weather == snow || weather == cloud || weather == rain) WeatherIdentify = true;
        else{
            cout<<"Try to enter another option"<<endl;
            cin>>weather;
        }
    }
    
    //Задання умови з надіванням куртки

    if(weather == snow || weather == rain) cout<<"The weather is too cold. You must put your jacket on."<<endl;
    else cout<<"The weather is warm. You shouldn't put your jacket on."<<endl;
    
    //Задання умови для вибору діяльності. Задання умови для вибору взуття

    if(weather == sun){
         cout<<"It's perfect weather for the picnic."<<endl;
         option = 1;
    }
    else if(weather == rain){
        cout<<"It's perfect weather for staying at home and reading a book."<<endl;
        option = 2;
    }
    else if(weather == cloud){
        cout<<"It's a great opportunity to visit a museum."<<endl;
        option = 3;
    }
    else if(weather == snow){
        cout<<"It's the best time for making a snowman."<<endl;
        option = 4;
    }
    else{
        cout<<"If you have a kite, it's a great chance to have a fun and spend your time outside."<<endl;
        option = 5;
    }

    switch(option){
        case 1: cout<<"You can put your favorite sneakers on."<<endl; break;
        case 2: cout<<"It's a good idea to put on boots."<<endl; break;
        case 3: cout<<"You can choose any kind of the shoes."<<endl; break;
        case 4: cout<<"You'd better put on winter boots."<<endl; break;
        case 5: cout<<"You should put on something warm."<<endl; break;
    }
    return 0;
}