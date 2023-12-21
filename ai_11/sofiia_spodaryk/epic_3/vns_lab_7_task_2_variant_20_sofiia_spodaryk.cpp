#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countEvenNumbers(const vector<int>& numbers) {
    int count = 0;
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int countWordsStartingWithA(const string& str) {
    int count = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (isalpha(str[i]) && tolower(str[i]) == 'a') {
            while (isalpha(str[i])) {
                ++i;
            }
            count++;
        }
    }
    return count;
}

int main() {
    int nNumb;
    cout << "Введіть кількість чисел: ";
    cin >> nNumb;

    vector<int> numbers;
    cout << "Введіть " << nNumb << " чисел:\n";
    for (int i = 0; i < nNumb; ++i) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string str;
    cout << "Введіть рядок: ";
    getline(cin, str);

    cout << "Кількість парних чисел: " << countEvenNumbers(numbers) << endl;
    cout << "Кількість слів, які починаються на 'a': " << countWordsStartingWithA(str) << endl;

    return 0;
}
