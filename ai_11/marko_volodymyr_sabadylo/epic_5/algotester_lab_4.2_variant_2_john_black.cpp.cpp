#include <iostream>
#include <vector>
using namespace std;
vector<int> bubble_sort(vector<int> arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
    return arr;
}

vector<int> removeDuplicates(vector<int> arr) {
    for (int i=1 ;i <arr.size()-1;i++){
        if (arr[i]==arr[i+1]||arr[i]==arr[i-1]){
            arr.erase(arr.begin()+i);
            i--;
        }
    }
    return arr;
}
vector<int> rotateArray(vector<int>arr, int k) {
    for(int i=0; i<k; i++){
        for(int j=0; j<arr.size()-1; j++){
            swap(arr[j],arr[j+1]);
        }
    }
    return arr;
}
int main() {
    int n,k;

    // Введення розміру масиву та значення k
    cin >> n >>k;
    if (n<1 ||n>1000||k<1 ||k>1000 )return 0;

    vector<int>  inputArray;
    // Введення елементів масиву
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a < 0 || a > 100)return 0;
        inputArray.push_back(a);
    }
    inputArray = bubble_sort(inputArray,n);
    inputArray = removeDuplicates(inputArray);
    inputArray = rotateArray(inputArray,k);

    cout << inputArray.size() << endl;
    for (int i = 0; i <inputArray.size(); ++i) {
        cout << inputArray[i] << " ";

    }
    cout << endl;

    return 0;
}