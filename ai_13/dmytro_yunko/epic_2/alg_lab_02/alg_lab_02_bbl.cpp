#include <iostream>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


void sort(int array[], int size) {

  
  for (int step = 0; step < size - 1; step++) {
    
    for (int i = 0; i < size - 1; i++) {

      if (array[i] > array[i+1]){
        swap(&array[i], &array[i+1]);
     
      }
    }
    
  }
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

    sort(road, roadSize);

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
