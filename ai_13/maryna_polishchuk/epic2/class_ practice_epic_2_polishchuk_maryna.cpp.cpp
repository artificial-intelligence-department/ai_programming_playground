#include <iostream>
#include <string>
using namespace std;

int main (){

string weather;
cout << "Write the weather today: " << endl;
cin >> weather; 
   if ( weather=="sunny")
   {
   cout << "You don't need jacket" << endl;}
   else if (weather=="cloudy"||weather=="rainy"||weather=="snowy"||weather=="windy")
   {
   cout << "Maybe you should take jacket with you" << endl;
   }
if (weather=="sunny")
   cout << "Let's play volleyball" << endl;
else if (weather=="cloudy"||weather=="rainy"||weather=="snowy")
{
    cout << "Let's grab some coffee"<<endl;
}
else if (weather=="windy")
{
    cout << "Let's fly a kite" << endl;
}
switch (weather[0]) {
case 's':
    if (weather=="sunny")
    cout << "I think you should wear flip flops" << endl;
    else 
    cout << "I think you should wear boots"<< endl;  
    break;

case 'r':
   cout << "I think you should wear rain boots" << endl;
   break;

case 'c':
    cout << "I think you should wear loafers" << endl; 
    break;

case 'w':
    cout << "I think you should wear sneakers" << endl;
    break;

default:
   cout  << "I don't know what to do with this weather" << endl;
   break;
}
   return 0;

}
   


