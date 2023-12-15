#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    const int ALPHABET_SIZE = 26;

    // Зчитування вхідних даних
    int N, K;
    cin >> N >> K;

    // Масив для зберігання кількості входжень кожної букви
    vector<int> letterCount(ALPHABET_SIZE, 0);

    // Зчитування слів та обчислення кількості букв
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;

        // Масив для відстеження, чи була буква вже врахована для слова
        set<char> counted;

        // Обробка кожного символу у слові
        for (char letter : word) {
            char lowercaseLetter = tolower(letter);
            int index = lowercaseLetter - 'a';

            // Якщо букву ще не враховано та кількість входжень цього слова менше або рівно K
            if (counted.find(lowercaseLetter) == counted.end() && letterCount[index] < K) {
                // Збільшуємо кількість входжень та відзначаємо букву як враховану
                letterCount[index]++;
                counted.insert(lowercaseLetter);
            }
        }
    }

    // Виведення результатів
    vector<char> uniqueLetters;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (letterCount[i] >= K) {
            uniqueLetters.push_back('a' + i);
        }
    }

    // Сортування унікальних букв від останньої до першої у алфавіті
    sort(uniqueLetters.rbegin(), uniqueLetters.rend());

    // Виведення кількості та унікальних букв
    cout << uniqueLetters.size() << endl;
    for (char letter : uniqueLetters) {
        cout << letter << " ";
    }

    return 0;
}
