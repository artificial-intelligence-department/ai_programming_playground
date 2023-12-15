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
int main(){
    int N, K;
    cin >> N >> K;
    vector <int> mas, finalmas;

    for (int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        mas.push_back(temp);
    }

    InsertionSort(mas);

    finalmas.push_back(mas[0]);
    for (int i = 0; i < N-1; i++){
        if (mas[i] != mas[i+1]){
            finalmas.push_back(mas[i+1]);
        }
    }
    for (int i = 0; i < K; i++){
        finalmas.push_back(finalmas[i]);
    }
    for (int i = 0; i < K; i++){
        finalmas.erase(finalmas.begin());
    }
    cout << finalmas.size() << endl; 
    for (int i = 0; i < finalmas.size(); i++){
        cout << finalmas[i] << " ";
    }
    
    return 0;
} 