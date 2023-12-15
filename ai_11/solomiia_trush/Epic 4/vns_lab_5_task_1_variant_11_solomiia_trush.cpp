#include <iostream>
using namespace std;

const int M = 4;
const int N = 4;
int x = 0;

bool Is_Ascending (int array[M][N], int mm) {
    for (int i=0; i<N-1; i++) {
        if (array[mm][i]>array[mm][i+1]) {
            Is_Ascending(array, mm+1);
            return false; 
        }
    }
    return true;
}

bool Is_Descending (int array[M][N], int mm) {
    for (int i=0; i<N-1; i++) {
        if (array[mm][i]<array[mm][i+1]) {
            Is_Descending(array, mm+1);
            return false;
            }
    }
    return true;
}

void AscendingSort (int new_array[M][N], int m) {
    for (int j=0; j<N; j++) {
        for (int w=0; w<N-1-j; w++) {
            if (new_array[m][w] > new_array[m][w+1]) {
                x = new_array[m][w];
                new_array[m][w] = new_array[m][w+1];
                new_array[m][w+1] = x;
            }
        }
    }
    
}


int main ( ) {

    int array [M][N];
    int new_array [M][N];

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> array[i][j];
        }
    }

    for (int k=0; k<M; k++) {
        for (int l=0; l<N; l++) {
            new_array[k][l]=array[k][l];
        }
    }

    for (int i=0; i<M; i++) {
        cout << i+1 << " row - Ascending : " << Is_Ascending(array, i) << " Descending : " << Is_Descending(array, i) << endl;
    }

    for (int i=0; i<M; i++) {
        if (!Is_Ascending(array, i) && !Is_Descending(array, i)) {
            AscendingSort(new_array, i);
        }
    }

    for (int i=0; i<M; i++) {
        for ( int j=0; j<N; j++) {
            cout << new_array[i][j] << " ";
        }
        cout << "\n";
    }
}