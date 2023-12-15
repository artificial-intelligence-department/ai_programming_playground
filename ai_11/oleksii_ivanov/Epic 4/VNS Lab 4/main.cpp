#include <iostream>
#include <algorithm>
using namespace std;

void print_from_k(int* ring, int size, int k);

// This procedure MUTATES the state of ring and its size
void ring_without_even(int** ring, int* size); 

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int* ring = new int[n];
    cout << "Enter ring: ";
    for (int i = 0; i < n; ++i) cin >> ring[i];

    cout << "Enter position: ";
    cin >> k;

    print_from_k(ring, n, k);
    sort(ring, ring + n);
    ring_without_even(&ring, &n);
    print_from_k(ring, n, k);

    delete[] ring;
    return 0;
}

void print_from_k(int* ring, int size, int k) {
    if (k < 0) {
        cout << "Error: k is out of range" << endl;
        return;
    }

    k %= size;

    for (int i = k; i < size; ++i) cout << ring[i] << " ";
    for (int i = 0; i < k; ++i) cout << ring[i] << " ";
    cout << endl;
}

// This procedure MUTATES the state of ring and its size
void ring_without_even(int** ring, int* size) {
    int new_size = 0;
    for (int i = 0; i < *size; ++i) if ((*ring)[i] % 2 == 1) ++new_size;

    int* new_ring = new int[new_size];
    for (int i = 0, j = 0; i < *size; ++i)
        if ((*ring)[i] % 2 == 1)
            new_ring[j++] = (*ring)[i];

    delete[] *ring;
    *ring = new_ring;
    *size = new_size;
}