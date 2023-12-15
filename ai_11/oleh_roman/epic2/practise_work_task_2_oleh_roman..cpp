#include <iostream> 
#include <string> 
using namespace std;

int main() {
    string input;
    cout << "What is the whether today?";
        cin >> input;
    if ( input=="rainy"||"snowy")
        {
            cout <<"You need a jacket" <<endl;
        }
        else 
        {
            cout <<"You dont need a jacket" <<endl;
        }

    if ( input=="rainy"||"snowy")
        {
            cout << "I advise to play game inside building" <<endl;
        } else if (input=="windy"||"cloudy") {
            cout << "I advise to play football or bsketball" <<endl;
        } else {
            cout <<"I advise to go to beach and play volleyball" <<endl;
        }
    switch (input[0])
        {
            case 's': 
                if (input[1]=='u') 
                {
                    cout << "you can wear sandals" <<endl; 
                } else {
                    cout << "you can wear boots" <<endl; 
                } break;              
            case 'r':
                cout << "you can wear rubber boots" <<endl; break;
            case 'c':
                cout << "you can wear sport shoes" <<endl; break;
            case 'w':
                cout << "you can wear trainers" <<endl; break;
            default: 
                cout << "wrong wheather" <<endl; break;   
        }
    
    return 0;
}
