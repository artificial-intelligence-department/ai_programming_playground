#include <iostream>
#include <string>
using namespace std;

int main(){

string weather;
int shoes;
cout <<"Whrite your weathe conditions \n";
cin >> weather;
if (weather=="snowly"||"windly"){
cout << "you need cuphead \n";
shoes = 1;
}
else {cout << "you dont need cuphead \n";}
 if (weather=="sunny")
 
{
    cout << "you can wear T-shirt,shorts \n";
    shoes =2;
}
 else if (weather=="rainy")
{
cout << "take an umbrella \n";
shoes = 3;
}
 else if (weather=="cloudly"){
    cout << "wear pants and hoodie \n";
   shoes = 4;
 }
 else if (weather=="snowly"){
    cout << "wear boots,pants and jacket \n";
    shoes = 1;
 }
 else if (weather=="windly"){
    cout << "Look at the window bro,you dont need that \n";
    shoes = 6;
 }

 switch (shoes)
 {
 case 1:
   cout << "Term shoes " << endl;
   break;
 case 2:
   cout <<"Crocs " <<endl;
   break;
 case 3:
   cout <<"Boots " <<endl;
   break;
 case 4:
   cout <<"Slippers " <<endl;
   break;
  case 6:
   cout <<"Sneakers " <<endl;
   break;
 }
}