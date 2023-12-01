#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<unsigned long long> legLength;
vector<unsigned long long> legChanges;

// Get leg length input and separate it into vector
void getInitialInput() {
    for (int i = 0; i < 4; i++) {
        unsigned long long lengthInput;
        cin >> lengthInput;
        legLength.push_back(lengthInput);
    }
}

// Gets leg cut input for each leg
void getChangesInput() {
    for (int i = 0; i < 4; i++) {
        unsigned long long change;
        cin >> change;
        legChanges.push_back(change);
    }
}

// Get max and min legs
vector<unsigned long long> getBorderValues() {
    vector<unsigned long long> borderValues;

    unsigned long long max = legLength[0];
    unsigned long long min = legLength[0];

    for (unsigned long long num: legLength) {
        if (num > max) {
            max = num;
        }
        else if (num < min) {
            min = num;
        }
    }
    borderValues.push_back(min);
    borderValues.push_back(max);

    return borderValues;
}

// Main comparisons
string evaluateInputs() {
    for (int n = 0; n < 4; n++) {
        if (legChanges[n] > legLength[n]) {
            return "ERROR";
        }
    }
    for (int i = 0; i < 4; i++) {
        legLength[i] -= legChanges[i];
        auto comp = getBorderValues();
        if (comp[1] >= 2 * comp[0] || comp[0] == 0) {
            return "NO";
        }
    }
    for (int c = 0; c < 3; c++) {
        if (legLength[c] != legLength[c+1] ) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    getInitialInput();
    getChangesInput();
    cout << evaluateInputs();
}
