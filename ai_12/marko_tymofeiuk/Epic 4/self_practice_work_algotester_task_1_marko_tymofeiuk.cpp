#include <iostream>
#include <vector>

int partition(std::vector<int> &vector, int left, int right){
    int pivot = vector[right];
    int i = left - 1;

    for (int j = left; j < right; j++){
        if (vector[j] <= pivot){
            i++;
            int tempvar = vector[i];
            vector[i] = vector[j];
            vector[j] = tempvar;
        }
    }
    int swap = vector[i+1];
    vector[i+1] = vector[right];
    vector[right] = swap;

    return i + 1;
}

void quickSort(std::vector<int> &vector, int left, int right){
    if (left<right){
        int pivotIndex = partition(vector, left, right);

        quickSort(vector, left, pivotIndex-1);
        quickSort(vector, pivotIndex+1, right);
    }
}

int main(){
    std::vector<int> zenyk;
    std::vector<int> marichka;
    
    size_t sizeZenyk;
    size_t sizeMarichka;
    std::cin >> sizeZenyk >> sizeMarichka;
    for (int i = 0; i < sizeZenyk; i++){
        int temp;
        std::cin >> temp;
        zenyk.push_back(temp);
    }
    for (int i = 0; i < sizeMarichka; i++){
        int temp;
        std::cin >> temp;
        marichka.push_back(temp);
    }

    quickSort(zenyk, 0, sizeZenyk-1);
    quickSort(marichka, 0, sizeMarichka-1);

    int final = zenyk[0] + marichka[0];
    std::cout << final;

}