#include <iostream>
#include <vector>

using namespace std;

vector<long int> v;

int findIndexOfNextOddElem(int fromIndex) {
    if (fromIndex < v.size()) {
        for (int j = fromIndex; j < v.size(); j++) {
            if (v[j] % 2 == 1) {
                return j;
            }
        }
    }
    return -1;
}

int findIndexOfNextEvenElem(int fromIndex) {
    if (fromIndex < v.size()) {
        for (int j = fromIndex; j < v.size(); j++) {
            if (v[j] % 2 == 0) {
                return j;
            }
        }
    }
    return -1;
}

void swapElems(int index1, int index2) {
    if (index1 < 0 || index2 < 0) {
        return;
    }
    long int temp = v[index1];
    v[index1] = v[index2];
    v[index2] = temp;
}


int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        long int elem;
        cin >> elem;
        v.push_back(elem);
    }
    
    int oddElemsCount = 0;
    int evenElemsCount = 0;
    
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i) % 2 == 0) {
            evenElemsCount++;
        }
        else {
            oddElemsCount++;
        }
    }
    
    if (abs(oddElemsCount - evenElemsCount) > 1) {
        cout << -1;
        return 0;
    }
    
    bool needEven = evenElemsCount > oddElemsCount;
    
    for (int i = 0; i < v.size(); i++) {
        bool currentIsEven = (v.at(i) % 2) == 0;
        if (needEven) {
            if (!currentIsEven) {
                int index2 = findIndexOfNextEvenElem(i + 1);
                swapElems(i, index2);
            }
        }
        else {
            if (currentIsEven) {
                int index2 = findIndexOfNextOddElem(i + 1);
                swapElems(i, index2);
            }
        }
        needEven = !needEven;
    }
    
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}