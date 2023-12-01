#include <iostream>
#include <string>
using namespace std;

int main(){

    string w; //weather

    cout << "What the weather:" << endl;

    cin >> w; // w = weather

    if(w == "sunny" || w == "cloudy"){
        cout << "wear T-shirt" << endl;
    }if(w == "rainy" || w =="snowy"){
        cout << "wear jacket" << endl;
    }if(w == "windy"){
        cout << "wear big jacket" << endl;
    }
    if(w == "sunny" || w == "cloudy"){
        cout << "go for a walk" << endl;
    }else if(w == "rainy" || w=="snowy"){
        cout << "play computer games" << endl;
    }else if(w == "windy"){
        cout << "sleep" << endl;
    }else{
        cout << "Weather in progress.." << endl;
    }
    switch(w[0])
    {
    case 'c':
    case 'C':
        cout << "Wear sneakers";
        break;
    case 's':
    case 'S':
        cout << "Wear crocks";
        break;
    case 'r':
    case 'R':
        cout << "Wear boots";
        break;
    case 'n':
    case 'N':
        cout << "Wear gavnodavi";
        break;
    case 'w':
    case 'W':
        cout << "Wear sneakers";
        break;
    }
    return 0;
}
