#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main () {
    double Rs, R1, R2, R3;

    cout << "Введіть початкові дані: "<< endl;
    cout << "опір першого резистора > ";
    cin >> R1; // take input
    cout << "опір другого резистора > ";
    cin >> R2; // take input
    cout << "опір третього резистора > ";
    cin >> R3; // take input
    Rs = R1+R2+R3; // calculate result
    cout << "Опір електричного ланцюга, що складається з трьох послідовно сполучених резисторів : " << Rs << endl; // display result
    cout << "Для завершення натисніть клавішу <Enter> ";
    
    return 0;
}