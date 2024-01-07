#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr;

    srand(time(0)); 
    const int arrSize = 10;
    for (int i = 0; i < arrSize; ++i) {
        arr.push_back(rand() % 100);
    }

    cout << "start array: ";
    for (int num : arr) 
        cout << num << " ";
    

    cout << endl;


    for (size_t i = 0; i < arr.size(); ++i) 
        if (arr[i] % 2 == 0) {
            arr[i + 1] += arr[i - 1] + 2;
            break;
        }
    cout << "new array: ";
    for (int num : arr)
        cout << num << " ";

    return 0;
}
