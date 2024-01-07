#include <iostream>
#include <vector>

using namespace std;

struct RingArray {
    vector<int> elements;
    int size;
};

void printRingArrayLeft(const RingArray& ring, int k) {
    int current_index = k;
    do {
        cout << ring.elements[current_index] << " ";
        current_index = (current_index - 1 + ring.size) % ring.size;
    } while (current_index != (k - 1 + ring.size) % ring.size);

    cout << ring.elements[(k - 1 + ring.size) % ring.size] << endl;
}

// Функція для додавання першого і останнього елементів до кільця
void addElementsToRing(RingArray& ring, int first_element, int last_element) {

    ring.elements.insert(ring.elements.begin(), first_element);
    ring.elements.push_back(last_element);
    ring.size += 2;
}

void printRingArrayRight(const RingArray& ring, int k) { // Функція для роздрукування масиву по колу вправо від K-го елемента до K+1
    
    int current_index = k;
    do {
        cout << ring.elements[current_index] << " ";
        current_index = (current_index + 1) % ring.size;
    } while (current_index != (k + 1) % ring.size);

    cout << ring.elements[(k + 1) % ring.size] << endl;
}

int main() {
    RingArray ring;
    ring.elements = {1, 2, 3, 4, 5};
    ring.size = 5;

    int k = 2;

    printRingArrayLeft(ring, k);    //  масив по колу вліво від k-го елемента до k-1


    addElementsToRing(ring, 99, 100);    // Додаємо перший і останній елементи до кільця


    printRingArrayRight(ring, k);// масив по колу вправо від k-го елемента до k+1

    return 0;
}
