#include <iostream>
#include <string>
using namespace std;

int main()
{
    string weather;
    cout<<"Введіть тип погоди"<< endl;
    cin >> weather;
    char firstletter = weather[0];
    if (firstletter == 's' )
    {
        if (weather[1] == 'u')
        {
            cout << "do not wear a jacket" << endl;
        }
            else if (weather[1] == 'n')
            {
                cout << "wear a jacket" << endl;
            }
    }
    if (firstletter == 'r' || firstletter == 'c' || firstletter == 'w')
    {
        cout << "wear a jacket" << endl;
    }
    if (firstletter == 's' )
    {
        if (weather[1]=='u')
        {
            cout << "wear sport shoes" << endl;
        }
    }
            else if (weather[1] == 'n')
            {
                cout << "wear waterproof boots" << endl;
            }
    if ( firstletter == 'r' )
        {
        cout << "wear waterproof boots" << endl;
        }
        else if (firstletter == 'c' )
            {
            cout << "wear sneakers" << endl;
            }
                else if (firstletter == 'w' )
                {
                cout << "boots" << endl;
                }

    switch(firstletter)
    {
        case 'r':
            cout << "better stay at home and read some books" << endl;
            break;
        case 'w':
            cout << "meet your friends" << endl;
            break;
        case 'c':
            cout << "go for a walk" << endl;
            break;
        case 's':
             if (weather[1] == 'u')
            {
                cout << "play tennis" << endl;
            }
            else if (weather[1] == 'n')
            {
            cout << "go skiing" << endl;
            }
            break;
            default:
            cout << "wrong weather" << endl;
            return 0;
    }
}
            





