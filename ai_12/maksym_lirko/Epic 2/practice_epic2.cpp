#include<iostream>
using namespace std;

int main()
{

    string weather;
    char weather_char;

    cout<<"Enter the weather condition(sunny,rainy,cloudy,snowy,windy): "<<endl;
    cin>>weather;
   
    
    if (weather !="sunny" && weather !="rainy" && weather  !="cloudy" && weather  !="snowy" && weather !="windy" )
    {
        cout<<"You enter wrong option. Try again!"<<endl;
        return 0;
    }
    weather_char = weather[1];

    if (weather == "rainy" || weather =="snowy" )
    {
        cout<<"You have to wear jacket!"<<endl;
    }
    else if (weather == "sunny" || weather == "cloudy" || weather == "windy")
    {
        cout<<"Dont wear a jacket!"<<endl;
    }

    if (weather =="sunny")
    {
        cout<<"A great day for a picnic!"<<endl;
    }
    else if(weather == "rainy")
    {
        cout<<"Perfect weather to read a book inside!"<<endl;
    }
    else if (weather =="cloudy")
    {
        cout<<"Maybe visit a museum?"<<endl;
    }
    else if(weather =="snowy")
    {
        cout<<"How about making a snowman?"<<endl;
    }
    else if(weather =="windy")
    {
        cout<<"Fly a kite if you have one!"<<endl;
    }

    switch (weather_char)
    {
    case 'u':
        cout<<"Wear your favorite sneakers!"<<endl;
        break;
    case 'a':
        cout<<"Rain boots are a good idea!"<<endl;
        break;
    case 'l':
        cout<<"Today, any shoe is suitable."<<endl;
        break;
    case 'n':
        cout<<"Snow boots will keep your feet warm!"<<endl;
        break;
    case 'i':
        cout<<"Wear something sturdy!"<<endl;
        break;
    }

    return 0;
}