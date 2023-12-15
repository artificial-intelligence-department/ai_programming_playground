#include <iostream>
#include <string>

using namespace std;

int main(){
    string array[5] = {"snowy" , "rainy" , "windy" , "cloudy" , "sunny"};
    string a;
    cout << "Enter a type of weather: " << endl;
    cin >> a;

    if (a == "snowy" ||  a == "rainy")
        cout << "U have to wear a jacket" << endl;
    else
        cout << "U dont wear a jacket" << endl;

    if (a == "rainy")
        cout << "Perfect weather to read a book inside!" << endl;

    if (a == "sunny")
    {
        cout << "U can wear a t-shirt" << endl;
        cout << "It's a good for a picnic" << endl;
    }

    else if (a == "cloudy")
        cout << "would be better if u go to a museum" << endl;
    
    else if (a == "windy")
        cout << "Fly a kite if you have one!" << endl;

    else if (a == "snowy")
    {
        cout << "U need gloves" << endl;
        cout << "How about making a snowman?" << endl;
    }



    switch(char n = a[0])
        {
            case 'r':   
                cout << "Rain boots are a good idea" << endl;
                break;
            case 's':{
                if (a == "sunny")
                    cout << "Wear your favourite shoes" << endl;
                else
                    cout << "Snow boots will keep your feet warm!" << endl;
                    break;
            }
            case 'c':
                cout << "Today, any shoe is suitable" << endl;
                break;
            case 'w':
                cout << "Wear something sturdy!" << endl;
                break;
                
        }    



    return 0;



}