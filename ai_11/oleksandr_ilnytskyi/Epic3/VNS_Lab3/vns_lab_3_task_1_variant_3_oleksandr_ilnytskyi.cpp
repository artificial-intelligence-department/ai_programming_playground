#include <iostream>
#include <cmath>

using namespace std;

static int nAccuracy = 10;
static float epsilon = 0.0001;
static float step = (1-0.1)/10;

int factorial(int x) {
    if (x>1) {
        return x * factorial(x-1);
    }
    return 1;
}

static float general(float x, int n) {
    return pow(-1, n)*(pow(x, 2*n+1)/factorial(2*n+1));
}

int main() {
    for (float x = 0.1; x <= 1; x += step) {
        float sumN = 0;
        for (int n = 0; n < nAccuracy; n++) {
            float res = general(x, n);
            sumN += res;
        }

        float sumE = 0;
        int i = 0;
        while (true) {
            float res = general(x, i);
            if (res >= epsilon) {
                sumE += res;
                i += 1;
            }
            else {
                break;
            }
        }
        cout << "For argument " << x << " with n accuracy it's: " << sumN << endl;
        cout << "For argument " << x << " with epsilon accuracy it's: " << sumE << endl;
    }

    return 0;
}
