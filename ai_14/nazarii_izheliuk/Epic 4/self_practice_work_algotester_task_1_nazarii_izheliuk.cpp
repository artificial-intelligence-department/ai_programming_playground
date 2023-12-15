#include<iostream>

using namespace std;

int findNSD(long long a, long long b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findArrayNSD(long long arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = findNSD(result, arr[i]);
    }
    return result;
}

int main() {
    int n, nsd;
    long long Number_of_deputies;

    cin >> n;
    if(n < 0){
        exit(0);
    }
    long long Number_of_voters[n];

    for(int i = 0; i < n; i++){
        cin >> Number_of_voters[i];
    }

    nsd = findArrayNSD(Number_of_voters, n);
    Number_of_deputies = 0;
    for(int i = 0; i < n; i++){
        Number_of_deputies = Number_of_deputies + Number_of_voters[i]/nsd;
    }

    cout << Number_of_deputies;
    return 0;
}