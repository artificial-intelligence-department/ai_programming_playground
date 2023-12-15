#include <iostream>
#include <cmath>

using namespace std;

bool PointBelongCircle(double x, double y, double r){
    double belonging = sqrt(pow(x, 2) + pow(y, 2));
    return belonging <= r;
}
int belong(double r, int p, ...){
    int count = 0;
    va_list args;
    va_start(args, p);

    for(int i = 0; i < p; i += 2){
        double x = va_arg(args, double);
        double y = va_arg(args, double);

        if (PointBelongCircle(x, y, r)) {
            count++;
        }
    }
    va_end(args);

    return count;
}



int main(){
    double r = rand();

    int request = belong(r, 23, 5, 5, 6, 7, 98);
    int request2 = belong(r, 5.0, 6.0, 2, 33, 4, 5, 7, 8 ,6,5,5,332,23,34,43,43,4,4);
    int request3 = belong(r, 6,5,5,332,23,34,43,43,4,4,2, 33, 4, 5, 7, 8 ,6,9,3,3,3,5);

    cout << "Three points: " << request << endl;
    cout << "Nine points: " << request2 << endl;
    cout << "Eleven points" << request3 << endl;


    return 0;
}