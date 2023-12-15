#include <iostream>
using namespace std;

int main()
{    
    string types[] = {"sunny", "rainy", "cloudy", "snowy", "windy"};

    string weath;

    cout << "What's the weather like today? (sunny, rainy, cloudy, snowy, windy)\n";
    cin >> weath;

    if(weath == "snowy" || weath == "rainy"){
        cout << "You should take a jacket!\n";
    } 
    else {
        cout << "No need a jacket!\n";
    }

    if(weath == "sunny"){
        cout << "A great day for a picnic!\n";
    }
    if((weath == "rainy")) {
        cout << "Good weather to read a book inside!\n";
    }
    if((weath == "cloudy")) {
        cout << "Maybe visit a museum?\n";
    }
    if((weath == "snowy")){
        cout << "How about making a snowman?\n";
    }
    else {
        cout << "Fly a kite if you have one!\n";
    }
    switch (weath[0]) {
    case 'su':
        if(weath == "sunny") {
            cout << "Wear your favorite sneakers!\n";
        }
        else {
            cout << "Snow boots will keep your feet warm!\n";
        }
        break;
    case 'ra':
        cout << "Rain boots are a good idea!\n";
        break;
    case 'cl':
        cout << "Today, any shoe is suitable.\n";
        break;
    case 'wi':
        cout << "Wear something sturdy!\n";
        break;
    }
    return 0;
}