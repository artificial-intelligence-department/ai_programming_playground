#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

enum wheathers{
    sunny,
    rainy,
    cloudy, 
    snowy, 
    windy
};

int main(){
    string WHEATHER;
    wheathers wheathertype;

    cout <<"Введіть які зараз погодні умови(sunny, rainy, cloudy, snowy, windy): ";
    cin >> WHEATHER;

    bool wheather_exeptable = false;

    while(!wheather_exeptable){
        if(WHEATHER == "sunny" || WHEATHER == "rainy" || WHEATHER == "cloudy" || WHEATHER == "snowy" || WHEATHER == "windy"){
            wheather_exeptable = true;
        }
        else{
            cout << "введіть правильне значення: ";
            cin >> WHEATHER;
        }
    }

    if(WHEATHER != "sunny"){
        cout << "вдягніть куртку" << endl;
    }
    else{
        cout << "йдіть голі" << endl;
    }
    if(WHEATHER == "sunny"){
        cout << "рекомендую пограти в футбол" << endl;
    }
    else if(WHEATHER == "cloudy"){
        cout << "рекомендую прогулятись" << endl;
    }
    else{
        cout << "рекомендую пограти в настільні ігри" << endl;
    }

    if(WHEATHER == "sunny"){
        wheathertype=wheathers::sunny;
    }
    else if(WHEATHER == "snowy"){
        wheathertype=wheathers::snowy;
    }
    else if(WHEATHER == "windy"){
        wheathertype=wheathers::windy;
    }
    else if(WHEATHER == "rainy"){
        wheathertype=wheathers::rainy;
    }
    else if(WHEATHER == "cloudy"){
        wheathertype=wheathers::cloudy;
    }

    switch(wheathertype){
   case wheathers::rainy:
       cout<<"беріть сапожки"<<endl;
       break;
   case wheathers::windy:
       cout<<"беріть тепле взуття"<<endl;
       break;
   case wheathers::cloudy:
       cout<<"беріть щось, що не промокне"<<endl;
       break;
   case wheathers::sunny:
       cout<<"вдягайте шльопки"<<endl;
       break;
   case wheathers::snowy:
       cout<<"сапожки і бахіли - ваш виір"<<endl;
       break;
    }
    
}
