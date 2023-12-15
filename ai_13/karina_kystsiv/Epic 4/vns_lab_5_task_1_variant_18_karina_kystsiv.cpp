#include <iostream>
using namespace std;

void move_max(int** arr, int n, int i) {
    // Перевіряємо, чи не досягли ми кінця бічної діагоналі
    if (i >= n) return;
    // Знаходимо максимальний елемент в підмасиві, який починається з (i, i)
    int max = arr[i][i];
    int max_row = i;
    int max_col = i;
    for (int r = i; r < n; r++) {
        for (int c = i; c < n; c++) {
            if (arr[r][c] > max) {
                max = arr[r][c];
                max_row = r;
                max_col = c;
            }
        }
    }

    if (max_row != i || max_col != n-1-i) {
        for (int c = i; c < n; c++) {
            int temp = arr[i][c];
            arr[i][c] = arr[max_row][c];
            arr[max_row][c] = temp;
        }
        for (int r = i; r < n; r++) {
            int temp = arr[r][n-1-i];
            arr[r][n-1-i] = arr[r][max_col];
            arr[r][max_col] = temp;
        }
    }
    move_max(arr, n, i+1);
}

// Функція, яка перевіряє, чи вийшла на бічній діагоналі спадаюча послідовність елементів
bool is_decreasing(int** arr, int n) {
    // Перебираємо всі елементи бічної діагоналі, починаючи з другого
    for (int i = 1; i < n; i++) {
        // Якщо поточний елемент більший або рівний попередньому, то повертаємо false
        if (arr[i][n-1-i] >= arr[i-1][n-i]) {
            return false;
        }
    }
    return true;
}

void print_array(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the size of array"<< endl;
    cin >> n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           cin >> arr[i][j] ;
        }
    }

    cout << "start"<<endl;
    print_array(arr, n);
    
    move_max(arr, n, 0);
    
    cout << "end"<<endl;
    print_array(arr, n);

    if (is_decreasing(arr, n)) {
        cout << "decrease sequance";
    } else {
        cout << "no decrece sequance";
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}