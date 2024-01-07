#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void InsertionSort(vector<int>& arr){
    sort(arr.begin(), arr.end());
}

void ReverseInsertionSort(vector<int>& arr){
    sort(arr.rbegin(), arr.rend());
}

int main(){
    int N;
    cin >> N;

    int mas[N];
    for (int i = 0; i < N; i++){
        cin >> mas[i];
    }

    vector<int> ost0, ost1, ost2;

    for (int i = 0; i < N; i++){
        if (mas[i] % 3 == 0) {
            ost0.push_back(mas[i]);
        } 
        else if (mas[i] % 3 == 1){
            ost1.push_back(mas[i]);
        } 
        else{
            ost2.push_back(mas[i]);
        }
    }

    InsertionSort(ost0);
    ReverseInsertionSort(ost1);
    InsertionSort(ost2);

    vector<int> finalvector;
    finalvector.insert(finalvector.end(), ost0.begin(), ost0.end());
    finalvector.insert(finalvector.end(), ost1.begin(), ost1.end());
    finalvector.insert(finalvector.end(), ost2.begin(), ost2.end());

    finalvector.erase(unique(finalvector.begin(), finalvector.end()), finalvector.end());

    cout << finalvector.size() << endl;
    for (int i = 0; i < finalvector.size(); i++){
        cout << finalvector[i] << " ";
    }

    return 0;
}