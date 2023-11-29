#include<iostream>
#include<string>
#include<vector>


std::string weather;
std::vector<std::string> w_type;
int main(){
    using namespace std;

    w_type = {"sunny","rainy","cloudy","snowy","windy"};

    cout << "Enter your weather: ";
    cin >> weather;

    bool accepted_weather = false;

    while(not accepted_weather){
        for(int i = 0; i <= w_type.size(); ++i){
            if(w_type[i] == weather)
                accepted_weather = true;
        }
        if(not accepted_weather){
            cout << "incorrect weather type,please enter weather type again: ";
            cin >> weather;
        }
        
        if(weather == "snowy" || weather == "rainy")
            cout << "You should wear a jacket today" << endl;
        else
            cout << "You dont need a jacket today" << endl;
        
        if(weather == "sunny")
            cout << "it's a great day for a picnic" << endl;

        if(weather == "rainy")
            cout << "Perfect weather to stay inside" << endl;

        if(weather == "cloudy")
            cout << "Maybe you should visit a museum" << endl;
        
        if(weather == "snowy")
            cout << "How about building a snowman?" << endl;
        
        if(weather == "windy")
            cout << "Fly a kite if you have one" << endl;

        switch (weather[0]){
            case 's':
                if(weather == "sunny")
                    cout << "Wear your favourite sneakers" << endl;
                else
                    cout << "Snow boots will keep your feet warm" << endl;
                break;
            case 'r':
                cout << "Rain boots are a good idea!" << endl;
                break;
            case 'c':
                cout << "Any footwear is fine today." << endl;
                break;
            case 'w':
                cout << "Wear something sturdy!" << endl;
                break;
            default:
                cout << "Invalid weather condition input." << endl;
                break;
        }

    }
    return 0;
}


