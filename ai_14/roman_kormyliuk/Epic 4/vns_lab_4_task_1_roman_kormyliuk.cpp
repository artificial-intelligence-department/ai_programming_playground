#include <iostream>
#include <conio.h> // getch
#include <cstdlib> // містить srand() и rand()
using namespace std;

int main()
{
int a[10];
cout << "Array: \n" << endl;
for (int i = 0; i < 10; i++)
{
a[i] = rand(); // запис випадкового числа, яке поверне rand()
cout << a[i] << endl;
}
for (int i = 0; i < 10 - 5; i++) {
        a[i] = a[i + 5];
    }
for (int i = 10 - 5; i < 10; i++) {
        a[i] = rand();
    }
cout << "Updated arrey: \n "<< endl;
for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }
getch();
}