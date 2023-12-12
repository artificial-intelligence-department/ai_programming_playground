#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftHalf[n1];
    int rightHalf[n2];

    for (int i = 0; i < n1; i++) {
        leftHalf[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightHalf[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftHalf[i] <= rightHalf[j]) {
            arr[k] = leftHalf[i];
            i++;
        } else {
            arr[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftHalf[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightHalf[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        std::swap(arr[start], arr[end]);

        start++;
        end--;
    }
}

int main()
{
    int N;
    cin >> N;

    int *a = new int [N];
    int *a0 = new int [N];
    int *a1 = new int [N];
    int *a2 = new int [N];

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    

    int j=0;
    int k1=0;
    int k2=0;
    int k3=0;
    for(int i = 0; i < N; i++){
        if (a[i]%3==0){
            a0[j]=a[i];
            j++;
            k1++;
        }
    }
    j=0;
    for(int i = 0; i < N; i++){
        if (a[i]%3==1){
            a1[j]=a[i];
            j++;
            k2++;
        }
    }
    j=0;
    for(int i = 0; i < N; i++){
        if (a[i]%3==2){
            a2[j]=a[i];
            j++;
            k3++;
        }
    }
    for(int i = 0; i < N; i++){
    }


    mergeSort(a0, 0, k1-1);
    mergeSort(a1, 0, k2-1);
    reverseArray(a1,k2);
    mergeSort(a2, 0, k3-1);
    j=0;
    for(int i = 0; i < k1; i++){
        a[j]=a0[i];
        j++;
    }
    for(int i = 0; i < k2; i++){
        a[j]=a1[i];
        j++;
    }
    for(int i = 0; i < k3; i++){
        a[j]=a2[i];
        j++;
    }





    int new_N = N;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(a[i]==a[j]){
                new_N -= 1;
                int *arr = new int [new_N];
                for(int k = 0, ind=0; k < new_N; k++, ind++){
                    if(ind == i){
                        k--;
                    } else{
                        arr[k]=a[ind];
                    }
                }
                delete[] a;
                a = arr;
                N = new_N;
                i--;
                j--;
            }
        }
    }
    cout << N << endl;
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
