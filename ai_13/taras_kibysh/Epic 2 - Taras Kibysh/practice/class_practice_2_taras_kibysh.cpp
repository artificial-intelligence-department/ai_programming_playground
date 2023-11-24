#include <iostream>
#include <string>
 
int main(){
using namespace std;
string weather;
while(true){
cout << "Write types of weather:";
cin >> weather;
cout  << weather<< endl;
if(weather != "sunny" && weather != "rainy" && weather != "cloudy" && weather != "snowy" && weather != "windy"){
cout << "invalid weather try again"<<endl;
}


else
break;
}





if(weather == "rainy" || weather == "snowy")
cout << "You need a jacket\n";

else
cout << "you dont need a jacket\n";





if(weather == "sunny")
cout << "Great day for picnic\n";

else if(weather == "rainy")
cout << "Perfect weather to read a book inside!\n";

else if(weather == "cloudy")
cout << "Maybe, lets visit the museum?\n";

else if(weather == "snowy")
cout << "How about making a snowman?\n";

else if(weather == "windy")
cout << "Fly a kite if you have one!\n";

// яке взуття взути за допомогою switch
char symbol = weather[0];


switch(symbol){

 case 'r':
 cout << "Rain boots are a good idea!";
 break;

 case 'c':
 cout << "Today, any shoe is suitable.";
 break;
 
 case 'w':
 cout << "Wear something sturdy!";
 break;
 
 case 's':
 if(weather == "sunny")
 cout << "Wear your favorite sneakers!";
 else
 cout << "Snow boots will keep your feet warm!" ;
 break;


}


return 0;
}