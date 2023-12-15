#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main()
{
    // вводимо кількість слів (N) і мінімальну кількість повторень (K)
    int N, K;
    cin >> N >> K;

    vector<string> words(N);

    // використовуємо map аби зберегти кількість повторень кожного слова
    map<string, int> words_count;

    // вводимо слова
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];

        // нормалізуємо (переводимо в нижній регістр)
        for (int j = 0; j < words[i].length(); j++)
        {
            words[i][j] = tolower(words[i][j]);
        }

        // зберігаємо кількість повторень кожного слова
        // якщо слово вже зустрічалось, збільшуємо кількість повторень на 1
        // інакше, додаємо слово до словника (ініціалізується нулем)
        // і ставимо кількість повторень 1
        words_count[words[i]]++;
    }

    // створюємо set для зберігання нових літер
    set<char> new_letters;

    // проходимо по словнику
    // pair<string, int> - пара ключ(слово)-значення(кількість повторень)
    for (auto pair : words_count)
    {
        // якщо значення (кількість повторень) більше або дорівнює K
        if (pair.second >= K)
        {
            // додаємо всі літери слова до set 
            // (а він сам відсортує їх, і збереже лише унікальні)
            for (int i = 0; i < pair.first.size(); i++)
            {
                new_letters.insert(pair.first[i]);
            }
        }
    }

    if (new_letters.empty())
    {
        cout << "Empty!";
    }
    else
    {
        cout << new_letters.size() << endl;

        // виводимо нові літери в зворотньому порядку
        // за допомогою ітератора rbegin (reverse begin)
        for (auto it = new_letters.rbegin(); it != new_letters.rend(); it++)
        {
            cout << *it << " ";
        }
    }

    return 0;
}
