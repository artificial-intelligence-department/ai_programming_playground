#include <iostream>
#include <string>
using namespace std;

int main() {
string weather;

int w;

cout << "Enter weather:";
cin >> weather;

// 1) Conditions
if(weather == "sunny") {
 cout << "You don't need a jacket \n";
 w = 1;
}
else if(weather == "rainy") {
    cout <<"You should take a jacket \n";
    w = 2;
}
else if(weather == "cloudy") {
    cout <<"You shouldn't take a jacket \n";
    w = 3;
}
else if(weather == "snowy"){
cout <<"You should take a jacket \n";
w = 4;
}
else if(weather == "windy"){
    cout <<"You should take a jacket \n";
    w = 5;
}


// 2)Type of activities
if (weather == "sunny"){
    cout <<"You can go play football \n";
}
else if(weather == "rainy"){
    cout <<"Sit at home and read a book \n";
}
else if(weather == "cloudy"){
    cout<<"Go for a walk \n";
}
else if(weather == "snowy"){
    cout<<"You can make a snowman \n";
}
else if(weather == "windy"){
    cout <<"You can fly a kite \n";
}

//3)Switch-Case

switch(w){
    case 1:
    cout << "Wear favourite sneakers";
    break;

    case 2:
    cout <<"Rain boots - it's a good idea!";
    break;

    case 3:
    cout<<"Any shoes fit today";
    break;

    case 4:
    cout<<"Wear something warm";
    break;

    case 5:
    cout << "Snow boots it's a good decision for this day";
    break;
}
    return 0;

}
