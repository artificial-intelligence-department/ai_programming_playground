#include <iostream>
using namespace std;

int main () {
    double  num;                    // Variable declaration and initialization using data type double
    cout << "Enter the number: ";    
    cin >> num;                         // Input of num

    int hrn = static_cast<int>(num);        // Intialize hrn ignoring fractional part of num 
    int kop = static_cast<int>((num - hrn) * 100);  //  Intialize kop using formula

    cout << "The number " << num << " is equal to " << hrn << " hrn. " << kop << " kop." << endl;

    return 0;

}