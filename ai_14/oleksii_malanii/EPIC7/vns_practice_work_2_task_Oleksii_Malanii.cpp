#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int studentNumber = 17;
    double xStart = 3.0;
    double xEnd = 5.0;
    double step = 0.1;
    int negativeCount = 0;
    if (studentNumber % 2 == 0) {
        for (double x = xStart; x <= xEnd; x += step) {
            double y = cos(pow(x, 2)) * exp(-x);
            if (y < 0) {
                negativeCount++;
            }
        }
    } else {
        for (double x = xStart; x <= xEnd; x += step) {
            double y = cos(pow(x, 2)) * exp(-x);
            if (y < 0) {
                negativeCount++;
            }
        }
    }
    cout << "The function takes a negative value " << negativeCount << " times." << endl;
    return 0;
}
