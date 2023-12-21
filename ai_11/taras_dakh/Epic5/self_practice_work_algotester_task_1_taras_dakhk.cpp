#include <iostream>
#include <algorithm>
#include <vector>

// Функція для зчитування масиву
void readArray(std::vector<int>& arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

// Функція для виведення масиву
void printArray(const std::vector<int>& arr) {
    std::cout << arr.size() << std::endl; // Вивести розмір масиву
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " "; // Вивести кожен елемент масиву
    }
    std::cout << std::endl;
}

int main() {
    int N, M;
    std::cin >> N; // Зчитати розмір першого масиву
    std::vector<int> arrayN(N); // Оголосити та створити перший масив розміру N
    readArray(arrayN, N); // Зчитати елементи першого масиву

    std::cin >> M; // Зчитати розмір другого масиву
    std::vector<int> arrayM(M); // Оголосити та створити другий масив розміру M
    readArray(arrayM, M); // Зчитати елементи другого масиву

    std::sort(arrayN.begin(), arrayN.end()); // Відсортувати перший масив
    std::sort(arrayM.begin(), arrayM.end()); // Відсортувати другий масив

    // Оголосити вектори для різниці, перетину, об'єднання та симетричної різниці масивів
    std::vector<int> differenceNM, differenceMN, intersection, Union, symmetricDifference;

    // Знайти різницю між першим та другим масивами та занести в differenceNM
    std::set_difference(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), std::back_inserter(differenceNM));
    printArray(differenceNM); // Вивести різницю NM

    // Знайти різницю між другим та першим масивами та занести в differenceMN
    std::set_difference(arrayM.begin(), arrayM.end(), arrayN.begin(), arrayN.end(), std::back_inserter(differenceMN));
    printArray(differenceMN); // Вивести різницю MN

    // Знайти перетин між першим та другим масивами та занести в intersection
    std::set_intersection(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), std::back_inserter(intersection));
    printArray(intersection); // Вивести перетин

    // Знайти об'єднання першого та другого масивів та занести в Union
    std::set_union(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), std::back_inserter(Union));
    printArray(Union); // Вивести об'єднання

    // Знайти симетричну різницю між першим та другим масивами та занести в symmetricDifference
    std::set_symmetric_difference(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), std::back_inserter(symmetricDifference));
    printArray(symmetricDifference); // Вивести симетричну різницю

    return 0;
}
