#include <iostream>
#include <algorithm>
using namespace std;

static const int legsCount = 4;

static const string positiveOutput  = "YES",
                    negativeOutput  = "NO",
                    errorOutput     = "ERROR";

template<class T>
T max(T* arr, int size) {
    return *max_element(arr, arr + size);
}

template<class T>
T min(T* arr, int size) {
    return *min_element(arr, arr + size);
}

int main() {
    long long legsHeights[legsCount];

    // reading h1, h2, h3, h4
    for (long long& legsHeight : legsHeights)
        cin >> legsHeight;

    // reading d1, d2, d3, d4
    // and sawing the leg for the di value.
    long long di;
    bool willStand = true;
    for (long long & legHeight : legsHeights) {
        cin >> di;
        if (di > legHeight) {
            cout << errorOutput;
            return 0;
        }

        legHeight -= di;

        if (max(legsHeights, legsCount)
            >= 2 * min(legsHeights, legsCount)) {
            willStand = false;
        }
    }

    cout << (willStand ? positiveOutput : negativeOutput);
    return 0;
}
