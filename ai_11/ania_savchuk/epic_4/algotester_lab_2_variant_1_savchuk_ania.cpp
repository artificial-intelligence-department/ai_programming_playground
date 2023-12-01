#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long find_tiredness(vector<long> array, long index) {
    array.erase(array.begin() + index);
    return (array[array.size() - 1] - array[0]);
}

int main() {
    long n;
    cin >> n;
    vector<long> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i]; 
    }

    sort(r.begin(), r.end());
    int min_tiredness = r[n-1] - r[0];
    
    for(int i = 0; i<n; i++) {
        long temporary = find_tiredness(r, i);
        if (temporary < min_tiredness) {
            min_tiredness = temporary; 
        }
    }
    cout << min_tiredness;
    return 0;
}