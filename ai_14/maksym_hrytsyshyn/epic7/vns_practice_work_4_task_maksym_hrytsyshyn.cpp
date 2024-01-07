#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of the first members of the series: ";
    cin >> n;
    double s = 0;
    
    int i = 1; 
    while (i <= n) {     // Loop for i from 1 to n
        s += 1.0 / i;       // formula for s
        i++;                   // Increment of i
    }
    cout << "The sum of the first " << n << " members of the series is equal to " << s << endl;
    

}