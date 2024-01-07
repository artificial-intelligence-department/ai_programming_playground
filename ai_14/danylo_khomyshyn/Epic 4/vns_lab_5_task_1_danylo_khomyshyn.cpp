#include <iostream>

using namespace std;

void swap_rows(int array[][3], int i, int j) {
  int temp[3];
  for (int k = 0; k < 3; k++) {
    temp[k] = array[i][k];
    array[i][k] = array[j][k];
    array[j][k] = temp[k];
  }
}

void sort_by_third_column(int array[][3], int M) {
  for (int i = 0; i < M - 1; i++) {
    for (int j = i + 1; j < M; j++) {
      if (array[i][2] > array[j][2]) {
        swap_rows(array, i, j);
      }
    }
  }
}

int main() {
  int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  sort_by_third_column(array, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
