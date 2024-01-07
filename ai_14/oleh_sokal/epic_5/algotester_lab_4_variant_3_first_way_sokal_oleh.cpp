#include <iostream>
using namespace std;


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


int partitionUp(int arr[], int low, int high) {
    int cock = arr[high];
    int i = (low - 1);


    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < cock) {
            i++;
            swap(arr[i], arr[j]);
        }
       
    }


swap(arr[i + 1], arr[high]);
    return (i + 1);
   
}


void quickSortUp(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionUp(arr, low, high);


        quickSortUp(arr, low, pi - 1);
        quickSortUp(arr, pi + 1, high);
    }
}


int partitionDown(int arr[], int low, int high) {
    int cock = arr[high];
    int i = (low - 1);


    for (int j = low; j <= high - 1; j++) {
        if (arr[j] > cock) {
            i++;
            swap(arr[i], arr[j]);
        }
       
    }


swap(arr[i + 1], arr[high]);
    return (i + 1);
   
}


void quickSortDown(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionDown(arr, low, high);


        quickSortDown(arr, low, pi - 1);
        quickSortDown(arr, pi + 1, high);
    }
}




int main() {
    int minus = 0;
    int n;
    cin >> n;
    int leftZero = 0;
    int arr[10000] = {0};
    int New[10000] = {0};
   
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 3 == 0) {
            New[leftZero] = arr[i];
            leftZero++;
        }
    }


    quickSortUp(New, 0, leftZero - 1);
    int leftOne=leftZero;
    for (int i = 0; i < n; i++) {
       
        if (arr[i] % 3 == 1) {
            New[leftOne] = arr[i];
            leftOne++;
        }
    }
    quickSortDown(New, leftZero, leftOne - 1);
    int leftTwo=leftOne;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 3 == 2) {
            New[leftTwo] = arr[i];
            leftTwo++;
        }
    }
    quickSortUp(New, leftOne, leftTwo - 1);
   
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(New[i]==New[j] && i != j){
                New[i] = -1;
                minus++;
            }
        }
    }
    cout << n-minus << endl;
    for (int i = 0; i < leftTwo; i++) {
        if(New[i] != -1){
            cout << New[i] << " ";
        }
       
    }
    return 0;
}
