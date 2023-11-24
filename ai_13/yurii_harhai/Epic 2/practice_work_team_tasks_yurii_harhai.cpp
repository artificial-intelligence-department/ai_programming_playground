#include <iostream>
using namespace std;


int main(){
 bool done {false};
 char weather{};
 

while (!done)
{
    cout << "Choose what kind of weather is today:\nS for sunny\nR for rainy\nC for cloudy\nN for snowy\nW for windy\n";
    cin >> weather; 
    if ( weather=='S' || weather=='R' || weather=='C' || weather=='N' || weather=='W')
        done = true;
    else
    cout <<"Oops... You probably wrote smth different. Please try again\n";
}
    if(weather=='N'|| weather=='R'){
        cout <<"Put on a jacket!\n";
    }
    else{
        cout <<"You don't need a jacket today :)\n";
    }

    if(weather=='S')
        cout <<"It's a beautiful day for a picnic\n";
    else if(weather=='R')
        cout <<"Brilliant weather to stay at home and read some books\n";
    else if(weather=='C')
        cout <<"Hmmm... Maybe u should visit a museum\n";
    else if(weather=='N')
        cout <<"Lets make a snowman)\n";
    else if(weather=='W')
        cout <<"Fly the kite, if u have it, obviously\n";

    switch (weather)
    {
    case 'S':
        cout <<"Wear your favourite shoes!";
        break;
    case 'R':
        cout <<"Rain boots may be a good idea";
        break;
    case 'C':
        cout <<"Any shoes are suitable today!";
        break;
    case 'N':
        cout <<"Snow boots will warm your feets";
        break;
    case 'W':
        cout <<"Wear something sturdy!";
        break;

    default:
        break;
    }
    return 0;
}