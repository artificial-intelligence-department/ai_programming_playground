#include <iostream>
using namespace std;

int main() {
    double a1, a2, a3, a4, a5;
    if (a1,a2,a3,a4,a5 >= -1000000000000 && a1,a2,a3,a4,a5 <= 1000000000000) {
} else {

    cout << "ERROR: Invalid side length." << endl;
}

cout << "Enter 5 sides of cubes:";
cin >> a1 >>a2 >>a3 >> a4>> a5;

    if (a1 <= 0 || a2 <=0 || a3 <=0 || a4 <=0 || a5 <=0){
        cout << "ERROR";
    }
    else if (a2 > a1 || a3 > a2 || a4 > a3 || a5 > a4) {
        cout << "LOSS";  
    }
    else if (a2 < a1 || a3 < a2 || a4 < a3 || a5 < a4){
        cout << "WIN"; 
    }

    return 0;
}
