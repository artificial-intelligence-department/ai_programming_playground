#include <iostream>
using namespace std;

int main(){
    cout << "Task 1\n\n";
    double notebook_price;
    double wrap_price;
    int count;
    cout << "Calculation of the purchase price\n";
    cout << "Enter initial values:\n";
    cout << "Notebook price (uah): ";
    cin >> notebook_price;
    cout << "Wrap price (uah): ";
    cin >> wrap_price;
    cout << "Number of sets: ";
    cin >> count;
    cout << "Purchase price: " << (notebook_price+wrap_price)*count;

    cout << "\n\nTask 2\n\n";
    double kol;
    cout << "Enter KOL: ";
    cin >> kol;
    cout << "Shift: " << kol * 7.0 << endl;
    cout << "Day: " << kol * 7.0 * 2.0 << endl;
    cout << "Month: " << kol * 7.0 * 2.0 * 26.0;
    return 0;
}