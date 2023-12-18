#include <iostream>
#include <vector>
using namespace std;

int main(){
    //Розв'язання через динамічний масив

    int Size, K;
    cout << "Enter length of array: ";
    cin >> Size;
    
    vector<int> array(Size);
    cout << "Enter value of each element of the array: " << endl; 
    for(int i = 0; i < array.size(); i++){
        cin >> array[i];
    }

    cout << "\nElements of array: " << endl;
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << "  ";
    }

    cout << "\n\nEnter value of K number: ";
    cin >> K;

    //Двонаправлене кільце вправу сторону

    for(int i = K - 1; i < array.size(); i++){
        cout << array[i] << "  ";
    }
    for(int i = 0; i < K - 1; i++){
        cout << array[i] << "  ";
    }
    cout << endl;

    int new_size = array.size() + 4;
    if(array.size() >= 4){
        array.push_back(array[0]);    
        for(int i = array.size(); i < new_size; i++){
            array.push_back(array[array.size() - 4]);
        }
    }
    else cout << "\nLength of the array is too short to add some elements" << endl;
    
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << "  ";
    }
    cout << endl;

    //Двонаправлене кільце вліву сторону

    for(int i = K - 1; i >= 0; i--){
        cout << array[i] << "  ";
    }
    for(int i = array.size() - 1; i > K - 1; i--){
        cout << array[i] << "  ";
    }

    //Розв'язання через статичний масив

    // int N = 100;
    // int K;
    // int array[N];
    // cout << "Enter length of the array: ";
    // cin >> N;

    // cout << "Enter value of each element of the array: " << endl; 
    // for(int i = 0; i < N; i++){
    //     cin >> array[i];
    // }

    // cout << "\nElements of array: " << endl;
    // for(int i = 0; i < N; i++){
    //     cout << array[i] << "  ";
    // }

    // cout << "\n\nEnter value of K number: ";
    // cin >> K;

    // //Двонаправлене кільце вправу сторону

    // for(int i = K - 1; i < N; i++){
    //     cout << array[i] << "  ";
    // }
    // for(int i = 0; i < K - 1; i++){
    //     cout << array[i] << "  ";
    // }
    // cout << endl;

    // int new_size = N + 4;
    // if(N >= 4){
    //     array[new_size];
    //     array[N] = array[0];
    //     for(int i = N + 1, j = 3; i < new_size; i++, j--){
    //         array[i] = array[N - j];
    //     }
    // }
    // else cout << "\nLength of the array is too short to add some elements" << endl;
    
    // for(int i = 0; i < new_size; i++){
    //     cout << array[i] << "  ";
    // }
    // cout << endl;

    // //Двонаправлене кільце вліву сторону

    // if(N < 3) {
    //     for(int i = 0; i < new_size; i++){
    //         cout << array[i] << "  ";
    //     }
    //     return 0;
    // }

    // for(int i = K - 1; i >= 0; i--){
    //     cout << array[i] << "  ";
    // }
    // for(int i = new_size - 1; i > K - 1; i--){
    //     cout << array[i] << "  ";
    // }
    return 0;
}