#include<iostream>

using namespace std;

int main(){
    int size, k, size2;

    cout << "Enter the ring size: ";
    cin >> size;
    int ring[size];
    cout << "Enter the elements of the ring: ";
    for(int i = 0; i < size; i++){
        cin >> ring[i];
    }

    cout << "Ring:";

    for(int i = 0; i < size; i++){
        cout << " [ " << ring[i] << " ] ";
    }     
    //друк вліво
    cout << endl << "Enter k: ";
    cin >> k;   
    cout << "Left from k";

    for(int i = k; i >= 0; i--){
        cout << " [ " << ring[i] << " ] ";
    }

    for(int i = size-1; i >= k+1 ; i--){
        cout << " [ " << ring[i] << " ] ";

    }
    cout << endl;
    //видалення
    size2 = 0;
    for (int i = 0; i < size; i++) {
        if (ring[i] != size) {
            ring[size2++] = ring[i];
        }
    }

    
    cout << "Ring after removing elements: ";
    for (int i = 0; i < size2; ++i) {
        cout << " [ " << ring[i] << " ] ";
    }
    cout << endl;
    //друк вправо  
    cout << "ring right from k: ";
    for(int i = k; i < size2; i++){
        cout << " [ " << ring[i] << " ] ";
    }
    for(int i = 0; i < k; i++){
        cout << " [ " << ring[i] << " ] ";
    }

    return 0;
}