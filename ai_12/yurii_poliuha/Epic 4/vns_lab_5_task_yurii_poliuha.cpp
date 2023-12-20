#include <iostream>
using namespace std;

const int row = 3;
const int col = 3;

void Show(int array[row][col], int max_repeated_element, int max_count, int max);
void Review(int array[row][col]);
void Initialization(int array[row][col]);

void Initialization(int array[row][col]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> array[i][j];
        }
    } 
    Review(array);
}

void Review(int array[row][col]){
    int max_repeated_element, max_count;
    max_repeated_element = 0;
    max_count = 0;
    int max = array[0][0];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(max < array[i][j]) max = array[i][j];

            int current_element = array[i][j];
            int count = 0;
            for(int i1 = 0; i1 < row; i1++){
                for(int j1 = 0; j1 < col; j1++){
                    if(current_element == array[i1][j1]) count++;
                }
            }
            if(count > max_count || (current_element > max_repeated_element && count == max_count)){
                max_repeated_element = current_element;
                max_count = count;
            }
        }
    }
    Show(array, max_repeated_element, max_count, max); 
}

void Show(int array[row][col], int max_repeated_element, int max_count, int max){
    cout << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << array[i][j] << "  ";
        }
        cout << endl;
    } 
    cout << "Max element is: " << max << endl;
    cout << "Max element among repeated elements is: " << max_repeated_element << endl;
    cout << "It repeats " << max_count << " times" << endl;
}

int main(){
    int array[row][col];
    Initialization(array);

    return 0;
}