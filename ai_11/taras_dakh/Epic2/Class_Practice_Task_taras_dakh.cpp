#include <iostream>
#include <string>
using namespace std;

int main()
{
    string type;

    cout<< "enter weather: ";
    cin>> type;
    if(type == "sunny"){
        cout << "you don't take a jacket"<<endl;
    }
    else{
        cout<<" take a jacket with you"<<endl;
    }

    if(type=="rainy"){
        cout<<"stay home"<<endl;
    }else if(type=="sunny"){
        cout<<"go walk with your friends"<<endl;
    }else if(type=="cloudy"){
        cout<<"play football"<<endl;
    }else if(type=="snowy"){
        cout<<"go for a walk"<<endl;
    }else if(type=="windy"){
        cout<<"stay home and drink tea"<<endl;
    }

   
    switch (type[0])
    {
    case 's':
    if(type=="sunny"){
        cout<<"wear sandals"<<endl;
    }else if(type=="snowy"){
        cout<<"wear boots"<<endl;
    }
        break;
    case 'r':
    cout<<"wear trainers"<<endl;
        break;
    case 'c':
    cout<<"wear sneakers"<<endl;
        break;
    case 'w':
    cout<<"wear sneakers"<<endl;
        break;
        default:
        cout<<"you entered wrong weather"<<endl;
    }

       
    return 0; 
}