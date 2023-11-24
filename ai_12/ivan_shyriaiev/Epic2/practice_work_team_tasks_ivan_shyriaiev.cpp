#include<iostream>
#include<string>
using namespace std;


int main(){

string weatherconditions[] = {"sunny", "rainy", "cloudy", "snowy", "windy"};
string  YOUrweather;
bool findWeatherCondition;
int casenumber;
cout<< " Here is possible weather conditions:\n"<< " - sunny\n"<< " - rainy\n"<< " - cloudy\n"<< " - snowy\n"<< " - windy\n";
cout<< "Enter your weather\n";

do{
    cin>> YOUrweather;
for(int i = 0; i<5 ; i++){
        if (YOUrweather == weatherconditions[i]){
            findWeatherCondition = true;
            casenumber = i+1;
            break;
             }      
                          }
            if(findWeatherCondition == false){
                cout<< "try again\n";}
}
while (  findWeatherCondition == false );

if(YOUrweather == weatherconditions[1]||YOUrweather == weatherconditions[3]){
    cout<< "take jacket with you\n";
} else {
    cout<< "you dont need jacket\n";
}

if(YOUrweather == weatherconditions[0]){
    cout<<"great day for picnic!\n";
}else if(YOUrweather == weatherconditions[1]){
    cout<<"ideal for reading book inside\n";
}else if(YOUrweather == weatherconditions[2]){
    cout<<"maybe go to museum?\n";
}else if(YOUrweather == weatherconditions[3]){
    cout<<"make a snowman\n";
}else if(YOUrweather == weatherconditions[4]){
    cout<<"fly the kite!(if you have one)\n";
}

switch (casenumber)
{
case 1:
    cout<<"put on your favourite shoes";
    break;
case 2:
    cout<<"rain boots - good idea!";
    break;
case 3:
    cout<<"any shoes is good!";
    break;
case 4:
    cout<<"put on warm boots";
    break;
case 5:
    cout<<"put on something sturdy";
    break;
}
     


            }
