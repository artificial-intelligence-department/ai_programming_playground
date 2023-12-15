#include <iostream>
using namespace std;

//Bubble sort
void BubbleSort (int arr[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j +1]);
            }
        }
    }
}

//serch for median for arr
int median(int arr[], int n)
{
    if (n % 2 != 0)
    {
        return arr[n/2];
    }else
    {
         return (arr[(n - 1) / 2] + arr[n / 2]) / 2;
    }
}

int main(){
    int diff = 0;
    int n = 0;
    cin >> n; // ask for arr size

    int arr [n];

    //ask num for arr
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //bubblesort for arr[n]
    BubbleSort(arr, n);
    for(int i=0;i<n;i++)
    {
    cout<<arr[i]<< " ";
    }
    cout << endl;
    //median for bubble sorted arr[n]
    int mediana = median(arr, n);
    //find diff for median from arr[n]
    for(int i = 0; i < n; ++i){
        diff += abs(arr[i] - mediana);
    }

    cout<< diff;
    return 0;
}