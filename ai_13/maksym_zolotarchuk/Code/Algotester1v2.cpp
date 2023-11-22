#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

long long int h[4];
long long int d[4];
bool turn = false;

// Вводимо довжину ніжок
for (int i = 0; i < 4; ++i) {
cin >> h[i];
}

// Вводимо довжину відпилювання
for (int i = 0; i < 4; ++i) {
    cin >> d[i];
}

// Перевіряємо чи не відпиляємо більше довжини ніжки
for (int i = 0; i < 4; ++i) {
   if( d[i] > h[i]) {
   cout << "ERROR" << endl;
   return 0;
   }
   h[i] -= d[i]; // Відпилюємо
// Умова коли стіл перевернеться
    if (*max_element (h, h+4) >= 2 * (*min_element(h, h+4))) {
    turn = true;
    }
}

    if (!turn && *min_element(h, h+4) == *max_element(h, h+4) && *min_element(h, h+4) != 0) {
        cout << "YES" << endl;
    }
    
    else {
        cout << "NO" << endl;
    }

      return 0;
}