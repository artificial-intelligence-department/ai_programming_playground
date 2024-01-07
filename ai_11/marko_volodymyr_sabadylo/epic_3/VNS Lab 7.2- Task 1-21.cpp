#include <iostream>
#include <cstring>
using namespace std;

//  знаходження кількості від'ємних елементів
int count_min_el(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            ++count;
        }
    }
    return count;
}

//знаходження кількості слів, що починаються і закінчуються на ту ж букву
int count_f_let(const char* str) {
    int count = 0;
    char* strCopy = new char[strlen(str) + 1]; // Створюємо копію рядка
    strcpy(strCopy, str);

    char* token = strtok(strCopy, " ,.;");
    while (token != nullptr) {
        if (strlen(token) >= 2 && token[0] == token[strlen(token) - 1]) {
            ++count;
        }
        token = strtok(nullptr, " ,.;");
    }

    delete[] strCopy;

    return count;
}

int main() {
    //  використання для масиву цілих чисел
    int intArray[] = {1, -2, 3, -4, 5, -6};
    int intArraySize = sizeof(intArray) / sizeof(int);

    int negativeCount = count_min_el(intArray, intArraySize);
    cout  << negativeCount << endl;

    //   використання для рядка
    const char* sampleString = "apple banana level cat dog";
    int wordCount = count_f_let(sampleString);
   cout << wordCount <<endl;

    return 0;
}