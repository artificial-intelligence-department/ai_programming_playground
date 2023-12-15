#include <iostream>
#include <string>

using namespace std;



int main() {

    cout<<("write type of weather:");

    string a = "sunny";
    string b = "rainy";
    string c = "cloudy";
    string d = "snowy";
    string e = "windy";
   


    string typeofweather;
    cin >> typeofweather;
    cout <<"weather outside is:"<<typeofweather<<endl;

    if (typeofweather == a){
        cout << "you should get drees T-shirt" << endl;

    }
    else if(typeofweather == b){
        cout << "you should get dress raincoat" << endl;
    }
    else if(typeofweather == c){
        cout << "you should take umbrella" << endl;
    }
    else if(typeofweather == d){
        cout << "you should get dress pullover " << endl;
    }
     else if(typeofweather == e){
        cout << "you should get dress scarf" << endl;
    }
    
    switch (typeofweather[1]){
     case 'u':
     case 'U':
        if (typeofweather == "sunny" || "Sunny"){
            cout << "i think you should take with you a boutle of water!" << endl;
        }
        break;
    case 'N':
    case 'n':
        if (typeofweather == "Snowy" || "snowy"){
            cout << "you can make a snowman :)" << endl;
            cout << "you really need something warm" << endl;}
        else{
          cout << "you really need something warm" << endl;  
        }
        break;
    case 'a':
    case 'L': 
    case 'I':
    case 'i': 
    case 'A': 
    case 'l':
        cout << "you should Wear boots" << endl;
        break;  
     default:
        cout << "Error" << endl;
        break;
    }
        
        
    return 0;
}
