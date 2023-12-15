#include <iostream>

using namespace std;

void arrays(int array[], int lenght) {
    for (int i = 0; i < lenght; i++) {
        cout << array[i] << endl;
    }

}

int main() {
  int len = 10;
  int len2=0;
  int len3=0;
  int arr[len];

  for(int i=0; i<len; i++) {
    arr[i] = rand();
  }

  arrays(arr, len);

  for(int i=0; i<len; i++) {
    if (arr[i] != 0) {
      len2++;
    }
  }

  int arr2[len2];
  int a=0;
  for (int i=0; i<len2; i++) {
    if (arr[i] != 0) {
      arr2[a] = arr[i];
      a++;
    }
  }

  arrays(arr2, len2);


  for(int i=0; i<len2; i++) {
    if (arr2[i]%2==0) {
      len3++;
    }
  }

  int arr3[len3];
  int b=0;
  for(int i=0; i<len3; i++) {
    if (arr2[i]%2==0) {
      arr3[b] = arr2[i];
      arr[b+1] = arr2[i-1]+2;
      b+=2;
    }
  }

  arrays(arr3, len3);

  return 0;
}









