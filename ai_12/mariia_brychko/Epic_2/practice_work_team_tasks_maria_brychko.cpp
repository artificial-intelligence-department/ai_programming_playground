#include <iostream>
#include <string>
using namespace std;
int main() {
    cout << "Hello! Please, enter the weather conditions (Choose from these options: sunny, rainy, cloudy, snowy, windy): ";
    string weather;
    string a = "sunny";
    string b = "rainy";
    string c = "cloudy";
    string d = "snowy";
    string e = "windy";
    cin >> weather;
while (weather != a && weather != b && weather != c && weather != d && weather != e) {
        cout << "Please, enter the proper option\n";
        cout << "Hello! Please, enter the weather conditions (Choose from these options: sunny, rainy, cloudy, snowy, windy): ";
        cin >> weather;
        }
if (weather == b || weather == d ) {
    cout << "Outerwear: You should take a jacket!\n";
} else if (weather == a || weather == c || weather == e) {
    cout << "Outerwear: You do not need to take a jacket\n";
}
if (weather == a){
    cout << "Activity to do: It is a nice day to have a picnic!\n";
} else if (weather == b) {
    cout << "Activity to do: It is the perfect weather to read a book inside!\n";
} else if (weather == c) {
    cout << "Activity to do: Maybe it is better to visit a museum.\n";
} else if (weather == d) {
    cout << "Activity to do: How about making a snowman?\n";
} else if (weather == e) {
    cout << "Activity to do: Fly a kite if you have got it!\n";
}
switch (weather[1]) {
case 'u':
    cout << "Shoes to wear: Put on your favorite sneakers!";
    break;
  case 'a':
    cout << "Shoes to wear: Rain boots are a good idea!";
    break;
  case 'l':
    cout << "Shoes to wear: Any shoes are fine today.";
    break;
  case 'n':
    cout << "Shoes to wear: Snow boots will keep your feet warm!";
    break;
  case 'i':
    cout << "Shoes to wear: Put on something strong!";
    break;
}
return 0;
}



