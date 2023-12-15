#include <iostream>
#include <string>
using namespace std;

int main(){
    string weather;
    
    weatherInput:
    cin >> weather;
    transform(weather.begin(), weather.end(), weather.begin(), ::tolower);
    
    if(weather == "sunny" || weather == "cloudy" || weather == "windy" || weather == "rainy" || weather == "snowy"){
        cout << "My advice for " << weather << " weather is:\n";
    }else{
        cout << "Invalid input. Try again\n";
        goto weatherInput;
    }
    
    if (weather == "rainy" || weather == "snowy"){
            cout << "Please put on a jacket!\n";
    }else{
            cout << "You do not need a jacket\n";
    }
    
    if (weather == "sunny"){
            cout << "Play outside\n";
    }else if(weather == "rainy"){
            cout << "Perfect weather for reading a book with a cup of tea\n";
    }else if(weather == "snowy"){
            cout << "Make a snowman!\n";
    }else if(weather == "cloudy"){
            cout << "Maybe you should go to the cinema?\n";
    }else if(weather == "windy"){
            cout << "Stay at home, play board games\n";
    }

    char sunny = 's', cloudy = 'c', rainy = 'r', snowy = 's', windy = 'w';
    switch (weather[0]){
        case 's':
            if(weather == "sunny"){
                cout << "You should wear flip-flops\n";
                break;
            }else if(weather == "snowy"){
                cout << "You should wear warm boots\n";
                break;
            }
        case  'c':
            cout << "You can wear any shoes\n";
            break;
        case 'r':
            cout << "You should wear rain boots\n";
            break;
        case 'w':
            cout << "You should wear sneakers\n";
            break;
    }

    return 0;
}