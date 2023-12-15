#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    // count counts consecutive sharp teeth
    int n, k, sharpness, count = 0;
    cin >> n >> k;
    vector<int> seq;

    for (int i=0; i<n; i++){
        cin >> sharpness;
        if(sharpness >= k){
            count++;
        }else{
            seq.push_back(count);
            count = 0;
        }
    }

    seq.push_back(count);

    cout << *max_element(seq.begin(), seq.end()) << endl;

    return 0;
}