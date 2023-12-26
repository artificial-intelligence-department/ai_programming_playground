#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>  
using namespace std;

int main() {


    int iUserChoose = 1;

    do{

        string weather;
        cout << "Write weather condition (sunny, rainy, cloudy, snowy, windy)\n";
        cin >> weather;
        int WatherCase = -1;



        if (weather == "rainy" || weather == "snowy") {
            cout << "You  need a jacket\n";
        }
        else if (weather == "sunny" || weather == "cloudy" || weather == "windy") {
            cout << "You don`t need a jacket\n";
        }



        if (weather == "sunny") {
            cout << "It's a good day to go outside and hang out with friends\n";
            WatherCase = 0;
        }
        else if (weather == "rainy") {
            cout << "You better take umbrellara\n";
            WatherCase = 1;
        }
        else if (weather == "cloudy") {
            cout << "How about going to restaurant?\n";
            WatherCase = 2;
        }
        else if (weather == "snowy") {
            cout << "lets make a snowman\n";
            WatherCase = 3;
        }
        else if (weather == "windy") {
            cout << "You may go to your friend's  home\n";
            WatherCase = 4;
        }




        switch (WatherCase) {
        case 0:
            cout << "You can wear flip flops\n";
            break;
        case 1:
            cout << "You can wear shoes\n";
            break;
        case 2:
            cout << "You should wear sneakers\n";
            break;
        case 3:
            cout << "You should wear boots\n";
            break;
        case 4:
            cout << "You can wear sneakers\n";
            break;
        default:
            cout << "Unknown condition\n";
            break;
        }
        cout << "\n\n\n";

        cout << "if you want to continue enter 1, else 0\n";
        cin >> iUserChoose;
        system("cls");

    } while (iUserChoose != 0);

    return 0;
}