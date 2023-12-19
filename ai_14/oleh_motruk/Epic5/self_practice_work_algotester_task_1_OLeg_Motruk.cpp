#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n , m , temp;

    cin >> n >> m;
    

    vector<int> array1(n);
    vector<int> array2(m);



    for (int i = 0; i < n; i++) {
        cin >> array1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> array2[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array1[j] > array1[j + 1]) {
                temp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (array2[j] > array2[j + 1]) {
                temp = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = temp;
            }
        }
    }

    cout << array1[0] + array2[0];


    return 0;
}