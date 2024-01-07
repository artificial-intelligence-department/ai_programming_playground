#include <iostream>
using namespace std;
     
void quickSort(int arr[], int first, int last){
    int middle = arr[(first + last) / 2];
    int i = first;
    int j = last;

    do {
        while (arr[i] < middle)
            i++;
        while (arr[j] > middle)
            j--;
        if (i <= j){
            swap (arr[i], arr[j]);
            i++;
            j--;
        }

    } while (i <= j);

    if (i < last)
        quickSort(arr, i, last);
    if (j > first)
        quickSort(arr, first, j);
}
              
  
int main() {
    const int SIZE = 5;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, SIZE - 1);

cout<<"Sorted Array:\n";
    for(int i = 0 ; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}