#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



int main() {
    srand(time(0)); 
    
    const int N = 100; 

    int array[N], realN;
    
    cout << "Реальна довжина масиву: " ;
    cin >> realN ;
    // 1) Сформувати одновимірний масив цілих чисел, використовуючи генератор випадкових чисел.
    for (int i = 0; i < realN; i++) {
        array[i] = rand() % 100 + 1;
    }

    // 2) Роздрукувати отриманий масив.
    cout << "Початковий масив: ";
    for (int i = 0; i < realN; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // 3) Знищити 5 останніх елементів масиву.
    realN -= 5; 
    
    // 4) Додати в початок масиву 3 елементи зі значенням M[I+1]+2.
    int added = 3;
    for (int i = realN - 1; i >= 0; i--) {
        array[i + added] = array[i];

        // умова M[I+1]+2
        if (i < added){
            array[i] = array[added + i + 1] + 2;
        }
    }
    realN += added;


    // 5) Роздрукувати отриманий масив.
    cout << "Змінений масив: ";
    for (int i = 0; i < realN; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
