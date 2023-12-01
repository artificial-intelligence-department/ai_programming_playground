#include <iostream>
#include <cstring>

using namespace std;
// a) Знаходження максимального елемента
int max1(int size, int array[]) {
    int max = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// b) Знаходження довжини найдовшого слова у рядку
int max1(string str) {
   int length = str.length();
   int temp = 0;
   int step = 0;
   for (int i = 0; i < length; i++) {
      if (str[i] != ' ')
         step++;
      else {
         temp = max(temp, step);
         step = 0;
      }
   }
   return max(temp, step);}

int main() {
    // a) Тестування функції для масиву цілих чисел
    int intArray[] = {12, 45, 65, 7, 11, 128};
    int arraySize = sizeof(intArray) / sizeof(int);

    int max = max1(arraySize, intArray);
    std::cout << "maximum element of array: " << max << std::endl;

    // b) Тестування функції для рядка
    string str = "Love C++";
    cout <<"maximum length of a word is: "<<max1(str);

    return 0;
}
