#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


    int** fill_matrix(int PR){ // заповнюємо матрицю значеннями функції
        int x = 1;
        int** matrix = new int*[10];

        for(int i = 0; i < 10; i++){
            matrix[i] = new int[10];
            for(int j = 0; j < 10; j++){
                matrix[i][j] = x*x;
                x += 1;
            }
        }

        return matrix;
}
    void print_matrix(int** matrix){ //виводимо матрицю
        for(int i = 0; i < 10; i ++){
            for(int j = 0; j < 10; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void buble_sort(int arr[] , int size){ //функція buble_sort для сортування рядків матриці
        for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                }
            }
        }

    }

    int** row_reverse(int** matrix , int PR){  //сортуємо матрицю за спаданням рядків
        int** new_matrix = new int*[10];
        for(int i = 0; i < 10; i++){
            new_matrix[i] = new int[10];
            for(int j = 0; j < 10; j++){
                new_matrix[i][j] = matrix[i][j];
            }
        }
        for(int i = 0; i < 10; i++){
            buble_sort(new_matrix[i], 10);
        }

        return new_matrix;
    
    }

    int* sum_of_element(int** matrix) { //знаходимо суму елементів кожного рядка
        int* sums = new int[10];

        for (int i = 0; i < 10; i++) {
            int sum = 0;
            for (int j = 0; j < 10; j++) {
                sum += matrix[i][j];
            }
            sums[i] = sum;
        }
        return sums;
}

    bool input_to_file(int* sums, int PR){ //записуємо суми рядків в файл
        ofstream fout;
        fout.open("output.txt");
        if(!fout.is_open()){
            return false;
        }
        else{
            for(int i = 0; i < 10; i++){
                fout << sums[i] << " ";
            }
        }
        fout.close();
        return true;
    }

    void multiplie_elements_in_file(int PR){ //знаходимо добуток елементів файлу
        ifstream fin;
        fin.open("output.txt");
        if(!fin.is_open()){
            cout << "Error" << endl;
        }
        else{
            int x;
            int sum = 0;
            while(fin >> x){
                sum += x;
            }
            cout << sum << endl;
        }
        fin.close();
    }

    void file_remove(int PR){ //видаляємо файл
        remove("output.txt");
    }


int main(){

    const int PR = 803;

    int** matrix = fill_matrix(PR);
    print_matrix(matrix);

    cout << endl;

    int** new_matrix = row_reverse(matrix, PR);
    print_matrix(new_matrix);

    cout << endl;

    int* sums = sum_of_element(matrix);
    input_to_file(sums, PR);

    multiplie_elements_in_file(PR);

    file_remove(PR);
    
    return 0;
}