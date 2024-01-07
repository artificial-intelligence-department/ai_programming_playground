#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Card {
    int weight;
    int index;
};

// Функція порівняння для сортування карт за їх вагою
bool compareByWeight(const Card &a, const Card &b) {
    return a.weight < b.weight;
}

int main() {
    int weightInHand;
    cin >> weightInHand;

    int n;
    cin >> n;

    vector<Card> cards(n);

    for (int i = 0; i < n; ++i) {
        cin >> cards[i].weight;
        cards[i].index = i + 1; 
    }

    
    sort(cards.begin(), cards.end(), compareByWeight);

    int totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        totalWeight += cards[i].weight;
    }

    vector<int> missingCards;

    // Знаходимо різницю між вагою колоди та вагою карт у руках
    int diff = weightInHand - totalWeight;

    if (diff < 0) {
        cout << 0 << endl; // Неможливо отримати таку вагу колоди
    } else if (diff > 0) {
        // Шукаємо карти, яких не вистачає в колоді
        int i = 0;
        while (diff > 0 && i < n) {
            diff -= cards[i].weight;
            missingCards.push_back(cards[i].index);
            ++i;
        }

        if (diff != 0) {
            cout << "Неможливо знайти відповідь" << endl; 
        } else {
            // Виводимо індекси карт, яких не вистачає в колоді
            for (int idx : missingCards) {
                cout << idx << " " << endl;
            }
        }
    } else {
        cout << "Багато розв'язків" << endl; 
    }

    return 0;
}