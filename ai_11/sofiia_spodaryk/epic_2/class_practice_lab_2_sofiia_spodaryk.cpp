#include <iostream>
#include <string>

using namespace std;
int main()
{
    string type;

    cout << "What is the weather like? ";
    cin >> type;
 
 if (type == "sunny") 
    cout << "Do not take a coat" << endl;
 else if (type == "rainy" || type == "cloudy" || type == "snowy" || type == "windy")
    cout << "Take a coat" << endl;
 else 
    cout << "Woops";

 if (type == "sunny") 
    cout << "You can ride a bike" << endl;
 else if (type == "rainy" )
    cout << "You should stay home" << endl;
 else if (type == "snowy" )
    cout << "You can make a snowman" << endl;
 else if (type == "windy" )
    cout << "You can vist your grandparents" << endl;
 else if (type == "cloudy" )
    cout << "You can go to a library" << endl;
 else 
    cout << "  " << endl;
 
  switch (type[1]) {
        case 'u':
            cout << "You can wear crocs";
            break;
         case 'n':
            cout << "You can wear warm boots";
            break;
        case 'i':
            cout << "You can wear sneakers";
            break;
        case 'a':
            cout <<  "You should wear waterproof shoes";
            break;
        case 'l':
            cout <<  "You can wear sneakers";
            break;
        default:
            cout << " ";
            break;
    }

  return 0;  
}