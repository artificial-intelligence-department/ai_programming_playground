#include <iostream>

using namespace std;



void merge(int array[],int left,int right, int mid ) {

  int leftArraySize = mid - left + 1;
  int rightArraySize = right - mid;
  
  int leftArray [leftArraySize] {0};
  int rightArray [rightArraySize] {0};

 for (size_t i = 0; i < leftArraySize; i++){

      leftArray[i] = array[left + i];
    }
    for (size_t j = 0; j < rightArraySize; j++){

        rightArray[j] = array[mid + 1 + j];
    }

    int iLeftArray = 0;
    int iRightArray = 0;
    int imergedArray = left;

    while (iLeftArray < leftArraySize && iRightArray < rightArraySize){
      if (leftArray[iLeftArray]<= rightArray[iRightArray]) {
            array[imergedArray] = leftArray[iLeftArray];
            iLeftArray++;
        }
        else {
            array[imergedArray]= rightArray[iRightArray];
            iRightArray++;
        }
        imergedArray++;
    }
    while (iLeftArray < leftArraySize) {
        array[imergedArray]= leftArray[iLeftArray];
        iLeftArray++;
        imergedArray++;
    }
    while (iRightArray < rightArraySize) {
        array[imergedArray]= rightArray[iRightArray];
        iRightArray++;
        imergedArray++;
    }


}

void mergeSort(int array[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;


    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, right, mid);
}


int main()
{
    int roadSize {0};
    cin >> roadSize;

    int road[roadSize] {0};
    int min {0};
    for (size_t i = 0; i < roadSize; i++)
    {
        cin >> road[i];
    }

    mergeSort(road, 0, roadSize-1);

    if(roadSize > 2){
      if(road[roadSize-1] - road[1] < road[roadSize-2] - road[0]){
        cout << road[roadSize-1] - road[1] <<endl; 
      }else{
        cout << road[roadSize-2] - road[0] <<endl;
      }
    
    }else if (roadSize == 2 ){
      cout << road[0];
    }else{
      cout << 0;
    }
    
    
    
    
    
    return 0;
}
