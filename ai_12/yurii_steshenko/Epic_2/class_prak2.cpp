#include<iostream>
#include <string>
using namespace std;

int main()
{
    int weather;
    cout<<"What the weather now?\n0 - sunny,\n1 - rainy,\n2 - cloudy,\n3 - snowy,\n4 - windy"<<endl;
    cin>>weather;

    if (weather < 0 || weather > 4) {
        cout << "Misinput\n";
        return 1;
    }

    // clothes
    if (weather== 1 || weather == 3)
    {
        cout<<"put the jacket"<<endl;
    }
    else
    {
        cout<<"jacket is not required"<<endl;
    }

    // shoes
    cout << "Put on ";
    switch (weather) {
        case 0:
            cout << "flip-flops";
            break;
        case 1:
        case 3:
            cout << "boots";
            break;
        case 2:
        case 4:
            cout << "sneakers";
            break;
        default:
            break;
    }
    cout << endl;

    // activity 
    if (weather == 0) {
        cout << "You may go to a park";
    } else if (weather == 1 || weather == 2) {
        cout << "Go to a cinema with friends";
    } else if (weather == 3) {
        cout << "Stay inside with a cup of tea";
    }  else {
        cout << "Incorrect input";
    }
    cout << endl;
    
    return 0;
}