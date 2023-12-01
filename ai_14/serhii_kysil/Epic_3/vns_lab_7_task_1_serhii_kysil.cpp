#include <iostream>
using namespace std;
int sum(int array[], int length) {
    if (length < 2) {
        cout << "Потрібно передати принаймні два параметри для обчислення суми." << endl;
        return -1; 
    }
    int result = 0;
    for (int i = 0; i < length - 1; i++) {
        result += array[i] * array[i + 1];
    }
    return result;
}
int main() {
    int n, a, u;
    cin>> n >> u >>a;
    int array1[n];
    for(int i = 0; i < n; i++){
        array1[i] = i + 1;
    }
    int result1 = sum(array1, n);
    cout << "Результат для " << n << " параметрів: " << result1 << endl;
    int array2[u];
    for(int i = 0; i < u; i++){
        array2[i] = i + 1;
    }
    int result2 = sum(array2, u);
    cout << "Результат для " << u << " параметрів: " << result2 << endl;
    int array3[a];
    for(int i = 0; i < a; i++){
        array3[i] = i + 1;
    }
    int result3 = sum(array3, a);
    cout << "Результат для " << a << " параметрів: " << result3 << endl;
    return 0;
}
