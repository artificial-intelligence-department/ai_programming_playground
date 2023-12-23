#include <iostream>
#include <string>
using namespace std;

int main()
{
    string weather;


    cout << "Enter the weather conditions: ";
    getline(std::cin, weather);
    if (weather != "cloudy" && weather != "snowy" && weather != "rainy" && weather != "windy" && weather != "sunny")
    {
        cout << "You entered unappropriate data";
    }

    else
    {
        char i = weather[0];
        if (weather == "snowy" || weather == "rainy")
        {
            cout << "You must take the jacket" << endl;;
        }
        else
        {
            cout << "You may not take the jacket" << endl;;
        }


        if (weather == "sunny")
        {
            cout << "Nice day for a picnic!" << endl;
            
        }
        else if (weather == "rainy")
        {
            cout << "An ideal for reading a book" << endl;
            
        }
        else if (weather == "cloudy")
        {
            cout << "Maybe, visit the museum?" << endl;
           

        }
        else if(weather == "snowy")
        {
            cout << "What about making snowman?" << endl;
            

        }
        else
        {
            cout << "What about flying a kite?" << endl;
            
        }

        switch(i)
        {
        case 's':
            if (weather == "sunny")
            {
                cout << "Wear your favourite shoes" << endl;
            }
            else
            {
                cout << "Snow boots will warm up your foots" << endl;
            }
            break;
        case 'r':
            
            cout << "Rainy boots is an ideal shoes" << endl;
            break;
        case 'c':
            cout << "You can wear any shoes" << endl;
            break;
        case 'w':
            cout << "Wear something strong" << endl;
            break;

         }
        
        

    }
}