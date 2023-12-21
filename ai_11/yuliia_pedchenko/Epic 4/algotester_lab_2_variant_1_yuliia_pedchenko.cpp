#include <iostream>

using namespace std;

void sort(int r[], int N) {                     //функція сортування елементів масиву від меншого до більшого,
    for (int i = 0; i < (N - 1); i++)           //щоб можна було в подальшому застосувати формулу
        for (int j = 0; j < (N - i - 1); j++) 
            if (r[j] > r[j + 1]) 
            swap(r[j], r[j + 1]);          

}

int main() {
int N;
int m;
cin >> N;

if (N<1) return 0; 

int r[N];
for (int i = 0; i < N; i++) {
    cin >> r[i];
    if (r[i]<0) return 0;
}

if (N==1) {cout << 0; return 0;}
sort(r, N);
int v1 = r[N-2]-r[0];       //перевіряємо, яка з різниць менша: різниця останнього і другого, чи 
int v2 = r[N-1]-r[1];       //передостаннього і першого
if (v1 < v2) m = v1;
else m = v2;
cout << m;
}
