#include <iostream>
#include <vector>
using namespace std;
void InsertionSort(vector <int>& arr){
    for (int i = 1; i < arr.size(); i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void ReverseInsertionSort(vector <int>& arr){
    for (int i = 1; i < arr.size(); ++i){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int N;
    cin >> N;
    int mas[N];
    for (int i = 0; i < N; i++){
        cin >> mas[i];
    }
    vector <int> ost0, ost1, ost2;
    for (int i = 0; i < N; i++){
        if (mas[i] % 3 == 0){
            ost0.push_back(mas[i]);
        }
        else if (mas[i] % 3 == 1){
            ost1.push_back(mas[i]);
        }
        else if (mas[i] % 3 == 2){
            ost2.push_back(mas[i]);
        }
    }
    InsertionSort(ost0);
    ReverseInsertionSort(ost1);
    InsertionSort(ost2);
    for (int i = 0; i < ost0.size(); i++){
        mas[i] = ost0[i];
    }
    for (int i = 0; i < ost1.size(); i++){
        mas[i + ost0.size()] = ost1[i];
    }
    for (int i = 0; i < ost2.size(); i++){
        mas[i + ost0.size() + ost1.size()] = ost2[i];
    }

    vector <int> finalvector;
    finalvector.push_back(mas[0]);
    for (int i = 0; i < N-1; i++){
        if (mas[i] != mas[i+1]){
            finalvector.push_back(mas[i+1]);
        }
    }

    cout << finalvector.size() << endl;
    for (int i = 0; i < finalvector.size(); i++){
        cout << finalvector[i] << " ";
    }
    return 0;
}