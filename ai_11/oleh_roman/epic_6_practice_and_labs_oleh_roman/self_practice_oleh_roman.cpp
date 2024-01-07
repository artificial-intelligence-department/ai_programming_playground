#include <iostream>
#include <ctime>

void Initialize(int arr[], int size);
void Show(int arr[], int size);
int LinearSearch(const int arr[], int size, int value);

int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    const int SIZE = 10;
    int arr[SIZE];

    Initialize(arr, SIZE);
    Show(arr, SIZE);
    std::cout << "Enter value which you want to find:\n" ;
    int value;
    std::cin >> value;
    int foundIndex = LinearSearch(arr, SIZE, value);
    if (foundIndex != -1){
        std::cout << "Array has your value" << std::endl;
        std::cout << "index of your number is:" << foundIndex << std::endl;
    } else
        std::cout << "Array hasnt your value!" << std::endl;

    return 0;
}


void Initialize(int arr[], int size){
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 100 + 1;
    }
}
void Show(int arr[], int size){
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int LinearSearch(const int arr[], int size, int value){
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            return i+1;
    
    
    return -1;
}