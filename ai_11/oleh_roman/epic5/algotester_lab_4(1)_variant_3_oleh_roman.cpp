#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void SortUp(vector<int>& arr, int size);
void SortDown(vector<int>& arr, int size);

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<int> arr0, arr1, arr2;
    for (int num : arr) {
        if (num % 3 == 0) {
            arr0.push_back(num);
        } else if (num % 3 == 1) {
            arr1.push_back(num);
        } else {
            arr2.push_back(num);
        }
    }

    SortUp(arr0, arr0.size());
    SortDown(arr1, arr1.size());
    SortUp(arr2, arr2.size());

    vector<int> result;
    result.insert(result.end(), arr0.begin(), arr0.end());
    result.insert(result.end(), arr1.begin(), arr1.end());
    result.insert(result.end(), arr2.begin(), arr2.end());

    vector <int> withoutDubl;
    for (int num : result) {
        if (find(withoutDubl.begin(), withoutDubl.end(), num) == withoutDubl.end()) {
            withoutDubl.push_back(num);
        }
    }
    result = withoutDubl;


    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}


void SortUp(vector<int>& arr, int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j;
        for (j = i -1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void SortDown(vector<int>& arr, int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j;
        for (j = i -1; j >= 0 && arr[j] < key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}
