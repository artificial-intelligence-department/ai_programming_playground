#include <iostream>

using namespace std;


int sum(int count, ...) {
    int sum = 0;
    int *ptr = &count; 

    
    ptr++;// Переміщення вказівника на наступні аргументи

    
    for (int i = 0; i < count; ++i) {
        sum += *ptr;
        ptr++;
    }

    return sum;
}

int main() {
    int result1 = sum(3, 10, 20, 30);
    int result2 = sum(7, 5, 15, 25, 10, 20, 30, 40);
    int result3 = sum(11, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22);

    cout << "Сума з першого виклику: " << result1 << endl;
    cout << "Сума з другого виклику: " << result2 << endl;
    cout << "Сума з третього виклику: " << result3 << endl;

    return 0;
}