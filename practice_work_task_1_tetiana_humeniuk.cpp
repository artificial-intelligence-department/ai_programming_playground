#include <iostream>
using namespace std;
int main()
{
    string weather;
    const string sunny = "sunny";
    const string rainy = "rainy";
    const string cloudy = "cloudy";
    const string snowy = "snowy";
    const string windy = "windy";
    cout<<"what is the weather?";
    cin>> weather;
    while (weather != sunny && weather != rainy && weather != cloudy && weather != snowy && weather != windy)
    {
        cout<<"what is the weather? sunny, rainy, cloudy, snowy or windy?";
        cin>> weather;
    }

        if(weather == sunny)
        {
            cout<<"Great day for a picnic"<<endl;
        }
        else if(weather == rainy)
        {
            cout<<"Perfect weather to read a book inside"<<endl;
        }
        else if(weather == cloudy)
        {
            cout<<"U can visit the museum"<<endl;
        }
        else if(weather == snowy)
        {
            cout<<"How about making a snowman"<<endl;
        }
        else if(weather == windy)
        {
            cout<<"Launch a kite if you have one"<<endl;
        }

        if(weather == snowy || weather == rainy )
        {
            cout<<"put on a jacket"<<endl;
        }
            
        switch (weather[1]) 
        {
        case /*sunny*/ 'u':
         cout<<"Wear your favorite sneakers";
         break;
        case /*rainy*/'a':
         cout<<"Rain boots are a good idea";
         break;
        case /*windy*/'i':
         cout<<"Put on something sturdy";
         break;
        case /*snowy*/'n':
         cout<<"Snow boots will keep your feet warm";
         break;
        case /*cloudy*/'l':
         cout<<"Any shoe is fine today";
         break;
        }
        cout<<endl;
}