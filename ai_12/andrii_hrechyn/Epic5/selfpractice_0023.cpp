#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

bool ties_calculation(vector<double> a, short people, double check) {
    double current = 0;
    for (short i =0; i < a.size(); i++) {
        while (a[i] >= check) {
            a[i] -= check;
            current++;
        }
    }
    return (current >= people);
}

int main() {
    short ties, people;
    cin >> ties >> people;
    double max = 0, length = 0;
    vector<double> a;
    a.resize(ties);

    for (short i = 0; i < ties; i++) {
        cin >> a[i];
        if (max < a[i]) max = a[i];
    }
    double first = 0, last = max, middle = max, past_middle = 0;
    if (ties_calculation(a, people, middle)) length = middle; 
    else {
        middle = (last + first)/2;
        do {
            past_middle = middle;
            if (ties_calculation(a, people, middle)) {
                length = middle;
                first = middle;
            }
            else {
                last = middle;
            }
            middle = (last + first)/2;
        } while (!((past_middle - middle > -0.00002) && (past_middle - middle < 0.00002)));
    }
    printf("%.5lf", length);
    return 0;
}
