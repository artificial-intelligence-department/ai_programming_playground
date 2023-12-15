#include <iostream>
using namespace std;

bool findIfTableIsBroken(long l1, long l2, long l3, long l4) {
    bool isTableBroken;
    long maxLeg, minLeg;

    maxLeg = l1;

    if (l2 > maxLeg) {
        maxLeg = l2;
    }

    if (l3 > maxLeg) {
        maxLeg = l3;
    }

    if (l4 > maxLeg) {
        maxLeg = l4;
    }

    minLeg = l1;

    if (l2 < minLeg) {
        minLeg = l2;
    }

    if (l3 < minLeg) {
        minLeg = l3;
    }

    if (l4 < minLeg) {
        minLeg = l4;
    }

    isTableBroken = (minLeg * 2 <= maxLeg);

    return isTableBroken;
}

int main () {
    long l1, l2, l3, l4; 
    long c1, c2, c3, c4; 
    long minLeg, maxLeg;
    bool isTableBalanced = true;
    bool isTableBroken = false;

    cin >> l1 >> l2 >> l3 >> l4;
    cin >> c1;
    cin >> c2;
    cin >> c3;
    cin >> c4;

    l1 = l1 - c1;

    isTableBroken = findIfTableIsBroken(l1, l2, l3, l4);

    l2 = l2 - c2;

    isTableBroken = (isTableBroken || findIfTableIsBroken(l1, l2, l3, l4));

    l3 = l3 - c3;

    isTableBroken = (isTableBroken || findIfTableIsBroken(l1, l2, l3, l4));

    l4 = l4 - c4;

    isTableBroken = (isTableBroken || findIfTableIsBroken(l1, l2, l3, l4));

    isTableBalanced = (l1 != 0 && l1 == l2 && l2 == l3 && l3 == l4);
   
    bool errorDuringCut = (l1 < 0 || l2 < 0 || l3 < 0 || l4 < 0);
    
    if (errorDuringCut) {
        cout << "ERROR" << endl;
    }

    else { 
        if (isTableBalanced && !isTableBroken) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}