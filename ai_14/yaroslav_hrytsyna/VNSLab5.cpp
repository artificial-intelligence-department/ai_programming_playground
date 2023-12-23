#include <iostream>
#include <cstdlib>

using namespace std;

int FindMaxEl(int a[10][10],int r){
    int maxel=0;
    for (int i = 0; i < 10; i++) {
        if (a[r][i]>a[r][maxel]){
            maxel=i;
        }
    }
    return a[r][maxel];
}

void rotateArray(int a[10], int k) {
    int temp[k];
    
    for (int i = 0; i < k; i++) {
        temp[i] = a[10 - k + i];
    }

    for (int i = 10 - 1; i >= k; i--) {
        a[i] = a[i - k];
    }

    for (int i = 0; i < k; i++) {
        a[i] = temp[i];
    }
}

int main(){
    int a[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
           a[i][j]=rand()%10;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        int m=FindMaxEl(a,i);
        rotateArray(a[i], m);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
           cout << a[i][j] << " ";
        }
        cout<<endl;
    }
}