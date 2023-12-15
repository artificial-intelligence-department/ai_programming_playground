#include <iostream>

void bubbleSort(long arr[], long size);

int main() {
    long N, m;

    std::cin >> N;

    long r[N];
    for(int i = 0; i < N; i++) {
        std::cin >> r[i];
    }

    bubbleSort(r, N);

    if (N == 1){
        m = 0;
    }else if(r[N - 2] - r[0] < r[N - 1] - r[1]) {
        m = r[N - 2] - r[0];
    }else {
        m = r[N - 1] - r[1];
    }

    std::cout << m << std::endl;

    return 0;
}

void bubbleSort(long arr[], long size) {
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - i; ++j){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}