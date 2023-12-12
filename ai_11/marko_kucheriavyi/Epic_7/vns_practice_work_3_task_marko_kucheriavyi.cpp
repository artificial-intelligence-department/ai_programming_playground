#include <iostream>
using namespace std;
int main(){
    double x, y;
    cout << "value of first resistance: ";
    cin >> x;
    cout << "value of second resistance: ";
    cin >> y;
    cout << "chain resistance: " << x + y; 

    double money;
    cout << "\n\nenter amount of money: ";
    cin >> money;
    for (int i = 0; i < 2; i++){
        money *= 1.03;
    }
    cout << "your money now is: " << money; 
    return 0;
}