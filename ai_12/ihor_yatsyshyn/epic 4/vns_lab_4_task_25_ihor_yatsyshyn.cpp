#include <iostream>

void print(int a[], int n, int k);
void bubbleSort(int a[], int size);
void removeEven(int a[], int &n);

int main() {
    int n, k;

    std::cout << "Enter the array size: ";
    std::cin >> n;
    std::cout << "Enter the value of 'K': ";
    std::cin >> k;

    int array[n];

    std::cout << "Enter elements of the array: ";
    for(int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    print(array, n, k);
    bubbleSort(array, n);
    removeEven(array, n);
    print(array, n, k);

    return 0;
}

void print(int a[], int n, int k) {
    for(int  i = k - 1; i < n; i++) {
        std::cout << a[i] << " ";
    }
    for(int i = 0; i < k - 1; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(int a[], int n) {
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n - i; ++j){
            if (a[j] < a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void removeEven(int a[], int &n) {
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0) {
            for(int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            n--;
        }
    }
}