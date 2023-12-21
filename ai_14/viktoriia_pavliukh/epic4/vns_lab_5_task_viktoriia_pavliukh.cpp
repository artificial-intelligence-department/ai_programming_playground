#include <iostream>
#include <string>

using namespace std;

const int row = 5;
const int col = 2;

int max_element( int a[2][5]){
    int maxElement = 0;

    for(int i=0; i<col; i++) {
        for (int j = 0; j < row; j++) {
            int currentElement = a[i][j];
            int currentCount = 0;
            for(int k=0; k<col; k++) {
                for (int t = 0; t < row; t++) {
                    if (a[k][t] == currentElement) {
                        currentCount++;
                    }
                }
            }
            if (currentCount > 1) {
                if (currentElement > maxElement) {
                    maxElement = currentElement;
                }

            }
        }
    }
    return maxElement;
}


int main() {
    int a[2][5]={
            {2,4,1,0,0},
            {1,6,4,3,7},
    };

    for(int i=0; i<col; i++) {
        for (int j = 0; j < row; j++) {
            cout << a[i][j] << " ";
        }
        cout <<endl;
    }
    int m = max_element(a);
    cout << "Максимальний серед повторюваних елементів: " <<m<<endl;
    return 0;
}