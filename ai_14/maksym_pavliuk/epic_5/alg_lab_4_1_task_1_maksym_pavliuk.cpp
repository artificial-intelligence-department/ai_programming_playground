#include<iostream>
#include<algorithm>
using namespace std;

void printSet(int arr[], int size) {
    cout << size << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void setDifference(int arr1[], int size1, int arr2[], int size2) {
    int result[size1];
    int resultSize = 0;

    for (int i = 0; i < size1; i++) {
        bool found = false;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[resultSize++] = arr1[i];
        }
    }

    sort(result, result + resultSize);
    printSet(result, resultSize);
}

void setIntersection(int arr1[], int size1, int arr2[], int size2) {
    int result[min(size1, size2)];
    int resultSize = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                result[resultSize++] = arr1[i];
                break;
            }
        }
    }

    sort(result, result + resultSize);
    printSet(result, resultSize);
}

void setUnion(int arr1[], int size1, int arr2[], int size2) {
    int result[size1 + size2];
    int resultSize = 0;

    for (int i = 0; i < size1; i++) {
        result[resultSize++] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        bool found = false;
        for (int j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[resultSize++] = arr2[i];
        }
    }

    sort(result, result + resultSize);
    printSet(result, resultSize);
}

void symmetricDifference(int arr1[], int size1, int arr2[], int size2) {
    int diff1[size1 + size2];
    int diff2[size1 + size2];
    int diff1Size = 0;
    int diff2Size = 0;

    for (int i = 0; i < size1; i++) {
        bool found = false;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            diff1[diff1Size++] = arr1[i];
        }
    }

    for (int i = 0; i < size2; i++) {
        bool found = false;
        for (int j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            diff2[diff2Size++] = arr2[i];
        }
    }

    int result[size1 + size2];
    int resultSize = 0;

    for (int i = 0; i < diff1Size; i++) {
        result[resultSize++] = diff1[i];
    }

    for (int i = 0; i < diff2Size; i++) {
        result[resultSize++] = diff2[i];
    }

    sort(result, result + resultSize);
    printSet(result, resultSize);
}

int main() {
    int N, M;

    cin >> N;
    int n[N];
    for(int i = 0; i < N; i++) {
        cin >> n[i];
    }

    cin >> M;
    int m[M];
    for(int i = 0; i < M; i++) {
        cin >> m[i];
    }

    sort(n, n + N);
    sort(m, m + M);

    setDifference(n, N, m, M);
    setDifference(m, M, n, N);
    setIntersection(n, N, m, M);
    setUnion(n, N, m, M);
    symmetricDifference(n, N, m, M);

    return 0;
}