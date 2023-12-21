#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string weather;
    cout << "What is the weather like today? (sunny, rainy, windy, cloudy, snowy) " << endl;
    cin >> weather;
 if ( weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy" && weather != "sunny") {
        cout << "Please enter a valid weather condition." << endl;
        cin >> weather;
    }
    if (weather == "rainy"|| weather=="snowy")
        cout << "You need to wear a coat" << endl;
    else 
        cout << "You don't need to wear a coat" << endl;
    if (weather == "sunny")
        cout << "A great day to have a picnic" << endl;
    else if (weather == "rainy")
        cout << "The weather outside is perfect for staying indoors and enjoying a good book" << endl;
    else if (weather == "cloudy")
        cout << "Would you like to consider visiting a museum?" << endl;
    else if (weather == "windy")
        cout << "If you have a kite, go ahead and fly it" << endl;
        else if (weather == "snowy")
        cout << "How about making a snowman?" << endl;


    switch (weather[0]) {
        case 's':
            if(weather=="sunny"){
                cout<<"Wear your favorite sneakers!"<<endl;
            }
            else if(weather=="snowy"){
                cout<<"Snow boots will keep your feet warm!"<<endl;
            }
            break;
        case 'c':
            cout << "Today, any type of shoe can be worn" << endl;
            break;
        case 'w':
            cout << "Make sure to wear something sturdy" << endl;
            break;
        case 'r':
            cout << "Trust me, you won't regret wearing rain boots" << endl;
            break;
        default:
            break;
    }

    return 0;
}
