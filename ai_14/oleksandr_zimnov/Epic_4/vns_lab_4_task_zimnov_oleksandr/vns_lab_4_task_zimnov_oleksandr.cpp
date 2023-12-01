#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>

using namespace std;

int main()
{
    int temp1;
    cout << "Enter number of massive: " << endl;
    cin >> temp1;
    int* mas = new int[temp1];
    cout << "Massive of random numbers: " << endl;
    for (int i = 0; i < temp1; i++) {
        mas[i] = rand();
        if (rand() % 2 == 0) {
            mas[i] *= -1;
        }
        cout << "A random element #" << i + 1 << ": " << mas[i] << endl;
    }
    int* mas2 = new int[temp1];
    int N = 0;
    cout << "\nMassive after change: " << endl;
    for (int i = 0; i < temp1; i++) {
        if (mas[i] % 3 != 0) {
            mas2[N] = mas[i];
            N++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (mas2[i - 1] < 0 && i!=0) {
            cout << "A random element #" << i + 1 << ": " << mas2[i] + mas2[i - 1] + 1 << endl;
        }
        else {
            cout << "A random element #" << i + 1 << ": " << mas2[i] << endl;
        }
    }
}