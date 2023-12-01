#include <iostream>
#include <string>

using namespace std;
int main() {
string weather;
cout <<"What's the weather like today? (sunny, rainy, cloudy, snowy, windy)" << endl;
cin >> weather;

while (weather!="sunny" && weather!="rainy" && weather!="cloudy" && weather!="snowy" && weather!="windy" ) {
    cout << "Please choose from recommended options" << endl;
    cin >> weather;
}

if (weather=="sunny" || weather=="rainy" || weather=="cloudy" || weather=="snowy" || weather=="windy" ) {

if (weather=="snowy" || weather=="rainy") {
    cout << "Wear your coat!" << endl;
}
else {
    cout << "Don't wear a coat" << endl;
}

if (weather=="sunny") {
    cout << "A great day to have a picnic!" << endl;
}

if (weather=="rainy") {
    cout << "Awesome day to read a book inside!" << endl;
}

if (weather=="cloudy") {
    cout << "Why not visit a museum?" << endl;
}

if (weather=="snowy") {
    cout << "What about making a snowman?" << endl;
}

if (weather=="windy") {
    cout << "Fly a kite if you have one!" << endl;
}

enum weather_conditions { //це тип змінної
    sunny,
    rainy,
    cloudy,
    snowy,
    windy
};
weather_conditions i; //сама змінна
switch (i)
{
case 0:
    cout << "Wear your favourite pair of trainers!" << endl;
    break;
case 1:
    cout << "It's a good idea to wear rubber boots..." << endl;
    break;
case 2:
    cout << "You can wear anything you want" << endl;
    break;
case 3:
    cout << "Boots are going to warm your feet up!" << endl;
    break;
case 4:
    cout << "Wear something strong!" << endl;
    break;
}
}

return 0;
}

