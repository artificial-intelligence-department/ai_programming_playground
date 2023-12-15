#include <iostream> 
#include <string> 
using namespace std; 
 
int main() { 
    string type; 
 
    cout << "What is the weather like? "; 
    cin >> type; 
 
    if (type == "sunny") 
        cout << "You should wear light shoes and do not take a coat." << endl; 
    else if (type == "rainy") 
        cout << "You should take an umbrella, a coat, and wear waterproof boots." << endl; 
    else if (type == "cloudy") 
        cout << "Do not take sunglasses." << endl; 
    else if (type == "snowy") 
        cout << "Take a scarf, gloves, and a warm tea." << endl; 
    else if (type == "windy") 
        cout << "Take a scarf and warm clothes." << endl; 
    else 
        cout << "Oops, I don't know what you mean." << endl; 
 
    cout << "Do you like to spend time outside? (yes/no) "; 
    cin >> type; 
 
    if (type == "yes") { 
        cout << "What would you like to do outside? (u/a/l/n/i) "; 
        cin >> type; 
        switch (type[0]) { 
            case 'u': 
                cout << "Attend an amusement park." << endl; 
                break; 
            case 'a': 
                cout << "Take an umbrella and attend a library." << endl; 
                break; 
            case 'l': 
                cout << "Go shopping." << endl; 
                break; 
            case 'n': 
                cout << "Make a snowman near your house." << endl; 
                break; 
            case 'i': 
                cout << "Make a city tour." << endl; 
                break; 
            default: 
                cout << "Oops, I don't know what you mean." << endl; 
                break; 
        } 
    } else if (type == "no") { 
        cout << "What would you like to do inside? (u/a/l/n/i) "; 
        cin >> type; 
        switch (type[0]) { 
            case 'u': 
                cout << "Listen to music and clean your house." << endl; 
                break; 
            case 'a': 
                cout << "Watch Netflix." << endl; 
                break; 
            case 'l': 
                cout << "Bake some cookies." << endl; 
                break; 
            case 'n': 
                cout << "Knit some gloves." << endl; 
                break; 
            case 'i': 
                cout << "Read some books." << endl; 
                break; 
            default: 
                cout << "Oops, I don't know what you mean." << endl; 
                break; 
        } 
    } else { 
        cout << "Oops, I don't know what you mean." << endl; 
    } 
 
    return 0; 
}
