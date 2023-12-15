#include <iostream>

using namespace std;

struct RingArray {
    static const int N = 100;
    int elements[N];
    int realSize;
};

void printRing(const RingArray& ring, int startIdx, int endIdx) {
    for (int i = startIdx; i != endIdx; i = (i + 1) % ring.realSize) {
        cout << ring.elements[i] << " ";
    }
    cout << endl;
}

void addZerosAfterMultiplesOfFive(RingArray& ring) {
    for (int i = 0; i < ring.realSize; ++i) {
        if (ring.elements[i] % 5 == 0) {
            for (int j = ring.realSize - 1; j > i; --j) {
                ring.elements[(j + 1) % RingArray::N] = ring.elements[j];
            }
            ring.elements[(i + 1) % RingArray::N] = 0;
            ++ring.realSize;
            ++i;
        }
    }
}

int main() {
    RingArray ring;
    
    cout << "Enter the real size of the array (not more than " << RingArray::N << "): ";
    cin >> ring.realSize;

    cout << "Enter array elements: ";
    for (int i = 0; i < ring.realSize; ++i) {
        cin >> ring.elements[i];
    }

    cout << "Original array: ";
    printRing(ring, 0, ring.realSize);

    int startIdx;
    cout << "Enter the starting index for printing the array: ";
    cin >> startIdx;

    cout << "Array printed to the left from index " << startIdx << ": ";
    printRing(ring, startIdx, (startIdx - 1 + ring.realSize) % ring.realSize);

    addZerosAfterMultiplesOfFive(ring);

    cout << "Array after adding zeros: ";
    printRing(ring, 0, ring.realSize);

    int startIdxAfterChanges;
    cout << "Enter the starting index for printing the array after changes: ";
    cin >> startIdxAfterChanges;

    cout << "Array printed to the right from index " << startIdxAfterChanges << ": ";
    printRing(ring, startIdxAfterChanges, (startIdxAfterChanges + 1) % ring.realSize);

    return 0;
}