#include <iostream>
#include <string>

using namespace std;

int main() {
    
    cout << "Яка ваша погода (sunny, rainy, cloudy, snowy, windy): ";
    string weather;
    cin >> weather;

  
    if ( weather =="snowy"|| weather=="windy" ) {
        cout << "Візьміть куртку та шапку." << endl;
    } if(weather =="rainy" || weather =="cloudy") {
      cout << "Візьміть парасолю." << endl;}
      if(weather =="sunny") {
      cout << "Одягайте фудболку та шорти." << endl;}


    if (weather == "sunny") {
        cout << "Візьміть сонячні окуляри!" << endl;
    } else if (weather == "rainy") {
        cout << "Краще подивіться Гаррі Потера!" << endl;
    } else if (weather == "cloudy") {
        cout << "Можете,прогулятись" << endl;
    } else if (weather == "snowy") {
        cout << "Час зліпити сніжки" << endl;
    } else if (weather == "windy") {
        cout << "На вулиці вітряно,будьте обачливі" << endl;
    } else {
        cout << "Ви ввели не вірну погоду,спробуйте ще раз." << endl;
        return 1; 
    }
    return 0;
}
