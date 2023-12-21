#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printElements(const vector<int>& ring, int k) { // Функція для виведення елементів кільця, починаючи з K-ого і до K+1
    int size = ring.size();
    for (int i = k; i != (k + 2) % size; i = (i + 1) % size) {
        cout << ring[i] << " ";
    }
    cout << endl;
}

int main() {
    int k;
    cout << "Введіть розмір масиву: ";
    int size;
    cin >> size;

    vector<int> ring(size);
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < size; ++i) {
        cin >> ring[i];
    }

    cout << "Введіть K: ";
    cin >> k;

    cout << "Елементи кільця, починаючи з K-ого і до K+1: ";
    printElements(ring, k);

    sort(ring.rbegin(), ring.rend());// впорядкування елементів по спаданню

    
    ring.erase(remove_if(ring.begin(), ring.end(), [](int x) { return x % 2 != 0; }), ring.end()); //  знищення непарних елементів

    cout << "Елементи кільця після видалення непарних, починаючи з K-ого і до K+1: ";
    printElements(ring, k);

    return 0;
}