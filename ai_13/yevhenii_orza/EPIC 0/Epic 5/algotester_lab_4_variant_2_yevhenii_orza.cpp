#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){

    int N, K;

    cin >> N;
    cin >> K;

    vector<int> arr(N);
    vector<int> arrCopy;

    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

   
    arrCopy = arr;

    sort(arrCopy.begin(), arrCopy.end());


    arrCopy.erase(unique(arrCopy.begin(), arrCopy.end()), arrCopy.end());

    rotate(arrCopy.begin(), arrCopy.begin() + K % arrCopy.size(), arrCopy.end());

    cout << arrCopy.size() << endl;
    for (int i = 0; i < arrCopy.size(); i++) {
        cout << arrCopy[i] << " ";
    }

    return 0;
}
