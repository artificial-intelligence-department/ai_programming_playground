#include <iostream>
#include <cstdlib>
#include <ctime>
#define size 10
using namespace std;
int main() {
    int mas[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % 100;
    }
    cout << "Original: ";
    for (int i = 0; i < size; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
    int nsize = 0;
    for (int i = 0; i < size; i++) {
        if (mas[i] % 7 != 0) {
            mas[nsize] = mas[i];
            nsize++;
        }
    }
    int upsize = nsize;
    for (int i = 0; i < size; i++) {
        if (mas[i] % 2 != 0) {
            upsize++;

            for (int j = upsize - 1; j > i + 1; j--) {
                mas[j] = mas[j - 1];
            }

            mas[i + 1] = 0;
            i++;
        }
    }
    cout << "Edited: ";
    for (int i = 0; i < upsize; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
    return 0;
}
