#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string weather;
    int con = 0;
    int w;
    cout << "Hello, i'm the weather advicer.\nTo start, enter type of weather:\n-sunny\n-rainy\n-cloudy\n-snowy\n-windy\n";
    while(con==0)
    {
        cin >> weather;
        if(weather == "sunny" ||weather == "rainy"||weather == "cloudy"||weather == "snowy"||weather == "windy")
        {
            con = 1;
        }
        else
        {
            cout << "\n \nPlease, enter real weather condition:\n-sunny\n-rainy\n-cloudy\n-snowy\n-windy\n" << weather << " - is not real type of weather.\n";
        }
    }
    if(weather == "rainy" || weather == "snowy" )
    {
        cout << "The weather is "<< weather<< " today. Please, wear jecket.\n";
    }
    else
    {
        cout << "Today is " << weather<<". You should not wear jecket.\n";
    }
    cout << "\n";
    if(weather == "sunny")
    {
        w=1;
        cout << "Today is nice weather to have picnic.\n";
    }
    else if(weather == "rainy")
    {
        w=2;
        cout << "Today's weather is not really good to go for a walk.\n It's better to stay inside and read.\n";
    }
    else if(weather == "cloudy")
    {
        w=3;
        cout <<"The best option today is visiting museum or theatre.\n";
    }
    else if(weather == "snowy")
    {
        w=4;
        cout <<"Today is nice weather to build a snowman.\n";
    }
    else if(weather == "windy")
    {  
        w=5; 
        cout <<"Yoy can fly kite if you have one!\n";
    }   
    cout<< "\n";
    switch(w)
    {
    case 1:
        cout << "Wear your the best shoes.\n";
        break;
    case 2:
        cout << "Wear rubber boots.\n";
        break;
    case 3:
        cout <<"You can wear anything you want.\n";
        break;
    case 4:
        cout <<"You should wear boots today, they will keep warm your legs.\n";
        break;
    case 5:
        cout <<"Wear strong shoes.\n";
    default:
        break;
    }
}