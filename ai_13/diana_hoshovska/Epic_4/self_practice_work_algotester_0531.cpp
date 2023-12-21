#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int k, n, counter=0; //гроші та атракціони
    cin >> k >> n;
    int arr[n]={0};

    for (int i = 0; i < n; i++){
        cin >> arr[i]; //ціна атракціону
    }

    int st = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+st);

    for (int i = 0; i < n; i++){
        if (k<arr[i]){
            break;
        }
        k=k-arr[i];
        counter++;
    }
    cout << counter;
}